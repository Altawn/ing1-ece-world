#include <stdio.h>
#include <allegro.h>

int main()
{
    //Supposant qu'on prend les deux variables pari gagnant du joueur
    int pari_gagnant_j1 = 0;
    int pari_gagnant_j2 = 0;

    //Autres varaibles
    BITMAP * magicarpe_1 = load_bitmap( "80x95-magicarpe.bmp", NULL);
    BITMAP * magicarpe_2 = load_bitmap("80x95-magicarpe2.bmp", NULL);
    BITMAP * magicarpe_3 = load_bitmap("80x95-magicarpe3.bmp", NULL);
    BITMAP * magicarpe_4 = load_bitmap("80x95-magicarpe4.bmp", NULL);
    BITMAP * magicarpe_5 = load_bitmap("80x95-magicarpe5.bmp", NULL);

    BITMAP * papillusion_1 = load_bitmap( "80x95-Papillon.bmp", NULL);
    BITMAP * papillusion_2 = load_bitmap( "80x95-Papillon2.bmp", NULL);
    BITMAP * papillusion_3 = load_bitmap( "80x95-Papillon3.bmp", NULL);
    BITMAP * papillusion_4 = load_bitmap( "80x95-Papillon4.bmp", NULL);
    BITMAP * papillusion_5 = load_bitmap( "80x95-Papillon5.bmp", NULL);

    int x_magicarpe;
    int y_magicarpe;

    int x_papillusion;
    int y_papillusion;

    //Initialisation Allegro
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

    //Boucle d'evenements
    while (!key[KEY_ESC])
    {}

    return 0;
}END_OF_MAIN()
