cmake_minimum_required(VERSION 3.10)

include(CMakePrintHelpers)

project(game)

# list(APPEND CMAKE_PREFIX_PATH "C:\\Development\\MinGW\\lib\\cmake\\SDL2")
find_package(SDL2 REQUIRED)

add_compile_options(-Wall -Wextra -Wdeprecated -w)

include_directories(src)
include_directories(src/miaangine)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCES "demo/main.cpp")
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})