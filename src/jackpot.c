#include "head.h"

void tournee_debut_jackpot(int vitesse,int y[3]){

    for (int i = 0; i < 3; ++i) {
        y[i] += vitesse;

        if (y[i] > 500) {
            y[i] = 95;
        }

    }

}



void arret_tour_jackpot(int vitesse,int y[3],int *arret){

    for (int i = 0; i < 3; ++i) {
        if(y[i]<341 && y[i]>330){
            y[i]=335;
            *arret=i;


        }
        y[i]+=vitesse;
        if (y[i] > 500) {
            y[i] = 95;
        }

    }
}

void start_jackpot(){

    BITMAP* start;

    start=load_bitmap("../assets/images/start_jackpot.bmp",NULL);

    while(!key[KEY_ENTER]){
        blit(start,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        textprintf_ex(start,font,680,50,makecol(0,0,0),-1,"APPUYEZ SUR ENTRER POUR CONTINUER");
    }

}
int jackpot_debut(){

    BITMAP* fond_ecran;
    BITMAP* page=NULL;



    BITMAP* gauche[3];
    BITMAP* milieu[3];
    BITMAP* droite[3];



    fond_ecran=load_bitmap("../assets/images/fond_ecran_jackpot.bmp",NULL);

    page=create_bitmap(SCREEN_W,SCREEN_W);
    gauche[0]=load_bitmap("../assets/images/tete_carapuce_jackpot.bmp",NULL);
    gauche[1]=load_bitmap("../assets/images/tete_dracaufeu_jackpot.bmp",NULL);
    gauche[2]=load_bitmap("../assets/images/tete_rondoudou_jackpot.bmp",NULL);

    milieu[0]=load_bitmap("../assets/images/tete_carapuce_jackpot.bmp",NULL);
    milieu[1]=load_bitmap("../assets/images/tete_dracaufeu_jackpot.bmp",NULL);
    milieu[2]=load_bitmap("../assets/images/tete_rondoudou_jackpot.bmp",NULL);

    droite[0]=load_bitmap("../assets/images/tete_carapuce_jackpot.bmp",NULL);
    droite[1]=load_bitmap("../assets/images/tete_dracaufeu_jackpot.bmp",NULL);
    droite[2]=load_bitmap("../assets/images/tete_rondoudou_jackpot.bmp",NULL);

    clear_to_color(page,makecol(255,255,255));

    int y_gauche[3];
    int y_milieu[3];
    int y_droite[3];

    y_gauche[0]=162;
    y_gauche[1]=297;
    y_gauche[2]=432;

    y_milieu[0]=162;
    y_milieu[1]=297;
    y_milieu[2]=432;

    y_droite[0]=162;
    y_droite[1]=297;
    y_droite[2]=432;

    int verif=0;
    int alea[3];
    int nbr_boucle=0;
    int vitesse[3];
    int test[3];
    int ticket=0;
    int time_entre_fonctions=0;


    srand(time(NULL));

    start_jackpot();


    while(!key[KEY_SPACE] || verif==0 ){

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        clear_to_color(page,makecol(255,255,255));


        for (int i = 0; i < 3; ++i) {
            draw_sprite(page,gauche[i],200,y_gauche[i]);
            draw_sprite(page,milieu[i],460,y_milieu[i]);
            draw_sprite(page,droite[i],720,y_droite[i]);
        }
        draw_sprite(page,fond_ecran,0,0);


        if(key[KEY_ENTER] && verif==0 && nbr_boucle>100) {
            verif=1;
            nbr_boucle=0;
            for (int i = 0; i < 3; ++i) {
                vitesse[i]=rand()%10 +1;
                alea[i]=rand()%1000 +200;
                test[i]=5;
            }


        }

        if(verif==0){
            textprintf_ex(page,font,145,590,makecol(0,0,0),-1,"APPUYEZ SUR ENTREE POUR TENTER TA CHANCE");
        }


        if(verif==1 && nbr_boucle<alea[0]){
            tournee_debut_jackpot(vitesse[0],y_gauche);
        }else if(verif==1 && test[0]==5){
            arret_tour_jackpot(vitesse[0],y_gauche,&test[0]);
        }


        if(verif==1 && nbr_boucle<alea[1]){
            tournee_debut_jackpot(vitesse[1],y_milieu);
        }else if(verif==1 && test[1]==5){
            arret_tour_jackpot(vitesse[1],y_milieu,&test[1]);
        }


        if(verif==1 && nbr_boucle<alea[2]){
            tournee_debut_jackpot(vitesse[2],y_droite);
        }else if(verif==1 && test[2]==5){
            arret_tour_jackpot(vitesse[2],y_droite,&test[2]);
        }

        if(test[0]==test[1] && test[1]==test[2] && verif==1 && test[0]!=5 && test[1]!=5 && test[2]!=5){
            textprintf_ex(page,font,290,585,makecol(0,0,0),-1,"BRAVO");
            textprintf_ex(page,font,175,605,makecol(0,0,0),-1,"APPUYEZ SUR ESPACE POUR CONTINUER");
            if(test[0]==0){
                //  printf("1 ticket");
                ticket=1;
            } if(test[0]==1){
                //   printf("3 ticket");
                ticket=3;
            } if(test[0]==2){
                //  printf("2 ticket");
                ticket=2;
            }
        }else if(verif==1 && test[0]!=5 && test[1]!=5 && test[2]!=5){
            textprintf_ex(page,font,290,585,makecol(0,0,0),-1,"PERDU");
            textprintf_ex(page,font,175,605,makecol(0,0,0),-1,"APPUYEZ SUR ESPACE POUR CONTINUER");
            ticket=-1;
        }

        nbr_boucle+=1;
    }

    return ticket;

}

void jackpot(t_player* player,t_player* player2){
    int ticket[2];

    for (int i = 0; i < 2; ++i) {
        ticket[i]=0;
        ticket[i]=jackpot_debut();
        printf("%d\n",ticket[i]);
    }
    score_modif(ticket[0],5,player->name);
    score_modif(ticket[1],5,player2->name);
    player->ticket+=ticket[0];
    player2->ticket+=ticket[1];

}