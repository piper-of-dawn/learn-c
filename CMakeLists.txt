cmake_minimum_required(VERSION 3.16)
project(MatrixHasher)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

set(HEADERS
    matrix_hasher.h
)

set(SOURCES
    matrix_hasher.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(tests)