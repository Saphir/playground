cmake_minimum_required(VERSION 3.0.0)

project(playground LANGUAGES CXX VERSION 0.1.0)
message(STATUS ">>> [PROJECT] ${PROJECT_NAME} @ ${PROJECT_SOURCE_DIR}/MakeLists.txt")
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # -fPIC

# set this to see the compilation commands
# set(CMAKE_VERBOSE_MAKEFILE 1)

add_compile_options(-Wall -g -O0)


add_subdirectory(proto)
add_subdirectory(module_c)
add_subdirectory(module_cpp)

add_library(${PROJECT_NAME} SHARED
    $<TARGET_OBJECTS:module_c>
    $<TARGET_OBJECTS:module_cpp>
    $<TARGET_OBJECTS:proto>
)

find_package(Protobuf REQUIRED)
target_link_libraries(${PROJECT_NAME} ${Protobuf_LIBRARIES})
