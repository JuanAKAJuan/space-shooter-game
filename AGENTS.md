# AGENTS.md - Space Shooter Game

## Build Commands

- Build: `cmake -B build && cmake --build build`
- Run: `./build/space_shooter`
- Clean: `rm -rf build/`

## Code Style (enforced by .clang-format)

- Language: C++
- Indentation: Tabs (4 spaces width)
- Column limit: 120 characters
- Braces: Attach style (`{` on same line)
- Pointer alignment: Left (`int* ptr`)
- Include order: Local headers first, then system headers
- Naming: snake_case for functions/variables, PascalCase for classes
- Constants: UPPER_CASE for static constexpr
- Access modifiers: -4 offset from class

## Project Structure

- Headers: Use `#pragma once`
- Source files in `src/` directory
- Dependencies: Raylib (auto-fetched via CMake)
- Compiler flags: `-Wall -Wextra -Wpedantic -Werror`

## Error Handling

- No specific error handling patterns established yet
- Follow C++ best practices for exceptions and RAII

## Other

- When you generate code, make sure to document the code using Doxygen styled comments
