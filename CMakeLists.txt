cmake_minimum_required(VERSION 3.19)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

#add_executable(main main.c predefined.h)


add_subdirectory(11_Sorting/23_StraightInsertionSort)
add_subdirectory(11_Sorting/24_Binary_Inserting_Sort)
add_subdirectory(11_Sorting/25_ShellsSort)
add_subdirectory(11_Sorting/26_BubbleSort)
add_subdirectory(11_Sorting/27_QuickSort)
add_subdirectory(11_Sorting/28_SimpleSelectionSort)
add_subdirectory(11_Sorting/29_HeapSort)
add_subdirectory(11_Sorting/30_MergingSort)


include_directories(./classdesign/include)

file(GLOB_RECURSE SOURCES "classdesign/*.*")

add_executable(main ${SOURCES})
