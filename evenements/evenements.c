#include "evenements.h"
#include "../donnees/monde.h"

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event Paramètre qui contient les événements
 * \param world Les données du monde
 */
void handle_events(SDL_Event *evenement, monde_t *monde)
{
    souris_t souris; // Instanciation d'une souris

    SDL_Rect grille_curseur = {
        .x = (20 - 1) / 2 * 30,
        .y = (6 - 1) / 2 * 30,
        .w = 30,
        .h = 30,
    };

    Uint8 *keystates;
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
            grille_curseur.x = (evenement->motion.x / 30) * 30;
            grille_curseur.y = (evenement->motion.y / 30) * 30;
            break;
        }
    }
}