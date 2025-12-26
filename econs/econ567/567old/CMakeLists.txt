cmake_minimum_required(VERSION 3.16)
project(EconsProject LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include-Verzeichnis
include_directories(${PROJECT_SOURCE_DIR}/include)

# Quell-Dateien
set(SOURCES
    src/main.cpp
    src/math_utils.cpp
    src/econ.cpp
    src/econ567.cpp
)

# Executable
add_executable(econs ${SOURCES})

# Ausgabeverzeichnis für build/bin
set_target_properties(econs PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
)

# Zusätzliches Kopieren nach ~/myRepos/econs/bin/
add_custom_command(TARGET econs POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:econs> ~/myRepos/econs/bin/
    COMMENT "Kopiere Executable nach ~/myRepos/econs/bin/"
)
