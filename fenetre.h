#ifndef FENETRE_H
#define FENETRE_H

#include <stdbool.h>
#include <stdio.h>
#include "blocs.h"
#include "grille.h"

/**
  * \brief La fenetre entiere du jeu
*/
typedef struct Fenetre fenetre_t;
struct Fenetre {
    grille_t grille;
    bloc_t* blocs;
    int hauteur;
    int largeur;
};

/**
 * \brief Fonction qui crée une fenetre en memoire
 * \param largeur La largeur de la fenetre
 * \param hauteur La hauteur de la fenetre
*/
fenetre_t allouer_fenetre(int largeur, int hauteur);

/**
 * \brief Fonction qui retire la fenetre en memoire
 * \param fenetre La fenetre a detruire
*/
void desallouer_fenetre(fenetre_t fenetre);


#endif