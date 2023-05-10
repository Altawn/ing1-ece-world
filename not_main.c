#include "not_main.h"

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
            sprintf(nomfichier, "Taureau/90x95-toreau%d.bmp", i + 1);
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
    int pas  = 550;

    //clear_bitmap(page);

    for (int i = 0; i < NPOK; i++)
    {
        draw_sprite(page, tab_rand[i]->img[tab_rand[i]->frame_act], tab_rand[i]->posx, pas);
        tab_rand[i]->frame_act++;
        if(tab_rand[i]->frame_act >= NIMAGE) tab_rand[i]->frame_act = 0;
        pas = pas+40;
    }

    rest(100);
    //blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    pas = 0;
}

int PI_depla_pok(Pokemon * tab_rand[NPOK])
{
    int flag_PI  = 0;

    for (int i = 0; i < NPOK; ++i)
    {
        tab_rand[i]->posx = tab_rand[i]->posx + tab_rand[i]->depx;

        if(tab_rand[i]->posx%25 == 0)
        {
            tab_rand[i]->depx = rand()%50 + 3;
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