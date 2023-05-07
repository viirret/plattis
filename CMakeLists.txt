cmake_minimum_required(VERSION 3.23)
project(plattis)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB LIB_SOURCES plattis/*.cc)
add_compile_options(-Wall -Wextra -pedantic -Wconversion)

add_subdirectory(Box2D)             # add Box2D as a subdirectory
include_directories(Box2D/include)  # include Box2D headers

add_executable(plattis ${LIB_SOURCES} main.cc)
target_link_libraries(plattis box2d -lSDL2 -lSDL2_image)
