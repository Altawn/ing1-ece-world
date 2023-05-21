#ifndef PROJET_HEAD_H
#define PROJET_HEAD_H
#define NB_poke_guitare 5

#include <stdio.h>
#include "allegro.h"
#include "time.h"
#include <stdbool.h>
#define NIMAGE 5
#define NPOK 5
#define TEMPSTETE 1000

//////////BASE + INTRO/////////


typedef struct player{
    int x;
    int y;
    int mouv;
    char name[50];
    int ticket;
    int type;
}t_player;

typedef struct objet{
    int x, y, x2, y2;
}t_objet;

void MAIN_initialisation_allegro();
void score_modif(int t, int type_jeux, const char* nom);
void afficher_score();
void poke_center(t_player* player,BITMAP* page, BITMAP* fond,BITMAP* tab[9]);
void calc(t_objet* ob);
bool colision(t_player* player,t_objet* ob);
void ecran();
void print_chen(BITMAP *page,t_player* player,t_player* player2);
void depla(t_player* player,BITMAP* page, BITMAP* fond,BITMAP* tab[9]);
void depla2(t_player* player,BITMAP* page, BITMAP* fond,BITMAP* tab[9]);


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

bool bulle(t_objet* player);
bool snake_defeat(int nbpart,t_liste* serpent);
void door_one(BITMAP* bit,t_player* player1);
void door_two(BITMAP* bit,t_player* player1);
void snake(t_player* player,t_player* player2);
void afficherListe(t_liste *liste,BITMAP* page,BITMAP* head1,BITMAP* head2,BITMAP* head3,BITMAP* head4,int mouvement);
void pomme_init(BITMAP* base2,t_pomme* apple);
bool colision_snake(t_liste* liste,t_pomme* pomme,BITMAP* base);
t_liste *initialisation(BITMAP* base);
void add_part(t_liste* liste,BITMAP* base);
void move_snake(t_liste* serpent,int mouvement);



///////////JEUX DE MATTHIAS//////////////////
//guitare hero
void deplacement_guitare(int y_poke[NB_poke_guitare], int vitesse,int *perreur);
void verification_touche_guitare(int y_poke[NB_poke_guitare],int *perreur);
void guitar_hero(t_player* player,t_player* player2);
double partie_guitar_hero(BITMAP* page);

//jackpot
void jackpot(t_player* player,t_player* player2);
int jackpot_debut();
void start_jackpot();
void arret_tour_jackpot(int vitesse,int y[3],int *arret);
void tournee_debut_jackpot(int vitesse,int y[3]);
//////////////////////////////////////////////////////////////////////////////////////////////////JEUX DU RORO//////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *
 *
 * Pari Hippique
 *
 *
 */
typedef struct
{
    int posx, posy; //posit. coin sup. gauche
    int depx; //deplacement en x
    int frame_act; //frame actuelle du pokemon
    int pok; //quel pokemon ?
    BITMAP *img[NIMAGE-1];
}Pokemon;

//Allouer + Initialisation d'acteurs
Pokemon * PI_init_pokemon(int posx, int posy, int pok, int depx);

//Remplir un tab avec des acteurs
void PI_remp_tab_pok(Pokemon * tab_rand[NPOK]);

//Animation des pokemons
void PI_anim_pok(Pokemon * tab_rand[NPOK], BITMAP * page);

//deplacement des pokemons
int PI_depla_pok(Pokemon * tab_rand[NPOK], BITMAP * page);

//transcription nombres -> chaine de caracteres
void PI_pok_gagnant(char * winner, int pok_gagnant);

//Affichage de la liste des pokemons dans le texte
void PI_affichage_liste(BITMAP * decor, char * liste[50], BITMAP * page);

//Texte d'entree du jeu
void PI_entree_jeu(BITMAP * decor, BITMAP * page, BITMAP * dialogue, char * liste[50]);

//sauvegarde des resultats des deux joueurs
int PI_choix_pok(int y_cir);

//navigtion pour le choix des pokemons dans PI_choix_pok
int PI_navigation(BITMAP*decor, BITMAP*page, int y_cir, int passe, int flag, int blanc);

//Affichage du pokemon gagnant
void PI_print_gagnant(BITMAP*decor, BITMAP*dialogue, char*pok_gagnant, int choix_j1, int arrivee, int choix_j2);

//Jeu principal
void Pari_Hippique(t_player* player,t_player* player2);

/*
 *
 *
 * Tir aux ballons
 *
 *
 */
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

ballons * TB_init_struct(int posx, int posy, int depx, int depy, int type, int attrape);

void TB_remp_tab_pok(ballons * taballons[7]);

void TB_anim_pok(ballons * pokemons[7], BITMAP*buffer);

void TB_click_souris(ballons * pokemons[7], int available_poke);

int TB_condition_attrap(BITMAP* pokeball[2], BITMAP*buffer);

void TB_entree_jeu(BITMAP* buffer, BITMAP* background, BITMAP* dialogue, int i);

double TB_jeu(BITMAP* buffer, BITMAP* background, BITMAP* dialogue, ballons* pokemons[7], BITMAP* pokeball[2]);

void TB_transition(BITMAP* background, BITMAP* buffer, int i);

void TB_resultats(double tps_j1, double tps_j2, BITMAP* background, BITMAP* buffer, BITMAP* dialogue,t_player* player,t_player* player2);

void Tir_Ballons(t_player* player,t_player* player2);
#endif //PROJET_HEAD_H

///////////////////////////MAXIMILIANO////////////////////
void  finalTP(t_player *player, t_player *player2);
void ecran_d_accueil();
int jeu_maximiliano();