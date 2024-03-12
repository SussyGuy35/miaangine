cmake_minimum_required(VERSION 3.10)

project(game)

# TAG
add_compile_options(-w -Wl,-subsystem,windows)

# SDL
find_package(SDL2 PATHS "vendor/SDL/lib/cmake/SDL2" NO_DEFAULT_PATH)
find_package(SDL2_image PATHS "vendor/SDL_image/lib/cmake/SDL2_image" NO_DEFAULT_PATH)

# DIRECTORIES
set(ENGINE_INC "src" "src/miaangine")
set(INCLUDES "src/demo/flappy-bird") # <============
list(APPEND INCLUDES ${ENGINE_INC})

include_directories(${INCLUDES} ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_LIBRARY})

# EXECUTABLE
file(GLOB_RECURSE ENGINE_SOURCES "src/miaangine/*.cpp")
file(GLOB_RECURSE SOURCES "src/demo/flappy-bird/*.cpp") # <============
list(APPEND SOURCES ${ENGINE_SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})

# LINK
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})