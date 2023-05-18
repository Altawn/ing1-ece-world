#include "not_main.h"

int main()
{

    //Temps des joueurs respectifs
    int tps_j1 = 0;
    int tps_j2 = 0;

    //init allegro
    TB_init_allegro();

    //init variables
    ballons * pokemons[7];
    BITMAP * background = NULL;
    BITMAP * buffer = NULL;
    BITMAP * open_poke = NULL;
    BITMAP * close_poke = NULL;
    BITMAP * pokeball[2] = {0, 0};
    int flag = 0;
    int available_poke = 1;
    int compteur = 0;
    int detection_y = 0;
    int detection_x = 0;

    srand(time(NULL));

//init structures
    TB_remp_tab_pok(pokemons);

//init bitmaps
    buffer = create_bitmap(1024, 768); clear_bitmap(buffer);
    if(!buffer) allegro_message("Erreur creation page");

    background = load_bitmap("fond_ballons.bmp", NULL);
    if(!background) allegro_message("Pas de fond d'ecran");

    pokeball[0] = load_bitmap("open_pokeball1.bmp", NULL);
    if(!background) allegro_message("Pas de pokeball 1");

    pokeball[1] = load_bitmap("closed_pokeball1.bmp", NULL);
    if(!background) allegro_message("Pas de pokeball 2");

    while(!key[KEY_ESC])
    {
        show_mouse(buffer);
        mouse_y = mouse_y;
        mouse_x = mouse_x;

        blit(background, buffer,0,0,0,0,SCREEN_W,SCREEN_H);

    //apparition des pokemons
        TB_anim_pok(pokemons, buffer);

    //affichage pokeball ouverte
        draw_sprite(buffer, pokeball[0], mouse_x - pokeball[0]->w/2, mouse_y- pokeball[0]->h/2);

    //test attraper pokemon
        TB_click_souris(pokemons, available_poke);

    //Si la pokeball reste appuyé, nous ne pouvons plus attraper de pokemons
        available_poke = TB_condition_attrap(pokeball, buffer);

    //fin de la boucle
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    //conditions de jeu
        if(compteur%30 == 0)
        {
            for (int i = 0; i < 7; ++i)
            {
                pokemons[i]->depx = rand()%50 - 25;
                pokemons[i]->depy = rand()%50 - 25;
            }
        }


        rest(20);
        compteur++;
    }

    return 0;
    allegro_exit();
}END_OF_MAIN()
