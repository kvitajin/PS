cmake_minimum_required(VERSION 3.17)
project(cv6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lssl -lcrypto -pthread")

set(CMAKE_CXX_STANDARD 17)

add_executable(cv6 main.cpp)