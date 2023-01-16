cmake_minimum_required(VERSION 3.24)
project(debbug_projeto C)

set(CMAKE_C_STANDARD 99)

add_executable(debbug_projeto novoGerador.c insertion_sort.c selection_sort.c bubble_sort.c merge_sort.c quick_sort.c counting_sort.c radix_sort.c bucket_sort.c metodos.h)