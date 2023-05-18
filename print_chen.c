#include "head.h"

void ecran(){
    BITMAP* page;
    page = load_bitmap("../pokepark.bmp",NULL);
    while(!key[KEY_ENTER]){
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        textout_centre_ex(screen, font, "press enter to continue",512,445, makecol(0, 0, 0), -1);
        rest(100);

    }
}

void print_chen(BITMAP *page,t_player *player1,t_player *player2) {

    char nom_perso1[256] = "";
    char stock_nom1[256];
    char nom_perso2[256] = "";
    char stock_nom2[256];
    int position_lettre = 0;
    int position_lettre2 = 0;

    bool draw = true;
    bool swap1 = false;
    bool swap2 = false;
    bool swap3 = false;
    bool swap4 = false;

    bool circle = false;
    int pos = 257;
    int i = 0;
    int yrec =0;
    int xrec=0;
    char* texte[] = {"Bonjour je suis le professeur chen ","Tu vas bien?","comment t'appelles tu?","et le joueur 2","tu t'apprète a rentrer dans le parc d'atraction pokemon de l'ece", "est-tu prêts ?","c'est bien dommage","d"};
    bool text = true;
    bool flag = false;
    BITMAP *chen;
    chen = load_bitmap("../pr_chen1.bmp", NULL);
    int current_phrase = 0;
    char display[256];
    memset(display, 0, sizeof(display)); // Initialisation de la chaîne de caractères à afficher


    while (!flag) {

        if (text) {
            if (i < strlen(texte[current_phrase]) && current_phrase <=6) {
                display[i] = texte[current_phrase][i];
                i++;
            }

            else {
                rest(500);
                memset(display, 0, sizeof(display));
                i = 0;
                if(current_phrase <= 6){
                    current_phrase = current_phrase + 1;
                }
            }

            ///////////BULLE 1///////

            if(current_phrase == 2 && swap1 == false ){
                swap1 = true;
                while (!key[KEY_ENTER]) {
                    circle = false;
                    if(key[KEY_UP]){
                        pos = 257;
                        circle = true;
                    }
                    if(key[KEY_DOWN]){
                        circle = true;
                        pos = 277;
                    }
                    if ( xrec<100){
                        rectfill(screen,237,239,(247+xrec),(249+yrec), 0);
                        rectfill(screen,242,244,(242+xrec),(244+yrec), makecol(255,255,255));
                        rest(10);
                        yrec++;
                        xrec= xrec+2;
                    }
                    if(xrec ==100){
                        if(circle == true){
                            rectfill(screen,242,244,(242+xrec),(244+yrec), makecol(255,255,255));
                        }
                        textprintf_ex(screen,font,262,254,0,-1,"OUI");
                        textprintf_ex(screen,font,262,274,0,-1,"NON");
                        circlefill(screen,252,pos,2,0);
                    }
                }
            }

            ///////// BULLE 2///////
            if(current_phrase == 3 && swap2 == false ){
                swap2 = true;
                while (!key[KEY_ENTER]) {
                    if ( xrec<150){
                        rectfill(screen,637,229,(647+xrec),(239+yrec), 0);
                        rectfill(screen,642,234,(642+xrec),(234+yrec), makecol(255,255,255));
                        rest(10);
                        yrec++;
                        xrec= xrec+6;
                    }
                    if (keypressed()) {
                        int key_code = readkey();
                        char lettre_nom = key_code & 0xFF;
                        if (lettre_nom >= ' ' && lettre_nom <= '~' && position_lettre < 255) {
                            nom_perso1[position_lettre++] = lettre_nom;
                            nom_perso1[position_lettre] = '\0';
                        }
                        if(key[KEY_BACKSPACE]){
                            if(position_lettre > 0){
                                for (int j = position_lettre; j != -1; j--) {
                                    nom_perso1[j] = '\0';
                                }
                                rectfill(screen,642,234,(632+xrec),(224+yrec), makecol(255,255,255));
                                position_lettre=0;
                            }
                        }
                    }
                    textout_ex(screen, font, nom_perso1, 652, 244, makecol(0, 0, 0), -1);
                }
            }

            ////////BULLE 2 BIS///////
            if(current_phrase == 4 && swap3 == false ){
                swap3 = true;
                while (!key[KEY_ENTER]) {
                    if (draw){
                        rectfill(screen,637,229,(647+xrec),(239+yrec), 0);
                        rectfill(screen,642,234,(642+xrec),(234+yrec), makecol(255,255,255));
                        draw = false;
                    }
                    if (keypressed()) {
                        int key_code = readkey();
                        char lettre_nom = key_code & 0xFF;
                        if (lettre_nom >= ' ' && lettre_nom <= '~' && position_lettre < 255) {
                            nom_perso2[position_lettre2++] = lettre_nom;
                            nom_perso2[position_lettre2] = '\0';
                        }
                        if(key[KEY_BACKSPACE]){
                            if(position_lettre2 > 0){
                                for (int j = position_lettre2; j != -1; j--) {
                                    nom_perso2[j] = '\0';
                                }
                                rectfill(screen,642,234,(632+xrec),(224+yrec), makecol(255,255,255));
                                position_lettre2=0;
                            }
                        }
                    }
                    textout_ex(screen, font, nom_perso2, 652, 244, makecol(0, 0, 0), -1);
                }
            }

            ////BULLE 3/////
            if(current_phrase == 6 && swap4 == false ){
                swap4 = true;
                xrec = 0;
                yrec =0;
                while (!key[KEY_ENTER]) {
                    circle = false;
                    if(key[KEY_UP]){
                        pos = 257;
                        circle = true;
                    }
                    if(key[KEY_DOWN]){
                        circle = true;
                        pos = 277;
                    }
                    if ( xrec<100){
                        rectfill(screen,237,239,(247+xrec),(249+yrec), 0);
                        rectfill(screen,242,244,(242+xrec),(244+yrec), makecol(255,255,255));
                        rest(10);
                        yrec++;
                        xrec= xrec+2;
                    }
                    if(xrec ==100){
                        if(circle == true){
                            rectfill(screen,242,244,(242+xrec),(244+yrec), makecol(255,255,255));
                        }
                        textprintf_ex(screen,font,262,254,0,-1,"OUI");
                        textprintf_ex(screen,font,262,274,0,-1,"NON");
                        circlefill(screen,252,pos,2,0);
                    }
                }

                if(pos == 257){
                    flag = true;
                }

            }
            if(current_phrase == 7){
                while(key[KEY_ENTER]){
                    rest(1);
                }
                allegro_exit();
            }



            clear_to_color(page, makecol(82,107,231));
            blit(chen, page, 0, 0, 192, 144, SCREEN_W, SCREEN_H);
            blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            textout_ex(screen, font, display, 232, 544, makecol(0, 0, 0), -1);


            rest(25);

        }

    }


    strcpy(player1->name,nom_perso1);
    strcpy(player2->name,nom_perso2);
}