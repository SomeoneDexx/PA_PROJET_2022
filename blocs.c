#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "blocs.h"

/**
 * \brief Fonction qui alloue un bloc en memoire
 * \param lignes Le nombre de lignes
 * \param colonnes Le nombre de colonnes
*/
bloc_t* allouer_bloc(int lignes, int colonnes){
    bloc_t* bloc = NULL;
    bloc = malloc(sizeof(bloc_t));

    bloc->tab = malloc(sizeof(char*) * colonnes);
    for(int i = 0; i < lignes; i++) {
        bloc->tab[i] = malloc(sizeof(char) * colonnes);
        for(int j = 0; j < colonnes; j++) {
            bloc->tab[i][j] = '#'; 
        }
    }

    return bloc;
}

/**
 * \brief Fonction qui desalloue un bloc en memoire
 * \param bloc Le bloc a desallouer
*/
void desallouer_bloc(bloc_t *bloc){
    for(int i = 0; i < bloc->lignes; i++) {
        free(bloc->tab[i]);
    }
    free(bloc->tab);
    free(bloc);
}

/**
 * \brief Fonction qui affiche un bloc
 * \param bloc Le bloc a afficher
*/
void afficher_bloc(bloc_t bloc){
    printf("Le bloc n°%d est le suivant :\n\n", bloc.num);
    for(int i = 0; i < bloc.lignes; i++) {
        for(int j = 0; j < bloc.colonnes; j++) {
            printf("%c", bloc.tab[i][j]);
        }
        printf("\n");
    }
}

/**
 * \brief Fonction qui compte le nombre de lignes et de colonnes maximum d'un bloc
 * \param bloc Le bloc dont on veut les dimensions
 * \param nbLig Parametre qui servira a changer la valeur de la variable rentree
 * \param nbCol Parametre qui servira a changer la valeur de la variable rentree
*/
void taille_bloc(bloc_t bloc, int* nbLig, int* nbCol){
    int lig = 0;
    int col = 0;
    int tmp = 0;
    int ind = bloc.num;
    char n[2];
    sprintf(n, "%d", ind);
    char* chemin = "ressources/blocs/bloc";
    char* extension = ".txt";
    strncat(chemin, n, 2);
    strncat(chemin, extension, 6);
    for (int i = 0; i < 5; i++){
        printf("iuo\n");
    }
    printf("%s\n", chemin);

    FILE* fich = NULL;
    fich = fopen(chemin, "r");

    if (fich != NULL)
    {
        while (feof(fich) != 1)  
        {  
            col++;
            char car = fgetc(fich);
            if (car == '\r' ){
                col--;
            } else {
                if (car == '\n'){
                    col--;
                    lig++;
                    if(col > tmp){
                       tmp = col;
                    }
                    col = 0;
                }
            }
        } 
        fclose(fich);   
    }

    *nbLig = lig;
    *nbCol = tmp;
}

/**
 * \brief Fonction qui recupere le bloc dans un fichier precise
 * \param nom_fichier Le fichier dans lequel recuperer le bloc
*/
bloc_t lire_bloc(const char* nom_fichier){
    int lig = 0, col = 0;

    taille_fichier(nom_fichier, &lig, &col);

    bloc_t *bloc = allouer_bloc(lig, col);

    char c; /* Caractère courant */
    int i = 0; /* Lignes */
    int j = 0; /* Colonnes */
 
    FILE *file = fopen(nom_fichier, "r");
    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    c = fgetc(file); /* Lecture du premier caractère du fichier */
    while (c != EOF)
    {
        if (c == '\n'){
            for(int k = j; k < col; k++){
                bloc->tab[i][k] = '\0'; /* Ajout du caractère de fin de chaîne */
            }
            i++;
            j=0;
        } else {
            bloc->tab[i][j] = c;
            j++;
        }
        c = fgetc(file); /* Lecture du prochaine caractère */
    }
 
    fclose(file);

    return *bloc;
}

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