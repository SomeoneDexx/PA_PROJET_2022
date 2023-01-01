#include "monde.h"
#include "bloc.h"

/**
 * \brief Alloue de la mémoire pour le monde
 * \param grille La grille du monde
*/
monde_t* allouer_monde(grille_t *grille){
    monde_t* monde = NULL;
    monde = malloc(sizeof(monde_t));

    // Allouer liste_blocs et grille !!!

    return monde;
}

/**
 * \brief Initialise les données du monde
 * \param monde Le monde à initialiser
*/
monde_t* init_monde(monde_t *monde){

    monde->etat = 0;
    monde->score = 0;
    monde->fin_partie = false;
    monde->current_screen = 0;

    // monde->grille = ?

    for(int i = 0; i < NB_BLOCS; i++) {
        monde->liste_blocs[i] = init_bloc(i + 1, BLANC);
    }

    return monde;
}

/**
 * \brief Désalloue les données du monde
 * \param monde Le monde à désallouer
*/
void desallouer_monde(monde_t *monde){
    free(monde);
    // Désallouer liste_blocs et grille !!!
}

/**
 * \brief Liste les blocs présents dans les données du monde sur la sortie standard
 * \param monde Le monde dont on affiche les blocs
*/
void print_liste_blocs(monde_t *monde){
    for (int i = 0; i < NB_BLOCS; i++)
    {
        print_bloc(monde->liste_blocs[i]);
    }
    
}