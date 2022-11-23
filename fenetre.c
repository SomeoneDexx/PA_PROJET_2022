#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fenetre.h"
#include "fonctions_fichier.h"

fenetre_t init_fenetre(char* nom_fichier, int hauteur, int largeur) {
    fenetre_t fenetre;

    int grille_hauteur;
    int grille_largeur;
    taille_fichier(nom_fichier, &grille_hauteur, &grille_largeur);

    fenetre.grille = init_grille(nom_fichier, grille_hauteur, grille_largeur);
    fenetre.hauteur = hauteur;
    fenetre.largeur = largeur;

    return fenetre;
}