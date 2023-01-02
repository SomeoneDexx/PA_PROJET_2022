#include "evenements.h"
#include "../graphique/graphique.h"

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param evenement Paramètre qui contient les événements
 * \param monde Les données du monde
 * \param souris La souris durant le jeu
 * \param fenetre_grille La grille de la fenetre
 */
void handle_events(SDL_Event *evenement, monde_t *monde, souris_t *souris, SDL_Rect *fenetre_grille, int* choice) {
    while (SDL_PollEvent(evenement)) {
        if(monde->current_screen == 0) {
            switch (evenement->type) {
                case SDL_KEYDOWN:
                    switch(evenement->key.keysym.sym) {
                        case SDLK_ESCAPE: // On indique la fin du jeu si la touche est Echap
                            monde->etat = -1;
                            break;
                        case SDLK_1:
                            *choice = 1;
                            monde->current_screen = 1;
                            break;
                        case SDLK_2:
                            *choice = 2;
                            monde->current_screen = 1;
                            break;
                        case SDLK_3:
                            *choice = 3;
                            monde->current_screen = 1;
                            break;
                        case SDLK_4:
                            *choice = 4;
                            monde->current_screen = 1;
                            break;
                    }
            }
        } else {
            switch (evenement->type) {
                // L'utilisateur a cliqué sur le X de la fenêtre
                case SDL_QUIT:
                    // On indique la fin du jeu
                    monde->etat = -1;
                    break;
                // Si une touche est appuyée
                case SDL_KEYDOWN:
                    switch (evenement->key.keysym.sym) {
                        case SDLK_ESCAPE: // On indique la fin du jeu si la touche est Echap
                            monde->etat = -1;
                            break;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    cursor_position(souris);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(souris->pos_x <= (monde->grille.colonnes) * CELL_SIZE && souris->pos_y <= (monde->grille.lignes) * CELL_SIZE) {
                        fenetre_grille->x = (evenement->motion.x / 30) * 30;
                        fenetre_grille->y = (evenement->motion.y / 30) * 30;
                    }
                    break;
            }
        }
    }
}

