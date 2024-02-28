cmake_minimum_required(VERSION 3.10)

project(game)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD 17)

# list(APPEND CMAKE_PREFIX_PATH "C:\\Devs\\i686-w64-mingw32\\lib\\cmake\\SDL2")
# list(APPEND CMAKE_EXE_LINKER_FLAGS "/machine:x64 /debug /INCREMENTAL /subsystem:console")

# Set include dir
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories("src/")
include_directories("src/miaangine")

# Set source files
file(GLOB_RECURSE SOURCES "demo/main.cpp")
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SDL2 libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
