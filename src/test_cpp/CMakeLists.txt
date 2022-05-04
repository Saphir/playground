cmake_minimum_required(VERSION 3.0.0)

project(test_cpp LANGUAGES CXX VERSION 0.1.0)

add_compile_options(-Wall -g -O0)

# source file dirs
list(APPEND SRC_DIR ${PROJECT_SOURCE_DIR})
# include dirs
list(APPEND INC_DIR ${PROJECT_SOURCE_DIR})

foreach(DIR ${SRC_DIR})
aux_source_directory(${DIR} SRCS)
endforeach()
message(STATUS ">>> SRCS: ${SRCS}")

add_library(${PROJECT_NAME} STATIC ${SRCS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR})
