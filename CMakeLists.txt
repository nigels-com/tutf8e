cmake_minimum_required(VERSION 2.8)
project(tutf8e)

set(CMAKE_C_FLAGS "-Os -Wall")

include_directories(include)
file(GLOB src src/*.c)
add_library(tutf8e STATIC ${src})

add_executable(tutf8e-test test/test.c)
target_link_libraries(tutf8e-test tutf8e)
