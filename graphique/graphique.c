#include "graphique.h"
#include "../donnees/fonctions_fichier.h"

SDL_Rect init_grille_curseur(int lignes, int colonnes) {
    SDL_Rect grille_curseur = {
        .x = (colonnes - 1) / 2 * CELL_SIZE,
        .y = (lignes - 1) / 2 * CELL_SIZE,
        .w = CELL_SIZE,
        .h = CELL_SIZE,
    };

    return grille_curseur;
}

void set_background_color(SDL_Renderer* ecran, SDL_Color grille_background_color) {
    SDL_SetRenderDrawColor(ecran, grille_background_color.r, grille_background_color.a, grille_background_color.b, grille_background_color.a);
}

void set_lines_color(SDL_Renderer* ecran, SDL_Color grille_lignes_color) {
    SDL_SetRenderDrawColor(ecran, grille_lignes_color.r, grille_lignes_color.g, grille_lignes_color.b, grille_lignes_color.a);
}

void draw_lines(SDL_Renderer* ecran, int lignes, int colonnes) {
    for(int i = 0; i <= colonnes * CELL_SIZE; i += CELL_SIZE) {
        SDL_RenderDrawLine(ecran, i, 0, i, lignes * CELL_SIZE);
    }

    for(int j = 0; j <= lignes * CELL_SIZE; j += CELL_SIZE) {
        SDL_RenderDrawLine(ecran,  0, j, colonnes * CELL_SIZE, j);
    }
}

void select_cell(SDL_Renderer* ecran, SDL_Rect selected_cell, SDL_Color background_color, SDL_Color selected_cell_color) {
    SDL_SetRenderDrawColor(ecran, background_color.r, background_color.a, background_color.b, background_color.a);
    SDL_SetRenderDrawColor(ecran, selected_cell_color.r, selected_cell_color.g, selected_cell_color.b, selected_cell_color.a);
    SDL_RenderFillRect(ecran, &selected_cell);
}