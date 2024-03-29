#include "monde.h"

monde_t* allouer_monde(int num_grille){
    monde_t* monde = NULL;
    monde = malloc(sizeof(monde_t));

    char n[2];
    sprintf(n, "%d", num_grille);

    char nom_grille[50] = "../ressources/grilles/grille";
    char* extension = ".txt";
    strcat(nom_grille, n);
    strcat(nom_grille, extension);

    int lignes, colonnes;
    taille_fichier(nom_grille, &lignes, &colonnes);

    monde->grille = init_grille(nom_grille, num_grille, lignes, colonnes);

    *monde->liste_blocs = malloc(sizeof(bloc_t));
    for(int i = 0; i < NB_BLOCS; i++) {
        monde->liste_blocs[i] = allouer_bloc(5, 5);
    }

    return monde;
}

void init_monde(monde_t *monde){

    monde->etat = 0;
    monde->score = 0;
    monde->fin_partie = false;
    monde->current_screen = 0;

    for(int i = 0; i < NB_BLOCS; i++) {
        monde->liste_blocs[i] = init_bloc(i + 1, i);
    }
}

void desallouer_monde(monde_t *monde){
    
    for (int i = 0; i < NB_BLOCS; i++)
    {
        free(monde->liste_blocs[i]);
    }
    
    desallouer_grille(&monde->grille);
    free(monde);
}

void print_liste_blocs(monde_t *monde){
    for (int i = 0; i < NB_BLOCS; i++)
    {
        print_bloc(monde->liste_blocs[i]);
    }
}

void update_grille(monde_t* monde, int l, int c) {
    monde->grille.lignes = l;
    monde->grille.colonnes = c;
}   