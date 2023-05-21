---

marp: true
theme: default
class : invert
paginate: true
_paginate: false

---

<script type="module">
  import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
    mermaid.initialize({ 
        startOnLoad: true,
        theme: 'forest',
    });
</script>

<!--
# Style lead only for this slide
_class: lead
_footer: Algorithmique Avancée et Bibliothèque Graphique - 2022-2023
-->

![bg left](./images/fond_ece.png)

**ING1** Projet d'informatique


# ECE World :muscle::trident:

Equipe 57 - TD 1

---

# Equipe 57  :bangbang:

![bg right:50%](./images/equipe.avif)
  
- Alexandre Charvet
- Matthias Aubert
- Maximiliano Berté
- Ronan Meyer-Roussilhon

---

# ECE World :circus_tent:

![bg right:50%](images/poke_world.jpg)

## Thème 

- Basé sur Pokemon gen.1 et gen.2
- Map : Pokemon
- Personnages : Pokemon

---

# <!--fit--><!--_color: black-->Carte :scroll:
![bg blur:5px](images/Map.jpeg)

---

![bg blur](images/Map.jpeg)
<!--_color: black-->
# <p style="text-align: center;">Carte :sparkler: `1/2`</p>

<p style="text-align: center;"> * Les joueurs ont un personnage à choisir chacun sur deux présents</p>
<p style="text-align: center;"> * Le personnage est animé sur la carte</p>
<p style="text-align: center;"> * Saisie des noms par clavier avec readkey()</p>
<p style="text-align: center;"> * Affichage des scores et classement...</p>
<p style="text-align: center;"> * Problemes rencontres ...</p>

---

![bg blur](images/Map.jpeg)
<!--_color: black-->
# <p style="text-align: center;">Carte :sparkler: `2/2`</p>

<p style="text-align: center;"> * La carte est le menu</p>
<p style="text-align: center;"> * Statistiques par attraction ?</p>
<p style="text-align: center;"> * Les joueurs ont 5 tickets au départ</p>
<p style="text-align: center;"> * A chaque jeu gagné par un joueur, l'autre perd un ticket</p>

---

# Organisation des jeux :moneybag: `1/3`

Précisez comment les jeux sont organisés ? Sont-ils dans des fichiers séparés ? Dans des dossiers ? Sont-ils éparpillés dans plusieurs fichiers ?

 - <initiale_du_jeu>_programmes.c : Tous les sous-programmes de chacun des jeux
 - <nom_du_jeu> : Programme principal appelant tous les SP d'un jeu
 - "head.h" : header commun à tous, avec des parties préfaites pour main et jeux
 - Les images sont dans des fichiers pour une meilleur lisibilité du GitHub

---

# Organisation des jeux :moneybag: `2/3`

Quels paramètres prennent les jeux ?  La file d'événement par exemple ? Ou est-ce que chaque jeu crée sa propre file ?

 - Notre jeu est organisé autour d'une structure principale :
 - structure
 - structure
 - structure

 - On envoie à chaque jeu deux pointeurs de stuctures pour joueur 1 et joueur 2 :
 ```C
void jeu_random(t_player * player, t_player * player2);
 ```
---

# Organisation des jeux :moneybag: `3/3`

Comment on lance un jeu et comment on revient à la carte à la fin de la partie ?
 - Les jeux sont lancés avec une collision avec leurs batiments respectifs
 - Le retour à la carte est fait par la touche 'entrée'

Comment le classement est-il mis à jour ?

---

# Template jeu - a enlever dans presentation finale

*Réalisé par : **votre nom**.*

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.
Pour chaque jeu (bien détailler au moins un jeu par personne), précisez les structures de données (structures importantes, tableaux importants, listes chainées...) et les fonctions importantes (avec leur prototype).
- ajoutez graphe d'appel->voir plus bas pour details (logigramme optionnel)
<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>
---

# <!--fit--><!--_color: black-->Attractions :tada:
![bg blur:5px](images/pokepark.bmp)

---

![bg left:35%](images/snake.png)

# Snake :snake:

*Réalisé par : **Alexandre**.*

## Résumé :
- Un serpent avance selon les touche préssées
- l'objectif est d'atteindre les rochers pour allonger le serpent
- un nouveau rocher est géneré aléatoirement a chaque fois que le précédent est attenit
- les joueurs doivent obtenir le plus de rocher possible sans rentrer dans les bords ni les dans sa queue

---
![bg right:35%](images/snake.png)

## Listes chainées principales :

typedef struct snake {
-       int x;
        int y;
        BITMAP* base;
        struct snake* next;
}t_snake;

typedef struct liste{
-       t_snake* head;
}t_liste;

---
![bg left:35%](images/snake.png)

# Snake :snake:
<br>

<div class="mermaid">
%%{init: {'theme':'dark'}}%%
flowchart LR
initialisation --> pomme_init --> move_snake-->collision_snake 
collision_snake --> addpart --> pomme_init
move_snake --> end_snake --> end_
 
</div>

---
![bg right:35%](images/peche_canards.jpg)

# Guitar Hero :guitar:

*Réalisé par : **Matthias**.*

Voir template jeu

---

![bg left:35%](images/le_vrai.bmp)

# Pari Hippique :horse_racing:

*Réalisé par : **Ronan**.*

## Résumé :
- 5 pokemons avance de gauche à droite
- Ils sont animés
- Leur déplacement est aléatoire, modifié souvent
- Les joueurs parient sur un pokemon chacun
- L'écran de fin prend un compte toutes les fins

---

![bg left:35%](images/le_vrai.bmp)

# Pari Hippique :horse_racing:

## Structure maître :

<div style="margin-left: auto;
            margin-right: auto;
            width: 40%">

| Struct Pokemon |
| --- | 
| int posx, posy | 
| int depx | 
| int pok (type) | 
| int frame_act | 
| BITMAP* img[4] | 

</div>

---

![bg left:35%](images/le_vrai.bmp)

# Pari Hippique :horse_racing:

<br>

<div class="mermaid">
%%{init: {'theme':'dark'}}%%
flowchart LR
Pari_Hippique --> PI_remp_tab_pok
PI_remp_tab_pok --> PI_init_pokemon
Pari_Hippique --> PI_entree_jeu
PI_entree_jeu --> PI_affichage_liste
Pari_Hippique --> PI_navigation
Pari_Hippique --> PI_navigation
PI_navigation  --> PI_choix_pok
Pari_Hippique --> PI_depla_pok
PI_depla_pok  --> PI_anim_pok
PI_print_gagnant --> PI_pok_gagnant
Pari_Hippique --> PI_print_gagnant  
</div>

---
![bg right:40%](images/maptaupela.jpeg)

# Taupe-la :hammer:
* Réalisé par : **Maximiliano**.
## Resumé :

* Un pokémon apparaît a une position aléatoire sur la map
* le pokemon change de position toute les quelques secondes.
* le joueur doit utiliser sa souris et son clic gauche pour cliquer sur le pokemon lorsqu'il apparaît
* les joueurs jouent chacun leurs tour 

---
![bg right:40%](images/maptaupela.jpeg)

# Taupe-la :hammer:

## fonctionnement génerale
### boucle while :
* variable aléatoire qui définit la position du sprite et l'affiche sur la page
* affichage d'une page blanche pour recouvrir l'ancien sprite 
* lorsque le sprite est cliqué le joueur gagne 1 point 


---

![bg right:40%](images/maptaupela.jpeg)

# Taupe-la :hammer:

<br>

<div class="mermaid">
%%{init: {'theme':'dark'}}%%
flowchart LR
Finale_TP --> fond_ecran 

jeu_maximiliano-->fond_ecran-->jeu_maximiliano
 
</div> 

---

![bg left:35%](images/peche_canards.jpg)

# Pierre:rock: - Feuille:page_facing_up: - Cisaux:scissors:

*Réalisé par : **Alexandre**.*

Voir template jeu

---

![bg right:35%](images/peche_canards.jpg)

# Jackpot :slot_machine:

*Réalisé par : **Matthias**.*

Voir template jeu

---

![bg left:35%](images/screenshot-tir_aux_ballons.png)

# Tir aux Ballons :balloon:`1/3`

*Réalisé par : **Ronan***

## Résumé :

- 7 pokémons se déplacent sur l'écran avec une vitesse aléatoire 
- Lorsqu'on clique dessus, ils disparaissent de l'écran
- La souris est matérialisé par une pokéball qui s'ouvre et qui se ferme
- Le gagnant est celui qui attrape tous les pokémons en un temps inférieur

---

![bg left:35%](images/TB.png)

# Tir aux Ballons :balloon:`2/3`

## Structure maître :

<div style="margin-left: auto;
            margin-right: auto;
            width: 40%">

| Struct Ballons |
| --- | 
| int posx, posy | 
| int depx, depy | 
| int type | 
| int attrape | 
| BITMAP* poke | 

</div>


---

![bg left:35%](images/screenshot-tir_aux_ballons.png)

# Tir aux Ballons :balloon:`3/3`

## Graphe d'appel :

<br>

<div class="mermaid">
%%{init: {'theme':'dark'}}%%
flowchart LR
    Tir_ballons --> TB_entree_jeu
    Tir_ballons --> TB_jeu
    Tir_ballons --> TB_resultats
    Tir_ballons --> TB_entree_jeu
    Tir_ballons --> TB_jeu
    TB_jeu --> TB_remp_tab_pok
    TB_jeu --> TB_anim_pok
    TB_jeu --> TB_click_souris
    TB_jeu --> TB_condition_attrap
    TB_remp_tab_pok --> TB_init_struct 
</div>


---

![bg right:40%](images/peche_canards.jpg)

# Pêche aux canards

### Logigramme

Que vous jugez pertinent (image ou Mermaid.js)



---

# Bilan collectif

- Bonne organisation de groupe et cohésion
- Beaucoup d'amusement avec ce projet -> meilleur travail
- Découverte de nouveaux outils ( Git, Github et Marp )

---

<!--
_class: lead
-->

# Les slides suivantes ne seront pas présentées oralement lors de la soutenance mais doivent figurer dans la présentation. Nous les survolerons rapidement.

---

# Tâches réalisées (pour chaque membre) `1/2`

- `✅ 100%` Exemple
- `✅ 90%`  Exemple
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*

- `❌ 20%` Exemple
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*
- `❌ 20%` Exemple
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*

---

# Tâches réalisées (pour chaque membre) `1/2`

- `✅ 100%` Exemple
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*
- `✅ 90%`  Exemple
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*

- `❌ 20%` Exemple
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*

---

# Investissement

<div class = "mermaid">
%%{init: {'theme':''}}%%
pie title Organisation de l'équipe
    "Maximiliano" : 15
    "Ronan" : 25
    "Matthias" : 25
    "Alexandre" : 35
</div>

---

# Récapitulatif des jeux

| Jeu | Avancement | Problèmes / reste |
| --- | --- |  --- |
| PFC | 100% | - |
| Tir aux ballons | 90% | Touche ECHAP permet de gagner le jeu |
| Guitar Hero | 100% | - |
| Pari hippique | 95% | Fond et taille des pokemons mal calibrés |
| Snake | 100% | - |
| Taupe-la | 100% | - |
| Jackpot | 100% | - |

---

<!--
_class: lead
-->
# Quelques éléments que vous pouvez utiliser à votre guise dans votre présentation

---

# Schémas et Graphes

Vous pouvez utiliser [Mermaid.js](https://mermaid.js.org/) pour générer des schémas. Regardez la documentation.

---

# Slide avec du code


```C
for(int i = 0; i < 5; i++) {
    printf("%d ", i);
}
```

> 0 1 2 3 4 


---

# Emojis

https://gist.github.com/rxaviers/7360908

---

# Thème 

Vous pouvez personnaliser l'affichage de votre présentation avec le langage CSS en modifiant le fichier `theme.css`.

---

# Export PDF

Depuis récemment, l'export (**`Export Slide Deck...`**) en PDF oublie parfois des éléments. 
Si c'est le cas, nous vous conseillons d'exporter en fichier PowerPoint (pptx), puis de l'exporter en PDF depuis PowerPoint.
