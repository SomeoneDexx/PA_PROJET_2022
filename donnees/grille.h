#ifndef GRILLE_H
#define GRILLE_H

#include "bloc.h"

/**
 * \brief La grille de jeu
*/
typedef struct Grille grille_t;
struct Grille {
    char** elements;
    int lignes;
    int colonnes;
    char* nom_fichier;
    int num;
};

/**
 * \brief Fonction qui créé la grille 
 * \param lignes colonnes de la grille de jeu, en fonction du nombre de colonne du fichier lu
 * \param colonnes lignes de la grille de jeu, en fonction du nombre de ligne du fichier lu
*/
grille_t init_grille(char* nom_fichier, int num, int lignes, int colonnes);

/**
 * \brief Fonction qui permet d'écrire dans le fichier de la grille les blocs placés dans la grille
 * \param bloc Le bloc à placer dans la grille
 * \param tab  Le tableau à changer  
*/
void ecrire_fichier_grille(grille_t grille, char** tab);

/**
 * \brief Fonction qui reset la grille actuelle en enlevant tous les blocs placés et en réécrivant le fichier
 * \param nom_fichier Le fichier à réécrire
 * \param tab Le tab à changer
 * \param lignes La hauteur du tableau
 * \param colonnes La largeur du tableau
*/ 
void reset_grille(grille_t grille, char** tab);

#endif