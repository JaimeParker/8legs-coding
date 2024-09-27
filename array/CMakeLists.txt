cmake_minimum_required(VERSION 3.24)
project(array)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(array_solutions
        BinarySearch.cpp
        RemoveElement.cpp
        SquaresOfASortedArray.cc
        MinimumSizeSubarraySum.cc
        SpiralMatrix2.cc
)

add_executable(KC58 KC58.cc)
