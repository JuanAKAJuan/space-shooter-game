# AGENTS.md - Space Shooter Game

## Build Commands

- Build: `cmake -B build && cmake --build build`
- Run: `./build/space_shooter`
- Quick build+run: `./run.sh`
- Clean: `rm -rf build/`
- Format code: `clang-format -i src/*.cpp src/*.h`

## Code Style (enforced by .clang-format)

- Language: C++17+ with `-Wall -Wextra -Wpedantic -Werror`
- Indentation: Always tabs (4 space width display)
- Column limit: 120 characters
- Braces: Attach style (`{` on same line)
- Pointer/reference alignment: Left (`int* ptr`, `int& ref`)
- Include order: Local headers first (`"header.h"`), then system (`<iostream>`)
- Naming: snake_case for functions/variables, PascalCase for classes
- Constants: UPPER_CASE for static constexpr
- Access modifiers: -4 indent offset from class

## Project Structure

- Headers: Use `#pragma once` instead of include guards
- All source files in `src/` directory
- Dependencies: Raylib 5.5 (auto-fetched via CMake FetchContent)
- CMake generates compile_commands.json for IDE support

## Documentation & Comments

- Use Doxygen-style comments for all public APIs: `/** @brief Description */`
- Document class members, function parameters, and return values
- Keep inline comments minimal and focused on "why", not "what"
