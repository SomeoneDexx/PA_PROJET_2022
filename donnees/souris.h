#ifndef SOURIS_H
#define SOURIS_H

#include <stdbool.h>

/**
 * \brief La souris
 * \param pox_x L'abscisse de la souris
 * \param pos_y L'ordonnee de la souris
*/
typedef struct Souris souris_t;
struct Souris {
    int pos_x;
    int pos_y;
    bool is_active;
    bool hover;
};

/**
 * \brief Fonction qui récupère les coordonnées de la souris
 * \param souris La souris à check 
*/
void cursor_position(souris_t* souris);

void init_souris(souris_t* souris);

#endif
