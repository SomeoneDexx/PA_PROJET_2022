#ifndef MONDE_H
#define MONDE_H

#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "grille.h"
#include "bloc.h"
#include "souris.h"

#define NB_BLOCS 12

/**
 * \brief Les données du jeu
*/
typedef struct Monde monde_t;
struct Monde {
    int etat; // Etat du jeu (en cours (0),  terminé (-1), en pause (1))
    int score; // Score du joueur
    bool fin; // Indique si le jeu est terminé ou non
};

#endif