cmake_minimum_required(VERSION 3.0)

project(ex2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")

add_executable(ex2 ex2.c)
