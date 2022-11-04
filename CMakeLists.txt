cmake_minimum_required(VERSION 3.17)
project(Matrix_solution)

set(CMAKE_CXX_STANDARD 14)

# Precompile catch2 to speed up re-compiles
add_library(catch2_main STATIC unit_tests/catch-main.cpp)
target_include_directories(catch2_main PUBLIC unit_tests/)

# Basic Test
add_executable(Basic_Matrix_Testing basic_matrix_driver.cpp MatrixT.h MatrixT.cpp)

# Catch Tests
add_executable(Matrix_Tests unit_tests/matrix_tests.cpp MatrixT.h MatrixT.cpp)

# Use precompiled catch2 library for all of the executables to speed up recompile times
target_link_libraries(Matrix_Tests catch2_main)
target_compile_definitions(Matrix_Tests PRIVATE CATCH_CONFIG_FAST_COMPILE CATCH_CONFIG_DISABLE_MATCHERS)
target_precompile_headers(Matrix_Tests PRIVATE unit_tests/catch.hpp)