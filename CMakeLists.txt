cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c print_chen.c head.h deplacement.c "petite fonction.c" snake.c snake.c Guitar_hero.c "TAupeLA V5.c")
target_link_libraries(PROJET -lmingw32 -lalleg44)
