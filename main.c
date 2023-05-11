#include <stdio.h>
#include <allegro.h>
#include <stdlib.h>
#include <time.h>

#define NB_poke_guitare 5

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
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1024, 768, 0, 0) != 0) {
        allegro_message("prb gfx mode\n :%s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
}





void deplacement(int y_poke[NB_poke_guitare], int vitesse,int *perreur){
    int i,j;
    int nb_alea[NB_poke_guitare];
    int verif;

    for ( i = 0; i < NB_poke_guitare; ++i) {
        verif=0;
        nb_alea[i]=0;
        if(y_poke[i]==-100){

            nb_alea[i]=rand()%1000;


            for ( j = 0; j < NB_poke_guitare; ++j) {
                if(y_poke[j]>20 || y_poke[j]==-100){
                    verif+=1;
                }

            }
            if(nb_alea[i]==5 && verif==NB_poke_guitare) {

                y_poke[i]=-99;

            }
        }else if(y_poke[i]>-100){
            y_poke[i]+=vitesse;}

        if(y_poke[i]>680){
            *perreur=1;
        }

    }
}


void verification_touche(int y_poke[NB_poke_guitare],int *perreur){
    int i;
    int  verification=0;

    for ( i = 0; i < NB_poke_guitare; ++i) {
        if (y_poke[i] > 520) {
            y_poke[i] = -100;
            verification=1;

        }
    }

    if(verification==0 ){
        *perreur=1;
    }

}


int main() {
    initialisation_allegro();

    int y_pikachu[NB_poke_guitare];
    int y_carapuce[NB_poke_guitare];
    int y_dracaufeu[NB_poke_guitare];
    int y_evoli[NB_poke_guitare];
    int y_rondoudou[NB_poke_guitare];

    int i;
    int vitesse=2;
    int temp=0;
    int temp_touche=0;
    int erreur=0;

    BITMAP* page=NULL;
    BITMAP* fond_ecran;
    BITMAP* fond_ecran2;
    BITMAP* pikachu[NB_poke_guitare];
    BITMAP* carapuce[NB_poke_guitare];
    BITMAP* dracaufeu[NB_poke_guitare];
    BITMAP* evoli[NB_poke_guitare];
    BITMAP* rondoudou[NB_poke_guitare];

    page=create_bitmap(SCREEN_W,SCREEN_H);

    if (!page){
        allegro_message("Erreur creation page");}

    clear_bitmap(screen);
    for ( i = 0; i < NB_poke_guitare; ++i) {

        pikachu[i]=load_bitmap("../tete_pikachu.bmp",NULL);
        carapuce[i]= load_bitmap("../tete_carapuce.bmp",NULL);
        dracaufeu[i]= load_bitmap("../tete_dracaufeu.bmp",NULL);
        evoli[i]= load_bitmap("../tete_evoli.bmp",NULL);
        rondoudou[i]= load_bitmap("../tete_rondoudou.bmp",NULL);
    }

    fond_ecran=load_bitmap("../fond_ecran_guitarre_heroo_1024.bmp",NULL);
    fond_ecran2=load_bitmap("../fond_ecran_guitarre_heroo_1024.bmp",NULL);





    for ( i = 0; i < NB_poke_guitare; ++i) {
        y_pikachu[i]=-100;
        y_carapuce[i]=-100;
        y_dracaufeu[i]=-100;
        y_evoli[i]=-100;
        y_rondoudou[i]=-100;
    }

    srand(time(NULL));

    while(!key[KEY_ESC] && erreur==0 ){

        blit(fond_ecran2,fond_ecran,0,0,0,0,SCREEN_W,SCREEN_H);


        for ( i = 0; i < NB_poke_guitare; ++i) {
            draw_sprite(fond_ecran,pikachu[i],52,y_pikachu[i]);
            draw_sprite(fond_ecran,carapuce[i],257,y_carapuce[i]);
            draw_sprite(fond_ecran,dracaufeu[i],462,y_dracaufeu[i]);
            draw_sprite(fond_ecran,evoli[i],667,y_evoli[i]);
            draw_sprite(fond_ecran,rondoudou[i],872,y_rondoudou[i]);
        }


        blit(fond_ecran,page,0,0,0,0,SCREEN_W,SCREEN_H);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);


        if(keypressed() && temp-temp_touche>10 ) {

            if (key[KEY_Q]) {

                verification_touche(y_pikachu,&erreur);
                temp_touche=temp;
            } else if (key[KEY_W]) {

                verification_touche(y_carapuce,&erreur);
                temp_touche=temp;
            } else if (key[KEY_E]) {

                verification_touche(y_dracaufeu,&erreur);
                temp_touche=temp;
            } else if (key[KEY_R]) {

                verification_touche(y_evoli,&erreur);
                temp_touche=temp;
            } else if (key[KEY_T]) {

                verification_touche(y_rondoudou,&erreur);
                temp_touche=temp;
            }
        }



        clear_bitmap(fond_ecran);

        deplacement(y_pikachu,vitesse,&erreur);
        deplacement(y_carapuce,vitesse,&erreur);
        deplacement(y_dracaufeu,vitesse,&erreur);
        deplacement(y_evoli,vitesse,&erreur);
        deplacement(y_rondoudou,vitesse,&erreur);

        temp+=1;
        if(temp % 1000 ==0){
            vitesse+=1;
        }

        vsync();

    }
    return 0;

}END_OF_MAIN()
