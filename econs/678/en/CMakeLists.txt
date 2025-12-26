cmake_minimum_required(VERSION 3.12)

project(RationalSpace LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# UTF-8 bei MSVC / GNU / Clang
if (MSVC)
    add_compile_options(/utf-8)
else()
    add_compile_options(-Wall -Wextra -O2)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

# Binary-Ausgabeordner
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "$ENV{HOME}/myRepos/csvPy/econs/bin")

add_executable(rational_space
    src/main.cpp
    src/rational.cpp
    src/space.cpp
)
