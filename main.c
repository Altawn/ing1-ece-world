#include <stdio.h>
#include <allegro.h>
#define NIMAGE 5

typedef struct
{
    BITMAP * img[NIMAGE];
    int posx, posy;
    int tx, ty;
    int depx, depy;
    int frame_act; //frame actuelle du pokemon
    int compteur;
}Pokemon, *Pok;

Pokemon init_magicarpe();
Pokemon init_papillusion();
void init_allegro();
void dessin_frame(Pokemon* animation, int x, int y, BITMAP * page);
void animation_sprite(Pokemon*animation);

int main()
{
    //Initialisation Allegro
    init_allegro();

    //Supposant qu'on prend les deux variables pari gagnant du joueur
    int pari_gagnant_j1 = 0;
    int pari_gagnant_j2 = 0;

    //Autres variables + structures
    Pokemon Magicarpe = init_magicarpe();
    //Pokemon Papillusion = init_papillusion();
    BITMAP * page = NULL;

    //Double buffer
    page = create_bitmap(800, 600);
    clear_bitmap(page);
    if(!page) allegro_message("Erreur creation page");

    //draw_sprite(page, Magicarpe.im_1, 0, 0);
    //draw_sprite(page, Papillusion.im_1, 100, 0);

    //Boucle d'evenements
    while (!key[KEY_ESC])
    {
        clear_bitmap(page);
        draw_sprite(page, Magicarpe.img[Magicarpe.frame_act], 0, 0);
        //acquire_screen();
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        //release_screen();
        //clear_to_color(page, makecol(255, 255, 255));
        //animation_sprite(&Magicarpe);
        //dessin_frame(&Magicarpe, 100, 100, page);
        rest(200);
        Magicarpe.frame_act++;
        if(Magicarpe.frame_act >= NIMAGE) Magicarpe.frame_act = 0;
        //draw_sprite(page,Magicarpe.im_1,0,0);
        //draw_sprite(page, Papillusion.im_1, 0, 100);
        //blit(page,screen,0, 0, 0, 0, SCREEN_W,SCREEN_H);
    }

    allegro_exit();
    return 0;
}END_OF_MAIN()

Pokemon init_magicarpe()
{
    char nomfichier[256];

    Pokemon Magicarpe =
            {
                    .tx = 80,
                    .ty = 95,
                    .posx = 0,
                    .posy = 0,
                    .depx = 0,
                    .depy = 0,
                    .frame_act = 0,
                    .compteur = 0
            };

    for (int i = 0; i < NIMAGE; ++i) {
        sprintf(nomfichier, "80x95-Magicarpe%d.bmp", i + 1);

        Magicarpe.img[i] = load_bitmap(nomfichier, NULL);
        if (!Magicarpe.img[i]) {
            allegro_message("Fichier %s non existant", nomfichier);
            exit(EXIT_FAILURE);

        }
    }
    return Magicarpe;
}

/*Pokemon init_papillusion()
{
    Pokemon Papillusion =
            {
                    .im_1 = load_bitmap("80x95-Papillon.bmp",  NULL),
                    .im_2 = load_bitmap("80x95-Papillon2.bmp",  NULL),
                    .im_3 = load_bitmap("80x95-Papillon3.bmp", NULL),
                    .im_4 = load_bitmap("80x95-Papillon4.bmp", NULL),
                    .im_5 = load_bitmap("80x95-Papillon5.bmp", NULL),
                    .tx = 0,
                    .ty = 0,
                    .posx = 0,
                    .posy = 0,
                    .depx = 0,
                    .depy = 0
            };
    if(!Papillusion.im_1 || !Papillusion.im_2 || !Papillusion.im_3 || !Papillusion.im_4 || !Papillusion.im_5)
    {
        allegro_message("pb chargement image Papillusion");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return Papillusion;
}
*/

void init_allegro()
{
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

void dessin_frame(Pokemon* animation, int x, int y, BITMAP * page)
{
    BITMAP * frame = animation->img[animation->frame_act];
    masked_blit(frame, page, 0, 0, x, y, 80, 95);
}

void animation_sprite(Pokemon*animation)
{
    rest(20);
    animation->frame_act += 1;
    if(animation->frame_act > NIMAGE) animation->frame_act = 0;
}