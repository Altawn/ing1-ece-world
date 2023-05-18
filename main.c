#include "not_main.h"

int main() {

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
        for (int i = 0; i < 7; ++i) {
            if(
                       (mouse_x <= pokemons[i]->posx + pokemons[i]->depx)
                    && (mouse_x >= pokemons[i]->posx - pokemons[i]->poke->w + pokemons[i]->depx)
                    && (mouse_b & 1)
                    && (available_poke == 1)
                    && (mouse_y <= pokemons[i]->posy + pokemons[i]->depy)
                    && (mouse_y >= pokemons[i]->posy - pokemons[i]->poke->h + pokemons[i]->depy))
            {
                pokemons[i]->posx = -10;
                pokemons[i]->posy = -10;
                pokemons[i]->depx = 0;
                pokemons[i]->depy = 0;
            }
        }

    //Animation pokeball ferme + mise a zero de la variable available_poke
        if(mouse_b & 1)
        {
            draw_sprite(buffer, pokeball[1], mouse_x - pokeball[1]->w/2, mouse_y- pokeball[1]->h/2);
            available_poke = 0; //Du temps que la pokeball est ferme, nous en pouvons plus attraper de pokemons  -->  il faut dont relacher le click gauche pour essayer d' en attraper de nouveau
        }


    //condition pour que la variable available_poke = 1
        if(!(mouse_b & 1))
        {
            available_poke = 1;
        }


    //fin de la boucle
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        //conditions de jeu
      /*  if(compteur%30 == 0)
        {
            for (int i = 0; i < 7; ++i)
            {
                pokemons[i]->depx = rand()%50 - 25;
                pokemons[i]->depy = rand()%50 - 25;
            }
            //if(compteur%60 == 0)
                //flag = 0;
        }

        if(compteur%10==0)
            flag = 0;
*/
        rest(20);
        compteur++;
    }

    return 0;
    allegro_exit();
}END_OF_MAIN()
