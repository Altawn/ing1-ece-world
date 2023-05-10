#ifndef PARI_HIPPIQUE_V2_NOT_MAIN_H
#define PARI_HIPPIQUE_V2_NOT_MAIN_H

#include <stdio.h>
#include <time.h>
#include <allegro.h>
#define NIMAGE 5
#define NPOK 5
#define TAILLEMAX 10

typedef struct
{
    int posx, posy; //posit. coin sup. gauche
    int tx, ty; //largeur / hauteur
    int depx; //deplacement en x
    int frame_act; //frame actuelle du pokemon
    int compdepx; //compteur pour ralentir deplacement (Randomiser la vitesse du pokemon)
    int xdx; //ralentir dep en x
    int pok; //quel pokemon ?
    int tmpimg; //?
    int cptimg; //?
    BITMAP *img[NIMAGE-1];
}Pokemon;

//Allouer + Initialisation d'acteurs
Pokemon * PI_init_pokemon(int tx, int ty, int xdx, int posx, int posxy, int pok, int depx, int tmpimg);

//Remplir un tab avec des acteurs
void PI_remp_tab_pok(Pokemon * tab_rand[NPOK]);

//Initialisation Allegro
void PI_init_allegro();

//Animation des pokemons
void PI_anim_pok(Pokemon * tab_rand[NPOK], BITMAP * page);

int PI_depla_pok(Pokemon * tab_rand[NPOK]);

void PI_pok_gagnant(char * winner, int pok_gagnant);


#endif //PARI_HIPPIQUE_V2_NOT_MAIN_H
