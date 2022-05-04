cmake_minimum_required(VERSION 3.0.0)

project(test LANGUAGES CXX VERSION 0.1.0)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_compile_options(-Wall -g -O0)

add_subdirectory(test_c)
add_subdirectory(test_cpp)

add_library(${PROJECT_NAME} SHARED $<TARGET_OBJECTS:test_c> $<TARGET_OBJECTS:test_cpp>)
