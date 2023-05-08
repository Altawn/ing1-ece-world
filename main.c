#include "not_main.h"

int main()
{
    //Initialisation Allegro
    init_allegro();

    //Supposant qu'on prend les deux variables pari gagnant du joueur
    int pari_gagnant_j1 = 0;
    int pari_gagnant_j2 = 0;

    //Autres variables + structures
    BITMAP * page = NULL;
    Pokemon * tab_pok[NPOK];
    int pas = 0;

    remp_tab_pok(tab_pok);

    //Double buffer
    page = create_bitmap(1024, 768);
    clear_bitmap(page);
    if(!page) allegro_message("Erreur creation page");

    //Boucle d'evenements
    while (!key[KEY_ESC])
    {
        clear_bitmap(page);

        for (int i = 0; i < NPOK; i++)
        {
            draw_sprite(page, tab_pok[i]->img[tab_pok[i]->frame_act], 0, pas);
            tab_pok[i]->frame_act++;
            if(tab_pok[i]->frame_act >= NIMAGE) tab_pok[i]->frame_act = 0;
            pas = pas+100;
        }
        rest(100);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        //blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        //rest(100);
        /*
        tab_pok[0]->frame_act++;
        tab_pok[1]->frame_act++;
        tab_pok[2]->frame_act++;
        tab_pok[3]->frame_act++;
        tab_pok[4]->frame_act++;
        if(tab_pok[0]->frame_act >= NIMAGE) tab_pok[0]->frame_act = 0;
        if(tab_pok[1]->frame_act >= NIMAGE) tab_pok[1]->frame_act = 0;
        if(tab_pok[2]->frame_act >= NIMAGE) tab_pok[2]->frame_act = 0;
        if(tab_pok[3]->frame_act >= NIMAGE) tab_pok[3]->frame_act = 0;
        if(tab_pok[4]->frame_act >= NIMAGE) tab_pok[4]->frame_act = 0;
        */
        pas = 0; 
    }

    for (int i = 0; i < NPOK; ++i)
    {
        free(tab_pok[i]);
    }

    allegro_exit();
    return 0;

}END_OF_MAIN()