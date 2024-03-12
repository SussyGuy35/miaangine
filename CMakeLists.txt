cmake_minimum_required(VERSION 3.10)

project(game)

# TAG
add_compile_options(-w -Wl,-subsystem,windows)

# EXECUTABLE
file(GLOB_RECURSE ENGINE_SOURCES "src/miaangine/*.cpp")
file(GLOB_RECURSE SOURCES "src/demo/flappy-bird/*.cpp") # <============
list(APPEND SOURCES ${ENGINE_SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})

# SDL
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL/lib/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# DIRECTORIES
set(ENGINE_INC "src;src/miaangine")
set(INCLUDES "src/demo/flappy-bird") # <============
list(APPEND INCLUDES ${ENGINE_INC})
# list(APPEND INCLUDES "vendor/SDL/include/SDL2")

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${INCLUDES} 
    PUBLIC ${SDL2_INCLUDE_DIRS} 
    PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS}
)

# LINK
target_link_libraries(${PROJECT_NAME} 
    -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
)