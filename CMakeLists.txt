cmake_minimum_required(VERSION 3.7)

project(sdl2game)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories( include )

add_executable(sdl2game main.cpp game.cpp)
target_link_libraries(sdl2game ${SDL2_LIBRARIES})
