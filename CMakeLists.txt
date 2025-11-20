cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

# Include directories
include_directories(include)

# Source files
add_executable(PROJET 
    src/main.c 
    src/print_chen.c 
    src/deplacement.c 
    src/petite_fonction.c 
    src/Snake_programmes.c 
    src/Guitar_hero.c 
    src/TP_programmes.c 
    src/PH_programmes.c 
    src/TB_programmes.c 
    src/jackpot.c 
    src/pfc.c
)

target_link_libraries(PROJET -lmingw32 -lalleg44)
