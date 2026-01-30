# Repository Guidelines

This repository is a collection of small, self-contained code samples across C/C++, Java, Python, HTML, and scripts. There is no single build system; each example is compiled or run on its own.

## Project Structure & Module Organization

- `c-plus/`: C/C++ sample programs and input files.
- `java/`: Java examples plus course subfolders like `java/cs352/`.
- `python/`: Python scripts and small data sets (e.g., `python/sherbert/recipes-form/`).
- `html/`: Standalone HTML samples.
- `scripts/`: Utility scripts in Python, PowerShell, and C/C++.
- Root-level `blank.*` files are minimal starting templates.

## Build, Test, and Development Commands

There is no unified build. Use per-file commands:

```bash
# C
gcc -std=c11 -Wall -Wextra c-plus/IfSample.cpp -o /tmp/IfSample

# C++
g++ -std=c++17 -Wall -Wextra c-plus/String01.cpp -o /tmp/String01

# Java
javac java/HelloWorld.java && java -cp java HelloWorld

# Python
python3 python/spellcheck.py
```

## Coding Style & Naming Conventions

- Follow the style in each directory (most files use simple, instructional formatting).
- Use 2–4 space indentation consistent with the file you edit.
- Match existing naming patterns (e.g., `CamelCase.java`, `snake_case.py` when present).
- Prefer minimal dependencies; examples should be runnable with standard toolchains.
- Keep line endings as LF (`\n`) to avoid `^M` artifacts in Unix tools.

### C/C++ Conventions

- Filenames: `PascalCase.cpp` for C++ samples; `snake_case.c` or existing pattern for C files.
- Types: `PascalCase` for structs/classes; `snake_case` or `lowerCamelCase` for variables/functions (follow file style).
- Constants: `UPPER_SNAKE_CASE` for macros and `const` globals.
- Headers: prefer `<cstdio>`, `<cstdlib>`, `<cstring>`, `<cmath>` in C++; C headers are acceptable if already used.
- Memory: use `new/delete` or `malloc/free` consistently within a file; if using `malloc/calloc/realloc` in C++, cast the result.
- I/O: stay consistent (either `printf/scanf` or `iostream`) within a file.

### Python Conventions

- Filenames: `snake_case.py`.
- Functions/vars: `snake_case`; classes: `PascalCase`; constants: `UPPER_SNAKE_CASE`.
- Imports: standard library first, then third‑party, then local; one per line when feasible.
- Formatting: 4 spaces; avoid trailing whitespace; keep scripts runnable with `python3`.

### Java Conventions

- Filenames: `PascalCase.java` matching the public class.
- Packages: `lowercase` with dots (e.g., `cs352.examples`).
- Classes/interfaces/enums: `PascalCase`; methods/vars: `lowerCamelCase`; constants: `UPPER_SNAKE_CASE`.
- One public class per file; keep `main` minimal and focused on example behavior.

### HTML/CSS/JS Conventions

- Filenames: `kebab-case.html`/`kebab-case.css`/`kebab-case.js` unless existing pattern differs.
- Indentation: 2 spaces for HTML/CSS, 2–4 for JS matching file style.
- Keep HTML standalone; avoid external dependencies unless the example is explicitly about them.

### Scripts (shell/PowerShell/etc.)

- Filenames: `snake_case.sh` / `PascalCase.ps1` when applicable (follow existing).
- Include a shebang for shell scripts when intended to be executable.
- Keep scripts self‑contained and non‑destructive by default; document any required args at top.

## Testing Guidelines

No centralized test framework is present. If you add tests, keep them near the example (e.g., `java/MyExampleTest.java`) and include a short run command in the file header or this guide.

## Commit & Pull Request Guidelines

Git history is not available in this workspace, so no commit convention can be inferred. Use clear, imperative commit messages (e.g., “Add sample for pointer arithmetic”) and include:

- A short summary of the change
- The directory or example affected
- Any run instructions if behavior changes

## Security & Configuration Tips

- Some samples read local input files (e.g., `c-plus/Input*.txt`). Keep paths relative.
- Avoid adding secrets or credentials to example data files.
