#include "head.h"

void pomme_init(BITMAP* base2,t_pomme* apple){
    apple->base = base2;
    apple->y = (rand()%13)*60;
    apple->x = (rand()%17)*60;

}

bool colision_snake(t_liste* liste,t_pomme* pomme,BITMAP* base) {
    if (liste->head->x < pomme->x +60 &&
        liste->head->x + 60> pomme->x &&
        liste->head->y  < pomme->y +60 &&
        liste->head->y + 60 > pomme->y  ){
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

    element->x = 0;
    element->y =0;
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
    nouvel_element->x= actuel->x-60;
    nouvel_element->y= actuel->y;
    actuel->next = nouvel_element;


}

void move_snake(t_liste* serpent,int mouvement) {
    if (mouvement == 1) { // Déplacement vers la gauche
        t_snake* actuel = serpent->head;
        if(serpent->head->x <= 0){
            serpent->head->x = SCREEN_W;
        }
        int prev_x = serpent->head->x;
        int prev_y = serpent->head->y;
        serpent->head->x -= 60;
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
        if(serpent->head->x >= SCREEN_W){
            serpent->head->x = 0;
        }
        int prev_x = serpent->head->x;
        int prev_y = serpent->head->y;
        serpent->head->x += 60;
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
        if(serpent->head->y >= SCREEN_H){
            serpent->head->y = 0;
        }
        int prev_x = serpent->head->x;
        int prev_y = serpent->head->y;
        serpent->head->y += 60;
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
        if(serpent->head->y <= 0){
            serpent->head->y = SCREEN_H;
        }
        int prev_x = serpent->head->x;
        int prev_y = serpent->head->y;
        serpent->head->y -= 60;
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
    rest(100);

}

void afficherListe(t_liste *liste,BITMAP* page)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    t_snake *actuel = liste->head;

    while ( actuel->next !=NULL)
    {
        draw_sprite(page,actuel->base,actuel->x,actuel->y);
        actuel = actuel->next;
    }
}


void snake() {

    BITMAP* base = create_bitmap(60,60);
    BITMAP* base2 = create_bitmap(60,60);
    BITMAP* page = create_bitmap(1024,768);
    clear_to_color(base,255);
    clear_to_color(base2, makecol(255,0,0));
    t_pomme * apple = malloc(sizeof(t_pomme*));
    int mouvement =2;
    t_liste* serpent = initialisation(base);
    pomme_init(base2,apple);

    add_part(serpent,base);

    while(!key[KEY_SPACE]){

        if(key[KEY_LEFT]){
            mouvement = 1;
        }
        if(key[KEY_RIGHT]){
            mouvement = 2;
        }
        if(key[KEY_UP]){
            mouvement = 3;
        }
        if(key[KEY_DOWN]){
            mouvement = 4;
        }

        clear_to_color(page, makecol(255,255,255));
        move_snake(serpent,mouvement);
        if(colision_snake(serpent,apple,base2) == true){
            add_part(serpent,base);
        }
        if(key[KEY_E]){
            add_part(serpent,base);
            rest(100);
        }
        afficherListe(serpent,page);
        draw_sprite(page,apple->base,apple->x,apple->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_W);
    }
}


