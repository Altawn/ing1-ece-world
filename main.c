#include "not_main.h"

int main()
{
    //Temps des joueurs respectifs
    double tps_j1 = 0;
    double tps_j2 = 0;

    //init allegro
    TB_init_allegro();

    //jeu
    Tir_Ballons(tps_j1, tps_j2);


    allegro_exit();
    return 0;
}END_OF_MAIN()
