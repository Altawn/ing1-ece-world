#include "head.h"

ballons * TB_init_struct(int posx, int posy, int depx, int depy, int type, int attrape)
{
    ballons * random;
    char nomFichier[50];
    random = (ballons *) malloc(sizeof(ballons));

    random->posx = posx; random->posy = posy;
    random->depx = depx; random->depy = depy;
    random->type = type; random->attrape = attrape;

    if(random->type == 0)
    {
        sprintf(nomFichier, "Tir_Ballons/Pokemons/articuno.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else if(random->type == 1)
    {
        sprintf(nomFichier, "Tir_Ballons/Pokemons/butterfree.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else if(random->type == 2)
    {
        sprintf(nomFichier, "Tir_Ballons/Pokemons/golbat.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else if(random->type == 3)
    {
        sprintf(nomFichier, "Tir_Ballons/Pokemons/magnemite.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else if(random->type == 4)
    {
        sprintf(nomFichier, "Tir_Ballons/Pokemons/mew.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else if(random->type == 5)
    {
        sprintf(nomFichier, "Tir_Ballons/Pokemons/weezing.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else
    {
        sprintf(nomFichier, "Tir_Ballons/Pokemons/zubat.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }
    return random;
}

void TB_remp_tab_pok(ballons * taballons[7])
{
    taballons[0] = TB_init_struct(rand()%1024, rand()%768, rand()%7 + 1,  rand()%7 + 1,  0, 0);
    taballons[1] = TB_init_struct(rand()%1024, rand()%768, rand()%6 + 1,  rand()%6 + 1,  1, 0);
    taballons[2] = TB_init_struct(rand()%1024, rand()%768, rand()%7 + 1,  rand()%7 + 1,  2, 0);
    taballons[3] = TB_init_struct(rand()%1024, rand()%768, rand()%10 + 1, rand()%10 + 1, 3, 0);
    taballons[4] = TB_init_struct(rand()%1024, rand()%768, rand()%12 + 1, rand()%12 + 1, 4, 0);
    taballons[5] = TB_init_struct(rand()%1024, rand()%768, rand()%3 + 1,  rand()%3 + 1,  5, 0);
    taballons[6] = TB_init_struct(rand()%1024, rand()%768, rand()%15 + 1, rand()%15 + 1, 6, 0);
}

void TB_anim_pok(ballons * pokemons[7], BITMAP*buffer)
{
    for (int i = 0; i < 7; ++i)
    {
        draw_sprite(buffer, pokemons[i]->poke, pokemons[i]->posx,pokemons[i]->posy);

        if((pokemons[i]->posx - pokemons[i]->poke->w/8 < 0 && pokemons[i]->depx < 0) || ((pokemons[i]->posx + pokemons[i]->poke->w > SCREEN_W) && pokemons[i]->depx > 0))
            pokemons[i]->depx = pokemons[i]->depx * -1;

        if((pokemons[i]->posy - pokemons[i]->poke->h/8 < 0 && pokemons[i]->depy < 0) || ((pokemons[i]->posy + pokemons[i]->poke->h > SCREEN_H) && pokemons[i]->depy > 0))
            pokemons[i]->depy = pokemons[i]->depy * -1;

        pokemons[i]->posx = pokemons[i]->posx + pokemons[i]->depx;
        pokemons[i]->posy = pokemons[i]->posy + pokemons[i]->depy;
    }
}

void TB_click_souris(ballons * pokemons[7], int available_poke)
{
    for (int i = 0; i < 7; ++i) {
        if(
                (mouse_x < pokemons[i]->posx + pokemons[i]->poke->w)
                && (mouse_x > pokemons[i]->posx)
                && (mouse_b & 1)
                && (available_poke == 1)
                && (mouse_y < pokemons[i]->posy + pokemons[i]->poke->h)
                && (mouse_y > pokemons[i]->posy))
        {
            pokemons[i]->posx = -100;
            pokemons[i]->posy = -100;
            pokemons[i]->depx = 0;
            pokemons[i]->depy = 0;
            pokemons[i]->attrape = 1;
        }
    }
}

int TB_condition_attrap(BITMAP* pokeball[2], BITMAP*buffer)
{

    int available_poke = 0;
    //Animation pokeball ferme + mise a zero de la variable available_poke
    if(mouse_b & 1)
    {
        draw_sprite(buffer, pokeball[1], mouse_x - pokeball[1]->w/2, mouse_y- pokeball[1]->h/2);
        available_poke = 0; //Du temps que la pokeball est ferme, nous en pouvons plus attraper de pokemons  -->  il faut dont relacher le click gauche pour essayer d' en attraper de nouveau
    }


    //condition pour que la variable available_poke = 1
    if(!(mouse_b & 1))
    {
        available_poke = 1;
    }

    return available_poke;
}

void TB_entree_jeu(BITMAP* buffer, BITMAP* background, BITMAP* dialogue, int i)
{
    while(!key[KEY_SPACE])
    {
        blit(background, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        background = load_bitmap("Tir_Ballons/fond_ballons.bmp", NULL);
        draw_sprite(background, dialogue, 125 + 12, 500);

        textprintf_ex
                (
                        background,
                        font,
                        425 - strlen("Joueur 1, c'est a toi :") / 2,
                        550,
                        makecol(0, 0, 0),
                        -1,
                        "Joueur %d, c'est a toi :", i
                );
        textprintf_ex
                (
                        background,
                        font,
                        330 - strlen("Le but est d'attraper tous les pokemons en un temps minimal") / 2,
                        590,
                        makecol(0, 0, 0),
                        -1,
                        "Le but est d'attraper tous les pokemons en un temps minimal"
                );
        textprintf_ex
                (
                        background,
                        font,
                        420 - strlen("Ton arme sera ton clic gauche") / 2,
                        630,
                        makecol(0, 0, 0),
                        -1,
                        "Ton arme sera ton clic gauche"
                );
        textprintf_ex
                (
                        background,
                        font,
                        375 - strlen("Appuyer sur la barre espace pour continuer...") / 2,
                        690,
                        makecol(0, 0, 0),
                        -1,
                        "Appuyer sur la barre espace pour continuer..."
                );
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}

double TB_jeu(BITMAP* buffer, BITMAP* background, BITMAP* dialogue, ballons* pokemons[7], BITMAP* pokeball[2])
{
    int compteur = 0;
    int available_poke = 0;
    int i;
    int flag = 0;

    //initiation des pokemons
    TB_remp_tab_pok(pokemons);

//debut du jeu
    clear(background);
    background = load_bitmap("Tir_Ballons/fond_ballons.bmp", NULL);
    blit(background, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(buffer , screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    double time_spent = 0; clock_t begin = clock();

    while(!key[KEY_ESC] && flag == 0)
    {
        //suppression des anciens sprites en reappliquant le background sur le buffer
        blit(background, buffer,0,0,0,0,SCREEN_W,SCREEN_H);

        //apparition des pokemons
        TB_anim_pok(pokemons, buffer);

        //affichage pokeball ouverte
        draw_sprite(buffer, pokeball[0], mouse_x - pokeball[0]->w/2, mouse_y- pokeball[0]->h/2);

        //test attraper pokemon
        TB_click_souris(pokemons, available_poke);

        //Si la pokeball reste appuyé, nous ne pouvons plus attraper de pokemons
        available_poke = TB_condition_attrap(pokeball, buffer);

        //envoie des infos à l'écran
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        //conditions de jeu (ballons changent de trajectoire a tt moment)²
        for (i = 0; i < 7; ++i)
        {
            if(pokemons[i]->attrape == 0 && compteur%30 == 0)
            {
                do
                {
                    pokemons[i]->depx = rand()%35 - 17;
                    pokemons[i]->depy = rand()%35 - 17; //35 - 17
                }while(pokemons[i]->depx == 0 && pokemons[i]->depy == 0);
            }
        }

        rest(20);
        compteur++;

        if(pokemons[0]->attrape == 1
           &&pokemons[1]->attrape == 1
           &&pokemons[2]->attrape == 1
           &&pokemons[3]->attrape == 1
           &&pokemons[4]->attrape == 1
           &&pokemons[5]->attrape == 1
           &&pokemons[6]->attrape == 1)
            flag = 1;
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    while(!key[KEY_SPACE])
    {
        blit(background, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(background, dialogue, 137, 500);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        textprintf_ex
                (
                        background,
                        font,
                        425 - strlen("Ton temps est de 0.00 secondes") / 2,
                        610,
                        makecol(0, 0, 0),
                        -1,
                        "Ton temps est de %.2f secondes", time_spent
                );
        textprintf_ex
                (
                        background,
                        font,
                        375 - strlen("Appuyer sur la barre espace pour continuer...") / 2,
                        690,
                        makecol(0, 0, 0),
                        -1,
                        "Appuyer sur la barre espace pour continuer..."
                );
    }

    return time_spent;
}

void TB_resultats(double tps_j1, double tps_j2, BITMAP* background, BITMAP* buffer, BITMAP* dialogue, t_player* player,t_player* player2)
{
    while(!key[KEY_ENTER])
    {
        blit(background, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        background = load_bitmap("Tir_Ballons/fond_ballons.bmp", NULL);
        draw_sprite(background, dialogue, 137, 500);

        if(tps_j1 < tps_j2)
        {
            textprintf_ex
                    (
                            background,
                            font,
                            410 - strlen("Bravo au joueur 1 ! Tu as gagne") / 2,
                            625,
                            makecol(0, 0, 0),
                            -1,
                            "Bravo au joueur 1 ! Tu as gagne"
                    );
            player2->ticket--;
        }

        else if(tps_j2 < tps_j1)
        {
            textprintf_ex
                    (
                            background,
                            font,
                            410 - strlen("Bravo au joueur 2 ! Tu as gagne") / 2,
                            625,
                            makecol(0, 0, 0),
                            -1,
                            "Bravo au joueur 2 ! Tu as gagne"
                    );
            player->ticket--;
        }
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}

void Tir_Ballons(t_player* player,t_player* player2)
{
    double tps_j1 = 0;
    double tps_j2 = 0;

    ballons * pokemons[7];
    BITMAP * background = NULL;
    BITMAP * buffer = NULL;
    BITMAP * pokeball[2] = {0, 0};
    BITMAP * dialogue = NULL;

    srand(time(NULL));

//init bitmaps
    buffer = create_bitmap(1024, 768); clear_bitmap(buffer);
    if(!buffer) allegro_message("Erreur creation page");

    background = load_bitmap("Tir_Ballons/fond_ballons.bmp", NULL);
    if(!background) allegro_message("Pas de fond d'ecran");

    pokeball[0] = load_bitmap("Tir_Ballons/open_pokeball1.bmp", NULL);
    if(!pokeball[0]) allegro_message("Pas de pokeball 1");

    pokeball[1] = load_bitmap("Tir_Ballons/closed_pokeball1.bmp", NULL);
    if(!pokeball[1]) allegro_message("Pas de pokeball 2");

    dialogue = load_bitmap("Tir_Ballons/dialogue_pokemon.bmp", NULL);
    if(!dialogue) allegro_message("Pas de dialogue");

    //Definition des regles du jeu pour j1
    TB_entree_jeu(buffer, background, dialogue, 1);

    //joueur 1
    tps_j1 = TB_jeu(buffer,background,dialogue,pokemons,pokeball);

    //transition
    rest(20);
    rectfill(background,410,600,450,620,makecol(255,255,255));

    //transition entre les deux joueurs
    TB_entree_jeu(buffer,background,dialogue,2);

    //Definition des regles du jeu pour j2
    tps_j2 = TB_jeu(buffer,background,dialogue,pokemons,pokeball);

    //transition
    rest(20);

    //affichage des resultats
    TB_resultats(tps_j1, tps_j2, background, buffer, dialogue, player, player2);
}