cmake_minimum_required(VERSION 3.10)

project(miaangine)

set(CMAKE_CXX_FLAGS "-Wall -O0 -g -mwindows")
set(CMAKE_CXX_STANDARD 14)

# Set include dir
# list(APPEND CMAKE_PREFIX_PATH "C:/Devs/i686-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories("src/")
include_directories("src/miaangine")

# Set source files
file(GLOB_RECURSE SOURCES "main.cpp" "src/*.cpp")

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SDL2 libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})