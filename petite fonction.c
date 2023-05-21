#include "head.h"

bool colision(t_player* player,t_objet* ob) {

    bool swap = true;

    if (player->x-5 < ob->x2 &&
        player->x + 28> ob->x &&
        player->y-5  < ob->y2 &&
        player->y + 35 > ob->y  )
    {
        if(player->x < ob->x){
            player->x =player->x-3;
            swap = false;
        }
        if(player->x > ob->x2 && swap == true){
            player->x= player->x+3;
            swap = false;
        }
        if(player->y < ob->y && swap == true){
            player->y =player->y-3;
            swap = false;
            return true;
        }
        if(player->y> ob->y2 && swap == true){
            player->y= player->y+3;
            swap = false;
            return true;
        }
    }
    return false;
}


bool bulle(t_objet* player){
    int pos = player->y -38;
    int yrec =0;
    int xrec=0;
    bool circle = false;

    while(!key[KEY_ENTER]){
        circle = false;
        if(key[KEY_UP]){
            pos = player->y -38;
            circle = true;
        }
        if(key[KEY_DOWN]){
            circle = true;
            pos = player->y -28;
        }
        if ( xrec<80){
            rectfill(screen,(player->x-50),(player->y-50),(player->x-50)+xrec,(player->y-50)+yrec, 0);
            rectfill(screen,(player->x-45),(player->y-45),(player->x-55)+xrec,(player->y-55)+yrec, makecol(255,255,255));
            rest(10);
            yrec++;
            xrec= xrec+2;
        }
        if(xrec ==80){
            if(circle == true){
                rectfill(screen,(player->x-45),(player->y-45),(player->x-23),(player->y-56)+yrec, makecol(255,255,255));
            }
            textprintf_ex(screen,font,(player->x-20),player->y -40,0,-1,"OUI");
            textprintf_ex(screen,font,(player->x-20), player->y -30,0,-1,"NON");
            circlefill(screen,player->x-30,pos,2,0);
        }

    }
    if(pos == player->y -38){
        return 1;
    }
    else {
        return 0;
    }
}

void door_one(BITMAP* bit,t_player* player1){
    for (int i = 0; i < 13; ++i) {
        rectfill(screen,725-i,405,725+i,429,0);
        draw_sprite(screen,bit,player1->x,player1->y);
        rest(100);
    }
}

void door_two(BITMAP* bit,t_player* player1){
    for (int i = 0; i < 13; ++i) {
        rectfill(screen,431-i,349,431+i,365,0);
        draw_sprite(screen,bit,player1->x,player1->y);
        rest(100);
    }
}

void poke_center(t_player* player,BITMAP* page, BITMAP* fond,BITMAP* tab[9]){
    t_objet sortie ={490,560,550,570};
    t_objet pc = {660,160,690,226};
    t_objet mur1 ={0,225,1024,225};
    t_objet mur2 ={305,0,305,768};
    t_objet mur3 ={0,515,470,515};
    t_objet mur4 ={555,515,1024,515};
    t_objet desk ={405,230,615,325};

    bool swap = false;
    bool end =true;
    blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
    draw_sprite(page,tab[6],player->x,player->y);
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    while(end){
        colision(player,&mur1);
        colision(player,&mur2);
        colision(player,&mur3);
        colision(player,&mur4);
        colision(player,&desk);
        depla(player,page,fond,tab);
        if (colision(player,&pc)){
            if(bulle(&pc)){
                afficher_score();
            }
        }
        if(colision(player,&sortie)){
            end = false;
        }
    }
}

void score_modif(int t, int type_jeux, const char* nom) {
    char fichier_jeux[20];
    sprintf(fichier_jeux, "../score%d.txt", type_jeux);
    FILE *pf = fopen(fichier_jeux, "r");
    if (pf == NULL) {
        pf = fopen(fichier_jeux, "w+");
    } else {
        pf = fopen(fichier_jeux, "a+");
    }

    int nombre_ligne = 0;
    char **tab_tri = malloc(20 * sizeof(char*)); // Alloue de la mémoire pour le tableau de pointeurs
    char temp[20];
    char caractere;

    srand(time(NULL));
    fprintf(pf, "%d %s\n", t, nom);
    rewind(pf);
    while ((caractere = fgetc(pf)) != EOF) {
        if (caractere == '\n') {
            nombre_ligne++;
        }
    }

    printf("%d\n", nombre_ligne);
    char temp_tri[nombre_ligne][20];

    rewind(pf);

    for (int i = 0; i < nombre_ligne; ++i) {
        fgets(temp_tri[i], 20, pf);
        tab_tri[i] = malloc(20 * sizeof(char));
        strcpy(tab_tri[i], temp_tri[i]);
    }

    for (int i = 0; i < nombre_ligne - 1; ++i) {
        for (int j = 0; j < nombre_ligne - 1 - i; ++j) {
            int score1, score2;
            char nom1[20], nom2[20];
            sscanf(tab_tri[j], "%d %s", &score1, nom1);
            sscanf(tab_tri[j + 1], "%d %s", &score2, nom2);
            if (score1 < score2) {
                strcpy(temp, tab_tri[j]);
                strcpy(tab_tri[j], tab_tri[j + 1]);
                strcpy(tab_tri[j + 1], temp);
            }
        }
    }

    rewind(pf);
    pf = fopen(fichier_jeux, "w");

    for (int i = 0; i < nombre_ligne; ++i) {
        fprintf(pf, "%s", tab_tri[i]);
    }

    fclose(pf);
    for (int i = 0; i < nombre_ligne; ++i) {
        free(tab_tri[i]);
    }
    free(tab_tri);
}


void afficher_score(){
    rest(100);
    BITMAP* page = create_bitmap(SCREEN_W,SCREEN_H);
    int number = 1;
    char fichier_jeux[20];
    bool end = true;
    clear_to_color(page, makecol(255,255,255));
    sprintf(fichier_jeux, "../score%d.txt", number);
    FILE *pf = fopen(fichier_jeux, "r");
    while(end){
        if(number == 1){
            textout_ex(page, font, "snake:", 10, 10, 0, -1);
        }
        if(number == 2){
            textout_ex(page, font, "Guitard hero:", 10, 10, 0, -1);
        }
        if(number == 3){
            textout_ex(page, font, "Pari pokemon:", 10, 10, 0, -1);
        }
        if(number == 4){
            textout_ex(page, font, "taupe la:", 10, 10, 0, -1);
        }
        if(number == 5){
            textout_ex(page, font, "Jackpot:", 10, 10, 0, -1);
        }
        if(number == 6){
            textout_ex(page, font, "Tir au ballon:", 10, 10, 0, -1);
        }
        int y = 30;
        if (key[KEY_RIGHT]){
            clear_to_color(page, makecol(255,255,255));
            if(number<6){number++;}
            sprintf(fichier_jeux, "../score%d.txt", number);
            pf = fopen(fichier_jeux, "r");
            rest(500);
        }
        if (key[KEY_LEFT]){
            clear_to_color(page, makecol(255,255,255));
            if(number>1){number--;}
            sprintf(fichier_jeux, "../score%d.txt", number);
            pf = fopen(fichier_jeux, "r");
            rest(500);
        }
        while (!feof(pf)) {
            char line[256];
            if (fgets(line, sizeof(line), pf) != NULL) {
                textout_ex(page, font, line, 10, y, makecol(0, 0, 0), -1);
                y += 20;
            }
        }
        if(key[KEY_ESC]){
            end =false ;
        }
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    fclose(pf);
}

void MAIN_initialisation_allegro()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}