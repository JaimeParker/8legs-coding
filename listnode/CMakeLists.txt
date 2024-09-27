cmake_minimum_required(VERSION 3.24)
project(listnode)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(listnode
        include/ListNode.h
        RemoveLinkedListElements.cc
        DesignLinkedList.cc
)