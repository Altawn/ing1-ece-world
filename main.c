#include "not_main.h"

/* Ce qu'il reste a faire
 *      Demande aux joueurs le pokemon sur lequel ils parient
 *          - Optionnel mais cool : affichage du sprite du pokemon pour qu'ils aient une idée
 *      Retranscription numero gagnant a si un joueur a gagne ou non
 */

int main()
{
    //Initialisation Allegro
    PI_init_allegro();

    //Supposant qu'on prend les deux variables pari gagnant du joueur
    int pari_gagnant_j1 = 0;
    int pari_gagnant_j2 = 0;

    //Autres variables + structures
    BITMAP * page = NULL;
    Pokemon * tab_pok[NPOK];
    BITMAP * decor = NULL;
    BITMAP * dialogue = NULL;
    int arrivee = 0;
    int * pokemon_gagnant = NULL;
    char pok_gagnant[50];

    //init du tableau de pointeurs de structures de type pokemon nommé tab_pok
    PI_remp_tab_pok(tab_pok);
    srand(time(NULL));

    //Init double buffer + decor
    page = create_bitmap(1024, 768); clear_bitmap(page);
    if(!page) allegro_message("Erreur creation page");

    decor = load_bitmap("city street.bmp", NULL);
    if(!decor) allegro_message("Pas de fond d'ecran");

    dialogue = load_bitmap("Dialogue_Pokemon.bmp", NULL);
    if(!page) allegro_message("Erreur creation page");

    //Boucle d'evenements
    while (!key[KEY_ESC] && arrivee == 0)
    {
        // Effacer buffer en appliquant decor
        blit(decor,page,0,0,0,0,SCREEN_W,SCREEN_H);

        //Animation des pokemons
        PI_anim_pok(tab_pok, page);

        //Affichage du buffer mis à jour
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        //Deplacement des pokemons
        arrivee = PI_depla_pok(tab_pok);
    }

    clear(screen);
    PI_pok_gagnant(pok_gagnant, arrivee);
    
    while(!key[KEY_Q])
    {
        blit(decor, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(decor, dialogue, 125+12, 500);
        //blit(dialogue, decor, 0, 0, 0, 0, 1000, 200);

        textprintf_ex
                (
                decor,
                font,
                53 + 375 - strlen("la gagnant est Magic")/2,
                623,
                makecol(0, 0, 0),
                -1,
                " Le gagnant est %s", pok_gagnant
                );
    }
//SCREEN_W / 2 + text_width/2 - text_width2/2
//SCREEN_H / 2
    for (int i = 0; i < NPOK; ++i)
    {
        free(tab_pok[i]);
    }
    //free(pok_gagnant);
    allegro_exit();
    return 0;

}END_OF_MAIN()