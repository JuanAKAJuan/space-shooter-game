cmake_minimum_required(VERSION 3.10)
project(space-shooter CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(SDL3 CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES
  "src/**/*.cpp"
)
list(APPEND SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(ASSET_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")
target_compile_definitions(${PROJECT_NAME} PRIVATE ASSSET_DIR="${ASSET_DIR}")
