#include <stdio.h>
#include <allegro.h>


void initialisation_allegro() {
    allegro_init();
    install_keyboard();
    install_mouse();

    if (install_mouse() == -1) {
        allegro_message("prb mouse\n :%s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (install_keyboard() == -1) {
        allegro_message("prb clavier\n :%s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0) {
        allegro_message("prb gfx mode\n :%s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
}





int main() {
    initialisation_allegro();

    BITMAP* page=NULL;
    BITMAP* fond_ecran;
    BITMAP* pikachu;

    page=create_bitmap(SCREEN_W,SCREEN_H);

    if (!page){
        allegro_message("Erreur creation page");}

    clear_bitmap(screen);
    fond_ecran=load_bitmap("../fond_ecran.bmp",NULL);
    pikachu=load_bitmap("../tete_pikachu.bmp",NULL);



    draw_sprite(fond_ecran,pikachu,17,0);


    /*
    circlefill(fond_ecran,64,430,35,makeacol(0,0,0,0));
    circlefill(fond_ecran,192,430,35,makeacol(0,0,0,0));
    circlefill(fond_ecran,318,430,35,makeacol(0,0,0,0));
    circlefill(fond_ecran,446,430,35,makeacol(0,0,0,0));
    circlefill(fond_ecran,574,430,35,makeacol(0,0,0,0));
    */


    int y_pikachu=-100;
    while(!key[KEY_ESC]){



        fond_ecran=load_bitmap("../fond_ecran.bmp",NULL);
        for (int i = 0; i < 5; ++i) {
            circlefill(fond_ecran,64+i*128,430,40,makecol(0,0,0));
        }
        draw_sprite(fond_ecran,pikachu,17,y_pikachu);

        blit(fond_ecran,page,0,0,0,0,SCREEN_W,SCREEN_H);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);


if(keypressed()) {



    if (key[KEY_Q]) {


        if (y_pikachu > 290) {
            y_pikachu = -100;


        } else if (y_pikachu >= 0) {

        }


    } else if (key[KEY_W]) {

        circlefill(fond_ecran, 192, 430, 50, makecol(0, 0, 0));


    } else if (key[KEY_E]) {

        circlefill(fond_ecran, 318, 430, 50, makecol(0, 0, 0));


    } else if (key[KEY_R]) {

        circlefill(fond_ecran, 446, 430, 50, makecol(0, 0, 0));


    } else if (key[KEY_T]) {

        circlefill(fond_ecran, 574, 430, 50, makecol(0, 0, 0));


    }
}


        clear(fond_ecran);
        y_pikachu+=2;
        if(y_pikachu==480){
            y_pikachu=-100;
        }
vsync();
    }
    return 0;


}END_OF_MAIN()