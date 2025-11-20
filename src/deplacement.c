#include "head.h"

void depla(t_player* player,BITMAP* page, BITMAP* fond,BITMAP* tab[9]){
    int lastmove;
    ////////PLAYER1////////////////////////
    if(player->mouv <= 5 && key[KEY_RIGHT] ){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[6],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        player->x= player->x+2;
        player->mouv++;
        lastmove =1;
        rest(1);
    }
    if(player->mouv > 5 && player->mouv <=10 && key[KEY_RIGHT]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[7],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        player->x= player->x+2;
        lastmove =1;
        player->mouv++;
        rest(1);
    }
    if(player->mouv > 10 && player->mouv <= 15  && key[KEY_RIGHT]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[8],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x+2;
        lastmove =1;
        player->mouv++;
        if(player->mouv == 15){player->mouv = 0;}
        rest(1);
    }
    if(player->mouv <= 5 && key[KEY_LEFT]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite_h_flip(page,tab[6],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x-2;
        lastmove =2;
        player->mouv++;
        rest(1);
    }
    if(player->mouv > 5 && player->mouv <=10 && key[KEY_LEFT]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite_h_flip(page,tab[7],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        player->x= player->x-2;
        lastmove =2;
        player->mouv++;
        rest(1);
    }
    if(player->mouv > 10 && player->mouv <= 15 && key[KEY_LEFT]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite_h_flip(page,tab[8],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        player->x= player->x-2;
        lastmove =2;
        player->mouv++;
        if(player->mouv == 15){player->mouv = 0;}
        rest(1);
    }
    if(player->mouv <= 5 && key[KEY_UP] ){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[3],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        player->y= player->y-2;
        player->mouv++;
        lastmove =3;
        rest(1);
    }
    if(player->mouv > 5 && player->mouv <=10 && key[KEY_UP]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[4],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        player->y= player->y-2;
        player->mouv++;
        lastmove =3;
        rest(1);
    }
    if(player->mouv > 10 && player->mouv <= 15  && key[KEY_UP]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[5],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        player->y= player->y-2;
        lastmove =3;
        player->mouv++;
        if(player->mouv == 15){player->mouv = 0;}
        rest(1);
    }
    if(player->mouv <= 5 && key[KEY_DOWN] ){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[0],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        player->y= player->y+2;
        player->mouv++;
        lastmove =4;
        rest(1);
    }
    if(player->mouv > 5 && player->mouv <=10&& key[KEY_DOWN] ){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[1],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        player->y= player->y+2;
        player->mouv++;
        lastmove =4;
        rest(1);
    }
    if(player->mouv > 10 && player->mouv <= 15 && key[KEY_DOWN]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[2],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y+2;
        player->mouv++;
        if(player->mouv == 15){player->mouv = 0;}
        lastmove =4;
        rest(1);
    }
    else if (keypressed()!= 1){
        if(lastmove == 1){
            clear(page);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tab[6],player->x,player->y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        if(lastmove == 2){
            clear(page);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite_h_flip(page,tab[6],player->x,player->y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        if(lastmove == 3){
            clear(page);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tab[3],player->x,player->y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        if(lastmove == 4){
            clear(page);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tab[0],player->x,player->y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
    }
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}

void depla2(t_player* player,BITMAP* page, BITMAP* fond,BITMAP* tab[9]){
    int lastmove;
    ////////PLAYER1/////////////////////////
    if(player->mouv <= 5 && key[KEY_D] ){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[6],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x+2;
        player->mouv++;
        lastmove =1;
        rest(1);
    }
    if(player->mouv > 5 && player->mouv <=10 && key[KEY_D]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[7],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x+2;
        lastmove =1;
        player->mouv++;
        rest(1);
    }
    if(player->mouv > 10 && player->mouv <= 15  && key[KEY_D]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[8],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x+2;
        lastmove =1;
        player->mouv++;
        if(player->mouv == 15){player->mouv = 0;}
        rest(1);
    }
    if(player->mouv <= 5 && key[KEY_A]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite_h_flip(page,tab[6],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x-2;
        lastmove =2;
        player->mouv++;
        rest(1);
    }
    if(player->mouv > 5 && player->mouv <=10 && key[KEY_A]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite_h_flip(page,tab[7],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x-2;
        lastmove =2;
        player->mouv++;
        rest(1);
    }
    if(player->mouv > 10 && player->mouv <= 15 && key[KEY_A]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite_h_flip(page,tab[8],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x-2;
        lastmove =2;
        player->mouv++;
        if(player->mouv == 15){player->mouv = 0;}
        rest(1);
    }
    if(player->mouv <= 5 && key[KEY_W] ){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[3],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y-2;
        player->mouv++;
        lastmove =3;
        rest(1);
    }
    if(player->mouv > 5 && player->mouv <=10 && key[KEY_W]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[4],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y-2;
        player->mouv++;
        lastmove =3;
        rest(1);
    }
    if(player->mouv > 10 && player->mouv <= 15  && key[KEY_W]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[5],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y-2;
        lastmove =3;
        player->mouv++;
        if(player->mouv == 15){player->mouv = 0;}
        rest(1);
    }
    if(player->mouv <= 5 && key[KEY_S] ){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[0],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y+2;
        player->mouv++;
        lastmove =4;
        rest(1);
    }
    if(player->mouv > 5 && player->mouv <=10&& key[KEY_S] ){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[1],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y+2;
        player->mouv++;
        lastmove =4;
        rest(1);
    }
    if(player->mouv > 10 && player->mouv <= 15 && key[KEY_S]){
        clear(page);
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tab[2],player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y+2;
        player->mouv++;
        if(player->mouv == 15){player->mouv = 0;}
        lastmove =4;
        rest(1);
    }
    else if (keypressed()!= 1){
        if(lastmove == 1){
            clear(page);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tab[6],player->x,player->y);
        }
        if(lastmove == 2){
            clear(page);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite_h_flip(page,tab[6],player->x,player->y);
        }
        if(lastmove == 3){
            clear(page);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tab[3],player->x,player->y);
        }
        if(lastmove == 4){
            clear(page);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tab[0],player->x,player->y);
        }
    }
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}
