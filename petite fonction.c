#include "head.h"

bool colision(t_player* player,t_objet* ob) {

    bool swap = true;

    if (player->x-5 < ob->x2 &&
        player->x + 28> ob->x &&
        player->y-5  < ob->y2 &&
        player->y + 35 > ob->y  )
    {
        if(player->x < ob->x){
            player->x =player->x-3;
            swap = false;
        }
        if(player->x > ob->x2 && swap == true){
            player->x= player->x+3;
            swap = false;
        }
        if(player->y < ob->y && swap == true){
            player->y =player->y-3;
            swap = false;
        }
        if(player->y> ob->y2 && swap == true){
            player->y= player->y+3;
            swap = false;
            return true;
        }
    }
    return false;
}


bool bulle(t_player* player){
    int pos = player->y -38;
    int yrec =0;
    int xrec=0;
    bool circle = false;

    while(!key[KEY_ENTER]){
        circle = false;
        if(key[KEY_UP]){
            pos = player->y -38;
            circle = true;
        }
        if(key[KEY_DOWN]){
            circle = true;
            pos = player->y -28;
        }
        if ( xrec<80){
            rectfill(screen,(player->x-50),(player->y-50),(player->x-50)+xrec,(player->y-50)+yrec, 0);
            rectfill(screen,(player->x-45),(player->y-45),(player->x-55)+xrec,(player->y-55)+yrec, makecol(255,255,255));
            rest(10);
            yrec++;
            xrec= xrec+2;
        }
        if(xrec ==80){
            if(circle == true){
                rectfill(screen,(player->x-45),(player->y-45),(player->x-23),(player->y-56)+yrec, makecol(255,255,255));
            }
            textprintf_ex(screen,font,(player->x-20),player->y -40,0,-1,"OUI");
            textprintf_ex(screen,font,(player->x-20), player->y -30,0,-1,"NON");
            circlefill(screen,player->x-30,pos,2,0);
        }

    }
    if(pos == player->y -38){
        return 1;
    }
    else {
        return 0;
    }
}

void door_one(BITMAP* bit,t_player* player1){
    for (int i = 0; i < 13; ++i) {
        rectfill(screen,725-i,405,725+i,429,0);
        draw_sprite(screen,bit,player1->x,player1->y);
        rest(100);
    }
}
void door_two(BITMAP* bit,t_player* player1){
    for (int i = 0; i < 13; ++i) {
        rectfill(screen,431-i,349,431+i,365,0);
        draw_sprite(screen,bit,player1->x,player1->y);
        rest(100);
    }
}