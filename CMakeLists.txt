cmake_minimum_required(VERSION 3.10)
project(pong)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable with all source files
add_executable(pong
        src/main.cpp
        src/Ball.cpp
        src/Paddle.cpp
        src/Game.cpp
        src/scoreboard.cpp
)

# Include directories
target_include_directories(pong PRIVATE include)

# Use SFML from external folder
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/external/SFML-2.6.2")

target_compile_definitions(pong PRIVATE SFML_STATIC)
target_include_directories(pong PRIVATE "${SFML_ROOT}/include")

# Link SFML static libraries
target_link_libraries(pong PRIVATE
        "${SFML_ROOT}/lib/libsfml-graphics.a"
        "${SFML_ROOT}/lib/libsfml-window.a"
        "${SFML_ROOT}/lib/libsfml-system.a"
)

# Windows system libraries
if(WIN32)
    target_link_libraries(pong PRIVATE opengl32 winmm gdi32)
endif()