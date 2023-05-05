#ifndef PARI_HIPPIQUE_V2_NOT_MAIN_H
#define PARI_HIPPIQUE_V2_NOT_MAIN_H

#include <stdio.h>
#include <allegro.h>
#define NIMAGE 5
#define NACTEUR 5

typedef struct
{
    BITMAP * img[NIMAGE];
    int posx, posy;
    int tx, ty;
    int depx, depy;
    int frame_act; //frame actuelle du pokemon
    int compteur;
}Pokemon, *Pok;

Pokemon init_magicarpe();
Pokemon init_papillusion();
void init_allegro();

#endif //PARI_HIPPIQUE_V2_NOT_MAIN_H
