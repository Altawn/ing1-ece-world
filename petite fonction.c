#include "head.h"

void colision(t_player* player,t_objet* ob) {

    bool swap = true;

    if (player->x - 5 < ob->x + ob->w &&
        player->x + 25
        > ob->x &&
        player->y - 5 < ob->y + ob->h &&
        player->y + 30 > ob->y  )
    {
        if(player->x < ob->x){
            player->x =player->x-3;
            swap = false;
        }
        if(player->x > ob->x + ob->w && swap == true){
            player->x= player->x+3;
            swap = false;
        }
        if(player->y < ob->y && swap == true){
           player->y =player->y-3;
            swap = false;
        }
        if(player->y > ob->y + ob->h && swap == true){
            player->y= player->y+3;
            swap = false;
        }
    }
}

void calc(t_objet* ob){
    ob->h = ob->y2 - ob->y;
    ob->w = ob->x2 - ob->x;
}