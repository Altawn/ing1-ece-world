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
    BITMAP * buffer_pts = NULL;
    int def = 0;
    int flag = 0;
    int arrivee = 0;
    int * pokemon_gagnant = NULL;
    char pok_gagnant[50];
    int i = -1;
    char * debut[50] =
            {
            "1. Magicarpe",
            "2. Papilusion",
            "3. Tauros",
            "4. Ponita",
            "5. Rondoudou"
            };
    int j = 0;
    //init du tableau de pointeurs de structures de type pokemon nommé tab_pok
    PI_remp_tab_pok(tab_pok);
    srand(time(NULL));

    //Init double buffer + decor
    page = create_bitmap(1024, 768); clear_bitmap(page);
    if(!page) allegro_message("Erreur creation page");

    buffer_pts = create_bitmap(1024, 768); clear_bitmap(buffer_pts);
    if(!buffer_pts) allegro_message("Erreur creation page");

    decor = load_bitmap("city_street.bmp", NULL);
    if(!decor) allegro_message("Pas de fond d'ecran");

    dialogue = load_bitmap("Dialogue_Pokemon.bmp", NULL);
    if(!page) allegro_message("Erreur creation page");

    //Demande de pokemon aux joueurs

    //////////////////////////////////////EN CONSTRUCTION/////////////////////////////////////
    PI_entree_jeu(decor, page, dialogue);

    rest(200);

    PI_affichage_liste(decor, debut);

    //Transition entre les deux sous-programmes
    circlefill(decor, 500, 579, 5, 0);
    blit(decor, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    draw_sprite(decor, dialogue, 125 + 12, 550);

    while(!key[KEY_ENTER])
    {
        int y_cir = 550;
        int passe = 25;
        /*
        if(key[KEY_UP])
        {
            y_cir = y_cir + passe;
            PI_entree_jeu(decor, page, dialogue);
            PI_affichage_liste(decor, debut);
            circlefill(decor, 500, y_cir, 3, 0);
        }
        if(key[KEY_DOWN])
        {
            y_cir = y_cir - passe;
            PI_entree_jeu(decor, page, dialogue);
            PI_affichage_liste(decor, debut);
            circlefill(decor, 500, y_cir, 3, 0);
        }
        */
    }

    rest(1000);
    ///////////////////////////////////////////////////////////////////////////////////////////
    //Boucle d'evenements
    while (!key[KEY_ESC] && arrivee == 0)
    {
        // Effacer buffer en appliquant decor
        blit(decor,page,0,0,0,0,SCREEN_W,SCREEN_H);

        //Animation des pokemons
        PI_anim_pok(tab_pok, page); //-> draw_sprite(page, tab_rand[i]->img[tab_rand[i]->frame_act], tab_rand[i]->posx, pas);

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

    for (i = 0; i < NPOK; ++i)
    {
        free(tab_pok[i]);
    }

    allegro_exit();
    return 0;

}END_OF_MAIN()