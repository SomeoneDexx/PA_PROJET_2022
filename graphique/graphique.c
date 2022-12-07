#include "graphique.h"
#include "../donnees/fonctions_fichier.h"

void refresh_graphics(SDL_Renderer* ecran) {
    draw_grid(ecran);
}

void draw_grid(SDL_Renderer* ecran) {
    /*SDL_SetRenderDrawColor(ecran, 255, 255, 0, 255);
    SDL_RenderDrawLine(ecran, 50, 50, 450, 450);
    SDL_SetRenderDrawColor(ecran, 0, 0, 0, 255);*/

    int lignes, colonnes;
    taille_fichier("../ressources/grilles/grille1.txt", &lignes, &colonnes);

    
}
