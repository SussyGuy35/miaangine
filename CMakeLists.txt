cmake_minimum_required(VERSION 3.10)

project(game)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_compile_options(-w -Wl,-subsystem,windows)

include_directories(src)
include_directories(src/miaangine)
include_directories(src/demo/flappy-bird)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2IMAGE_LIBRARY})

file(GLOB_RECURSE SOURCES "src/demo/flappy-bird/main.cpp")
file(GLOB_RECURSE SOURCES "src/*.cpp")
# file(GLOB_RECURSE SOURCES "src/miaangine/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})