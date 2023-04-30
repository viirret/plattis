cmake_minimum_required(VERSION 3.23)
project(plattis)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(project "plattis")

file(GLOB LIB_SOURCES ${project}/*.cc)

# -werror
add_compile_options(-Wall -Wextra -pedantic -Wconversion)

# add Box2D as a subdirectory
add_subdirectory(Box2D)

# include Box2D headers
include_directories(Box2D/include)

add_executable(plattis ${LIB_SOURCES} main.cc)

target_link_libraries(plattis box2d -lSDL2 -lSDL2_image)
