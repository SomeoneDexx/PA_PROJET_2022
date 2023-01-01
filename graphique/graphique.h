#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 600
#define CELL_SIZE 30

#include <SDL2/SDL.h>

SDL_Rect init_grille_curseur(int lignes, int colonnes);
void set_background_color(SDL_Renderer* ecran, SDL_Color grille_background_color);
void set_lines_color(SDL_Renderer* ecran, SDL_Color grille_lignes_color);
void draw_lines(SDL_Renderer* ecran, int lignes, int colonnes);
void select_cell(SDL_Renderer* ecran, SDL_Rect selected_cell, SDL_Color background_color, SDL_Color selected_cell_color);
void complete_grid(SDL_Renderer* ecran, SDL_Color grille_background_color, SDL_Color grille_curseur_color, SDL_Color grille_ligne_color, SDL_Rect case_curseur, int l, int c);

#endif