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
#include "fonctions_fichier.h"
#include "fenetre.h"

/**
 * \brief Programme principal qui créé les éléments/variables et implémente la boucle du jeu et 
 */
int main(void){
    SDL_Window* window; // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
    bool terminer = false;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    int width = 500;
    int height = 500;
    window = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

    if(window == NULL) {
        printf("Erreur de la creation d'une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    //Mettre en place un contexte de rendu de l’écran
    SDL_Renderer* ecran;
    ecran = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);    


    //Initialisation du jeu.
    /* code ... */

    // Boucle de jeu
    while(!terminer) {
        SDL_RenderClear(ecran);

        //Gestion des mouvements du personnage
        while(SDL_PollEvent(&evenements)) {
            switch(evenements.type) {
                case SDL_QUIT:
                    terminer = true; 
                    break;
                case SDL_KEYDOWN:
                    switch(evenements.key.keysym.sym) {
                        case SDLK_ESCAPE:
                        case SDLK_q:
                            terminer = true; 
                            break;
                    
                    }
            }
        
        }

        SDL_RenderPresent(ecran);
    }

    // Libérer de la mémoire
    SDL_DestroyRenderer(ecran);

    // Quitter SDL
    SDL_DestroyWindow(window);
    SDL_Quit();
  
    //Nettoyage final
  
    return 0;
}