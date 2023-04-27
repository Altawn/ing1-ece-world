
#include "head.h"

typedef struct objet{
    int x1, y1, x2, y2;
}t_objet;


/*void colision(int x, int y, int x1, int y1, int x2, int y2){

    if((x >= x2 ) ){
        x =0;
        y =0;

         if (x -2 < x1)
             x = x - 2;
         if (x - 2 < x2)
            x = x + 2;
        if (y -2 < y1)
            y = y - 2;
        if (y - 2 < y2)
            y = y + 2;
    }
}*/

int main() {

    t_player player1;
    t_objet rectangle;

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

    BITMAP* fond;BITMAP* t0;BITMAP* t1;BITMAP* t2;BITMAP* tup0;BITMAP* tup1;BITMAP* tup2;BITMAP* ts0;BITMAP* ts1;BITMAP* ts2;BITMAP * page;

    player1.x=0;
    player1.y=0;
    player1.mouv=0;

    //////////////////BITMAP/////////////////
    page = create_bitmap(640,480);
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

    blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
    draw_sprite(page,t0,0,0);
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    if(!fond){
        printf("erreur");
    }

    print_chen(page);
    while (!key[KEY_A])
    {
        depla(&player1,page,fond,t0,t1,t2,tup0,tup1,tup2,ts0,ts1,ts2);
    }
    return 0;
}END_OF_MAIN()

