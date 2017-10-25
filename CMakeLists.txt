cmake_minimum_required(VERSION 3.8)
project(08_Ordenamiento)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp BubbleSort.cpp BubbleSort.h QuickSort.cpp QuickSort.h InterSort.cpp InterSort.h ShellSort.cpp ShellSort.h dic.txt dicc.txt)
add_executable(08_Ordenamiento ${SOURCE_FILES})