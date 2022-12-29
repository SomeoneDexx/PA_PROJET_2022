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
    int num;
};

/**
 * \brief Fonction qui créer la grille 
 * \param lignes colonnes de la grille de jeu, en fonction du nombre de colonne du fichier lu
 * \param colonnes lignes de la grille de jeu, en fonction du nombre de ligne du fichier lu
*/
grille_t init_grille(char* nom_fichier, int num, int lignes, int colonnes);

/**
 * \brief Fonction qui permet de désallouer la mémoire d'une grille
 * \param grille La grille à désallouer
*/
void desallouer_grille(grille_t *grille);

/**
 * \brief Fonction qui permet d'écrire dans le fichier de la grille les blocs placés dans la grille
 * \param grille La grille nous permettant de modifier son fichier texte
*/
void ecrire_fichier_grille(grille_t grille);

/**
 * \brief Fonction qui reset la grille actuelle en enlevant tous les blocs placés et en réécrivant le fichier
 * \param grille
*/ 
void reset_grille(grille_t grille);

/**
 * \brief Fonction qui modifie la grille
 * \param grille La grille a modifier
 * \param tab Le tableau du bloc à placer dans la grille
*/
void modif_grille(grille_t grille, char** tab);

int choose_grid();

#endif