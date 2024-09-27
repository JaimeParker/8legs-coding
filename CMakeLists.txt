cmake_minimum_required(VERSION 3.24)
project(8legs_coding)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/include)

# add all sub dirs here
add_subdirectory(array)
add_subdirectory(listnode)

add_executable(8legs_coding main.cpp)

# link all sub dirs here
target_link_directories(8legs_coding PRIVATE array listnode)
