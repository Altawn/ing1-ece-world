
#ifndef PROJET_HEAD_H
#define PROJET_HEAD_H

#define TRAINER_W 44
#define TRAINER_H 46
#include <stdio.h>
#include "allegro.h"
#include "time.h"
#include <stdbool.h>

typedef struct player{
        int x;
        int y;
        int mouv;
        char name[50];
}t_player;

typedef struct objet{
    int x, y, x2, y2,w,h;
}t_objet;

void calc(t_objet* ob);
void colision(t_player* player,t_objet* ob);
void ecran();
void print_chen(BITMAP*page);
void depla(t_player* player,BITMAP* page, BITMAP* fond,BITMAP* t0,BITMAP* t1,BITMAP* t2,BITMAP* tup0,BITMAP* tup1,BITMAP* tup2,BITMAP* ts0,BITMAP* ts1,BITMAP* ts2);

#endif //PROJET_HEAD_H
