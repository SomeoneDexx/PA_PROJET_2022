#ifndef FONCTIONS_FICHIER_H
#define FONCTIONS_FICHIER_H

/**
 * \brief Fonction qui alloue en memoire un tableau de caracteres
 * \param lignes La hauteur du tableau
 * \param colonnes La largeur du tableau
*/
char** allouer_tab_blocs(int lignes, int colonnes);

/**
 * \brief Fonction qui desalloue un tableau en memoire
 * \param tab_bloc Le tableau a desallouer
 * \param lignes La hauteur du tableau a desallouer
*/
void desallouer_tab_blocs(char** tab_bloc, int lignes);

/**
 * \brief Fonction qui fait tourner un bloc dans le sens horaire
 * \param tab_bloc Le tableau a afficher
 * \param lignes La hauteur du tableau a afficher
 * \param colonnes La largeur du tableau a afficher
*/
void afficher_tab_cases(char** tab_bloc, int lignes, int colonnes);

/**
 * \brief Fonction qui recupere la taille d'un fichier
 * \param nom_fichier Le fichier dans lequel on travaille
 * \param nombre_lignes Le parametre sera modifie avec le nombre de ligne du fichier
 * \param nombre_colonnes Le parametre sera modifie avec le nombre de colonnes du fichier
*/
void taille_fichier(const char* nom_fichier, int* nombre_lignes, int* nombre_colonnes);

/**
 * \brief Fonction qui recupere la taille d'un fichier
 * \param nom_fichier Le fichier dans lequel on travaille
*/
char** lire_fichier(const char* nom_fichier);

/**
 * \brief Fonction qui recupere la taille d'un fichier
 * \param nom_fichier Le fichier dans lequel on travaille
 * \param tab Le tableau contenant les nouvelles valeurs
 * \param lignes Le nombre de lignes du nouveau tableau
 * \param colonnes Le nombre de colonnes du nouveau tableau 
*/
char** ecrire_fichier(const char* nom_fichier, char** tab, int lignes, int colonnes);

#endif