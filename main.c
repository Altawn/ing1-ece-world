#include "not_main.h"

int main()
{
    //Initialisation Allegro
    init_allegro();

    //Supposant qu'on prend les deux variables pari gagnant du joueur
    int pari_gagnant_j1 = 0;
    int pari_gagnant_j2 = 0;
    Pokemon * tab_pok[NPOK] = {0,0,0,0,0};

    //Autres variables + structures
    //Pokemon Magicarpe = init_magicarpe();
    //Pokemon Papillusion = init_papillusion();
    BITMAP * page = NULL;
    remp_tab_pok(tab_pok);
    //Double buffer
    page = create_bitmap(800, 600);
    clear_bitmap(page);
    if(!page) allegro_message("Erreur creation page");
    //Boucle d'evenements
    while (!key[KEY_ESC])
    {
        clear_bitmap(page);
        draw_sprite(page, tab_pok[0]->img[tab_pok[0]->frame_act], 0, 0);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(100);
        tab_pok[0]->frame_act++;
        if(tab_pok[0]->frame_act >= NIMAGE) tab_pok[0]->frame_act = 0;
        Actu_Pok(tab_pok[0]);
    }

    allegro_exit();
    return 0;
}END_OF_MAIN()