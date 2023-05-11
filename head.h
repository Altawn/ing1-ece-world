#ifndef PROJET_HEAD_H
#define PROJET_HEAD_H
#define NB_poke_guitare 5

#include <stdio.h>
#include "allegro.h"
#include "time.h"
#include <stdbool.h>

//////////BASE + INTRO/////////
typedef struct player{
    int x;
    int y;
    int mouv;
    char name[50];
    int ticket;
}t_player;

typedef struct objet{
    int x, y, x2, y2,w,h;
}t_objet;


void calc(t_objet* ob);
bool colision(t_player* player,t_objet* ob);
void ecran();
void print_chen(BITMAP*page);
void depla(t_player* player,BITMAP* page, BITMAP* fond,BITMAP* t0,BITMAP* t1,BITMAP* t2,BITMAP* tup0,BITMAP* tup1,BITMAP* tup2,BITMAP* ts0,BITMAP* ts1,BITMAP* ts2);


/////////JEUX DE ALEXANDRE///////////

typedef struct pomme{
    int x;
    int y;
    BITMAP *base;
}t_pomme;


typedef struct snake{
    int x;
    int y;
    BITMAP* base;
    struct snake* next;
}t_snake;

typedef struct liste{
    t_snake* head;
}t_liste;

bool bulle(t_player* player);
bool snake_defeat(int nbpart,t_liste* serpent);
void door_one(BITMAP* bit,t_player* player1);
void door_two(BITMAP* bit,t_player* player1);
void snake();
void afficherListe(t_liste *liste,BITMAP* page,BITMAP* head1,BITMAP* head2,BITMAP* head3,BITMAP* head4,int mouvement);
void pomme_init(BITMAP* base2,t_pomme* apple);
bool colision_snake(t_liste* liste,t_pomme* pomme,BITMAP* base);
t_liste *initialisation(BITMAP* base);
void add_part(t_liste* liste,BITMAP* base);
void move_snake(t_liste* serpent,int mouvement);



///////////jeux de matthias//////
void deplacement(int y_poke[NB_poke_guitare], int vitesse,int *perreur);
void verification_touche(int y_poke[NB_poke_guitare],int *perreur);
void guitar_hero();
int partie_guitar_hero(BITMAP* page);
#endif //PROJET_HEAD_H