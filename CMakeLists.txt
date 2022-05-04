cmake_minimum_required(VERSION 3.0.0)

project(main VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_RPATH "$ORIGIN")

add_compile_options(-Wall -g -O0)

add_subdirectory(src)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(${PROJECT_NAME} PRIVATE test)
