# ECE Pokémon World - Projet Ing1

Un projet de jeu interactif en C utilisant la bibliothèque Allegro 4, développé par des étudiants de l'ECE Paris.

## 📁 Structure du Projet

```
ing1-ece-world/
├── src/                    # Code source (.c)
│   ├── main.c             # Point d'entrée du programme
│   ├── deplacement.c      # Gestion des déplacements
│   ├── print_chen.c       # Affichage et dialogues
│   ├── Snake_programmes.c # Jeu du Snake
│   ├── Guitar_hero.c      # Jeu Guitar Hero
│   ├── jackpot.c          # Jeu du Jackpot
│   ├── pfc.c              # Pierre-Feuille-Ciseaux
│   ├── PH_programmes.c    # Pari Hippique
│   ├── TB_programmes.c    # Tir aux Ballons
│   ├── TP_programmes.c    # Taupe La
│   └── petite_fonction.c  # Fonctions utilitaires
├── include/               # Headers (.h)
│   └── head.h            # Déclarations et structures
├── assets/               # Ressources du jeu
│   ├── images/          # Images et sprites
│   │   ├── pfc/        # Images pour Pierre-Feuille-Ciseaux
│   │   ├── snake/      # Images pour le Snake
│   │   ├── deplacement/# Sprites de déplacement
│   │   └── presentation/# Écrans de présentation
│   └── sounds/          # Musiques et sons (.mid)
├── data/                # Données du jeu
│   └── scores/         # Fichiers de scores
├── docs/               # Documentation
│   ├── presentation/   # Présentation Marp du projet
│   └── archived/       # Fichiers archivés
├── CMakeLists.txt     # Configuration CMake
└── README.md          # Ce fichier

```

## 🎮 Description

ECE Pokémon World est un ensemble de mini-jeux sur le thème Pokémon :
- **Snake** : Jeu du serpent version Pokémon
- **Guitar Hero** : Jeu de rythme
- **Jackpot** : Machine à sous
- **Pierre-Feuille-Ciseaux** : Combat Pokémon
- **Pari Hippique** : Course de Pokémon
- **Tir aux Ballons** : Jeu d'adresse
- **Taupe La** : Frappe la taupe

## 🔧 Compilation

### Prérequis

- **CMake** (version 3.10 minimum)
- **Compilateur C** compatible C99 (GCC, MinGW, etc.)
- **Bibliothèque Allegro 4.4** (liballeg44)

### Installation d'Allegro 4

**Sur Windows (MinGW):**
```bash
# Télécharger et installer Allegro 4.4 depuis allegro.cc
# Ajouter le chemin d'installation aux variables d'environnement
```

**Sur Linux (Debian/Ubuntu):**
```bash
sudo apt-get install liballegro4-dev
```

### Compilation avec CMake

```bash
# Créer un dossier de build
mkdir build
cd build

# Générer les fichiers de build
cmake ..

# Compiler le projet
cmake --build .

# Ou simplement avec make
make
```

### Exécution

```bash
# Depuis le dossier build/
./PROJET

# Ou depuis la racine (après compilation)
./build/PROJET
```

## 📝 Notes Importantes

### Chemins des Ressources

Après la réorganisation, les chemins d'accès aux assets dans le code source doivent pointer vers :
- Images : `assets/images/nom_fichier.bmp`
- Sons : `assets/sounds/nom_fichier.mid`
- Images de sous-dossiers : `assets/images/snake/nom_fichier.bmp`

⚠️ **Important** : Vérifiez et mettez à jour les chemins hardcodés dans le code source si nécessaire.

### Fichiers de Scores

Les scores des joueurs sont sauvegardés dans `data/scores/`. Les fichiers vides ont été archivés dans `docs/archived/`.

## 🤝 Contribution

Voir [CONTRIBUTING.md](CONTRIBUTING.md) pour les règles de contribution.

## 📚 Documentation

- Présentation du projet : `docs/presentation/`
- Documentation des assets : `assets/README.md`

## 👥 Auteurs

Projet réalisé par des étudiants de l'ECE Paris - Promotion Ing1

## 📄 Licence

Projet académique - ECE Paris

---

*Vous pouvez éditer ce fichier README.md (en langage **Markdown**).*
*Vous pouvez générer des schémas en utilisant [Mermaid](https://github.com/mermaid-js/mermaid).*