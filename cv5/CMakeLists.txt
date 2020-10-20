cmake_minimum_required(VERSION 3.17)
project(cv5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lssl -lcrypto -pthread")

set(CMAKE_CXX_STANDARD 20)

add_executable(cv5 main.cpp)