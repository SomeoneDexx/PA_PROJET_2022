#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <string.h>
#include "grille.h"
#include "bloc.h"

grille_t init_grille(char* nom_fichier, int num, int lignes, int colonnes) {
    grille_t grille;

    grille.num = num;
    grille.elements = allouer_tab_cases(lignes, colonnes);

    // On met les tailles en fonction de la grille choisie
    int lines, columns;
    taille_fichier(nom_fichier, &lines, &columns);

    grille.lignes = lines;
    grille.colonnes = columns;

    return grille;
}

void desallouer_grille(grille_t *grille){
    for(int i = 0; i < grille->lignes; i++) {
        free(grille->elements[i]);
    }
    free(grille->elements);
    free(grille);
}

void ecrire_fichier_grille(grille_t grille) {
    // On récupère le nom du fichier texte de la grille dont on veut réécrire le fichier.
    char n[2];
    int num = grille.num;
    sprintf(n, "%d", num);
    char chemin[50] = "../ressources/grilles/grille";
    char* extension = ".txt";
    strcat(chemin, n);
    strcat(chemin, extension);

    ecrire_fichier(chemin, grille.elements, grille.lignes, grille.colonnes);
}

void reset_grille(grille_t grille) {
    // On "réinitilise" le tableau de la grille
    for(int i = 0; i < grille.lignes; i++) {
        for(int j = 0; j < grille.colonnes; j++) {
            grille.elements[i][j] = '#';
        }
    }

    // On récupère le nom du fichier texte de la grille dont on veut réécrire le fichier.
    char n[2];
    int num = grille.num;
    sprintf(n, "%d", num);
    char chemin[50] = "../ressources/grilles/grille";
    char* extension = ".txt";
    strcat(chemin, n);
    strcat(chemin, extension);

    ecrire_fichier(chemin, grille.elements, grille.lignes, grille.colonnes);
}



