---
marp: true
theme: projet
paginate: true
_paginate: false
---

<script type="module">
  import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
    mermaid.initialize({ 
        startOnLoad: true,
        theme: 'base',
    });
</script>

<!--
# Style lead only for this slide
_class: lead
_footer: Algorithmique Avancée et Bibliothèque Graphique - 2022-2023
-->

![bg left](./images/fond_ece.png)

**ING1** Projet d'informatique


# ECE World

Equipe 57 - TD 1

---

# Equipe 57

![bg right:50%](./images/equipe.avif)

- Alexandre Charvet
- Matthias Aubert
- Maximiliano Berté
- Ronan Meyer-Roussilhon

---

# ECE World

![bg right:50% 198%](./images/theme.webp)

## Thème

Lorem ipsum dolor sit amet, **consectetur** adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. 

---

# Carte `1/2`

*Réalisée par : **Alexandre**, **Ronan**, **Matthias**, **Maximiliano**.*

Décrire ici les fonctionnalités implémentées : choix joueurs, saisie des noms, affichage des scores/classement... Comment avez-vous fait ? Quels étaient les problèmes rencontrés.

---

# Carte `2/2`

Suite si ça ne tient pas sur une slide. 

:bulb: *Vous pouvez faire comme ça à chaque fois qu'une slide ne suffit pas, il vaut mieux 5 slides légères qu'une surchargée.*

---

# Organisation des jeux

Précisez comment les jeux sont organisés ? Sont-ils dans des fichiers séparés ? Dans des dossiers ? Sont-ils éparpillés dans plusieurs fichiers ?

Quels paramètres prennent les jeux ?  La file d'événement par exemple ? Ou est-ce que chaque jeu crée sa propre file ?

Comment on lance un jeu et comment on revient à la carte à la fin de la partie ?
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
- Ajoutez structures + graphe d'appel (logigramme optionnel)
<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>
---

![bg right:40%](images/peche_canards.jpg)

# Snake

*Réalisé par : **Alexandre**.*

Voir template jeu

---
![bg right:40%](images/peche_canards.jpg)

# Guitar Hero

*Réalisé par : **Matthias**.*

Voir template jeu

---

![bg right:40%](images/peche_canards.jpg)

# Pari Hippique

*Réalisé par : **Ronan**.*

Voir template jeu

---
![bg right:40%](images/peche_canards.jpg)

# Taupe-la

*Réalisé par : **Maximiliano**.*

Voir template jeu

---

![bg right:40%](images/peche_canards.jpg)

# Pierre - Feuille - Cisaux (style pokémon)

*Réalisé par : **Alexandre**.*

Voir template jeu

---

![bg right:40%](images/peche_canards.jpg)

# Jackpot

*Réalisé par : **Matthias**.*

Voir template jeu

---

![bg right:40%](screenshot-tir_aux_ballons.png)

# Tir aux Ballons

*Réalisé par : **Ronan**.*

- 7 pokémons avec une vitesse aléatoire se déplacent sur l'écran en rebondissant sur les bords
- Lorsqu'on clique dessus, ils disparaissent de l'écran
- La souris est matérialiser par une pokéball qui s'ouvre et qui se ferme
- Le gagnant est celui qui attrape tous les pokémons en un temps inférieur

### Structure
[comment]: <> "Presentation de ma structure"
<div class="mermaid"> 
%%{init: {'theme':'neutral'}}%%
classDiagram
    class Ballons
    Ballons : int posx, posy
    Ballons : int depx, depy
    Ballons : int type
    Ballons : int attrape
    Ballons : BITMAP * poke
</div>

### Tableaux

- `Canard canards[20]`

---

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    pecheAuxCanards --> initialiserCanards
    initialiserCanards --> positionnerCanard
    pecheAuxCanards --> deplacerCanards
    deplacerCanards --> deplacerCanard
    pecheAuxCanards --> detecterCollisionCanards
</div>


---

![bg right:40%](images/peche_canards.jpg)

# Pêche aux canards

### Logigramme

Que vous jugez pertinent (image ou Mermaid.js)



---

# Bilan collectif

---

<!--
_class: lead
-->

# Les slides suivantes ne seront pas présentées oralement lors de la soutenance mais doivent figurer dans la présentation. Nous les survolerons rapidement.

---

# Toto

## Tâches réalisées (pour chaque membre de l'équipe)

- `✅ 100%` Tâche 1
- `✅ 80%` Tâche 2
    - *Développer ici pourquoi cette tâche n'est pas terminée à 100%. (exemple : on aurait pu améliorer...).*
- `❌ 20%` Tâche 3
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*
- `❌ 20%` Tâche 4
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*

---

# Investissement

Si vous deviez vous répartir des points, comment feriez-vous ?

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
pie showData
    "Toto Jojo" : 20
    "Tata Jaja" : 20
    "Tyty Jyjy" : 10
    "Tutu Juju" : 40
    "Titi Jiji" : 10
</div>

---

# Récapitulatif des jeux

| Jeu | Avancement | Problèmes / reste |
| --- | --- | --- |
| Pêche aux canards | 100% | - |
| Tir aux ballons | 100% | - |
| Guitar Hero | 60% | Ne se synchronise pas avec la musique. Bug lors de l'appui sur deux touches en même temps (ne traite que la première note). |

Vous pouvez faire ce tableau sur plusieurs slides en dupliquant l'en-tête.

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
