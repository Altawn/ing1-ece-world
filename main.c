#include "not_main.h"

int main()
{
    //Temps des joueurs respectifs
    double tps_j1 = 0.0;
    double tps_j2 = 0.0;

    //init allegro
    TB_init_allegro();

    //init variables
    ballons * pokemons[7];
    BITMAP * background = NULL;
    BITMAP * buffer = NULL;
    BITMAP * open_poke = NULL;
    BITMAP * close_poke = NULL;
    BITMAP * pokeball[2] = {0, 0};
    BITMAP * dialogue = NULL;
    int flag = 0;
    int available_poke = 1;
    int compteur = 0;
    int detection_y = 0;
    int detection_x = 0;
    int i = 1;

    srand(time(NULL));

//init structures
    TB_remp_tab_pok(pokemons);

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
    TB_entree_jeu(buffer, background, dialogue, i);

    //joueur 1
    tps_j1 = TB_jeu(buffer,background,dialogue,pokemons,pokeball);

    //Definition des regles du jeu pour j2
    TB_entree_jeu(buffer, background, dialogue, i);

    return 0;
    allegro_exit();
}END_OF_MAIN()
