#ifndef BLOCS_H
#define BLOCS_H

/**
 * \brief Les couleurs possibles des blocs
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
    char** tab; 
    int index;
    enum couleur coul; 
};

/**
 * \brief Fonction qui allouer un bloc en memoire
 * \param lignes Le nombre de lignes
 * \param colonnes Le nombre de colonnes
 * \param coul La couleur du bloc
*/
bloc_t allouer_bloc(int lignes, int colonnes);

/**
 * \brief Fonction qui desalloue un bloc enn memoire
 * \param bloc Le bloc a desallouer
*/
void desallouer_bloc(bloc_t bloc);

/**
 * \brief Fonction qui affiche un bloc
 * \param bloc Le bloc a afficher
*/
void afficher_bloc(bloc_t bloc);

/**
 * \brief Fonction qui allouer un bloc en memoire
 * \param bloc Le bloc dont on veut les dimensions
 * \param nbLig Parametre qui servira a changer la valeur de la variable rentree
 * \param nbCol Parametre qui servira a changer la valeur de la variable rentree
*/
void taille_bloc(bloc_t bloc, int* nbLig, int* nbCol);

/**
 * \brief Fonction qui recupere un bloc a l'indice en parametre dansun fichier precise
 * \param nom_fichier Le fichier dans lequel recuperer le bloc
 * \param ind L'indice du bloc a recuperer
*/
bloc_t lire_bloc(const char* nom_fichier, int ind); 

/**
 * \brief Fonction qui change les valeurs attributs du bloc 
 * \param bloc Le bloc a modifier
 * \param lignes Le nombre de lignes voulu
 * \param colonnes Le nombre de colonnes voulu
 * \param coul La couleur voulue
*/
void modif_bloc(bloc_t bloc, int lignes, int colonnes, enum couleur coul);

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