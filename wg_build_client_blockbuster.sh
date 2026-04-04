#!/usr/bin/env bash
set -euo pipefail

# ─── Configuration ────────────────────────────────────────────────────────────
WG_INTERFACE="blockbuster"
SERVER_PUBKEY="h3H2rlhWIeVI8pIcYZDTTRyUyNnGcPqpdtAEVxLK8xw="
SERVER_PORT="51821"
CLIENT_DNS="192.168.0.153"
SUBNET_PREFIX="10.0.123"
# ──────────────────────────────────────────────────────────────────────────────

# Run from the directory the script lives in so key/conf files land there
cd "$(dirname "$(realpath "$0")")"

usage() {
  echo "Usage: sudo ./wg_build_client_blockbuster.sh <peer-name> [--force|--remove]"
}

# Must run as root to read/write /etc/wireguard/
if [[ "${EUID}" -ne 0 ]]; then
  usage; exit 1
fi

if [[ $# -lt 1 || -z "${1:-}" ]]; then
  usage; exit 1
fi

name="$1"
force=0
remove=0

if [[ -n "${2:-}" ]]; then
  case "${2}" in
    --force)  force=1 ;;
    --remove) remove=1 ;;
    *) usage; exit 1 ;;
  esac
fi

# Restrict peer names to safe characters
if [[ ! "$name" =~ ^[a-zA-Z0-9_-]+$ ]]; then
  echo "Invalid peer name '${name}'. Use only letters, numbers, underscores, and hyphens."
  exit 1
fi

wg_conf="/etc/wireguard/${WG_INTERFACE}.conf"
key_file="${name}.key"
conf_file="${name}.conf"

# ─── Remove mode ──────────────────────────────────────────────────────────────
if [[ "$remove" -eq 1 ]]; then
  [[ ! -f "$key_file" ]] && { echo "No key file found: $(pwd)/${key_file}"; exit 1; }

  pubkey="$(wg pubkey < "$key_file")"

  # Strip the matching [Peer] block from the server config.
  # awk buffers each [Peer] block and only prints it if the PublicKey doesn't match.
  if grep -qF "$pubkey" "$wg_conf"; then
    awk -v key="$pubkey" '
      /^\[Peer\]$/ {
        if (in_peer && !skip) printf "%s", buf
        buf = $0 "\n"; in_peer = 1; skip = 0; next
      }
      in_peer && /^PublicKey[[:space:]]*=/ {
        v = $0; sub(/^PublicKey[[:space:]]*=[[:space:]]*/, "", v)
        gsub(/^[[:space:]]+|[[:space:]]+$/, "", v)
        if (v == key) skip = 1
        buf = buf $0 "\n"; next
      }
      in_peer && /^\[/ {
        # Start of a new section — flush buffered peer block if it was not the target
        if (!skip) printf "%s", buf
        in_peer = 0; buf = ""
        # Fall through to print the new section header
      }
      in_peer { buf = buf $0 "\n"; next }
      { print }
      END { if (in_peer && !skip) printf "%s", buf }
    ' "$wg_conf" > "${wg_conf}.tmp" && mv "${wg_conf}.tmp" "$wg_conf"
    echo "Removed peer from ${wg_conf}"

    # Remove from the live interface without restarting it
    if wg show "$WG_INTERFACE" >/dev/null 2>&1; then
      wg set "$WG_INTERFACE" peer "$pubkey" remove
      echo "Removed peer from live interface."
    fi
  else
    echo "Peer not found in ${wg_conf}, skipping server config."
  fi

  [[ -f "$conf_file" ]] && { rm "$conf_file"; echo "Deleted ${conf_file}"; }
  rm "$key_file" && echo "Deleted ${key_file}"
  echo "Done."
  exit 0
fi

# ─── Build mode ───────────────────────────────────────────────────────────────

for cmd in wg curl qrencode; do
  if ! command -v "$cmd" >/dev/null 2>&1; then
    echo "Missing required command: $cmd"; exit 1
  fi
done

[[ ! -f "$wg_conf" ]] && { echo "Server config not found: $wg_conf"; exit 1; }

# Generate a private key if one doesn't already exist for this peer
if [[ ! -f "$key_file" ]]; then
  echo "Generating new private key: $(pwd)/${key_file}"
  wg genkey > "$key_file"
  chmod 600 "$key_file"
fi

# Bail out if the client config already exists (use --force to overwrite)
if [[ -e "$conf_file" && "$force" -ne 1 ]]; then
  echo "File already exists: $(pwd)/${conf_file}. Use --force to overwrite."
  exit 1
fi

privkey="$(<"$key_file")"
pubkey="$(wg pubkey < "$key_file")"

# Look up the IP already assigned to this peer in the server config
assigned_ip="$(
  awk -v key="$pubkey" '
    function trim(s) { gsub(/^[[:space:]]+|[[:space:]]+$/, "", s); return s }
    /^\[Peer\]$/                { in_peer = 1; found_key = 0; next }
    /^\[/ && !/^\[Peer\]$/      { in_peer = 0 }
    !in_peer                    { next }
    /^PublicKey[[:space:]]*=/   {
      v = $0; sub(/^PublicKey[[:space:]]*=[[:space:]]*/, "", v)
      found_key = (trim(v) == key); next
    }
    found_key && /^AllowedIPs[[:space:]]*=/ {
      v = $0; sub(/^AllowedIPs[[:space:]]*=[[:space:]]*/, "", v)
      split(v, parts, ",")
      ip = trim(parts[1]); sub(/\/32$/, "", ip)
      print ip; exit
    }
  ' "$wg_conf"
)"

# If the peer isn't registered yet, pick the next free IP and add it
if [[ -z "$assigned_ip" ]]; then
  echo "Peer not found — assigning a new IP and registering in ${wg_conf}."

  assigned_ip="$(
    awk -v prefix="$SUBNET_PREFIX" '
      /^AllowedIPs[[:space:]]*=/ {
        n = split($0, parts, ",")
        for (i = 1; i <= n; i++) {
          v = parts[i]; gsub(/^[[:space:]]+|[[:space:]]+$/, "", v)
          if (match(v, prefix "\\.[0-9]+")) {
            sub(/.*\./, "", v); sub(/\/.*/, "", v)
            used[v + 0] = 1
          }
        }
      }
      END {
        for (i = 2; i <= 254; i++)
          if (!used[i]) { print prefix "." i; exit }
      }
    ' "$wg_conf"
  )"

  [[ -z "$assigned_ip" ]] && { echo "No free IPs left in ${SUBNET_PREFIX}.0/24"; exit 1; }

  # Append the new [Peer] block to the server config
  printf '\n[Peer]\n# %s\nPublicKey = %s\nAllowedIPs = %s/32\n' \
    "$name" "$pubkey" "$assigned_ip" >> "$wg_conf"
  echo "Registered peer with IP ${assigned_ip}/32"

  # Hot-add to the live interface if it's running (no restart needed)
  if wg show "$WG_INTERFACE" >/dev/null 2>&1; then
    wg addconf "$WG_INTERFACE" \
      <(printf '[Peer]\nPublicKey = %s\nAllowedIPs = %s/32\n' "$pubkey" "$assigned_ip")
    echo "Live interface updated."
  fi
fi

# Sanity-check the IP before embedding it in the config
if [[ ! "$assigned_ip" =~ ^([0-9]{1,3}\.){3}[0-9]{1,3}$ ]]; then
  echo "Resolved client IP is not a valid IPv4 address: ${assigned_ip}"; exit 1
fi

# Fetch the server's current public IP for the Endpoint field
endpoint_ip="$(curl -s https://ifconfig.me)"
[[ -z "$endpoint_ip" ]] && { echo "Failed to resolve public IP."; exit 1; }
if [[ ! "$endpoint_ip" =~ ^([0-9]{1,3}\.){3}[0-9]{1,3}$ ]]; then
  echo "Resolved endpoint is not a valid IPv4 address: ${endpoint_ip}"; exit 1
fi

# Write the client config
cat > "$conf_file" <<EOF
[Interface]
PrivateKey = ${privkey}
Address = ${assigned_ip}/32
DNS = ${CLIENT_DNS}

[Peer]
# Server public key
PublicKey = ${SERVER_PUBKEY}
Endpoint = ${endpoint_ip}:${SERVER_PORT}
# Route LAN and VPN subnet through the tunnel; everything else goes direct
AllowedIPs = 192.168.0.0/24, ${SUBNET_PREFIX}.0/24
PersistentKeepalive = 25
EOF

chmod 600 "$conf_file"

# Print a QR code so phones can import the config directly
qrencode -t ansiutf8 < "$conf_file"

echo
echo "Done."
echo "  Name:    ${name}"
echo "  IP:      ${assigned_ip}/32"
echo "  Pubkey:  ${pubkey}"
echo "  Config:  $(pwd)/${conf_file}"
