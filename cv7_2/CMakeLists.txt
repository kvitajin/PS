set(CMAKE_CUDA_COMPILER /usr/local/cuda/bin/nvcc)

cmake_minimum_required(VERSION 3.10.2)
project(cv7_2 LANGUAGES CXX CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(cv7_2 main.cu cuda.cu)

set_target_properties(
        cv7_2
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)