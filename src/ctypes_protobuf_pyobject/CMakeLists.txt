cmake_minimum_required(VERSION 3.0.0)

project(demo VERSION 0.1.0)
message(STATUS ">>> [${PROJECT_NAME}] @ ${PROJECT_SOURCE_DIR}/MakeLists.txt")
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -g -O0)

# source file dirs
list(APPEND SRC_DIR ${PROJECT_SOURCE_DIR})

foreach(DIR ${SRC_DIR})
aux_source_directory(${DIR} SRCS)
endforeach()
message(STATUS ">>> SRCS: ${SRCS}")

find_package(Protobuf REQUIRED)
find_package(PythonLibs REQUIRED)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS
    addressbook.proto
)
protobuf_generate_python (PROTO_PYS
    addressbook.proto
)

add_library(${PROJECT_NAME} STATIC ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC
    ${Protobuf_INCLUDE_DIRS}
    ${PYTHON_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_sources(${PROJECT_NAME} PRIVATE
    ${PROTO_SRCS}
    ${PROTO_PYS}
    ${PROTO_HDRS}
)
target_link_libraries(${PROJECT_NAME}
    ${Protobuf_LIBRARIES}
    ${PYTHON_LIBRARIES}
)

message(STATUS ">>> [END] ${PROJECT_NAME} @ ${PROJECT_SOURCE_DIR}/MakeLists.txt")
