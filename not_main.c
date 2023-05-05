#include "not_main.h"

Pokemon init_magicarpe()
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
}

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
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}