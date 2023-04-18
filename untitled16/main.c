
#include <stdio.h>
#include "allegro.h"
#include "time.h"

void centre(){
    BITMAP* fond;
    BITMAP* t0;BITMAP* t1;BITMAP* t2;BITMAP* tup0;BITMAP* tup1;BITMAP* tup2;BITMAP* ts0;BITMAP* ts1;BITMAP* ts2;
    BITMAP * page;
    int y =0;
    int x = 0;
    int mouv =0;



    fond = create_bitmap(SCREEN_W,SCREEN_H);
    clear_to_color(fond,255);
    t0 = load_bitmap("../t1.bmp",NULL);
    t1 = load_bitmap("../t2.bmp",NULL);
    t2 = load_bitmap("../t3.bmp",NULL);
    ts0 = load_bitmap("../ts1.bmp",NULL);
    ts1 = load_bitmap("../ts2.bmp",NULL);
    ts2= load_bitmap("../ts3.bmp",NULL);
    tup0 = load_bitmap("../tu1.bmp",NULL);
    tup1 = load_bitmap("../tu2.bmp",NULL);
    tup2= load_bitmap("../tu3.bmp",NULL);

    page = create_bitmap(640,480);

    blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
    draw_sprite(page,t0,0,0);
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    if(!fond){
        printf("erreur");
    }

    while (!key[KEY_A] || x < SCREEN_W)
    {
        clear_to_color(fond,255);
        if(mouv <= 5 && key[KEY_RIGHT] ){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,ts0,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            x= x+2;
            mouv++;
            rest(10);
        }
        if(mouv > 5 && mouv <=10 && key[KEY_RIGHT]){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,ts1,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            x= x+2;
            mouv++;
            rest(10);
        }
        if(mouv > 10 && mouv <= 20  && key[KEY_RIGHT]){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,ts2,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            x= x+2;
            mouv = 0;
            rest(10);
        }


        if(mouv <= 5 && key[KEY_LEFT]){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite_h_flip(page,ts0,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            x= x-2;
            mouv++;
            rest(10);
        }
        if(mouv > 5 && mouv <=10 && key[KEY_LEFT]){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite_h_flip(page,ts1,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            x= x-2;
            mouv++;
            rest(10);
        }
        if(mouv > 10 && mouv <= 20  && key[KEY_LEFT]){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite_h_flip(page,ts2,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            x= x-2;
            mouv=0;
            rest(10);
        }
        if(mouv <= 5 && key[KEY_UP] ){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tup0,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            y= y-2;
            mouv++;
            rest(10);
        }
        if(mouv > 5 && mouv <=10 && key[KEY_UP]){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tup1,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            y= y-2;
            mouv++;
            rest(10);
        }
        if(mouv > 10 && mouv <= 20  && key[KEY_UP]){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tup2,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            y= y-2;
            mouv = 0;
            rest(10);
        }
        if(mouv <= 5 && key[KEY_DOWN] ){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,t0,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            y= y+2;
            mouv++;
            rest(10);
        }
        if(mouv > 5 && mouv <=10 && key[KEY_DOWN] ){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,t1,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            y= y+2;
            mouv++;
            rest(10);
        }
        if(mouv > 10 && mouv <= 20  && key[KEY_DOWN]){
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,t2,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            y= y+2;
            mouv = 0;
            rest(10);
        }
        else{
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,t0,x,y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
    }

}



int main() {

    allegro_init();
    install_keyboard();
    srand(time(NULL));
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    centre();
    return 0;
}END_OF_MAIN()