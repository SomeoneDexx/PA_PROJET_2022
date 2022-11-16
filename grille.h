#ifndef GRILLE_H
#define GRILLE_H

#include <stdbool.h>
#include <stdio.h>

/**
 * \brief La grille de jeu
*/
typedef struct Grille grille_t;
struct Grille {
    char** elements;
    int lignes;
    int colonnes;
};

/**
 * \brief Fonction qui alloue la grille en memoire
 * \param colonnes colonnes de la grille de jeu, en fonction du nombre de colonne du fichier lu
 * \param lignes lignes de la grille de jeu, en fonction du nombre de ligne du fichier lu
*/
grille_t allouer_grille(int colonnes, int lignes);

/**
 * \brief Fonction qui detruit la grille en memoire
 * \param grille La grille a detruire
 * \param lignes La lignes de la grille a detruire
*/
void desallouer_grille(grille_t grille, int lignes);

#endif