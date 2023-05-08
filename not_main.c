#include "not_main.h"

/*Pokemon init_magicarpe()
{
    char nomfichier[256];

    Pokemon Magicarpe =
            {
                    .tx = 80,
                    .ty = 95,
                    .posx = 0,
                    .posy = 0,
                    .depx = 0,
                    .depy = 0,
                    .frame_act = 0,
                    .compteur = 0
            };

    for (int i = 0; i < NIMAGE; ++i) {
        sprintf(nomfichier, "80x95-Magicarpe%d.bmp", i + 1);

        Magicarpe.img[i] = load_bitmap(nomfichier, NULL);
        if (!Magicarpe.img[i]) {
            allegro_message("Fichier %s non existant", nomfichier);
            exit(EXIT_FAILURE);

        }
    }
    return Magicarpe;
}*/

/*Pokemon init_papillusion()
{
    Pokemon Papillusion =
            {
                    .im_1 = load_bitmap("80x95-Papillon.bmp",  NULL),
                    .im_2 = load_bitmap("80x95-Papillon2.bmp",  NULL),
                    .im_3 = load_bitmap("80x95-Papillon3.bmp", NULL),
                    .im_4 = load_bitmap("80x95-Papillon4.bmp", NULL),
                    .im_5 = load_bitmap("80x95-Papillon5.bmp", NULL),
                    .tx = 0,
                    .ty = 0,
                    .posx = 0,
                    .posy = 0,
                    .depx = 0,
                    .depy = 0
            };
    if(!Papillusion.im_1 || !Papillusion.im_2 || !Papillusion.im_3 || !Papillusion.im_4 || !Papillusion.im_5)
    {
        allegro_message("pb chargement image Papillusion");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return Papillusion;
}
*/

void init_allegro()
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

Pokemon * init_pokemon(int tx, int ty, int xdx, int posx, int posy, int pok, int depx, int tmpimg)
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

void remp_tab_pok(Pokemon * tab_rand[NPOK])
{
    tab_rand[0] = init_pokemon(80, 95, 1, 0,   0, 0, 1, 5);
    tab_rand[1] = init_pokemon(80, 95, 1, 0, 100, 1, 1, 5);
    tab_rand[2] = init_pokemon(90, 95, 1, 0, 200, 2, 1, 5);
    tab_rand[3] = init_pokemon(80, 95, 1, 0, 300, 3, 1, 5);
    tab_rand[4] = init_pokemon(80, 95, 1, 0, 400, 4, 1, 5);
}

void Actu_Pok(Pokemon * random)
{
    //Enchainement images
    random->cptimg++;
    if(random->cptimg >= random->tmpimg)
    {
        random->cptimg = 0;
        random->frame_act++;
        if (random->frame_act >= NIMAGE) random->frame_act = 0;
    }

    //Calcul nouvelle position
    random->compdepx++;
    if(random->compdepx >= random->xdx)
    {
        random->compdepx = 0;
        random->posx = random->posx + random->depx;
    }
}

void Tab_Actu_Pok(Pokemon * tab_rand[NPOK])
{
    for (int i = 0; i < NPOK; ++i)
    {
        Actu_Pok(tab_rand[i]);
    }
}

/*void chargerBITMAP(Sequence * anim)
{
*/