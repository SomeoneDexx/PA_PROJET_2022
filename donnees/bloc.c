#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bloc.h"

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

bloc_t init_bloc(bloc_t bloc, int num, enum couleur coul){
    bloc.num = num;
    bloc.coul = coul;

    int l = 0;
    int c = 0;

    char n[2];
    sprintf(n, "%d", bloc.num);
    char* chemin = "ressources/blocs/bloc";
    char* extension = ".txt";
    strncat(chemin, n, 2);
    strncat(chemin, extension, 6);

    taille_bloc(chemin, &l, &c);

    return bloc;
}

void desallouer_bloc(bloc_t *bloc){
    for(int i = 0; i < bloc->lignes; i++) {
        free(bloc->tab[i]);
    }
    free(bloc->tab);
    free(bloc);
}

void print_bloc(bloc_t bloc){
    printf("Le bloc n°%d est le suivant :\n\n", bloc.num);
    for(int i = 0; i < bloc.lignes; i++) {
        for(int j = 0; j < bloc.colonnes; j++) {
            printf("%c", bloc.tab[i][j]);
        }
        printf("\n");
    }
}

void taille_bloc(char* nom_fichier_bloc, int* nbLig, int* nbCol){
    int lig = 0;
    int col = 0;
    int tmp = 0;

    FILE* fich = NULL;
    fich = fopen(nom_fichier_bloc, "r");

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

void modif_bloc(bloc_t bloc, int lignes, int colonnes, enum couleur coul);

void rotation_sh(bloc_t bloc);

void rotation_sah(bloc_t bloc);