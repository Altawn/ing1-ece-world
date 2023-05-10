#include "not_main.h"

/* Ce qu'il reste a faire
 *      Demande aux joueurs le pokemon sur lequel ils parient
 *          - Optionnel mais cool : affichage du sprite du pokemon pour qu'ils aient une idée
 *      Retranscription numero pokemon en nom de pokemon
 *      Retranscription numero gagnant a si un joueur a gagne ou non
 *      Alternatice pour le textprint_ex a la fin -> photo avec tout noté déja dessus
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
    int arrivee = 0;
    int * pokemon_gagnant = NULL;
    char message[] = "Le pokemon gagnant est : ";
    int text_width = text_length(font, message);
    int rect_width = text_width + 20;
    int rect_height =  30;
    int rect_x = (SCREEN_W - rect_width) / 2;
    int rect_y = (SCREEN_H - 25) / 2;

    //init du tableau de pointeurs de structures de type pokemon nommé tab_pok
    PI_remp_tab_pok(tab_pok);
    srand(time(NULL));

    //Init double buffer + decor
    page = create_bitmap(1024, 768); clear_bitmap(page);
    if(!page) allegro_message("Erreur creation page");

    decor = load_bitmap("city street.bmp", NULL);
    if(!decor) allegro_message("Pas de fond d'ecran");

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
    //clear_to_color(screen,makecol(255, 255, 255));
    clear(screen);

    while(!key[KEY_SPACE])
    {
        blit(decor,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rectfill(decor, rect_x, rect_y, rect_x + rect_width + 5, rect_y + rect_height, makecol(255, 255, 255));
        textout_centre_ex(decor, font, message, SCREEN_W / 2, SCREEN_H / 2, makecol(0, 0, 0), -1);
        textprintf_ex(decor, font, SCREEN_W / 2 + text_width/2, SCREEN_H / 2, makecol(0,0,0), -1, "%d", arrivee);
    }


    for (int i = 0; i < NPOK; ++i)
    {
        free(tab_pok[i]);
    }

    allegro_exit();
    return 0;

}END_OF_MAIN()