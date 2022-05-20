cmake_minimum_required(VERSION 3.0.0)

project(playground VERSION 0.1.0)
message(STATUS ">>> [${PROJECT_NAME}] @ ${PROJECT_SOURCE_DIR}/MakeLists.txt")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_RPATH "$ORIGIN")
# set(CMAKE_VERBOSE_MAKEFILE 1)

add_compile_options(-Wall -g -O0)

add_subdirectory(src)
