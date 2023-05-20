
#include "head.h"



int main() {
    t_player player1;
    t_player player2;
    t_player player_temp;
    t_objet snake_game ={707,415,727,415};
    t_objet hero ={414,349,440,355};
    t_objet ballon ={140,610,160,630};
    t_objet pari = {862,624,890,632};
    t_objet rectangle3 ={0,85,1024,85};
    t_objet rectangle4 ={55,0,55,768};
    t_objet rectangle5 ={965,0,965,768};
    t_objet rectangle6 ={0,700,220,700};
    t_objet rectangle7 ={345,700,1024,768};
    t_objet rectangle8 ={220,768,220,700};
    t_objet rectangle9 ={340,768,340,700};
    t_objet rectangle10 ={515,95,566,410};
    t_objet rectangle11 ={525,510,560,760};
    t_objet rectangle12 ={69,188,250,188};
    t_objet rectangle13 ={322,188,503,188};
    t_objet rectangle14 ={250,192,250,420};
    t_objet rectangle15 ={322,192,322,420};
    t_objet rectangle16 ={350,272,508,355};
    t_objet rectangle17 ={85,510,246,620};
    t_objet rectangle18 ={351,505,415,519};
    t_objet rectangle19 ={458,100,482,115};
    t_objet rectangle20 ={235,750,340,750};
    t_objet rectangle21 ={845,405,875,420};
    t_objet rectangle22 ={809,526,947,630};
    t_objet gym ={575,290,970,415};


    bool swap1 = false;
    bool swap2 = false;
    bool swap3 = false;
    bool swap4 = false;
    bool swap5 = false;
    bool end = true;

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

    BITMAP* fond;BITMAP* fond2;BITMAP* t0;BITMAP* t1;BITMAP* t2;BITMAP* tup0;BITMAP* tup1;BITMAP* tup2;BITMAP* ts0;BITMAP* ts1;BITMAP* ts2;BITMAP * page;BITMAP* page2;
    BITMAP* e1;BITMAP* e2;BITMAP* e3;BITMAP* e_s1;BITMAP* e_s2;BITMAP* e_s3;BITMAP* e_u1;BITMAP* e_u2;BITMAP* e_u3;
    BITMAP* quoi;
    BITMAP* cent;
    player1.x=270;
    player1.y=700;
    player1.mouv=0;
    player1.type =1;
    player2.type =2;
    player2.x=270;
    player2.y=670;
    player2.mouv=0;
    player_temp.x=501;
    player_temp.y=489;
    player_temp.mouv=0;

    player1.ticket=5;
    player2.ticket=5;
    //////////////////BITMAP/////////////////
    page2 = create_bitmap(1024,768);
    page = create_bitmap(1024,768);
    cent = load_bitmap("../présentation+fond/poke_center.bmp",NULL);
    fond = load_bitmap("../présentation+fond/fond_park.bmp",NULL);

    t0 = load_bitmap("../image_deplacement/t1.bmp",NULL);
    t1 = load_bitmap("../image_deplacement/t2.bmp",NULL);
    t2 = load_bitmap("../image_deplacement/t3.bmp",NULL);
    ts0 = load_bitmap("../image_deplacement/ts1.bmp",NULL);
    ts1 = load_bitmap("../image_deplacement/ts2.bmp",NULL);
    ts2= load_bitmap("../image_deplacement/ts3.bmp",NULL);
    tup0 = load_bitmap("../image_deplacement/tu1.bmp",NULL);
    tup1 = load_bitmap("../image_deplacement/tu2.bmp",NULL);
    tup2= load_bitmap("../image_deplacement/tu3.bmp",NULL);
    BITMAP* tab_depla1[] ={t0,t1,t2,tup0,tup1,tup2,ts0,ts1,ts2,};

    e1 = load_bitmap("../image_deplacement/img8.bmp",NULL);
    e2 = load_bitmap("../image_deplacement/img7.bmp",NULL);
    e3 = load_bitmap("../image_deplacement/img9.bmp",NULL);
    e_s1 = load_bitmap("../image_deplacement/img5.bmp",NULL);
    e_s2= load_bitmap("../image_deplacement/img6.bmp",NULL);
    e_s3 = load_bitmap("../image_deplacement/img4.bmp",NULL);
    e_u1 = load_bitmap("../image_deplacement/img2.bmp",NULL);
    e_u2 = load_bitmap("../image_deplacement/img1.bmp",NULL);
    e_u3 = load_bitmap("../image_deplacement/img3.bmp",NULL);
    BITMAP* tab_depla2[] ={e1,e2,e3,e_u1,e_u2,e_u3,e_s1,e_s2,e_s3};

    quoi = load_bitmap("../présentation+fond/quoi.bmp",NULL);
    if(!fond){
        printf("erreur");
    }
    MIDI* midi = load_midi("../music/Pokemon_sound.mid");
    play_midi(midi, true);
    clear_to_color(page, makecol(255,255,255));
    //afficher_score(page);
    //ecran();
    //print_chen(page,&player1,&player2);
    blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
    if(player1.type == 2){
        draw_sprite(page,ts0,player1.x,player1.y);
    }
    if (player1.type ==1){
        draw_sprite(page,e_u1,player1.x,player1.y);
    }

    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    while (end)
    {
        //////colision///////
        textprintf_ex(fond,font,920,30,makecol(255,0,0),-1,"%s : %d",player1.name,player1.ticket);
        textprintf_ex(fond,font,920,40,makecol(255,0,0),-1,"%s : %d",player2.name,player2.ticket);
        colision(&player1,&rectangle3);
        colision(&player1,&rectangle4);
        colision(&player1,&rectangle5);
        colision(&player1,&rectangle6);
        colision(&player1,&rectangle7);
        colision(&player1,&rectangle8);
        colision(&player1,&rectangle9);
        colision(&player1,&rectangle10);
        colision(&player1,&rectangle11);
        colision(&player1,&rectangle12);
        colision(&player1,&rectangle13);
        colision(&player1,&rectangle14);
        colision(&player1,&rectangle15);
        colision(&player1,&rectangle16);
        colision(&player1,&rectangle17);
        colision(&player1,&rectangle18);
        colision(&player1,&rectangle22);
        colision(&player1,&gym);
        colision(&player2,&rectangle3);
        colision(&player2,&rectangle4);
        colision(&player2,&rectangle5);
        colision(&player2,&rectangle6);
        colision(&player2,&rectangle7);
        colision(&player2,&rectangle8);
        colision(&player2,&rectangle9);
        colision(&player2,&rectangle10);
        colision(&player2,&rectangle11);
        colision(&player2,&rectangle12);
        colision(&player2,&rectangle13);
        colision(&player2,&rectangle14);
        colision(&player2,&rectangle15);
        colision(&player2,&rectangle16);
        colision(&player2,&rectangle17);
        colision(&player2,&rectangle18);
        colision(&player2,&rectangle22);
        colision(&player2,&gym);

        /////deplacement/////

        if(player1.type == 2 && player2.type == 1){
            depla(&player1,page,fond,tab_depla1);
            depla2(&player2,page,fond,tab_depla2);
        }
        if(player1.type == 1 && player2.type == 2){
            depla(&player1,page,fond,tab_depla2);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            depla2(&player2,page,fond,tab_depla1);
        }

        //////condition jeux/////////
        if(colision(&player1,&snake_game) || colision(&player2,&snake_game)){
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

        if(colision(&player1,&hero) || colision(&player2,&hero)){
            if(bulle(&player1)){
                stop_midi();
                blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
                draw_sprite(page,tup0,player1.x,player1.y);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                door_two(tup0,&player1);
                swap2= true;
            }
            else{
                blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
                draw_sprite(page,tup0,player1.x,player1.y);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            }
        }
        if(colision(&player1,&rectangle19) || colision(&player2,&rectangle19)){
            clear(screen);
            while(!key[KEY_ENTER])
            {
                draw_sprite(page,quoi,0,0);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            }

            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tup0,player1.x,player1.y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        if(colision(&player1,&rectangle20) || colision(&player2,&rectangle20)){
            if(bulle(&player1)){
                end = false;
            }
            else{
                blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
                draw_sprite(page,tup0,player1.x,player1.y);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            }

        }
        if(colision(&player1,&ballon)|| colision(&player2,&ballon)){
            if(bulle(&player1)){
                stop_midi();
                blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
                draw_sprite(page,tup0,player1.x,player1.y);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                swap4= true;
            }
            else{
                blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
                draw_sprite(page,tup0,player1.x,player1.y);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            }
        }
        if(colision(&player1,&pari)|| colision(&player2,&pari)){
            if(bulle(&player1)){
                stop_midi();
                blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
                draw_sprite(page,tup0,player1.x,player1.y);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                swap3= true;
            }
            else{
                blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
                draw_sprite(page,tup0,player1.x,player1.y);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            }
        }

        ///////declanchement jeux///////

        if(colision(&player1,&rectangle21)|| colision(&player2,&rectangle21)){
            swap5 = true;
        }

        if(swap5 == true){
            clear(page);
            poke_center(&player_temp,page,cent,tab_depla1);
            swap5 = false;
        }

        if (swap1 == true){
            // jeux 1
            clear(page);
            snake(&player1,&player2);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tup0,player1.x,player1.y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            play_midi(midi, true);
            swap1 = false;
        }

        if (swap2 == true){
            clear(page);
            guitar_hero( &player1,&player2);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tup0,player1.x,player1.y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            play_midi(midi, true);
            // jeux 2
            swap2 = false;
        }

        if (swap3 == true)
        {
            clear(page);
            Pari_Hippique(&player1,&player2);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tup0,player1.x,player1.y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            play_midi(midi, true);
            swap3 = false;
        }

        if (swap4 == true)
        {
            clear(page);
            Tir_Ballons(&player1,&player2);
            blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(page,tup0,player1.x,player1.y);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            play_midi(midi, true);
            swap4 = false;
        }
    }
    return 0;
}END_OF_MAIN()