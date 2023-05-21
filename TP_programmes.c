#include "head.h"


int jeu_maximiliano()
{

    srand(time(NULL));
    int compteur_points_joueur = 0;
    int randomposition         = rand()%13;
    int x=0;
    int y=0;
    int temp=0;
    int compt=0;
    int defaite;
    BITMAP *sprite_tiplouf_tete;
    BITMAP *fond_d_ecran;
    BITMAP* page=NULL;
    show_mouse(screen);


    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear(page);


    sprite_tiplouf_tete = load_bitmap("../tetedetiplouf.bmp", NULL);
    if(!sprite_tiplouf_tete){
        allegro_message("l'image ne charge pas");
        exit(1);
    }

    fond_d_ecran = load_bitmap("../map_taupe_la.bmp", NULL);
    if (!fond_d_ecran)
    {
        allegro_message("erreur de chargement");
        exit(1);
    }



    defaite = 0;

    while (defaite != 1){



        blit(fond_d_ecran,page,0,0,0,0, SCREEN_W, SCREEN_H);





        if(temp>TEMPSTETE){
            randomposition = rand()%13;
            temp=0;
        }




        for (int i = 0; i < 12; ++i) {

            if(randomposition==0){
                draw_sprite(page,sprite_tiplouf_tete,135,158);
                x=135;
                y=158;
            }else if (randomposition==1){
                draw_sprite(page,sprite_tiplouf_tete,303,158);
                x=303;
                y=158;
            }else if(randomposition==2){
                draw_sprite(page,sprite_tiplouf_tete,468,158);
                x=468;
                y=158;
            }else if(randomposition==3){
                draw_sprite(page,sprite_tiplouf_tete,633,158);
                x=633;
                y=158;
            }else if(randomposition==4){
                draw_sprite(page,sprite_tiplouf_tete,135,350);
                x=135;
                y=350;
            }else if(randomposition==5){
                draw_sprite(page,sprite_tiplouf_tete,303,350);
                x=303;
                y=350;
            }else if(randomposition==6){
                draw_sprite(page,sprite_tiplouf_tete,468,350);
                x=468;
                y=350;
            }else if(randomposition==7){
                draw_sprite(page,sprite_tiplouf_tete,633,350);
                x=633;
                y=350;
            }else if(randomposition==8){
                draw_sprite(page,sprite_tiplouf_tete,135,539);
                x=135;
                y=539;
            }else if(randomposition==9){
                draw_sprite(page,sprite_tiplouf_tete,303,539);
                x=303;
                y=539;
            }else if(randomposition==10){
                draw_sprite(page,sprite_tiplouf_tete,468,539);
                x=468;
                y=539;
            }else if(randomposition==11){
                draw_sprite(page,sprite_tiplouf_tete,633,539);
                x=633;
                y=539;
            }

        }




        if(compt<0){
            if (mouse_b & 1){
                if(mouse_x<x+100 && mouse_x>x-100 && mouse_y<x+100 && mouse_y>y-100 ){
                    compteur_points_joueur = compteur_points_joueur + 1;
                    printf("%d\n",compteur_points_joueur);
                    compt=100;
                }else{
                    ////DEFAITE//////
                    printf("defaite \n");
                    defaite = 1;

                }
            }}

        compt--;
        blit(page,screen,0,0,0,0, SCREEN_W, SCREEN_H);
        temp+=1;
    }
    return compteur_points_joueur;
}

void ecran_d_accueil(){
    BITMAP *ecran_accueil;
    BITMAP *page = create_bitmap(1024, 768);
    clear_bitmap(page);
    ecran_accueil = load_bitmap("../ecranaccueil.bmp", NULL);
    if (!ecran_accueil)
    {
        allegro_message("erreur de chargement");
        exit(1);
    }

    while (!key[KEY_ENTER])
    {
        blit(page,screen,0,0,0,0, SCREEN_W, SCREEN_H);
        blit(ecran_accueil,page,0,0,0,0, SCREEN_W, SCREEN_H);
    }
}

void  finalTP(t_player *player, t_player *player2){
    int point_joueur1TP;
    int point_joueur2TP;
    ecran_d_accueil();
    point_joueur1TP = jeu_maximiliano();
    ecran_d_accueil();
    point_joueur2TP = jeu_maximiliano();
    clear(screen);
    while(!key[KEY_ESC]) {

        if (point_joueur1TP < point_joueur2TP) {
            textprintf_ex(screen, font, 10, 10, makecol(255, 100, 100), -1, " %s vous avez gagné !",player2->name);

        } else {
            textprintf_ex(screen, font, 10, 10, makecol(255, 100, 100), -1, "%s vous avez gagné !", player->name);

        }
    }
    if (point_joueur1TP < point_joueur2TP) {
        player->ticket--;
    }else if (point_joueur1TP > point_joueur2TP){
        player2->ticket--;
    }

    score_modif(point_joueur1TP,4,player->name);
    score_modif(point_joueur2TP,4,player2->name);


}
