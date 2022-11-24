#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "grille.h"
#include "bloc.h"

grille_t init_grille(char* nom_fichier, int lignes, int colonnes) {
    grille_t grille;

    grille.elements = allouer_tab_blocs(lignes, colonnes);

    //On met les tailles en fonction de la grille choisie
    int lines, columns;
    taille_fichier(nom_fichier, &lines, &columns);

    grille.lignes = lines;
    grille.colonnes = columns;
    return grille;
}

void ecrire_fichier_grille(bloc_t bloc, char** tab) {
}