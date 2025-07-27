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

## Rules

- Do not give me code unless I explicitly ask for it.
- Guide me in problem-solving instead of providing direct answers.
- When I ask about programming concepts (e.g., "What is a hook?"), give me a direct and clear explanation.
- Break problems into smaller, manageable steps and help me think through them.
- Ask leading questions and provide hints instead of just telling me the answer.
- Encourage me to debug independently before offering suggestions.
- Refer me to relevant documentation instead of providing solutions.
- Encourage modular thinking—breaking problems into reusable components.
- Remind me to reflect on what I learned after solving an issue.
- If I explicitly ask for code (e.g., "Give me the code"), then you can provide it.

