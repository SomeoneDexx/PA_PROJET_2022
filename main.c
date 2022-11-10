/**
 * \file main.c
 * \brief Programme principal du projet Pentomino
 * \author Pierre Géronimus et Baptiste Ruault
 * \version 1.0
 * \date 10 novembre 2022
 */

/* include */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fonctions_fichier.h"
#include "blocs.h"
#include "fenetre.h"

/**
 * \brief Programme principal qui implémente la boucle du jeu
 */
int main(void){
    //Données
    bool terminer = false;
    //Initialisation du jeu.
    /* code ... */

    // Boucle de jeu
    char** tab = lire_fichier("./ressources/grille_trois.txt");
    int testW, testH;
    taille_fichier("./ressources/grille_trois.txt", &testH, &testW);
    afficher_tab_blocs(tab, testH, testW);
  
    //Nettoyage final
  
    return 0;
}