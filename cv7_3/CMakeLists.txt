set(CMAKE_CUDA_COMPILER /usr/local/cuda/bin/nvcc)
cmake_minimum_required(VERSION 3.10)
project(cv7_3 CXX CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(cv7_3 main.cu  sauce.cu md5.cu)

set_target_properties(
        cv7_3
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)

