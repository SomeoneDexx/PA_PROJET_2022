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
 * \brief Programme principal qui créé les éléments et les variables et qui implémente la boucle du jeu 
 */
int main(void){
    SDL_Window* window; // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
    souris_t souris; // Instanciation d'une souris
    monde_t* monde; // Déclaration du monde

    // Initialise les champs de la souris
    init_souris(&souris);

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Crée la fenêtre
    int width = WINDOW_WIDTH;
    int height = WINDOW_HEIGHT;
    window = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);


    if(window == NULL) {
        printf("Erreur de la creation d'une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_SetWindowTitle(window, "Pentamino");

    // Mettre en place un contexte de rendu de l’écran
    SDL_Renderer* ecran;
    ecran = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);    

    // Initialisation du jeu.
    // Création des couleurs de chaques éléments
    SDL_Color grille_background_color = {43, 43, 43, 43};
    SDL_Color grille_ligne_color = {125, 125, 125, 125};
    SDL_Color grille_curseur_color = {255, 255, 255, 255};
    SDL_Color menu_color = {80, 80, 80, 80};
    SDL_Color menu_text_color = {255, 255, 255, 255};

    // Texte du menu
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("ressources/font/arial.ttf", 28);
    char msg[] = "Choisissez une grille entre 1 et 4 au clavier";
    SDL_Texture* texte = charger_texte(msg, ecran, font, menu_text_color);

    int wText, hText;
    SDL_QueryTexture(texte, NULL, NULL, &wText, &hText);

    SDL_Rect text_pos; // Position du texte
    text_pos.x = (WINDOW_WIDTH / 2) - (wText / 2);
    text_pos.y = (WINDOW_HEIGHT / 2) - (hText / 2) - 30;
    text_pos.w = wText; // Largeur du texte en pixels (à récupérer)
    text_pos.h = hText; // Hauteur du texte en pixels (à récupérer)

    int l, c, choice = 0;
    char n[2];
    SDL_Rect case_curseur = init_grille_curseur(0, 0); 
    monde = allouer_monde(1);

    // Choix de la grille de jeu
    while (choice == 0) {
        handle_events(&evenements, monde, &souris, &case_curseur, &choice);
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, texte, NULL, &text_pos);
        set_background_color(ecran, menu_color);
        SDL_RenderPresent(ecran);
    }

    sprintf(n, "%d", choice);
    char filename[50] = "ressources/grilles/grille";
    char* extension = ".txt";
    strcat(filename, n);
    strcat(filename, extension);
    taille_fichier(filename, &l, &c);

    // Initialisation du monde selon la grille

    init_monde(monde);
    monde->current_screen = 1;
    update_grille(monde, l, c);

    // Déclaration et initialisation pour les textures
    SDL_Texture *sprites_blocs;
    SDL_Rect SrcR_sprite_blocs[NB_BLOCS];
    SDL_Rect DestR_sprite_blocs[NB_BLOCS][25];
    
    Uint8 r = 0, g = 255, b = 255;
    sprites_blocs = charger_image_transparente("ressources/blocs.bmp", ecran, r, g, b);

    // Décalage pour ne pas superposer les blocs
    int offset = 0;

    for (int i = 0; i < NB_BLOCS; i++) {
        SrcR_sprite_blocs[i].x = i * 32;
        SrcR_sprite_blocs[i].y = 0;
        SrcR_sprite_blocs[i].w = 32;
        SrcR_sprite_blocs[i].h = 32;
    
        for (int j = 0; j < 25; j++) {
            DestR_sprite_blocs[i][j].x = offset + (j / 5 + 1) * CELL_SIZE;
            DestR_sprite_blocs[i][j].y = i > 5 ? (j % 5 + 13) * CELL_SIZE : (j % 5 + 7) * CELL_SIZE;
            DestR_sprite_blocs[i][j].w = CELL_SIZE;
            DestR_sprite_blocs[i][j].h = CELL_SIZE;
        }

        if(i == (NB_BLOCS / 2) - 1) {
            offset = -5 * CELL_SIZE;
        }
        offset += 5 * CELL_SIZE;
    }

    // Boucle de jeu
    while(monde->etat != -1) {
        // Gestion des évènements
        handle_events(&evenements, monde, &souris, &case_curseur, &choice);
        set_background_color(ecran, grille_background_color); //Couleur du background
        SDL_RenderClear(ecran);
        complete_grid(ecran, grille_background_color, grille_curseur_color, grille_ligne_color, case_curseur, l, c); //Dessin de la grille
        
        // Positionnement des blocs sur la fenêtre
        for (int i = 0; i < NB_BLOCS; i++) {
            for (int j = 0; j < 25; j++) {
                int nb_lig_b = monde->liste_blocs[i]->lignes;
                int nb_col_b = monde->liste_blocs[i]->colonnes;

                for (int k = 0; k < nb_lig_b; k++) {
                    for (int l = 0; l < nb_col_b; l++) {
                        if(monde->liste_blocs[i]->tab[k][l] == '#') {
                            SDL_RenderCopy(ecran, sprites_blocs, &SrcR_sprite_blocs[i], &DestR_sprite_blocs[i][j]);
                        } else {
                           SDL_RenderCopy(ecran, sprites_blocs, &SrcR_sprite_blocs[12], &DestR_sprite_blocs[i][j]);
                        }
                    }
                }                  
            }
        }
        SDL_RenderPresent(ecran);
    }
  
    // Nettoyage final
    TTF_CloseFont(font);
    TTF_Quit();

    // Libérer de la mémoire
    SDL_DestroyRenderer(ecran);

    // Quitter SDL
    SDL_DestroyWindow(window);
    SDL_Quit();
  
    return 0;
}