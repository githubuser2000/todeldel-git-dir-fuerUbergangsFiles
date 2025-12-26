cmake_minimum_required(VERSION 3.16)
project(econ567 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Primärer Output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Bibliothek
add_library(econlib STATIC
    econ.cpp
)

target_include_directories(econlib
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)

# Executable
add_executable(econ567
    main.cpp
)

target_link_libraries(econ567
    PRIVATE econlib
)

# Kopie in ../../bin nach Build
add_custom_command(TARGET econ567 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:econ567>
            "${CMAKE_SOURCE_DIR}/../bin/econ567"
    COMMENT "Kopiere econ567 nach ../../bin/"
)
