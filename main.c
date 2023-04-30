
#include "head.h"


int main() {

    t_player player1;
    t_objet rectangle ={320,240,360,260,0,0};

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

    if(!fond){
        printf("erreur");
    }

    calc(&rectangle);
    ecran();
    //print_chen(page);
    while (!key[KEY_A])
    {
        rectfill(fond,rectangle.x,rectangle.y,rectangle.x+rectangle.w,rectangle.y+rectangle.h,0);
        depla(&player1,page,fond,t0,t1,t2,tup0,tup1,tup2,ts0,ts1,ts2);
        colision(&player1,&rectangle);
    }
    return 0;
}END_OF_MAIN()

