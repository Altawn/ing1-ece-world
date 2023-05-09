#include <stdio.h>
#include <allegro.h>
#include "head.h"
#include <time.h>

void jeu_maximiliano()
{
    int temps_tete = 0;

    srand(time(NULL));
    int randomposition ;
    int x=0;
    allegro_init();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1120,700,0,0);

    BITMAP *sprite_tiplouf_tete;
    sprite_tiplouf_tete = load_bitmap("../tetedetiplouf.bmp", NULL);
    if(!sprite_tiplouf_tete){
        allegro_message("l'image ne charge pas");
        exit(1);
    }
    BITMAP *fond_d_ecran;
    fond_d_ecran = load_bitmap("../map_taupe_la.bmp", NULL);
    if (!fond_d_ecran)
    {
        allegro_message("erreur de chargement");
        exit(1);
    }
    install_keyboard();
    while (x=5){
        blit(fond_d_ecran,screen,0,0,0,0, SCREEN_W, SCREEN_H);
        temps_tete = 0;
        randomposition = rand()%13+1;
        if (randomposition = 1){
            while(temps_tete = 10){
                    draw_sprite(fond_d_ecran,sprite_tiplouf_tete,135,158);
                    temps_tete = temps_tete+1;
            }
        }
        if (randomposition = 2){
            while (temps_tete = 10){
            draw_sprite(fond_d_ecran,sprite_tiplouf_tete,303,158);
            temps_tete = temps_tete +1;
            }
        }
        if (randomposition = 3){
            while (temps_tete  = 10){
                draw_sprite(fond_d_ecran,sprite_tiplouf_tete,468,158);
                temps_tete = temps_tete + 1;
            }
        }
        if (randomposition = 4){
            while (temps_tete = 10){
            draw_sprite(fond_d_ecran,sprite_tiplouf_tete,135,350);
            temps_tete = temps_tete + 1;
            }

        }
        if (randomposition = 5){
            while (temps_tete = 10){
                draw_sprite(fond_d_ecran,sprite_tiplouf_tete,303,350);
                temps_tete  = temps_tete + 1 ;
            }

        }
        if (randomposition = 6){
            while (temps_tete = 10){
                draw_sprite(fond_d_ecran,sprite_tiplouf_tete,468,350);
                temps_tete = temps_tete + 1 ;
            }
        }
        if (randomposition = 7){
            while (temps_tete = 10){
            draw_sprite(fond_d_ecran,sprite_tiplouf_tete,633,350);
            temps_tete = temps_tete + 1;
            }

        }
        if (randomposition = 8){
            while (temps_tete = 10){
                draw_sprite(fond_d_ecran,sprite_tiplouf_tete,135,539);
                temps_tete = temps_tete + 1;
        }

        }
        if (randomposition = 9){
            while (temps_tete = 10){
                draw_sprite(fond_d_ecran,sprite_tiplouf_tete,633,158);
                temps_tete  = temps_tete + 1;
            }


        }
        if (randomposition = 10){
            while (temps_tete = 10){
                draw_sprite(fond_d_ecran,sprite_tiplouf_tete,303,539);
                temps_tete = temps_tete + 1;
            }

        }
        if (randomposition = 11){
            while (temps_tete = 10){
            draw_sprite(fond_d_ecran,sprite_tiplouf_tete,468,539);
            temps_tete = temps_tete + 1;
            }

        }
        if (randomposition = 12){
            while(temps_tete = 10){
            draw_sprite(fond_d_ecran,sprite_tiplouf_tete,633,539);
            temps_tete =  temps_tete + 1;
            }

        }
        x= x+1;
    }
}







