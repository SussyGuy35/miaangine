cmake_minimum_required(VERSION 3.10)

project(m)

set(CMAKE_CXX_STANDARD 14)

# TAG
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (NOT CMAKE_GENERATOR STREQUAL "Visual Studio 17 2022" OR NOT CMAKE_GENERATOR STREQUAL "Visual Studio 16 2019")
        add_compile_options(-Wall -Wextra)
    endif()
else()
    add_compile_options(-w)
endif()

# SDL
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL/lib/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# EXECUTABLE
file(GLOB_RECURSE SOURCES "src/demo/flappy-bird/*.cpp") # <===== EDIT HERE =====
file(GLOB_RECURSE E_SOURCES "src/miaangine/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${E_SOURCES})

# DIRECTORIES
set(INCLUDES "src/demo/flappy-bird") # <===== EDIT HERE =====
set(E_INCLUDES "src" "src/miaangine" ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

target_include_directories(${PROJECT_NAME} 
    PRIVATE ${INCLUDES}
    PUBLIC ${E_INCLUDES}
)

# LINK
target_link_libraries(${PROJECT_NAME} 
    -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
)