cmake_minimum_required(VERSION 3.15)
project(AngleConverter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output binaries in bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Executable from_rational
add_executable(from_rational src/from_rational.cpp)
target_include_directories(from_rational PRIVATE include)
target_compile_definitions(from_rational PRIVATE BUILD_MAIN)

# Executable to_rational
add_executable(to_rational src/to_rational.cpp)
target_include_directories(to_rational PRIVATE include)
target_compile_definitions(to_rational PRIVATE BUILD_MAIN)
set(DEPLOY_DIR $ENV{HOME}/myRepos/econs/7/bin)

# --- Beim Build zusätzlich dorthin kopieren ---
add_custom_command(TARGET from_rational POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:from_rational>
        ${DEPLOY_DIR}
    COMMENT "Kopiere Binary nach ${DEPLOY_DIR}"
)
set(DEPLOY_DIR ../../bin)

# --- Beim Build zusätzlich dorthin kopieren ---
add_custom_command(TARGET to_rational POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:to_rational>
        ${DEPLOY_DIR}
)
set(DEPLOY_DIR $ENV{HOME}/myRepos/econs/7/bin)

# --- Beim Build zusätzlich dorthin kopieren ---
add_custom_command(TARGET to_rational POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:to_rational>
        ${DEPLOY_DIR}
    COMMENT "Kopiere Binary nach ${DEPLOY_DIR}"
)
set(DEPLOY_DIR ../../bin)

# --- Beim Build zusätzlich dorthin kopieren ---
add_custom_command(TARGET from_rational POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:from_rational>
        ${DEPLOY_DIR}
)
