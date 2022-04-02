cmake_minimum_required(VERSION 3.0.0)

project(master VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_RPATH "$ORIGIN")

add_compile_options(-Wall -g -O0)

# source file dirs
list(APPEND SRC_DIR ${PROJECT_SOURCE_DIR}/src)
# include dirs
list(APPEND INC_DIR ${PROJECT_SOURCE_DIR}/src)

foreach(DIR ${SRC_DIR})
aux_source_directory(${DIR} SRCS)
endforeach()
message(STATUS "SRCS: ${SRCS}")

add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR})
