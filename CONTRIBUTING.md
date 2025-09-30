# Contributing to tinyzip

Thank you for considering a contribution! This guide covers how to propose changes, develop locally, and submit a high‑quality pull request.

## Code of Conduct

Be respectful and constructive. Disagreements happen—keep discussions technical. Harassment, discrimination, and personal attacks are not tolerated.

## How to Contribute

- Report bugs and request features via issues. Please include:
  - Exact command(s) you ran
  - Expected vs. actual behavior
  - OS and version, compiler and version, and any logs
- For larger changes, open an issue first to discuss the approach.
- For small fixes (typos, docs, minor code cleanups), feel free to go straight to a PR.

## Development Workflow

1. Fork the repository and create your feature branch:
   ```bash
   git checkout -b feature/short-description
   ```
2. Build in Debug:
   ```bash
   mkdir -p build && cd build
   cmake -DCMAKE_BUILD_TYPE=Debug ..
   cmake --build . --config Debug
   ```
3. Run the binary:
   ```bash
   ./tinyzip --help  # if available
   # or run commands, e.g.:
   ./tinyzip compress <path>
   ./tinyzip decompress <path>.gz
   ```
4. Add tests and documentation (README, usage examples) as needed.
5. Ensure all tests pass (see Testing below).
6. Commit cleanly and open a pull request.

Tip: For more warnings during development:
