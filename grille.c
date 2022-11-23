#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "grille.h"
#include "blocs.h"
#include "fonctions_fichier.h"

grille_t init_grille(char* nom_fichier, int lignes, int colonnes) {
    grille_t grille;

    grille.elements = allouer_tab_blocs(lignes, colonnes);

    //On met les tailles en fonction de la grille choisie
    int lines, columns;
    taille(nom_fichier, &lines, &columns);

    grille.lignes = lines;
    grille.colonnes = columns;
    return grille;
}

void ecrire_grille(bloc_t bloc, char** tab) {
}
