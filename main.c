
#include "head.h"



int main() {

    t_player player1;
    t_objet snake_game ={707,415,727,415,0,0};
    t_objet hero_game ={420,240,460,260,0,0};
    t_objet rectangle3 ={0,85,1024,85,0,0};
    t_objet rectangle4 ={55,0,55,768,0,0};
    t_objet rectangle5 ={965,0,965,768,0,0};
    t_objet rectangle6 ={0,700,220,700,0,0};
    t_objet rectangle7 ={345,700,1024,768,0,0};
    t_objet rectangle8 ={220,768,220,700,0,0};
    t_objet rectangle9 ={340,768,340,700,0,0};
    t_objet gym ={570,290,970,415,0,0};


    bool swap1 = false;
    bool swap2 = false;
    bool swap3 = false;
    bool swap4 = false;

    allegro_init();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    srand(time(NULL));
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP* fond;BITMAP* t0;BITMAP* t1;BITMAP* t2;BITMAP* tup0;BITMAP* tup1;BITMAP* tup2;BITMAP* ts0;BITMAP* ts1;BITMAP* ts2;BITMAP * page;

    player1.x=270;
    player1.y=720;
    player1.mouv=0;

    //////////////////BITMAP/////////////////
    page = create_bitmap(1024,768);
    fond = load_bitmap("../fond_park.bmp",NULL);
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

    calc(&snake_game);
    calc(&hero_game);
    calc(&rectangle3);
    calc(&rectangle4);
    calc(&rectangle5);
    calc(&rectangle6);
    calc(&rectangle7);
    calc(&rectangle8);
    calc(&rectangle9);
    calc(&gym);

    MIDI* midi = load_midi("../Pokemon_sound.mid");
    play_midi(midi, true);
    ecran();
   // print_chen(page)
    blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
    draw_sprite(page,ts0,player1.x,player1.y);
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    while (!key[KEY_A])
    {
        colision(&player1,&rectangle3);
        colision(&player1,&rectangle4);
        colision(&player1,&rectangle5);
        colision(&player1,&rectangle6);
        colision(&player1,&rectangle7);
        colision(&player1,&rectangle8);
        colision(&player1,&rectangle9);
        colision(&player1,&gym);
        rectfill(screen,hero_game.x,hero_game.y,hero_game.x2,hero_game.y2,0);
        depla(&player1,page,fond,t0,t1,t2,tup0,tup1,tup2,ts0,ts1,ts2);

        if(colision(&player1,&snake_game)){
            if(bulle(&player1)){
                stop_midi();
                blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
                draw_sprite(page,tup0,player1.x,player1.y);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                door_one(tup0,&player1);
                swap1= true;
            }
            else{
                blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
                draw_sprite(page,tup0,player1.x,player1.y);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            }
        }

        if(colision(&player1,&hero_game)){
            if(bulle(&player1)){
                stop_midi();
                blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
                draw_sprite(page,tup0,player1.x,player1.y);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                door_one(tup0,&player1);
                swap2= true;
            }
            else{
                blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
                draw_sprite(page,tup0,player1.x,player1.y);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            }
        }


        if (swap1 == true){
            // jeux 1
            clear(page);
            snake();
            play_midi(midi, true);
            depla(&player1,page,fond,t0,t1,t2,tup0,tup1,tup2,ts0,ts1,ts2);
            swap1 = false;
        }

        if (swap2 == true){
            clear(page);
            guitar_hero();
            depla(&player1,page,fond,t0,t1,t2,tup0,tup1,tup2,ts0,ts1,ts2);
            // jeux 2
            swap2 = false;
        }

        if (swap3 == true){

            // jeux 3
            swap3 = false;
        }

        if (swap4 == true){

            // jeux 4
            swap4 =false;
        }


    }
    return 0;
}END_OF_MAIN()

