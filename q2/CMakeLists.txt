
cmake_minimum_required(VERSION 3.7)
project(q2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Werror")

add_executable(q2 main.cpp)
