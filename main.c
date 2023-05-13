#include "not_main.h"

int main() {

    TB_init_allegro();

    BITMAP * background = NULL;
    BITMAP * buffer = NULL;
    BITMAP * open_poke = NULL;
    BITMAP * close_poke = NULL;
    BITMAP * poke[2] = {0, 0};

    int flag = 0;

    buffer = create_bitmap(1024, 768); clear_bitmap(buffer);
    if(!buffer) allegro_message("Erreur creation page");

    background = load_bitmap("fond_ballons.bmp", NULL);
    if(!background) allegro_message("Pas de fond d'ecran");

    poke[0] = load_bitmap("open_pokeball1.bmp", NULL);
    if(!background) allegro_message("Pas de pokeball 1");

    poke[1] = load_bitmap("closed_pokeball1.bmp", NULL);
    if(!background) allegro_message("Pas de pokeball 2");


    while(!key[KEY_ESC])
    {
        mouse_y = mouse_y;
        mouse_x = mouse_x;

        blit(background, buffer,0,0,0,0,SCREEN_W,SCREEN_H);

        draw_sprite(buffer, poke[0], mouse_x, mouse_y);

        if(mouse_b & 1 && flag == 0)
        {
            clear(buffer);
            blit(background, buffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(buffer, poke[1], mouse_x, mouse_y);
            flag = 1;
        }


        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        flag = 0;
    }

    return 0;
    allegro_exit();
}END_OF_MAIN()
