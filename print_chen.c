#include "head.h"

void print_chen(BITMAP *page) {

    char nom_perso[256] = "";
    int position_lettre = 0;

    bool swap1 = false;
    bool swap2 = false;

    bool circle = false;
    int pos = 113;
    int i = 0;
    int yrec =0;
    int xrec=0;
    char* texte[] = {"Bonjour je suis le professeur chen ","Tu vas bien?","comment t'appelles tu?"};
    bool text = true;
    bool flag = false;
    BITMAP *chen;
    chen = load_bitmap("../pr_chen1.bmp", NULL);
    int current_phrase = 0;
    char display[256]; // Chaîne de caractères à afficher
    memset(display, 0, sizeof(display)); // Initialisation de la chaîne de caractères à afficher


    while (!flag) {


        if (text) {
            if (i < strlen(texte[current_phrase]) && current_phrase <=2) {
                display[i] = texte[current_phrase][i];
                i++;
            }

            else {
                while (!key[KEY_ENTER]) {
                    rest(10);
                }
                rest(500);
                memset(display, 0, sizeof(display));
                i = 0;
                if(current_phrase <4){
                    current_phrase = current_phrase + 1;
                }
            }

            ///////////BULLE 1///////

            if(current_phrase == 2 && swap1 == false ){
                swap1 = true;
                while (!key[KEY_ENTER]) {
                    circle = false;
                    if(key[KEY_UP]){
                        pos = 113;
                        circle = true;
                    }
                    if(key[KEY_DOWN]){
                        circle = true;
                        pos = 133;
                    }
                    if ( xrec<100){
                        rectfill(screen,45,95,(55+xrec),(105+yrec), 0);
                        rectfill(screen,50,100,(50+xrec),(100+yrec), makecol(255,255,255));
                        rest(10);
                        yrec++;
                        xrec= xrec+2;
                    }
                    if(xrec ==100){
                        if(circle == true){
                            rectfill(screen,50,100,(69),(90+yrec), makecol(255,255,255));
                        }
                        textprintf_ex(screen,font,70,110,0,-1,"OUI");
                        textprintf_ex(screen,font,70,130,0,-1,"NON");
                        circlefill(screen,60,pos,2,0);
                    }
                }
            }

            ///////// BULLE 2///////
            if(current_phrase == 3 && swap2 == false ){
                swap2 = true;
                while (!key[KEY_ENTER]) {
                    if ( xrec<150){
                        rectfill(screen,445,85,(455+xrec),(95+yrec), 0);
                        rectfill(screen,450,90,(450+xrec),(90+yrec), makecol(255,255,255));
                        rest(10);
                        yrec++;
                        xrec= xrec+6;
                    }
                    if (keypressed()) {
                        int key_code = readkey();
                        char lettre_nom = key_code & 0xFF;
                        if (lettre_nom >= ' ' && lettre_nom <= '~' && position_lettre < 255) {
                            nom_perso[position_lettre++] = lettre_nom;
                            nom_perso[position_lettre] = '\0';
                        }
                        if(key[KEY_BACKSPACE]){
                            if(position_lettre > 0){
                                for (int j = position_lettre; j != -1; j--) {
                                    nom_perso[j] = '\0';
                                }
                                rectfill(screen,450,90,(440+xrec),(80+yrec), makecol(255,255,255));
                                position_lettre=0;
                            }
                        }
                    }
                    textout_ex(screen, font, nom_perso, 460, 100, makecol(0, 0, 0), -1);
                }
            }

            clear_bitmap(page);
            blit(chen, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            textout_ex(screen, font, display, 40, 400, makecol(0, 0, 0), -1);

            rest(25);


            if (key[KEY_1_PAD]) {
                flag = true;
            }
        }

    }
}