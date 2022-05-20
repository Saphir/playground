cmake_minimum_required(VERSION 3.0.0)

project(playground LANGUAGES CXX VERSION 0.1.0)
message(STATUS ">>> [${PROJECT_NAME} ] @ ${PROJECT_SOURCE_DIR}/MakeLists.txt")
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # -fPIC

add_compile_options(-Wall -g -O0)

add_subdirectory(ctypes_protobuf_pyobject)

add_library(${PROJECT_NAME} SHARED
    $<TARGET_OBJECTS:demo>
)

find_package(Protobuf REQUIRED)
target_link_libraries(${PROJECT_NAME} ${Protobuf_LIBRARIES})
