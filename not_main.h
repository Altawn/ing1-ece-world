#ifndef TIR_AUX_BALLONS_NOT_MAIN_H
#define TIR_AUX_BALLONS_NOT_MAIN_H

#include <allegro.h>
#include <stdio.h>
#include <time.h>

typedef struct
{
    int posx;
    int posy;
    int depx;
    int depy;
    int type;
    int attrape;
    BITMAP*poke;
}ballons;

void TB_init_allegro();

ballons * TB_init_struct(int posx, int posy, int depx, int depy, int type, int attrape);

void TB_remp_tab_pok(ballons * taballons[7]);

void TB_anim_pok(ballons * pokemons[7], BITMAP*buffer);

void TB_click_souris(ballons * pokemons[7], int available_poke);

int TB_condition_attrap(BITMAP* pokeball[2], BITMAP*buffer);

void TB_entree_jeu(BITMAP* buffer, BITMAP* background, BITMAP* dialogue, int i);

double TB_jeu(BITMAP* buffer, BITMAP* background, BITMAP* dialogue, ballons* pokemons[7], BITMAP* pokeball[2]);

void TB_transition(BITMAP* background, BITMAP* buffer, int i);

void TB_resultats(double tps_j1, double tps_j2, BITMAP* background, BITMAP* buffer, BITMAP* dialogue);

void Tir_Ballons(double tps_j1, double tps_j2);

#endif //TIR_AUX_BALLONS_NOT_MAIN_H
