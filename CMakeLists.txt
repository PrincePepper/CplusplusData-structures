cmake_minimum_required(VERSION 3.15)
project(CplusplusLists)

set(CMAKE_CXX_STANDARD 14)
#Фильтры
add_executable(median_filter Filtres/median_filter.cpp)
#Структуры данных
add_executable(singly_linked_list Main/singly_linked_list.cpp)
add_executable(double_linked_list Main/double_linked_list.cpp)
add_executable(stek_list Main/stek_list.cpp)
add_executable(heap Main/heap.cpp)
add_executable(IsBalancedTree Main/isBalancedTree.cpp)
#Библиотеки
add_executable(singly_list_lib Library/singly_list/singly_list_lib.cpp Library/singly_list/singly_list_lib.h)
add_executable(double_list_lib Library/double_list/double_list_lib.cpp Library/double_list/double_list_lib.h)

