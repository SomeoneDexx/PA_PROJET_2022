#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 600
#define CELL_SIZE 30

#include <SDL2/SDL.h>

void draw_grid(SDL_Renderer* ecran);
void refresh_graphics(SDL_Renderer* ecran);

#endif