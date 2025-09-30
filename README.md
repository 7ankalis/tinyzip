# tinyzip

A tiny, dependency-free command‑line file compressor and decompressor written in C++14. It focuses on a clean CLI, predictable file naming, and a minimal build footprint.

Note on format: The tool uses “.gz” as the default output suffix for compressed files. This suffix is used by convention in this project and only guarantees round‑trip compatibility with tinyzip itself unless otherwise documented.

---

## Table of Contents
- Overview
- Features
- Platform Support
- Installation
  - Prebuilt Binary (local install)
  - Build from Source
- Usage
  - Synopsis
  - Commands
  - Examples
  - Exit Codes
- Troubleshooting
- Testing
- Project Structure
- Contributing
- License

## Overview

tinyzip provides two commands:
- compress <path> → writes <path>.gz
- decompress <path>.gz → writes <path>.out

This makes it simple to validate round‑trip integrity (compare original and .out).

## Features

- Single, small CLI binary
- No external runtime dependencies
- C++14 implementation, built with CMake
- Clear and predictable file naming
- Round‑trip friendly workflow

## Platform Support

- Linux, macOS (x86_64/arm64) with a C++14‑capable compiler (GCC, Clang)
- Windows via WSL or native toolchains if configured appropriately

## Installation

### Option A: Use the built binary locally
After building (see below), the binary is located at build/tinyzip (Unix‑like systems). You can run it directly or place it on your PATH: