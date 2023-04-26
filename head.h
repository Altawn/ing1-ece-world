//
// Created by charv on 26/04/2023.
//

#ifndef PROJET_HEAD_H
#define PROJET_HEAD_H
#include <stdio.h>
#include "allegro.h"
#include "time.h"
#include <stdbool.h>

typedef struct player{
        int x;
        int y;
        int mouv;
}t_player;

void print_chen(BITMAP*page);
void depla(t_player* player,BITMAP* page, BITMAP* fond,BITMAP* t0,BITMAP* t1,BITMAP* t2,BITMAP* tup0,BITMAP* tup1,BITMAP* tup2,BITMAP* ts0,BITMAP* ts1,BITMAP* ts2);

#endif //PROJET_HEAD_H
