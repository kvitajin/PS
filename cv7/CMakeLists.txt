cmake_minimum_required(VERSION 3.10.2)
project(cv7)

set(CMAKE_CUDA_STANDARD 14)


set(CMAKE_CXX_STANDARD 14)

add_executable(cv7 main.cpp)

set_target_properties( cv7
        PROPERTIES
        CUDA_SEPARATE_COMPILATION ON)