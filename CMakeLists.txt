cmake_minimum_required(VERSION 3.25)
project(Tir_aux_ballons C)

set(CMAKE_C_STANDARD 23)

add_executable(Tir_aux_ballons main.c not_main.h not_main.c)
target_link_libraries(Tir_aux_ballons -lalleg44)
