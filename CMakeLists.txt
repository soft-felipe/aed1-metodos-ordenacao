cmake_minimum_required(VERSION 3.23)
project(aed1-metodos-ordenacao C)

set(CMAKE_C_STANDARD 99)

add_executable(aed1-metodos-ordenacao novoGerador.c insertion_sort.c selection_sort.c bubble_sort.c merge_sort.c quick_sort.c counting_sort.c radix_sort.c bucket_sort.c metodos.h)
#add_executable(aed1-metodos-ordenacao testes.c)