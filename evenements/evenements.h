#ifndef EVENEMENTS_H
#define EVENEMENTS_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "../donnees/monde.h"

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param evenement Paramètre qui contient les événements
 * \param monde Les données du monde
 * \param souris La souris durant le jeu
 * \param fenetre_grille La grille de la fenetre
 */
void handle_events(SDL_Event *evenement, monde_t *monde, souris_t *souris, SDL_Rect *fenetre_grille, int* choice);

#endif