#ifndef FENETRE_H
#define FENETRE_H

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 500

#include <SDL2/SDL.h>
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
    int hauteur;
    int largeur;
};

/**
 * \brief Fonction qui crée une fenetre en memoire
 * \param hauteur La largeur de la fenetre
 * \param largeur La hauteur de la fenetre
*/
fenetre_t init_fenetre(char* nom_fichier, int hauteur, int largeur);

/**
 * \brief Fonction qui retire la fenetre en memoire
 * \param fenetre La fenetre a detruire
*/
void desallouer_fenetre(fenetre_t fenetre);


#endif