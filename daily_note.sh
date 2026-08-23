#!/usr/bin/env bash
set -euo pipefail

# To use this script easily:
#   1. Symlink it:  ln -s /path/to/daily_note ~/.local/bin/daily_note
#   2. Add alias:   echo "alias dn='~/.local/bin/daily_note'" >> ~/.zshrc
#   3. Reload:      source ~/.zshrc

# Discover the Obsidian vault by checking a few likely locations and
# verifying the folder looks like a real vault (contains .obsidian).
find_vault() {
  local candidates=(
    "$HOME/vaultimore"
    "$HOME/documents/vaultimore"
    "$HOME/Documents/vaultimore"
  )
  for candidate in "${candidates[@]}"; do
    local resolved
    if [[ -d "$candidate" ]]; then
      if command -v realpath >/dev/null 2>&1; then
        resolved=$(realpath "$candidate" 2>/dev/null || true)
      fi
      if [[ -z "${resolved:-}" ]]; then
        resolved=$(cd "$candidate" 2>/dev/null && pwd || true)
      fi
    fi
    if [[ -n "$resolved" && -d "$resolved/.obsidian" ]]; then
      echo "$resolved"
      return
    fi
  done
  echo "daily_note: could not find vaultimore vault" >&2
  exit 1
}

# Resolve core paths for today's daily note inside the discovered vault.
VAULT=$(find_vault)
DAILY_DIR="$VAULT/daily"
DATE=$(date +%Y-%m-%d)
NOTE="$DAILY_DIR/$DATE.md"

# Parse CLI flags and enable scratchpad mode when requested.
SCRATCHPAD=false
for arg in "$@"; do
  case "$arg" in
  --scratchpad | --s | -s) SCRATCHPAD=true ;;
  esac
done

# Create today's note if missing, including parent directory and title header.
if [[ ! -f "$NOTE" ]]; then
  mkdir -p "$DAILY_DIR"
  printf "# %s\n\n" "$DATE" >"$NOTE"
fi

# Launch editor in scratchpad terminal when requested; otherwise open normally.
if $SCRATCHPAD; then
  if [[ "$(uname -s)" == "Darwin" ]]; then
    exec nvim "$NOTE"
  else
    hyprctl dispatch exec "[workspace special:scratchpad silent] alacritty -e nvim '$NOTE'"
  fi
else
  exec nvim "$NOTE"
fi
