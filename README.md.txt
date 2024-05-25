# Read Me - Projet CY-Fish

## Table des matières

1. [Description du projet](#description-du-projet)
2. [Créateurs](#créateurs)
3. [Règles du jeu](#règles-du-jeu)
4. [Fonctionnalités du projet](#fonctionnalités-du-projet)
5. [Structure du code](#structure-du-code)
6. [Fonctions du code](#fonctions-du-code)
7. [Ressources utiles](#ressources-utiles)
8. [Contact](#contact)

## Description du projet  

Le projet CY-Fish est un jeu en mode terminal où des pingouins s'affrontent à tour de rôle en se déplaçant sur une grille hexagonale parsemée de poissons à récolter. Le joueur dont les pingouins ont collecté le plus de poissons à la fin du jeu remporte la victoire.

## Créateurs

- Ryan Trabelsi (ryan.trabelsi@cyu.fr)
- Ameesha Zaffersatick (ameesha.zaffersatick@cyu.fr)

## Règles du jeu

- *Déplacement :* Les pingouins se déplacent en ligne droite et ne peuvent pas traverser d'autres pingouins ou des cases fondues.
- *Collecte de poissons :* Lorsqu'un pingouin se déplace, la case de départ est retirée et les poissons de cette case sont ajoutés au score du joueur.
- *Séquence de tour :* Les joueurs jouent à tour de rôle. Si un joueur ne peut pas déplacer un pingouin, il passe son tour.
- *Fin du jeu :* Le jeu se termine lorsqu'aucun joueur ne peut plus déplacer de pingouin, et le joueur avec le plus de poissons gagne.

## Fonctionnalités du projet

- *Saisie des joueurs :* Le jeu demande le nombre de joueurs (2 à 6).
- *Configuration du plateau :* La taille du plateau de jeu est de 6x13 cases.
- *Répartition des pingouins :* Le nombre de pingouins par joueur varie selon le nombre de joueurs (2 joueurs = 4 pingouins chacun, 3 joueurs = 3 pingouins chacun, 4 joueurs = 2 pingouins chacun).
- *Grille hexagonale :* Le jeu affiche une grille hexagonale où chaque case peut contenir de 1 à 3 poissons. Les pingouins sont identifiés par joueur et case.
- *Tour de joueur :* Les joueurs choisissent quel pingouin déplacer, la direction et la distance. Le programme valide le déplacement.
- *Affichage des scores :* Le jeu affiche les scores de chaque joueur à chaque round.
- *Fin du jeu :* Le jeu se termine lorsque plus aucun joueur ne peut déplacer de pingouin, et le gagnant est affiché.

## Structure du code  

- *struct Player* : Représente un pingouin sur la grille
- *struct Hex* : Représente une case hexagonale sur la grille de jeu

## Fonctions du code

- *Hex initialize_grid(int size, int players);*
  - Initialise la grille de jeu avec des cases hexagonales. Chaque case contient un nombre aléatoire de poissons et certaines cases sont initialisées avec des pingouins.

- *void upper(int r);*
  - Affiche la partie supérieure des cases hexagonales pour une rangée donnée.

- *void middle(Hex **grid, int r);*
  - Affiche la partie centrale des cases hexagonales pour une rangée donnée, en indiquant la présence de pingouins et de poissons.

- *void lower(Hex **grid, int r);*
  - Affiche la partie inférieure des cases hexagonales pour une rangée donnée.

- *void print_grid(Hex **grid, Player *players, int total_players);*
  - Affiche la grille de jeu complète avec l'état actuel de chaque case.

- *bool valid_move(Hex **grid, int x, int y, int direction, int distance, int player, int size);*
  - Vérifie si un déplacement est valide pour un pingouin donné en fonction de la direction et de la distance.

- *bool move(Hex **grid, Player *players, int player_index, int total_players);*
  - Effectue un déplacement pour un pingouin appartenant à un joueur et met à jour la grille et les scores.

- *bool game_over(Player *players, int total_players, Hex **grid);*
  - Vérifie si le jeu est terminé en déterminant si aucun joueur ne peut plus déplacer ses pingouins.

- *void printCYFISH();*
  - Affiche le logo du jeu CY-Fish.

- *void printRYAN_AMEESHA();*
  - Affiche les noms des créateurs du jeu.

- *void printOptions();*
  - Affiche le menu des options pour le jeu.

- *void Penguin();*
  - Lance une nouvelle partie du jeu CY-Fish en initialisant les paramètres et en démarrant la boucle principale du jeu.

- *void printRules();*
  - Affiche les règles du jeu CY-Fish.

- *void Main();*
  - Fonction principale du programme qui gère le menu principal et les options du jeu

## Ressources utiles

- *GitHub :* [GitHub](https://www.github.com), [Guide de démarrage GitHub](https://docs.github.com/en/get-started/quickstart/hello-world)
- *Emojis dans le terminal :* [emojis poissons](https://emojiterra.com/fr/poisson/), [emojis pingouins](https://emojiterra.com/fr/pingouin/)

## Contact

Pour toute question ou assistance supplémentaire, veuillez contacter les auteurs aux adresses email fournies.