#include "not_main.h"

int main()
{
    //Temps des joueurs respectifs
    double tps_j1;
    double tps_j2;

    //init allegro
    TB_init_allegro();

    //init variables
    ballons * pokemons[7];
    BITMAP * background = NULL;
    BITMAP * buffer = NULL;
    BITMAP * pokeball[2] = {0, 0};
    BITMAP * dialogue = NULL;

    srand(time(NULL));

//init bitmaps
    buffer = create_bitmap(1024, 768); clear_bitmap(buffer);
    if(!buffer) allegro_message("Erreur creation page");

    background = load_bitmap("fond_ballons.bmp", NULL);
    if(!background) allegro_message("Pas de fond d'ecran");

    pokeball[0] = load_bitmap("open_pokeball1.bmp", NULL);
    if(!pokeball[0]) allegro_message("Pas de pokeball 1");

    pokeball[1] = load_bitmap("closed_pokeball1.bmp", NULL);
    if(!pokeball[1]) allegro_message("Pas de pokeball 2");

    dialogue = load_bitmap("dialogue_pokemon.bmp", NULL);
    if(!dialogue) allegro_message("Pas de dialogue");

    //Definition des regles du jeu pour j1
    TB_entree_jeu(buffer, background, dialogue, 1);

    //joueur 1
    tps_j1 = TB_jeu(buffer,background,dialogue,pokemons,pokeball);

    //transition
    rest(20);
    rectfill(background,410,600,450,620,makecol(255,255,255));

    //transition entre les deux joueurs
    TB_entree_jeu(buffer,background,dialogue,2);

    //Definition des regles du jeu pour j2
    tps_j2 = TB_jeu(buffer,background,dialogue,pokemons,pokeball);

    //transition
    rest(20);

    //affichage des resultats
    TB_resultats(tps_j1, tps_j2, background, buffer, dialogue);


    allegro_exit();
    return 0;
}END_OF_MAIN()
