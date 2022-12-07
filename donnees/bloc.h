#ifndef BLOC_H
#define BLOC_H

#include "fonctions_fichier.h"

/**
 * \brief Les 16 couleurs possibles des blocs
*/
enum couleur { 
    ROUGE,
    VERT_F,
    VERT_C,
    ROSE, 
    BRUN, 
    JAUNE, 
    BLEU_F, 
    BLEU_C, 
    VIOLET, 
    MAGENTA, 
    CYAN, 
    ORANGE, 
    BLANC, 
    GRIS_C, 
    GRIS_F, 
    NOIR
};

/**
 * \brief Représentation d'un bloc 
*/
typedef struct Bloc bloc_t;
struct Bloc {
    int lignes; 
    int colonnes;
    int num;
    char** tab;
    enum couleur coul; 
};

/**
 * \brief Fonction qui alloue un bloc en memoire
 * \param lignes Le nombre de lignes
 * \param colonnes Le nombre de colonnes
*/
bloc_t* allouer_bloc(int lignes, int colonnes);

/**
 * \brief Fonction qui initialise un bloc grace aux donnees passees en parametres
 * \param num Le numero du bloc
 * \param coul La couleur du bloc
*/
bloc_t* init_bloc(int num, enum couleur coul);

/**
 * \brief Fonction qui desalloue un bloc en memoire
 * \param bloc Le bloc a desallouer
*/
void desallouer_bloc(bloc_t *bloc);

/**
 * \brief Fonction qui affiche un bloc dans la console
 * \param bloc Le bloc a afficher
*/
void print_bloc(bloc_t bloc);

/**
 * \brief Fonction qui compte le nombre de lignes et de colonnes maximum d'un bloc
 * \param nom_fichier Le fichier du bloc dont on veut les dimensions
 * \param nbLig Parametre qui servira a changer la valeur de la variable rentree
 * \param nbCol Parametre qui servira a changer la valeur de la variable rentree
*/
void taille_bloc(const char* nom_fichier, int* nbLig, int* nbCol);

/**
 * \brief Fonction qui recupere le contenu d'un fichier bloc precise
 * \param nom_fichier Le fichier dans lequel recuperer le bloc
*/
char** lire_bloc(char* nom_fichier); 

/**
 * \brief Fonction qui fait tourner un bloc dans le sens horaire
 * \param bloc Le bloc a faire tourner
*/
void rotation_sh(bloc_t bloc);

/**
 * \brief Fonction qui fait tourner un bloc dans le sens anti-horaire
 * \param bloc Le bloc a faire tourner
*/
void rotation_sah(bloc_t bloc);

#endif