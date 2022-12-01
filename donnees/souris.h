#ifndef SOURIS_H
#define SOURIS_H

/**
 * \brief La souris
 * \param pox_x L'abscisse de la souris
 * \param pos_y L'ordonnee de la souris
*/
typedef struct Souris souris_t;
struct Souris {
    int pos_x;
    int pos_y;
};

/**
 * \brief Fonction qui récupère les coordonnées de la souris
 * \param souris La souris à check 
*/
void cursor_pos(souris_t souris);

#endif
