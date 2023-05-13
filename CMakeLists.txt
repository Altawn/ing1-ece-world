cmake_minimum_required(VERSION 3.25)
project(Pari_Hippique_v2 C)

set(CMAKE_C_STANDARD 23)

add_executable(Pari_Hippique_v2 main.c not_main.h not_main.c)
target_link_libraries(Pari_Hippique_v2 -lalleg44)
