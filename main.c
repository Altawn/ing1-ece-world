#include <stdio.h>
#include <allegro.h>

typedef struct
{
    BITMAP * im_1;
    BITMAP * im_2;
    BITMAP * im_3;
    BITMAP * im_4;
    BITMAP * im_5;
    int posx, posy;
    int tx, ty;
    int depx, depy;
}Pokemon, *Pok;

Pok init_magicarpe();
void init_allegro();

int main()
{
    //Supposant qu'on prend les deux variables pari gagnant du joueur
    int pari_gagnant_j1 = 0;
    int pari_gagnant_j2 = 0;

    //Autres variables
    Pok Magicarpe;
    BITMAP * page = NULL;

    //Initialisation Allegro + structures
    init_allegro();
    //Magicarpe = init_magicarpe();
    BITMAP * test = load_bitmap("80x95-Magicarpe.bmp", NULL);

    //Double buffer
    page = create_bitmap(800, 600);
    clear_bitmap(page);
    if(!page) allegro_message("Erreur creation page");

    draw_sprite(page, test, 0, 0);
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    //Boucle d'evenements
    while (!key[KEY_ESC])
    {
        clear_bitmap(page);
        clear_to_color(page, makecol(255, 255, 255));
        draw_sprite(page,test,0,0);
        blit(page,screen,0, 0, 0, 0, SCREEN_W,SCREEN_H);
    }

    allegro_exit();
    return 0;
}END_OF_MAIN()

Pok init_magicarpe()
{
    Pokemon * Magicarpe = 0;

    Magicarpe->im_1 = load_bitmap("80x95-Magicarpe.bmp",  NULL);
    Magicarpe->im_2 = load_bitmap("80x95-Magicarpe2.bmp", NULL);
    Magicarpe->im_3 = load_bitmap("80x95-Magicarpe3.bmp", NULL);
    Magicarpe->im_4 = load_bitmap("80x95-Magicarpe4.bmp", NULL);
    Magicarpe->im_5 = load_bitmap("80x95-Magicarpe5.bmp", NULL);

    if(!Magicarpe->im_1 || !Magicarpe->im_2 || !Magicarpe->im_3 || !Magicarpe->im_4 || !Magicarpe->im_5)
    {
        allegro_message("pb chargement image Magicarpe");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    Magicarpe->tx = Magicarpe->im_1->w;
    Magicarpe->tx = Magicarpe->im_1->h;

    Magicarpe->posx = SCREEN_W/2-Magicarpe->tx/2;
    Magicarpe->posy = SCREEN_H/2-Magicarpe->ty/2;

    Magicarpe->depx = 9;
    Magicarpe->depy = 5;

    return Magicarpe;
}

void init_allegro()
{
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}