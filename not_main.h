#ifndef PARI_HIPPIQUE_V2_NOT_MAIN_H
#define PARI_HIPPIQUE_V2_NOT_MAIN_H

#include <stdio.h>
#include <allegro.h>
#define NIMAGE 5
#define NPOK 5

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
    BITMAP **img;
}Pokemon;

//Allouer + Initialisation d'acteurs
Pokemon * init_pokemon(int tx, int ty, int xdx, int posx, int posxy, int pok, int depx, int tmpimg);

//Remplir un tab avec des acteurs
void remp_tab_pok(Pokemon * tab_rand[NPOK]);

//Actualisation d'acteurs
void Actu_Pok(Pokemon * random);

//Actualisation de tous les acteurs
void Tab_Actu_Pok(Pokemon * tab_rand[NPOK]);

//Dessiner un pokemon sur une Bitmap
void Dessin_Pok(BITMAP * quelconque, Pokemon * random);

//Dessiner tous les pokemons
void Tab_Dessin_Pok(BITMAP * quelconque, Pokemon * tab_rand[NPOK]);

Pokemon init_magicarpe();
Pokemon init_papillusion();
void init_allegro();

#endif //PARI_HIPPIQUE_V2_NOT_MAIN_H
