#include "head.h"

void pomme_init(BITMAP* base2,t_pomme* apple){
    apple->base = base2;
    apple->y = (rand()%12)*64;
    apple->x = (rand()%16)*64;

}

bool colision_snake(t_liste* liste,t_pomme* pomme,BITMAP* base) {
    if (liste->head->x < pomme->x +64 &&
        liste->head->x + 64> pomme->x &&
        liste->head->y  < pomme->y +64 &&
        liste->head->y + 64 > pomme->y  ){
        pomme_init(base,pomme);
        return true;
    }
    else return false;
}



t_liste *initialisation(BITMAP* base)
{
    t_liste *liste = malloc(sizeof(*liste));
    t_snake *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->x = 64;
    element->y =64;
    element->next = NULL;
    element->base = base;
    liste->head = element;

    return liste;
}

void add_part(t_liste* liste,BITMAP* base)
{

    t_snake* nouvel_element = malloc(sizeof(*nouvel_element));
    nouvel_element->next = NULL;
    nouvel_element->base =base;
    t_snake* actuel = liste->head;
    while (actuel->next != NULL)
    {
        actuel = actuel->next;
    }
    nouvel_element->x= actuel->x-64;
    nouvel_element->y= actuel->y;
    actuel->next = nouvel_element;


}

void move_snake(t_liste* serpent,int mouvement) {
    if (mouvement == 1) { // Déplacement vers la gauche
        t_snake* actuel = serpent->head;
        int prev_x = serpent->head->x;
        int prev_y = serpent->head->y;
        serpent->head->x -= 64;
        actuel = actuel->next;
        while (actuel != NULL) {
            int temp_x = actuel->x;
            int temp_y = actuel->y;
            actuel->x = prev_x;
            actuel->y = prev_y;
            prev_x = temp_x;
            prev_y = temp_y;
            actuel = actuel->next;
        }
    }
    else if (mouvement == 2) { // Déplacement vers la droite
        t_snake* actuel = serpent->head;
        int prev_x = serpent->head->x;
        int prev_y = serpent->head->y;
        serpent->head->x += 64;
        actuel = actuel->next;
        while (actuel != NULL) {
            int temp_x = actuel->x;
            int temp_y = actuel->y;
            actuel->x = prev_x;
            actuel->y = prev_y;
            prev_x = temp_x;
            prev_y = temp_y;
            actuel = actuel->next;
        }
    }
    else if (mouvement == 4) { // Déplacement vers le bas
        t_snake* actuel = serpent->head;
        int prev_x = serpent->head->x;
        int prev_y = serpent->head->y;
        serpent->head->y += 64;
        actuel = actuel->next;
        while (actuel != NULL) {
            int temp_x = actuel->x;
            int temp_y = actuel->y;
            actuel->x = prev_x;
            actuel->y = prev_y;
            prev_x = temp_x;
            prev_y = temp_y;
            actuel = actuel->next;
        }
    }
    else if (mouvement == 3) { // Déplacement vers le haut
        t_snake* actuel = serpent->head;
        int prev_x = serpent->head->x;
        int prev_y = serpent->head->y;
        serpent->head->y -= 64;
        actuel = actuel->next;
        while (actuel != NULL) {
            int temp_x = actuel->x;
            int temp_y = actuel->y;
            actuel->x = prev_x;
            actuel->y = prev_y;
            prev_x = temp_x;
            prev_y = temp_y;
            actuel = actuel->next;

        }
    }
    rest(150);

}

void afficherListe(t_liste *liste,BITMAP* page,BITMAP* head1,BITMAP* head2,BITMAP* head3,BITMAP* head4,int mouvement)
{
    if(mouvement == 1){
        liste->head->base = head1;
    }
    if(mouvement == 3){
        liste->head->base = head2;
    }
    if(mouvement == 2){
        liste->head->base = head3;
    }
    if(mouvement == 4){
        liste->head->base = head4;
    }

    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    t_snake *actuel = liste->head;

    while ( actuel->next !=NULL)
    {
        if(actuel == liste->head){
            if(mouvement == 1)
                draw_sprite(page,actuel->base,actuel->x+5,actuel->y-15);
            if(mouvement == 2)
                draw_sprite(page,actuel->base,actuel->x+2,actuel->y-15);
            if(mouvement == 3)
                draw_sprite(page,actuel->base,actuel->x+15,actuel->y+5);
            if(mouvement == 4)
                draw_sprite(page,actuel->base,actuel->x+15,actuel->y+2);

        }
        else
            draw_sprite(page,actuel->base,actuel->x,actuel->y);
        actuel = actuel->next;
    }
}

bool snake_defeat(int nbpart, t_liste* serpent) {

    t_snake* head = serpent->head;
    t_snake* actuel = head->next;

    for (int i = 1; i < nbpart; i++) {
        if (head->x == actuel->x && head->y == actuel->y) {
            return true;
        }
        actuel= actuel->next;
    }
    return false;
}



void snake(t_player* player,t_player* player2) {

    MIDI* snake_music = load_midi("../snake_music.mid");
    play_midi(snake_music, true);
    BITMAP* over = load_bitmap("../game-over1.bmp",NULL);
   BITMAP* fond = load_bitmap("../cave_background.bmp",NULL);
   BITMAP* head1= load_bitmap("../onyx_head1.bmp",NULL);
   BITMAP* head2= load_bitmap("../onyx_head2.bmp",NULL);
   BITMAP* head3= load_bitmap("../onyx_head3.bmp",NULL);
   BITMAP* head4= load_bitmap("../onyx_head4.bmp",NULL);

    BITMAP* base = load_bitmap("../onyx_part.bmp",NULL);
    BITMAP* base2 = create_bitmap(64,64);
    BITMAP* page = create_bitmap(1024,768);
    clear_to_color(base2, makecol(255,0,0));
    t_pomme * apple = malloc(sizeof(t_pomme*));

    int turn[2];
    int t=0;
    bool end =true ;

    while(t!=2) {
        int mouvement =2;
        int nb_part = 1;
        t++;
        t_liste* serpent = initialisation(base);
        pomme_init(base,apple);
        add_part(serpent,base);add_part(serpent,base);

        while (end) {

            textprintf_ex(screen, font, 980, 10, makecol(255, 255, 255), -1, "%d", nb_part - 1);
            if (key[KEY_LEFT]) {
                mouvement = 1;
            }
            if (key[KEY_RIGHT]) {
                mouvement = 2;
            }
            if (key[KEY_UP]) {
                mouvement = 3;
            }
            if (key[KEY_DOWN]) {
                mouvement = 4;
            }

            blit(fond, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            move_snake(serpent, mouvement);
            if (colision_snake(serpent, apple, base) == true) {
                nb_part++;
                add_part(serpent, base);
            }
            if (key[KEY_E]) {
                nb_part++;
                add_part(serpent, base);
                rest(100);
            }
            if (serpent->head->x == SCREEN_W || serpent->head->x == -64 || serpent->head->y == SCREEN_H ||
                serpent->head->y == -64) {
                end = false;
            }

            if (snake_defeat(nb_part, serpent)) {
                end = false;
            }
            if (key[KEY_P]) {
                while (!key[KEY_ENTER]) {
                    rest(1);
                }
            }

            afficherListe(serpent, page, head1, head2, head3, head4, mouvement);
            draw_sprite(page, apple->base, apple->x, apple->y);
            blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_W);
        }
        clear(screen);
        draw_sprite(page, over, 0, 0);
        while(!key[KEY_ENTER]){
            textprintf_ex(page, font, 512, 700, makecol(255, 255, 255), -1, "%d", nb_part - 1);
            blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_W);
        }
        turn[t] = nb_part-1;
        if(t == 1){
            score_modif(turn[t],1,player->name);
        } else
            score_modif(turn[t],1,player2->name);

        printf("%d\n",turn[t]);
        end = true;
    }
    if(turn[0] > turn[1]){
        player->ticket++;
    } else
        player2->ticket++;


    printf("%s\n",player->name);
    printf("%s\n",player2->name);


}

