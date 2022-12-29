#include "monde.h"

/**
 * \brief Alloue de la mémoire pour le monde
 * \param grille La grille du monde
*/
monde_t* allouer_monde(grille_t *grille){
    monde_t* monde = NULL;
    monde = malloc(sizeof(monde_t));

    char n[2];
    int num = grille->num;
    sprintf(n, "%d", num);

    char nom_grille[50] = "../ressources/grilles/grille";
    char* extension = ".txt";
    strcat(nom_grille, n);
    strcat(nom_grille, extension);

    monde->grille = init_grille(nom_grille, grille->num, grille->lignes, grille->colonnes);

    *monde->liste_blocs = malloc(sizeof(bloc_t));
    for(int i = 0; i < NB_BLOCS; i++) {
        monde->liste_blocs[i] = allouer_bloc(5, 5);
    }

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

    monde->grille = init_grille("../ressources/grilles/grille1.txt", 1, 6, 10);

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
    
    for (int i = 0; i < NB_BLOCS; i++)
    {
        free(monde->liste_blocs[i]);
    }
    
    desallouer_grille(&monde->grille);
    free(monde);
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