#include "head.h"

void depla(t_player* player,BITMAP* page, BITMAP* fond,BITMAP* t0,BITMAP* t1,BITMAP* t2,BITMAP* tup0,BITMAP* tup1,BITMAP* tup2,BITMAP* ts0,BITMAP* ts1,BITMAP* ts2){

    if(player->mouv <= 5 && key[KEY_RIGHT] ){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,ts0,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x+2;
        player->mouv++;
        rest(10);
    }
    if(player->mouv > 5 && player->mouv <=10 && key[KEY_RIGHT]){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,ts1,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x+2;
        player->mouv++;
        rest(10);
    }
    if(player->mouv > 10 && player->mouv <= 20  && key[KEY_RIGHT]){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,ts2,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x+2;
        player->mouv = 0;
        rest(10);
    }
    if(player->mouv <= 5 && key[KEY_LEFT]){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite_h_flip(page,ts0,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x-2;
        player->mouv++;
        rest(10);
    }
    if(player->mouv > 5 && player->mouv <=10 && key[KEY_LEFT]){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite_h_flip(page,ts1,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x-2;
        player->mouv++;
        rest(10);
    }
    if(player->mouv > 10 && player->mouv <= 20  && key[KEY_LEFT]){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite_h_flip(page,ts2,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->x= player->x-2;
        player->mouv=0;
        rest(10);
    }
    if(player->mouv <= 5 && key[KEY_UP] ){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tup0,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y-2;
        player->mouv++;
        rest(10);
    }
    if(player->mouv > 5 && player->mouv <=10 && key[KEY_UP]){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tup1,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y-2;
        player->mouv++;
        rest(10);
    }
    if(player->mouv > 10 && player->mouv <= 20  && key[KEY_UP]){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,tup2,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y-2;
        player->mouv = 0;
        rest(10);
    }
    if(player->mouv <= 5 && key[KEY_DOWN] ){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,t0,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y+2;
        player->mouv++;
        rest(10);
    }
    if(player->mouv > 5 && player->mouv <=10 && key[KEY_DOWN] ){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,t1,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y+2;
        player->mouv++;
        rest(10);
    }
    if(player->mouv > 10 && player->mouv <= 20  && key[KEY_DOWN]){
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,t2,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        player->y= player->y+2;
        player->mouv = 0;
        rest(10);
    }
    else{
        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,t0,player->x,player->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
}
