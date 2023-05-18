#include "not_main.h"

void TB_init_allegro()
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

ballons * TB_init_struct(int posx, int posy, int depx, int depy, int type)
{
    ballons * random;
    char nomFichier[50];
    random = (ballons *) malloc(sizeof(ballons));

    random->posx = posx; random->posy = posy;
    random->depx = depx; random->depy = depy;
             random->type = type;

    if(random->type == 0)
    {
        sprintf(nomFichier, "articuno.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else if(random->type == 1)
    {
        sprintf(nomFichier, "butterfree.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else if(random->type == 2)
    {
        sprintf(nomFichier, "golbat.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else if(random->type == 3)
    {
        sprintf(nomFichier, "magnemite.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else if(random->type == 4)
    {
        sprintf(nomFichier, "mew.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else if(random->type == 5)
    {
        sprintf(nomFichier, "weezing.bmp");
        random->poke = load_bitmap(nomFichier, NULL);
        if (!random->poke)
        {
            allegro_message("Fichier %s non existant", nomFichier);
            exit(EXIT_FAILURE);
        }
    }

    else
    {
        sprintf(nomFichier, "zubat.bmp");
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
    taballons[0] = TB_init_struct(rand()%1024, rand()%768, rand()%7 + 1,  rand()%7 + 1,  0);
    taballons[1] = TB_init_struct(rand()%1024, rand()%768, rand()%6 + 1,  rand()%6 + 1,  1);
    taballons[2] = TB_init_struct(rand()%1024, rand()%768, rand()%7 + 1,  rand()%7 + 1,  2);
    taballons[3] = TB_init_struct(rand()%1024, rand()%768, rand()%10 + 1, rand()%10 + 1, 3);
    taballons[4] = TB_init_struct(rand()%1024, rand()%768, rand()%12 + 1, rand()%12 + 1, 4);
    taballons[5] = TB_init_struct(rand()%1024, rand()%768, rand()%3 + 1,  rand()%3 + 1,  5);
    taballons[6] = TB_init_struct(rand()%1024, rand()%768, rand()%15 + 1, rand()%15 + 1, 6);
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
            pokemons[i]->posx = -10;
            pokemons[i]->posy = -10;
            pokemons[i]->depx = 0;
            pokemons[i]->depy = 0;
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