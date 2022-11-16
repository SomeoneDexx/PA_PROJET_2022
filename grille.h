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
    int hauteur;
    int largeur;
};

/**
 * \brief Fonction qui alloue la grille en memoire
 * \param largeur Largeur de la grille de jeu, en fonction du nombre de colonne du fichier lu
 * \param hauteur Hauteur de la grille de jeu, en fonction du nombre de ligne du fichier lu
*/
grille_t allouer_grille(int largeur, int hauteur);

/**
 * \brief Fonction qui detruit la grille en memoire
 * \param grille La grille a detruire
 * \param lignes La hauteur de la grille a detruire
*/
void desallouer_grille(grille_t grille, int lignes);

#endif