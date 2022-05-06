cmake_minimum_required(VERSION 3.0.0)

project(proto VERSION 0.1.0)
message(STATUS ">>> [PROJECT] ${PROJECT_NAME} @ ${PROJECT_SOURCE_DIR}/MakeLists.txt")
set(CMAKE_CXX_STANDARD 14)

find_package(Protobuf REQUIRED)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS
    addressbook.proto
)

add_library(${PROJECT_NAME} STATIC "")

target_include_directories(${PROJECT_NAME} PUBLIC
    ${Protobuf_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_sources(${PROJECT_NAME} PRIVATE
    ${PROTO_SRCS}
    ${PROTO_HDRS}
)

target_link_libraries(${PROJECT_NAME} ${Protobuf_LIBRARIES})
message(STATUS ">>> [END] ${PROJECT_NAME} @ ${PROJECT_SOURCE_DIR}/MakeLists.txt")
