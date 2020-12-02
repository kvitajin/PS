cmake_minimum_required(VERSION 3.10)
project(cv7_1 CXX CUDA)

set_source_files_properties( main.cu PROPERTIES LANGUAGE CUDA)
add_executable(cv7_1 main.cu)

set_target_properties(
        cv7_1
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
