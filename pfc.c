#include "head.h"

void slashed(BITMAP* page,BITMAP*fond,BITMAP*bar_menu,pokemon* s,pokemon* c,int x,int y,BITMAP* slash[5]){
    int frame=0;
    while(frame <=4){
        clear(page);
        blit(fond, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(page, s->sprite[0], 165, 382);
        draw_sprite(page, c->sprite_f[0], 690, 273);
        draw_sprite(page,slash[frame], x, y);
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        frame++;
        rest(120);
    }
}

void fight(pokemon* s,pokemon* c,BITMAP* page,t_player* player1,t_player* player2) {

    BITMAP* slash1;BITMAP* slash2;BITMAP* slash3;BITMAP* slash4;BITMAP* slash5;
    slash1 = load_bitmap("../image/Classic_19.bmp",NULL);slash2 = load_bitmap("../image/Classic_20.bmp",NULL);
    slash3 = load_bitmap("../image/Classic_21.bmp",NULL);slash4 = load_bitmap("../image/Classic_22.bmp",NULL);
    slash5 = load_bitmap("../image/Classic_23.bmp",NULL);
    BITMAP* slash[5] ={slash1,slash2,slash3,slash4,slash5};
    BITMAP* bar1; BITMAP* bar2;BITMAP* bar_menu;BITMAP* fond;BITMAP* sword;BITMAP* shield;BITMAP* staff;
    s->attack1 =0;s->attack2 =0;s->attack3 =0;c->attack1 =0;c->attack2 =0;c->attack3 =0;
    shield = load_bitmap("../image/shield.bmp",NULL);
    sword = load_bitmap("../image/sword.bmp",NULL);
    staff = load_bitmap("../image/staff2.bmp",NULL);
    bar_menu = load_bitmap("../image/bar_menu.bmp",NULL);
    bar1 = load_bitmap("../image/bar1.bmp",NULL);
    bar2 = load_bitmap("../image/bar2.bmp",NULL);
    fond = load_bitmap("../image/b1.bmp",NULL);
    int pv1 =0;int barx = -200;int bar2x = 900;int bar_my = 978; int pv2 =0;
    while(barx != 610){
        blit(fond, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(page,bar1, barx, 460);
        draw_sprite(page,bar2, bar2x, 270);
        draw_sprite(page,bar_menu, 0, bar_my);
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        if(bar_my >610){
            bar_my -=5;
        }
        barx= barx+10;
        bar2x = bar2x -10;
        rest(1);
    }

    int turn = 1;
    int frame = 0;
    int i =0;
    int pos_cursx=0;int pos_cursy=0;
    while (!key[KEY_S] && pv1 >= -160 && pv2 >= -210 ) {
        if(i == 2){i =0;}if(turn == 3){turn =1;}
        if(key[KEY_DOWN]){
            pos_cursy = 65;
        }
        if(key[KEY_UP]){
            pos_cursy =0;
        }
        if(key[KEY_RIGHT]){
            pos_cursx =310;
        }
        if(key[KEY_LEFT]){
            pos_cursx =0;
        }
        clear(page);
        blit(fond, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(page,bar1, barx, 460);
        draw_sprite(page,bar2, bar2x, 270);
        draw_sprite(page,bar_menu, 0, bar_my);
        rectfill(page,pos_cursx+ 46, pos_cursy+ 655,pos_cursx+20,pos_cursy+680, makecol(255,0,0));
        rectfill(page,barx+346,536,barx+346+pv1,546, makecol(255,255,255));
        rectfill(page,bar2x+390,361,bar2x+390+pv2,374, makecol(255,255,255));

        if(pos_cursy == 0 && pos_cursx ==0){
            draw_sprite(page,sword,780,630);
        }
        if(pos_cursy == 0 && pos_cursx ==310){
            draw_sprite(page,shield,780,630);
        }
        if(pos_cursy == 65 && pos_cursx ==0){
            draw_sprite(page,staff,780,630);
        }


        if(turn == 1){
            draw_sprite(page, s->sprite[i], 165, 382);
            draw_sprite(page, c->sprite_f[i], 690, 273);
        }if(turn == 2){
            draw_sprite(page, c->sprite[i], 165, 382);
            draw_sprite(page, s->sprite_f[i], 690, 273);
        }

        if(key[KEY_ENTER] && (pos_cursy == 0 && pos_cursx ==0)){
            if (turn == 1){
                s->attack1 = 1;
            }
            if (turn == 2){
                c->attack1 = 1;
            }
            turn++;
            rest(500);
        }
        if(key[KEY_ENTER] && (pos_cursy == 0 && pos_cursx ==310)){
            if (turn == 1){
                s->attack2 = 1;
            }
            if (turn == 2){
                c->attack2 = 1;
            }
            turn++;
            rest(500);
        }
        if(key[KEY_ENTER] && (pos_cursy == 65 && pos_cursx ==0)){
            if (turn == 1){
                s->attack3 = 1;
            }
            if (turn == 2){
                c->attack3 = 1;
            }
            turn++;
            rest(500);
        }
        if(turn ==3){
            if(s->attack1 && c->attack2){
                slashed(page,fond,bar_menu,s,c,250, 412,slash);
                pv1-=42;
            }
            else if(s->attack2 && c->attack3 ){
                slashed(page,fond,bar_menu,s,c,250, 412,slash);
                pv1-=42;
            }
            else if(s->attack3 && c->attack1 ){
                slashed(page,fond,bar_menu,s,c,250, 412,slash);
                pv1-=42;
            }
            else if(s->attack1 && c->attack3){
                slashed(page,fond,bar_menu,s,c,730,313,slash);
                pv2-=55;
            }
            else if(s->attack3 && c->attack2 ){
                slashed(page,fond,bar_menu,s,c,730,313,slash);
                pv2-=55;
            }
            else if(s->attack2 && c->attack1 ){
                slashed(page,fond,bar_menu,s,c,730,313,slash);
                pv2-=55;
            }
            s->attack1 =0;s->attack2 =0;s->attack3 =0;c->attack1 =0;c->attack2 =0;c->attack3 =0;
        }

        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        if(frame == 150 || frame == 300){
            i++;
        }
        frame++;
        if(frame == 301){
            frame = 0;
        }

        if(pv1 >= -160){
            player1->ticket--;
        }
        if(pv2 >= -210){
            player2->ticket--;
        }
    }
}

void pfc(t_player* player1,t_player* player2)  {

    bool end = true;
    bool exit = true;
    t_objet bord1 = {347,137,347,589};
    t_objet bord2 = {347,126,700,210};
    t_objet bord3 = {700,237,700,589};
    t_objet sortie = {500,590,550,600};
    t_objet pok1 = {630,265,650,270};
    t_objet pok2 = {595,265,610,270};
    t_objet pok3 = {570,265,590,270};

    BITMAP* fond, * fond2, * t0, * t1, * t2, * tup0, * tup1, * tup2, * ts0, * ts1, * ts2, * page;
    BITMAP* e1, * e2, * e3, * e_s1, * e_s2, * e_s3, * e_u1, * e_u2, * e_u3;

    BITMAP*frame1_s;BITMAP* frame2_s;
    BITMAP*frame1_c;BITMAP* frame2_c;
    BITMAP*frame1_b;BITMAP* frame2_b;

    BITMAP*face_s;BITMAP* face2_s;
    BITMAP*face_c;BITMAP* face2_c;
    BITMAP*face_b;BITMAP* face2_b;

    MIDI* snake_music = load_midi("../music/snake_music.mid");
    t0            = load_bitmap("../image_deplacement/t1.bmp",NULL);
    t1            = load_bitmap("../image_deplacement/t2.bmp",NULL);
    t2            = load_bitmap("../image_deplacement/t3.bmp",NULL);
    ts0           = load_bitmap("../image_deplacement/ts1.bmp",NULL);
    ts1           = load_bitmap("../image_deplacement/ts2.bmp",NULL);
    ts2           = load_bitmap("../image_deplacement/ts3.bmp",NULL);
    tup0          = load_bitmap("../image_deplacement/tu1.bmp",NULL);
    tup1          = load_bitmap("../image_deplacement/tu2.bmp",NULL);
    tup2          = load_bitmap("../image_deplacement/tu3.bmp",NULL);
    e1            = load_bitmap("../image_deplacement/img8.bmp",NULL);
    e2            = load_bitmap("../image_deplacement/img7.bmp",NULL);
    e3            = load_bitmap("../image_deplacement/img9.bmp",NULL);
    e_s1          = load_bitmap("../image_deplacement/img5.bmp",NULL);
    e_s2          = load_bitmap("../image_deplacement/img6.bmp",NULL);
    e_s3          = load_bitmap("../image_deplacement/img4.bmp",NULL);
    e_u1          = load_bitmap("../image_deplacement/img2.bmp",NULL);
    e_u2          = load_bitmap("../image_deplacement/img1.bmp",NULL);
    e_u3          = load_bitmap("../image_deplacement/img3.bmp",NULL);

    BITMAP* tab_depla1[] = {t0,t1,t2,tup0,tup1,tup2,ts0,ts1,ts2,};
    BITMAP* tab_depla2[] = {e1,e2,e3,e_u1,e_u2,e_u3,e_s1,e_s2,e_s3};

    frame1_s = load_bitmap("../image/frame1_s.bmp",NULL);frame2_s = load_bitmap("../image/frame2_s.bmp",NULL);
    frame1_c = load_bitmap("../image/frame1_c.bmp",NULL);frame2_c = load_bitmap("../image/frame2_c.bmp",NULL);
    frame1_b = load_bitmap("../image/frame1_b.bmp",NULL);frame2_b = load_bitmap("../image/frame_2b.bmp",NULL);

    face_s = load_bitmap("../image/face1_s.bmp",NULL);face2_s = load_bitmap("../image/face2_s.bmp",NULL);
    face_c = load_bitmap("../image/face1_c.bmp",NULL);face2_c = load_bitmap("../image/face2_c.bmp",NULL);
    face_b = load_bitmap("../image/face1_b.bmp",NULL);face2_b = load_bitmap("../image/face2_b.bmp",NULL);

    pokemon s = {1,1,1,2,3,frame1_s,frame2_s,0.7,face_s,face2_s};
    pokemon b = {2,2,4,5,6,frame1_b,frame2_b,0.6,face_b,face2_b};
    pokemon c = {3,3,7,8,9,frame1_c,frame2_c,0.5,face_c,face2_c};

    BITMAP* salameche;BITMAP* carapuce;BITMAP* bulbizarre;

    page = create_bitmap(1024,768);
    salameche = load_bitmap("../image/salamèche.bmp",NULL);
    carapuce = load_bitmap("../image/Carapuce.bmp",NULL);
    bulbizarre = load_bitmap("../image/Bulbizarre.bmp",NULL);
    fond = load_bitmap("../image/pokemon_lab.bmp",NULL);
    player1->x=510;
    player1->y=535;
    player1->mouv=0;
    player1->pokemon1 =NULL;
    player2->x=510;
    player2->y=500;
    player2->mouv=0;
    player2->pokemon1 =NULL;
    blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
    draw_sprite(page,tup0,player1->x,player1->y);
    draw_sprite(page,tup0,player2->x,player2->y);
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    while(exit){
        end = true;
        colision(player1,&bord1);
        colision(player1,&bord2);
        colision(player1,&bord3);
        if(player1->type == 2 && player2->type == 1){
            depla(player1,page,fond,tab_depla1);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            depla2(player2,page,fond,tab_depla2);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        if(player1->type == 1 && player2->type == 2){
            depla(player1,page,fond,tab_depla2);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            depla2(player2,page,fond,tab_depla1);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        if(colision(player1,&pok1)){
            rectfill(page,360,265,660,435, 0);
            rectfill(page,365,270,655,430, makecol(255,255,255));
            textout_centre_ex(page,font,"Appuie sur c pour choisir  salameche ",512,290,0,-1);
            while (end){
                draw_sprite(page,salameche,480,330);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                if (key[KEY_ENTER]){
                    end = false;
                }
                if (key[KEY_C]){
                    player1->pokemon1 = &s;
                    end = false;
                }
            }
        }
        if(colision(player1,&pok2)){
            rectfill(page,360,265,660,435, 0);
            rectfill(page,365,270,655,430, makecol(255,255,255));
            textout_centre_ex(page,font,"Appuie sur c pour choisir carapuce ",512,290,0,-1);
            while (end){
                draw_sprite(page,carapuce,480,330);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                if (key[KEY_ENTER]){
                    end = false;
                }
                if (key[KEY_C]){
                    player1->pokemon1 = &c;
                    end = false;
                }
            }
        }
        if(colision(player1,&pok3)){
            rectfill(page,360,265,660,435, 0);
            rectfill(page,365,270,655,430, makecol(255,255,255));
            textout_centre_ex(page,font,"Appuie sur c pour choisir bulbizarre",512,290,0,-1);
            while (end){
                draw_sprite(page,bulbizarre,480,330);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                if (key[KEY_ENTER]){
                    end = false;
                }
                if (key[KEY_C]){
                    player1->pokemon1 = &b;
                    end = false;
                }
            }
        }
        if(colision(player2,&pok1)){
            rectfill(page,360,265,660,435, 0);
            rectfill(page,365,270,655,430, makecol(255,255,255));
            textout_centre_ex(page,font,"Appuie sur c pour choisir  salameche ",512,290,0,-1);
            while (end){
                draw_sprite(page,salameche,480,330);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                if (key[KEY_ENTER]){
                    end = false;
                }
                if (key[KEY_C]){
                    player2->pokemon1 = &s;
                    end = false;
                }
            }
        }
        if(colision(player2,&pok2)){
            rectfill(page,360,265,660,435, 0);
            rectfill(page,365,270,655,430, makecol(255,255,255));
            textout_centre_ex(page,font,"Appuie sur c pour choisir carapuce ",512,290,0,-1);
            while (end){
                draw_sprite(page,carapuce,480,330);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                if (key[KEY_ENTER]){
                    end = false;
                }
                if (key[KEY_C]){
                    player2->pokemon1 = &c;
                    end = false;
                }
            }
        }
        if(colision(player2,&pok3)){
            rectfill(page,360,265,660,435, 0);
            rectfill(page,365,270,655,430, makecol(255,255,255));
            textout_centre_ex(page,font,"Appuie sur c pour choisir bulbizarre",512,290,0,-1);
            while (end){
                draw_sprite(page,bulbizarre,480,330);
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                if (key[KEY_ENTER]){
                    end = false;
                }
                if (key[KEY_C]){
                    player2->pokemon1 = &b;
                    end = false;
                }
            }
        }
        if(colision(player1,&sortie)){
            exit = false;
        }
        if( player1->pokemon1 != NULL && player2->pokemon1 != NULL){
            rest(1000);
            play_midi(snake_music, true);
            fight(player1->pokemon1,player2->pokemon1,page,player1,player2);
        }
    }
}