#include <stdio.h>
#include <allegro.h>
#include <stdlib.h>



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
    BITMAP* fond_ecran2;
    BITMAP* pikachu[3];

    page=create_bitmap(SCREEN_W,SCREEN_H);

    if (!page){
        allegro_message("Erreur creation page");}

    clear_bitmap(screen);
    for (int i = 0; i < 3; ++i) {
        pikachu[i]=load_bitmap("../tete_pikachu.bmp",NULL);
    }

    fond_ecran=load_bitmap("../fond_ecran.bmp",NULL);
    fond_ecran2=load_bitmap("../fond_ecran.bmp",NULL);




    /*
    circlefill(fond_ecran,64,430,35,makeacol(0,0,0,0));
    circlefill(fond_ecran,192,430,35,makeacol(0,0,0,0));
    circlefill(fond_ecran,318,430,35,makeacol(0,0,0,0));
    circlefill(fond_ecran,446,430,35,makeacol(0,0,0,0));
    circlefill(fond_ecran,574,430,35,makeacol(0,0,0,0));
    */


    int y_pikachu[3];
    int vitesse=1;
    int temp=0;
    for (int i = 0; i < 3; ++i) {
        y_pikachu[i]=-100;
    }
    int nb[3];
    while(!key[KEY_ESC]){

        blit(fond_ecran2,fond_ecran,0,0,0,0,SCREEN_W,SCREEN_H);


        for (int i = 0; i < 5; ++i) {
            circlefill(fond_ecran,64+i*128,430,40,makecol(255,0,0));
        }
        for (int i = 0; i < 3; ++i) {
            draw_sprite(fond_ecran,pikachu[i],17,y_pikachu[i]);
        }
       // draw_sprite(fond_ecran,pikachu,17,y_pikachu);

        blit(fond_ecran,page,0,0,0,0,SCREEN_W,SCREEN_H);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);


if(keypressed()) {



    if (key[KEY_Q]) {
int verification_touche=0;
        for (int i = 0; i < 3; ++i) {
            if (y_pikachu[i] > 290) {
                y_pikachu[i] = -100;
                verification_touche=1;
            }
        }
        if(verification_touche==0){


            }

    /*    if (y_pikachu[0] > 290) {
            y_pikachu[0] = -100;
        }else if (y_pikachu[1] > 290) {
            y_pikachu[1] = -100;
        }else if (y_pikachu[2] > 290) {
            y_pikachu[2] = -100;
        }
*/
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


        clear_bitmap(fond_ecran);

        for (int i = 0; i < 3; ++i) {


if(y_pikachu[i]==-100){

    nb[i]=rand()%200;
    if(nb[i]==5 && (y_pikachu[0]>1 || y_pikachu[0]==-100) && (y_pikachu[1]>1 || y_pikachu[1]==-100) && (y_pikachu[2]>1 || y_pikachu[2]==-100)){
        y_pikachu[i]=-99;

    }
}else if(y_pikachu[i]>-100){
        y_pikachu[i]+=vitesse;}

         if(y_pikachu[i]>450){


        }

        }

        temp+=1;
        if(temp % 1000 ==0){
            vitesse+=1;
        }

vsync();

    }
    return 0;


}END_OF_MAIN()
