cmake_minimum_required(VERSION 3.10)
project(sdl2_template)

file(GLOB_RECURSE SOURCES "src/*.cpp")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} include)

add_executable(app ${SOURCES})

target_compile_options(app PRIVATE -std=c++17 -O0 -Wall -Wextra -pedantic)

target_link_libraries(app ${SDL2_LIBRARIES})

