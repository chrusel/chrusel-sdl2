cmake_minimum_required(VERSION 3.7)

project(sdl2game)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp game.cpp)
set(INCLUDE_DIRS include)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${INCLUDE_DIRS})

add_executable(sdl2game ${SOURCE_FILES})
target_link_libraries(sdl2game ${SDL2_LIBRARIES})
