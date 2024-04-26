cmake_minimum_required(VERSION 3.10)

project(BunTheBunny)

set(CMAKE_CXX_STANDARD 14)

# TAG
# if (CMAKE_BUILD_TYPE STREQUAL "Debug")
#     add_compile_options(-Wall -Wextra)
# else()
#     add_compile_options(-w)
# endif()

# SDL
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/vendor")
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
find_package(SDL2_MIXER REQUIRED)
set(SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})

# EXECUTABLE
file(GLOB_RECURSE SOURCES "src/bunthebunny/*.cpp") # <===== EDIT HERE =====
file(GLOB_RECURSE E_SOURCES "src/miaangine/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${E_SOURCES})

# DIRECTORIES
set(INCLUDES "src/bunthebunny") # <===== EDIT HERE =====
set(E_INCLUDES "src/miaangine/include" "src/miaangine/vendor" ${SDL2_INCLUDE_DIRS})

target_include_directories(${PROJECT_NAME} 
    PRIVATE ${INCLUDES}
    PUBLIC ${E_INCLUDES}
)

# LINK
target_link_libraries(${PROJECT_NAME} 
    -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
)