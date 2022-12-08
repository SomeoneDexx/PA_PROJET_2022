#include "evenements.h"

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param evenement Paramètre qui contient les événements
 * \param monde Les données du monde
 * \param souris La souris durant le jeu
 * \param fenetre_grille La grille de la fenetre
 */
void handle_events(SDL_Event *evenement, monde_t *monde, souris_t *souris, SDL_Rect *fenetre_grille)
{

    while (SDL_PollEvent(evenement))
    {

        switch (evenement->type)
        {
        // L'utilisateur a cliqué sur le X de la fenêtre
        case SDL_QUIT:
            // On indique la fin du jeu
            monde->etat = -1;
            break;
        // Si une touche est appuyée
        case SDL_KEYDOWN:
            switch (evenement->key.keysym.sym)
            {
            case SDLK_ESCAPE:
                // On indique la fin du jeu si la touche est Echap
                monde->etat = -1;
                break;
            }
            break;
        case SDL_MOUSEMOTION:
            cursor_position(souris);
            break;
        case SDL_MOUSEBUTTONDOWN:
            fenetre_grille->x = (evenement->motion.x / 30) * 30;
            fenetre_grille->y = (evenement->motion.y / 30) * 30;
            break;
        }
    }
}