cmake_minimum_required(VERSION 3.7)

project(sdl2game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(SOURCE_FILES main.cpp game.cpp texture_manager.cpp)
set(INCLUDE_DIRS include)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${INCLUDE_DIRS})

add_executable(sdl2game ${SOURCE_FILES})
target_link_libraries(sdl2game ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
