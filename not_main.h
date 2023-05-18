#ifndef TIR_AUX_BALLONS_NOT_MAIN_H
#define TIR_AUX_BALLONS_NOT_MAIN_H

#include <allegro.h>
#include <stdio.h>

typedef struct
{
    int posx;
    int posy;
    int depx;
    int depy;
    int type;
    BITMAP*poke;
}ballons;

void TB_init_allegro();

ballons * TB_init_struct(int posx, int posy, int depx, int depy, int type);

void TB_remp_tab_pok(ballons * taballons[7]);

void TB_anim_pok(ballons * pokemons[7], BITMAP*buffer);

void TB_click_souris(ballons * pokemons[7], int available_poke);

int TB_condition_attrap(BITMAP* pokeball[2], BITMAP*buffer);

#endif //TIR_AUX_BALLONS_NOT_MAIN_H
