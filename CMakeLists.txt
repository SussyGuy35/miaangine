cmake_minimum_required(VERSION 3.10)

project(m)

set(CMAKE_CXX_STANDARD 14)

# TAG
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (CMAKE_GENERATOR STREQUAL "MinGW Makefiles")
        add_compile_options(-Wall -Wextra)
    endif()
else()
    add_compile_options(-w)
endif()

# SDL
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL/lib/cmake")

find_package(SDL2 REQUIRED)

set(SDL2IMAGE_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL/include")
set(SDL2IMAGE_LIBRARIES "SDL2_image::SDL2_image")
find_package(SDL2_IMAGE REQUIRED)

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
    PUBLIC ${SDL2_LIBRARIES} 
    PUBLIC ${SDL2IMAGE_LIBRARIES}
)