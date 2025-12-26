cmake_minimum_required(VERSION 3.16)


project(menu LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Output in <project>/bin ---
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


# Standardmäßig USE_NCURSES aktivieren
option(USE_NCURSES "Enable ncurses TUI" ON)

# Alle cpp-Dateien im Ordner src
file(GLOB MENU_SRC "src/*.cpp")

add_executable(menu
    ${MENU_SRC}
    ../567/src/math_utils.cpp  
    ../567/src/notMain567a.cpp
    ../567/src/econ567emo2.cpp
    ../econ567/src/notMain567b.cpp
    ../678/de/src/text.cpp 
    ../678/de/src/notMainDe.cpp 
    ../678/de/src/space.cpp
    ../678/de/src/random.cpp
    ../678/de/src/notMainDe.cpp
    ../567/src/notMain567a.cpp   
    ../567/include/math_utils.h
    src/bitmask.cpp
    src/mode_text.cpp
    src/mode_toggle.cpp
    src/mode_ncurses.cpp
)

# Header-Verzeichnisse hinzufügen
target_include_directories(menu PRIVATE
    ../567/include
    ../econ567/include
    #../678/en/include
    ../678/de/include
    ../econ567/include
)
# --- Includes ---
include_directories(${PROJECT_SOURCE_DIR}/include)


# --- Optional: ncurses Mode ---
if (USE_NCURSES)
    target_compile_definitions(menu PRIVATE USE_NCURSES)
    target_link_libraries(menu ncurses)
endif()

# --- Zielpfad für Deployment ---
set(DEPLOY_DIR $ENV{HOME}/myRepos/econs/econs/bin)

# --- Beim Build zusätzlich dorthin kopieren ---
add_custom_command(TARGET menu POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:menu>
        ${DEPLOY_DIR}
    COMMENT "Kopiere Binary nach ${DEPLOY_DIR}"
)
set(DEPLOY_DIR ../../bin)

# --- Beim Build zusätzlich dorthin kopieren ---
add_custom_command(TARGET menu POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:menu>
        ${DEPLOY_DIR}
    COMMENT "Kopiere Binary nach ${DEPLOY_DIR}"
)
