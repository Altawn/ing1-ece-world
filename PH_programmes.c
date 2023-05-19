#include "PH_programmes.h"

void Pari_Hippique(int p_gagnant_j1, int p_gagnant_j2, int tickets_j1, int tickets_j2)
{

    //Autres variables + structures
    Pokemon * tab_pok[NPOK];

    BITMAP * page = NULL;
    BITMAP * decor = NULL;
    BITMAP * dialogue = NULL;

    int flag = 0;
    int arrivee = 0;
    int y_cir = 579;
    int passe = 25;
    int choix_j1;
    int choix_j2;
    int blanc = makecol(255, 255, 255);
    int i;

    char pok_gagnant[50];
    char * debut[50] =
            {
                    "1. Magicarpe (poisson rouge)",
                    "2. Papilusion (papillon geant)",
                    "3. Tauros (taureau)",
                    "4. Ponita (cheval en feu)",
                    "5. Rondoudou (petite boule rose)"
            };

    srand(time(NULL));

    //init du tableau de pointeurs de structures de type pokemon nommé tab_pok
    PI_remp_tab_pok(tab_pok);

    //Init double buffer + decor
    page = create_bitmap(1024, 768); clear_bitmap(page);
    if(!page) allegro_message("Erreur creation page");

    decor = load_bitmap("le_vrai.bmp", NULL);
    if(!decor) allegro_message("Pas de fond d'ecran");

    dialogue = load_bitmap("Dialogue_Pokemon.bmp", NULL);
    if(!page) allegro_message("Erreur creation dialogue");

    //Dialogue d'entree
    PI_entree_jeu(decor, page, dialogue);

    //Cache la phrase de continuation avant le prochain sous-programme
    rest(200);
    rectfill(decor, 375 - strlen("Appuyer sur la barre espace pour continuer...") / 2, 690, 720, 700,makecol(255, 255, 255));
    rest(200);

    //Affichage de la liste des pokemons combattants
    PI_affichage_liste(decor, debut, page);

    //Transition entre les deux sous-programmes
    circlefill(decor, 750, 579, 3, 0);
    blit(decor, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    //Recuperation des paris
    choix_j1 = PI_navigation(decor, page, y_cir, passe, flag, blanc);
    rectfill(decor,225,545,350,560, blanc);
    textprintf_ex
            (
                    decor,
                    font,
                    250 - strlen("Joueur 1") / 2,
                    550,
                    makecol(0, 0, 255),
                    -1,
                    "Joueur 2"
            );
    rest(200);
    choix_j2 = PI_navigation(decor, page, y_cir, passe, flag, blanc);

    //Suppression du dialogue et affichage de la course
    clear(decor);
    decor = load_bitmap("le_vrai.bmp", NULL);
    blit(decor, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    //Boucle d'evenements
    while (!key[KEY_ESC] && arrivee == 0)
    {
        // Effacer buffer en appliquant decor
        blit(decor,page,0,0,0,0,SCREEN_W,SCREEN_H);

        //Animation des pokemons
        PI_anim_pok(tab_pok, page); //-> draw_sprite(page, tab_rand[i]->img[tab_rand[i]->frame_act], tab_rand[i]->posx, pas);

        //Affichage du buffer mis à jour
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        //Deplacement des pokemons
        arrivee = PI_depla_pok(tab_pok);
    }

    clear(screen);

    //Transformation du pokemon gagnant (int -> char)
    PI_pok_gagnant(pok_gagnant, arrivee);

    //Affichage du pokemon victorieux et du resultat du pari
    PI_print_gagnant(decor, dialogue, pok_gagnant, choix_j1, arrivee, p_gagnant_j1, p_gagnant_j2, choix_j2, tickets_j1, tickets_j2);

    //Libere la memoire
    for (i = 0; i < NPOK; ++i)
    {
        free(tab_pok[i]);
    }
}

void PI_init_allegro()
{
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0)!=0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

Pokemon * PI_init_pokemon(int tx, int ty, int xdx, int posx, int posy, int pok, int depx, int tmpimg)
{
    Pokemon * random;
    char nomfichier[256];
    random = (Pokemon *) malloc(sizeof(Pokemon));

    random->posx = posx;  random->posy = posy;
    random->xdx = xdx;    random->depx = depx;
    random->compdepx = 0; random->tmpimg = tmpimg;
    random->tx = tx;      random->ty = ty;
    random->pok = pok;    random->frame_act = 0;
    random->cptimg = 0;

    if(random->pok == 0)
    {
        for (int i = 0; i < NIMAGE; ++i)
        {
            sprintf(nomfichier, "Magicarpe/80x95-Magicarpe%d.bmp", i + 1);
            random->img[i] = load_bitmap(nomfichier, NULL);
            if (!random->img[i])
            {
                allegro_message("Fichier %s non existant", nomfichier);
                exit(EXIT_FAILURE);
            }

        }
        memset(nomfichier,'\0',50);
    }

    else if(random->pok == 1)
    {
        for (int i = 0; i < NIMAGE; ++i)
        {
            sprintf(nomfichier, "Papilusion/80x95-Papillon%d.bmp", i + 1);
            random->img[i] = load_bitmap(nomfichier, NULL);
            if (!random->img[i])
            {
                allegro_message("Fichier %s non existant", nomfichier);
                exit(EXIT_FAILURE);
            }

        }
        memset(nomfichier,'\0',50);
    }

    else if(random->pok == 2)
    {
        for (int i = 0; i < NIMAGE; ++i)
        {
            sprintf(nomfichier, "Taureau/80x95-toreau%d.bmp", i + 1);
            random->img[i] = load_bitmap(nomfichier, NULL);
            if (!random->img[i])
            {
                allegro_message("Fichier %s non existant", nomfichier);
                exit(EXIT_FAILURE);
            }

        }
        memset(nomfichier,'\0',50);
    }

    else if(random->pok == 3)
    {
        for (int i = 0; i < NIMAGE; ++i)
        {
            sprintf(nomfichier, "Ponita/90x95-ponita%d.bmp", i + 1);
            random->img[i] = load_bitmap(nomfichier, NULL);
            if (!random->img[i])
            {
                allegro_message("Fichier %s non existant", nomfichier);
                exit(EXIT_FAILURE);
            }

        }
        memset(nomfichier,'\0',50);
    }

    else
    {
        for (int i = 0; i < NIMAGE; ++i)
        {
            sprintf(nomfichier, "Rondoudou/60x55-rondoudou%d.bmp", i + 1);
            random->img[i] = load_bitmap(nomfichier, NULL);
            if (!random->img[i])
            {
                allegro_message("Fichier %s non existant", nomfichier);
                exit(EXIT_FAILURE);
            }

        }
        memset(nomfichier,'\0',50);
    }
    return random;
}

void PI_remp_tab_pok(Pokemon * tab_rand[NPOK])
{
    tab_rand[0] = PI_init_pokemon(80, 95, 1, 0,   0, 0, 10, 5);
    tab_rand[1] = PI_init_pokemon(80, 95, 1, 0, 0, 1, 10, 5);
    tab_rand[2] = PI_init_pokemon(90, 95, 1, 0, 0, 2, 10, 5);
    tab_rand[3] = PI_init_pokemon(80, 95, 1, 0, 0, 3, 10, 5);
    tab_rand[4] = PI_init_pokemon(80, 95, 1, 0, 0, 4, 10, 5);
}

void PI_anim_pok(Pokemon * tab_rand[NPOK], BITMAP * page)
{
    int pas  = 150;

    for (int i = 0; i < NPOK; i++)
    {
        draw_sprite(page, tab_rand[i]->img[tab_rand[i]->frame_act], tab_rand[i]->posx, pas);
        tab_rand[i]->frame_act++;
        if(tab_rand[i]->frame_act >= NIMAGE) tab_rand[i]->frame_act = 0;

        if(tab_rand[i]->pok == 0 || tab_rand[i]->pok == 1)
        {
            pas = pas+96;
        }
        if(tab_rand[i]->pok == 2 || tab_rand[i]->pok == 3)
        {
            pas = pas + 110;
        }
    }

    rest(100);
}

int PI_depla_pok(Pokemon * tab_rand[NPOK])
{
    int flag_PI  = 0;

    for (int i = 0; i < NPOK; ++i)
    {
        tab_rand[i]->posx = tab_rand[i]->posx + tab_rand[i]->depx;

        if(tab_rand[i]->posx%25 == 0)
        {
            tab_rand[i]->depx = rand()%10 + 5;
        }

        if (tab_rand[i]->posx >= 1024)
        {
            flag_PI = tab_rand[i]->pok + 1 ;
        }
    }
    return flag_PI;
}

void PI_pok_gagnant(char * winner, int pok_gagnant)
{

    if(pok_gagnant == 1)
        strcpy(winner, "magicarpe");

    else if(pok_gagnant == 2)
        strcpy(winner, "papilusion");

    else if(pok_gagnant == 3)
        strcpy(winner, "tauros");

    else if(pok_gagnant == 4)
        strcpy(winner, "ponita");

    else
        strcpy(winner, "rondoudou");

}

void PI_affichage_liste(BITMAP * decor, char * liste[50], BITMAP * page)
{
    int def = 0;

    for (int k = 0; k < NPOK; ++k)
    {
        def = def + 25;
        textprintf_ex
                (
                        decor,
                        font,
                        375 - strlen(liste[k]) / 2,
                        550 + def,
                        makecol(0, 0, 0),
                        -1,
                        "%s", liste[k]
                );
        blit(decor, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    }
}

void PI_entree_jeu(BITMAP * decor, BITMAP * page, BITMAP * dialogue)
{
    while(!key[KEY_SPACE])
    {
        blit(decor, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(decor, dialogue, 125 + 12, 500);
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        textprintf_ex
                (
                        decor,
                        font,
                        375 - strlen("Joueurs, quel pokemon choisissez-vous ?") / 2,
                        550,
                        makecol(0, 0, 0),
                        -1,
                        "Joueurs, quel pokemon choisissez-vous ?"
                );
        textprintf_ex
                (
                        decor,
                        font,
                        250 - strlen("Joueur 1") / 2,
                        550,
                        makecol(255, 0, 0),
                        -1,
                        "Joueur 1"
                );
        textprintf_ex
                (
                        decor,
                        font,
                        375 - strlen("Appuyer sur la barre espace pour continuer...") / 2,
                        690,
                        makecol(0, 0, 0),
                        -1,
                        "Appuyer sur la barre espace pour continuer..."
                );
    }
}

int PI_choix_pok(int y_cir)
{
    if(y_cir == 679) return 5;

    else if(y_cir == 654) return 4;

    else if(y_cir == 629) return 3;

    else if(y_cir == 604) return 2;

    else return 1;

}

int PI_navigation(BITMAP*decor, BITMAP*page, int y_cir, int passe, int flag, int blanc)
{
    int choix_j;

    while(!key[KEY_SPACE] && flag == 0)
    {
        flag = 0;
        blit(decor, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        if(key[KEY_UP] && y_cir > 579)
        {
            circlefill(decor, 750, y_cir, 3, blanc);
            y_cir = y_cir - passe;
            circlefill(decor, 750, y_cir, 3, 0);
            readkey();
        }
        if(key[KEY_DOWN] && y_cir < 679)
        {
            circlefill(decor, 750, y_cir, 3, blanc);
            y_cir = y_cir + passe;
            circlefill(decor, 750, y_cir, 3, 0);
            flag = 0;
            rest(200);
            readkey();
        }

        if(key[KEY_ENTER])
        {
            choix_j = PI_choix_pok(y_cir);
            circlefill(decor, 750, y_cir, 3, blanc);
            flag = 1;
        }

    }

    return choix_j;
}

void PI_print_gagnant(BITMAP*decor, BITMAP*dialogue, char*pok_gagnant, int choix_j1, int arrivee, int p_gagnant_j1, int p_gagnant_j2, int choix_j2, int tickets_j1, int tickets_j2)
                      {
                          while(!key[KEY_ENTER])
                          {
                              blit(decor, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                              draw_sprite(decor, dialogue, 125+12, 500);
                              textprintf_ex
                                      (
                                              decor,
                                              font,
                                              53 + 375 - strlen("la gagnant est Magic")/2,
                                              579,
                                              makecol(0, 0, 0),
                                              -1,
                                              " Le gagnant est %s", pok_gagnant
                                      );
                              textprintf_ex
                                      (
                                              decor,
                                              font,
                                              375 - strlen("Appuyer sur la barre espace pour continuer...") / 2,
                                              690,
                                              makecol(0, 0, 0),
                                              -1,
                                              "Appuyer sur la barre entree pour quitter..."
                                      );
                              if(choix_j1 == arrivee)
                              {
                                  textprintf_ex
                                          (
                                                  decor,
                                                  font,
                                                  340 - strlen("Bravo au joueur 1 pour avoir parie sur le bon poulin" )/2,
                                                  610,
                                                  makecol(0, 0, 0),
                                                  -1,
                                                  "Bravo au joueur 1 pour avoir parie sur le bon poulin"
                                          );
                                  p_gagnant_j1++;
                                  tickets_j2--;

                                  readkey();
                              }
                              if(choix_j2 == arrivee)
                              {
                                  textprintf_ex
                                          (
                                                  decor,
                                                  font,
                                                  340 - strlen("Bravo au joueur 1 pour avoir parie sur le bon poulin" )/2,
                                                  610,
                                                  makecol(0, 0, 0),
                                                  -1,
                                                  "Bravo au joueur 2 pour avoir parie sur le bon poulin"
                                          );
                                  p_gagnant_j2++;
                                  tickets_j1--;
                                  readkey();
                              }
                              if(choix_j2 == arrivee && choix_j1 == arrivee)
                              {
                                  textprintf_ex
                                          (
                                                  decor,
                                                  font,
                                                  53 + 375 - strlen("Bravo a nos deux joueurs pour avoir parie sur le bon poulin" )/2,
                                                  610,
                                                  makecol(0, 0, 0),
                                                  -1,
                                                  "Bravo a nos deux joueurs pour avoir parie sur le bon poulin"
                                          );
                                  p_gagnant_j1++;
                                  p_gagnant_j2++;
                                  readkey();
                              }
                              if(choix_j2 != arrivee && choix_j1 != arrivee)
                              {
                                  textprintf_ex
                                          (
                                                  decor,
                                                  font,
                                                  20 + 375 - strlen("Vous ferez mieux une prochaine fois..." )/2,
                                                  610,
                                                  makecol(0, 0, 0),
                                                  -1,
                                                  "Vous ferez mieux une prochaine fois..."
                                          );
                                  tickets_j1--;
                                  tickets_j2--;
                                  readkey();
                              }
                          }
                      }
