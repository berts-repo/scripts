#!/usr/bin/env python3
"""
Bulk rename files/directories to snake_case or kebab-case.

Defaults to DRY RUN. Use --apply to actually rename.

Examples:
  # Preview changes (dry-run)
  python3 rename_case.py ~/Documents --mode snake --recursive

  # Apply changes
  python3 rename_case.py ~/Documents --mode kebab --recursive --apply

  # Only rename files (not directories)
  python3 rename_case.py . --mode snake --recursive --files-only --apply

  # Include hidden files/folders
  python3 rename_case.py . --mode kebab --recursive --include-hidden --apply
"""

from __future__ import annotations
import argparse
import os
import re
from pathlib import Path
from typing import Iterable, Tuple

SEP_MAP = {
    "snake": "_",
    "kebab": "-",
}

def normalize_name(name: str, mode: str) -> str:
    """
    Convert a filename (without path) to snake_case or kebab-case.
    Preserves file extension for files (handled outside).
    """
    sep = SEP_MAP[mode]

    # Normalize unicode-ish whitespace to plain spaces
    s = re.sub(r"\s+", " ", name.strip())

    # Replace any non-alphanumeric with spaces (we'll collapse later)
    # Keep letters/numbers. Everything else becomes a space.
    s = re.sub(r"[^A-Za-z0-9]+", " ", s)

    # Collapse multiple spaces to one
    s = re.sub(r"\s+", " ", s).strip()

    # Lowercase and join with separator
    if not s:
        return ""
    return sep.join(s.lower().split(" "))

def is_hidden(path: Path) -> bool:
    return path.name.startswith(".")

def unique_target(parent: Path, target_name: str) -> Path:
    """
    Ensure we don't collide with an existing sibling.
    If parent/target_name exists, append -2, -3, etc (or _2 for snake).
    """
    base = target_name
    suffix_num = 2
    target = parent / base
    while target.exists():
        # Try to preserve extension if present
        stem, ext = os.path.splitext(base)
        target = parent / f"{stem}-{suffix_num}{ext}"
        suffix_num += 1
    return target

def plan_renames(
    root: Path,
    mode: str,
    recursive: bool,
    include_hidden: bool,
    files_only: bool,
    dirs_only: bool,
) -> Iterable[Tuple[Path, Path]]:
    """
    Yield (src, dst) rename operations. Renames are planned bottom-up so
    directories rename after contents (avoids path breakage).
    """
    if files_only and dirs_only:
        raise ValueError("Choose at most one of --files-only or --dirs-only")

    # Gather candidates
    paths: list[Path] = []
    if recursive:
        for p in root.rglob("*"):
            paths.append(p)
    else:
        paths.extend(root.iterdir())

    # Bottom-up: deeper paths first so renaming directories doesn't break iteration
    paths.sort(key=lambda p: len(p.parts), reverse=True)

    for p in paths:
        if not include_hidden and is_hidden(p):
            continue
        if files_only and not p.is_file():
            continue
        if dirs_only and not p.is_dir():
            continue

        parent = p.parent

        if p.is_file():
            stem = p.stem
            ext = p.suffix  # includes the dot or empty
            new_stem = normalize_name(stem, mode)
            if not new_stem or new_stem == stem:
                continue
            new_name = new_stem + ext
        else:
            new_name = normalize_name(p.name, mode)
            if not new_name or new_name == p.name:
                continue

        dst = parent / new_name

        # No-op if same path
        if dst == p:
            continue

        # Handle collisions
        if dst.exists():
            dst = unique_target(parent, new_name)

        yield (p, dst)

def main() -> int:
    ap = argparse.ArgumentParser(description="Bulk rename to snake_case or kebab-case.")
    ap.add_argument("path", help="Root path to rename within")
    ap.add_argument("--mode", choices=["snake", "kebab"], default="snake",
                    help="Rename style (default: snake)")
    ap.add_argument("--recursive", action="store_true", help="Recurse into subdirectories")
    ap.add_argument("--apply", action="store_true", help="Actually rename (default: dry-run)")
    ap.add_argument("--include-hidden", action="store_true", help="Include dotfiles and hidden folders")
    ap.add_argument("--files-only", action="store_true", help="Rename files only")
    ap.add_argument("--dirs-only", action="store_true", help="Rename directories only")
    args = ap.parse_args()

    root = Path(args.path).expanduser().resolve()
    if not root.exists():
        print(f"Error: path does not exist: {root}")
        return 2
    if not root.is_dir():
        print(f"Error: path must be a directory: {root}")
        return 2

    ops = list(plan_renames(
        root=root,
        mode=args.mode,
        recursive=args.recursive,
        include_hidden=args.include_hidden,
        files_only=args.files_only,
        dirs_only=args.dirs_only,
    ))

    if not ops:
        print("No changes needed.")
        return 0

    # Print plan
    print(f"{'APPLY' if args.apply else 'DRY RUN'}: {len(ops)} rename(s)")
    for src, dst in ops:
        rel_src = src.relative_to(root)
        rel_dst = dst.relative_to(root)
        print(f"  {rel_src}  ->  {rel_dst}")

    if not args.apply:
        print("\nNothing renamed (dry-run). Re-run with --apply to perform changes.")
        return 0

    # Apply renames
    # Important: rename in the planned order (bottom-up)
    for src, dst in ops:
        try:
            src.rename(dst)
        except Exception as e:
            print(f"FAILED: {src} -> {dst} ({e})")
            return 1

    print("Done.")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())

