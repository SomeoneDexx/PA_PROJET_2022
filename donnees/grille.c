#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <string.h>
#include "grille.h"
#include "bloc.h"

grille_t init_grille(char* nom_fichier, int num, int lignes, int colonnes) {
    grille_t grille;

    grille.num = num;
    grille.elements = allouer_tab_blocs(lignes, colonnes);

    //On met les tailles en fonction de la grille choisie
    int lines, columns;
    taille_fichier(nom_fichier, &lines, &columns);

    grille.lignes = lines;
    grille.colonnes = columns;

    return grille;
}

void ecrire_fichier_grille(grille_t grille, char** tab) {
    char n;
    sprintf(n, "%d", grille.num);
    char* chemin = "ressources/grilles/grille";
    char* extension = ".txt";
    strncat(chemin, n, 1);
    char* file_name = strncat(chemin, extension, 5);

    ecrire_fichier(file_name, grille.elements, grille.lignes, grille.colonnes);
}

void reset_grille(grille_t grille, char** tab) {
    for(int i = 0; i < grille.lignes; i++) {
        for(int j = 0; j < grille.colonnes; j++) {
            tab[i][j] = '#';
        }
    }

    char n;
    sprintf(n, "%d", grille.num);
    char* chemin = "ressources/grilles/grille";
    char* extension = ".txt";
    strncat(chemin, n, 1);
    char* file_name = strncat(chemin, extension, 5);

    ecrire_fichier(file_name, grille.elements, grille.lignes, grille.colonnes);
}
