cmake_minimum_required(VERSION 3.0.0)

project(module_c LANGUAGES C VERSION 0.1.0)
message(STATUS ">>> [PROJECT] ${PROJECT_NAME} @ ${PROJECT_SOURCE_DIR}/MakeLists.txt")
set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -g -O0)

# source file dirs
list(APPEND SRC_DIR ${PROJECT_SOURCE_DIR})
# include dirs
list(APPEND INC_DIR ${PROJECT_SOURCE_DIR})
list(APPEND INC_DIR ${CMAKE_BINARY_DIR}/src)

foreach(DIR ${SRC_DIR})
aux_source_directory(${DIR} SRCS)
endforeach()
message(STATUS ">>> SRCS: ${SRCS}")

add_library(${PROJECT_NAME} STATIC ${SRCS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC proto)
