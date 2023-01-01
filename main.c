/**
 * \file main.c
 * \brief Programme principal du projet Pentomino
 * \author Pierre Géronimus et Baptiste Ruault
 * \version 1.0
 * \date 10 novembre 2022
 */

/* include */
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "donnees/fonctions_fichier.h"
#include "evenements/evenements.h"
#include "donnees/souris.h"
#include "graphique/graphique.h"
#include "donnees/monde.h"

/**
 * \brief Programme principal qui créé les éléments/variables et implémente la boucle du jeu et 
 */
int main(void){
    SDL_Window* window; // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
    souris_t souris; //Instanciation d'une souris
    monde_t monde;

    //Initialise les champs de la souris
    init_souris(&souris);
    monde.etat = 1;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    int width = WINDOW_WIDTH;
    int height = WINDOW_HEIGHT;
    window = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);


    if(window == NULL) {
        printf("Erreur de la creation d'une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_SetWindowTitle(window, "Pentamino");

    //Mettre en place un contexte de rendu de l’écran
    SDL_Renderer* ecran;
    ecran = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);    

    //Initialisation du jeu.
    //Création des couleurs de chaques éléments
    SDL_Color grille_background_color = {43, 43, 43, 43};
    SDL_Color grille_ligne_color = {125, 125, 125, 125};
    SDL_Color grille_curseur_color = {255, 255, 255, 255};
    SDL_Color color_test = {255, 0, 0, 255};

    int l, c, choice;
    char n[2];
    sprintf(n, "%d", choice);
    char filename[50] = "../ressources/grilles/grille";
    char* extension = ".txt";
    strcat(filename, n);
    strcat(filename, extension);
    taille_fichier(filename, &l, &c); //CHANGER LE NOM DU FICHIER EN DUR PAR LE CHOIX DE GRILLE DU JOUEUR
    SDL_Rect case_curseur = init_grille_curseur(l, c); 

    // Boucle de jeu
    while(monde.etat != -1) {
        // Gestion des évènements
        handle_events(&evenements, &monde, &souris, &case_curseur, &choice);
    
        // Rafraichissement graphique
        if(monde.current_screen == 0) {
            set_background_color(ecran, color_test);

            SDL_RenderClear(ecran);
        } else {
            set_background_color(ecran, grille_background_color); //Couleur du background

            SDL_RenderClear(ecran);

            complete_grid(ecran, grille_background_color, grille_curseur_color, grille_ligne_color, case_curseur, l, c); //Dessin de la grille
        }

        SDL_RenderPresent(ecran);
    }
  
    //Nettoyage final
    // Libérer de la mémoire
    SDL_DestroyRenderer(ecran);

    // Quitter SDL
    SDL_DestroyWindow(window);
    SDL_Quit();
  
    return 0;
}