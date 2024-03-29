#ifndef MONDE_H
#define MONDE_H

#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grille.h"
#include "bloc.h"
#include "souris.h"

#define NB_BLOCS 12

/**
 * \brief Les données du jeu
*/
typedef struct Monde monde_t;
struct Monde {
    int etat; // Etat du jeu (en cours (0),  terminé (-1), en pause (1))
    int score; // Score du joueur
    bool fin_partie; // Indique si la partie est terminée ou non
    grille_t grille; // La grille de jeu
    bloc_t *liste_blocs[NB_BLOCS]; // Liste des blocs du jeu
    int current_screen; // Ecran du jeu, menu (0), jeu (1)
};

/**
 * \brief Alloue de la mémoire pour le monde
 * \param num_grille Le numéro de la grille du monde
*/
monde_t* allouer_monde(int num_grille);

/**
 * \brief Initialise les données du monde
 * \param monde Le monde à initialiser
*/
void init_monde(monde_t *monde);

/**
 * \brief Désalloue les données du monde
 * \param monde Le monde à désallouer
*/
void desallouer_monde(monde_t *monde);

/**
 * \brief Liste les blocs présents dans les données du monde sur la sortie standard
 * \param monde Le monde dont on affiche les blocs
*/
void print_liste_blocs(monde_t *monde);

/** \brief Fonction qui update les dimensions de la grille en fonction du choix du joueur
 * \param monde Le monde associé à la grille 
 * \param l Le nombre de ligne du fichier choisi
 * \param c Le nombre de colonne du fichier choisi
*/
void update_grille(monde_t* monde, int l, int c);

#endif