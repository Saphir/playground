cmake_minimum_required(VERSION 3.0.0)

project(python_binding LANGUAGES CXX VERSION 0.1.0)
message(STATUS ">>> [${PROJECT_NAME}] @ ${PROJECT_SOURCE_DIR}/MakeLists.txt")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # -fPIC
set(CMAKE_INSTALL_RPATH "$ORIGIN")

# set this to see the compilation commands
set(CMAKE_VERBOSE_MAKEFILE 1)

add_compile_options(-Wall -g -O0)

# source file dirs
list(APPEND SRC_DIR ${PROJECT_SOURCE_DIR})
# include dirs
list(APPEND INC_DIR ${PROJECT_SOURCE_DIR})

foreach(DIR ${SRC_DIR})
aux_source_directory(${DIR} SRCS)
endforeach()
message(STATUS ">>> [${PROJECT_NAME}] SRCS: ${SRCS}")

find_package(Protobuf REQUIRED)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS addressbook.proto)
protobuf_generate_python(PROTO_PYS addressbook.proto)

add_library(${PROJECT_NAME} SHARED addressbook.cc ${PROTO_SRCS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR} ${CMAKE_BINARY_DIR})
target_link_libraries(${PROJECT_NAME} ${Protobuf_LIBRARIES})

add_custom_target(proto_python ALL DEPENDS ${PROTO_PYS})
