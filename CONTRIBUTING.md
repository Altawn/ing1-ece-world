# Guide de Contribution

Merci de votre intérêt pour contribuer au projet ECE Pokémon World ! Ce document établit les règles et bonnes pratiques pour maintenir un code de qualité.

## 📋 Structure du Repository

Avant de contribuer, familiarisez-vous avec la structure du projet :

```
src/        - Code source C
include/    - Headers
assets/     - Ressources (images, sons)
data/       - Données (scores)
docs/       - Documentation
```

**Règle importante** : Respectez cette structure. Ne placez pas de fichiers .c à la racine.

## 🔀 Workflow Git

### Branches

- `main` : Branche principale stable
- `develop` : Branche de développement
- `feature/nom-feature` : Nouvelles fonctionnalités
- `fix/nom-bug` : Corrections de bugs
- `refactor/nom-refactor` : Refactorisation

### Créer une Nouvelle Branche

```bash
# Depuis la branche main ou develop
git checkout -b feature/ma-nouvelle-fonctionnalite

# Ou pour un bug fix
git checkout -b fix/correction-bug-snake
```

## 📝 Conventions de Commit

Utilisez des messages de commit clairs et descriptifs en français.

### Format

```
Type: Description courte (max 50 caractères)

Description détaillée si nécessaire (max 72 caractères par ligne).
Expliquez le "pourquoi" plus que le "quoi".

Fixes #issue_number (si applicable)
```

### Types de Commit

- **feat**: Nouvelle fonctionnalité
- **fix**: Correction de bug
- **docs**: Modification de documentation
- **style**: Formatage, espaces, etc. (pas de changement de code)
- **refactor**: Refactorisation sans ajout de fonctionnalité
- **test**: Ajout ou modification de tests
- **chore**: Tâches de maintenance (build, config, etc.)

### Exemples

```bash
git commit -m "feat: Ajout du jeu Taupe La avec système de score"

git commit -m "fix: Correction du crash lors du chargement des sprites Snake"

git commit -m "refactor: Déplacement des fichiers images dans assets/"

git commit -m "docs: Mise à jour du README avec instructions de compilation"
```

## 💻 Conventions de Code

### Style C

- **Indentation** : 4 espaces (pas de tabulations)
- **Accolades** : Style K&R
```c
void fonction() {
    if (condition) {
        // code
    }
}
```
- **Noms de variables** : snake_case
```c
int score_joueur;
t_player* player_one;
```
- **Noms de fonctions** : snake_case avec préfixe du module
```c
void snake_init();
void jackpot_spin();
void pfc_fight();
```
- **Constantes** : MAJUSCULES
```c
#define MAX_PLAYERS 2
#define SCREEN_WIDTH 1024
```

### Commentaires

```c
// Commentaire court sur une ligne

/*
 * Commentaire multi-lignes
 * pour expliquer une logique complexe
 */

/**
 * Documentation de fonction (optionnel mais recommandé)
 * @param player Pointeur vers la structure joueur
 * @return Code d'erreur ou 0 si succès
 */
int init_player(t_player* player);
```

## 🎨 Assets et Ressources

### Ajout de Nouvelles Images

1. Placez les images dans le bon sous-dossier de `assets/images/`
2. Utilisez des noms descriptifs en snake_case : `sprite_pikachu_attaque.bmp`
3. Préférez PNG à BMP pour de nouvelles images (meilleure compression)
4. Documentez l'ajout dans `assets/README.md` si nécessaire

### Ajout de Sons

1. Placez les fichiers dans `assets/sounds/`
2. Format MIDI recommandé (.mid)
3. Noms descriptifs : `musique_combat.mid`, `effet_victoire.mid`

## ✅ Checklist Avant Commit

- [ ] Le code compile sans erreurs ni warnings
- [ ] Le code respecte les conventions de style
- [ ] Les chemins vers les assets sont corrects
- [ ] Les commentaires sont clairs et utiles
- [ ] Pas de fichiers temporaires ou de build dans le commit
- [ ] Le message de commit est clair et suit les conventions

## 🚀 Pull Requests

### Avant de Soumettre

1. Assurez-vous que votre branche est à jour avec `main`
```bash
git checkout main
git pull
git checkout votre-branche
git merge main
```

2. Testez votre code
```bash
mkdir build && cd build
cmake ..
cmake --build .
./PROJET
```

3. Vérifiez les fichiers modifiés
```bash
git status
git diff
```

### Description de la PR

Incluez dans la description :
- **Objectif** : Qu'est-ce que cette PR accomplit ?
- **Changements** : Liste des modifications majeures
- **Tests** : Comment avez-vous testé ?
- **Screenshots** : Pour les changements visuels
- **Notes** : Informations additionnelles

### Exemple de Description

```markdown
## Objectif
Ajout d'un nouveau mini-jeu "Qui est ce Pokémon ?"

## Changements
- Nouveau fichier src/quiz_pokemon.c
- Ajout de sprites dans assets/images/quiz/
- Mise à jour du menu principal
- Ajout de la fonction quiz_pokemon() dans head.h

## Tests
- Compilation : ✅
- Jeu fonctionnel : ✅
- Pas de régression sur autres jeux : ✅

## Notes
Les sprites utilisent le format PNG. Nécessite liballegro avec support PNG.
```

## 🐛 Signaler un Bug

Ouvrez une issue avec :
- **Titre** : Description courte du bug
- **Description** : Étapes pour reproduire
- **Comportement attendu** : Ce qui devrait se passer
- **Comportement actuel** : Ce qui se passe réellement
- **Environnement** : OS, version de GCC, version d'Allegro
- **Logs/Screenshots** : Si disponibles

## 📞 Contact

Pour toute question sur le processus de contribution, contactez l'équipe de développement.

---

**Merci de contribuer au projet ECE Pokémon World ! 🎮**
