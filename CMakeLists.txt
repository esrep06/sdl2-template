cmake_minimum_required(VERSION 3.10)
project(sdl2_template)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

find_package(SDL2 REQUIRED)

add_executable(app ${SOURCES})

target_link_libraries(app ${SDL2_LIBRARIES})

