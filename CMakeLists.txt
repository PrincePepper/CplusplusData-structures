cmake_minimum_required(VERSION 3.15)
project(CplusplusLists)

set(CMAKE_CXX_STANDARD 14)

add_executable(singly_linked_list main/singly_linked_list.cpp)
add_executable(double_linked_list main/double_linked_list.cpp)
add_executable(stek_list main/stek_list.cpp)
add_executable(heap main/heap.cpp)

add_executable(singly_list_lib library/singly_list/singly_list_lib.cpp library/singly_list/singly_list_lib.h)
add_executable(double_list_lib library/double_list/double_list_lib.cpp library/double_list/double_list_lib.h)
