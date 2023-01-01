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
            bloc->tab[i][j] = '$'; 
        }
    }

    return bloc;
}

bloc_t* init_bloc(int num, enum couleur coul){

    int length = snprintf(NULL, 0, "%d", num);
    char* n = malloc(length + 1);
    snprintf(n, length + 1, "%d", num);

    sprintf(n, "%d", num);
    char chemin[50] = "ressources/blocs/bloc";
    char* extension = ".txt";
    strcat(chemin, n);
    strcat(chemin, extension);

    int l, c;
    taille_bloc(chemin, &l, &c);
    bloc_t* bloc = allouer_bloc(l, c);

    bloc->tab = lire_bloc(chemin);

    bloc->lignes = l;
    bloc->colonnes = c;
    bloc->num = num;
    bloc->coul = coul;

    return bloc;
}

void modif_bloc(bloc_t *bloc, int num, int l, int c, char** tab, enum couleur coul){

    // Désallocation du tableau
    for(int i = 0; i < bloc->lignes; i++) {
        free(bloc->tab[i]);
    }
    free(bloc->tab);

    // Réallocation du tableau
    bloc->tab = malloc(sizeof(char*) * c);
    for(int i = 0; i < l; i++) {
        bloc->tab[i] = malloc(sizeof(char) * c);
        for(int j = 0; j < c; j++) {
            bloc->tab[i][j] = '$'; 
        }
    }

    // Modification des attributs du bloc
    bloc->num = num;
    bloc->lignes = l;
    bloc->colonnes = c;
    bloc->coul = coul;
    bloc->tab = tab;
}

void desallouer_bloc(bloc_t *bloc){
    for(int i = 0; i < bloc->lignes; i++) {
        free(bloc->tab[i]);
    }
    free(bloc->tab);
    free(bloc);
}

void print_bloc(bloc_t *bloc){
    printf("Le bloc n°%d est le suivant :\n", bloc->num);
    printf("Dimension du bloc n°%d : %dx%d\n\n", bloc->num, bloc->lignes, bloc->colonnes);
    for(int i = 0; i < bloc->lignes; i++) {
        for(int j = 0; j < bloc->colonnes; j++) {
            printf("%c", bloc->tab[i][j]);
        }
        printf("\n");
    }
}

void taille_bloc(const char* nom_fichier, int* nbLig, int* nbCol){
    int lig = 0;
    int col = 0;
    int tmp = 0;

    FILE* fich = NULL;
    fich = fopen(nom_fichier, "r");

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

char** lire_bloc(char* nom_fichier){
    FILE* fileOpen = NULL;
    fileOpen = fopen(nom_fichier, "r"); 

    int lignes, colonnes;
    taille_bloc(nom_fichier, &lignes, &colonnes);
    char** tab = allouer_tab_cases(lignes, colonnes);
    
    char c;
    int lineCount = 0, columnCount = 0;

    if (fileOpen != NULL) {
        for(;;) {
            c = fgetc(fileOpen);

            if(c == '\r') {
                continue;
            } else if(c == '\n') {
                lineCount++;
                columnCount = 0;
            } else if(c == EOF) {
                break;
            } else {
                tab[lineCount][columnCount] = c;
                columnCount++;
            }
        }
    }

    fclose(fileOpen);
        
    return tab;
}

void rotation_sh(bloc_t *bloc){

    int lignes = bloc->lignes;
    int colonnes = bloc->colonnes;

    // Allocation du nouveau tableau
    bloc_t* bloc_tmp = allouer_bloc(colonnes, lignes);
    char** tab_rsh = bloc_tmp->tab;

    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            tab_rsh[j][i] = bloc->tab[lignes - i - 1][j];
        }
    }

    modif_bloc(bloc, bloc->num, colonnes, lignes, tab_rsh, bloc->coul);
}

void rotation_sah(bloc_t *bloc){

    int lignes = bloc->lignes;
    int colonnes = bloc->colonnes;

    // Allocation du nouveau tableau
    bloc_t* bloc_tmp = allouer_bloc(colonnes, lignes);
    char** tab_rsah = bloc_tmp->tab;

    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            tab_rsah[j][i] = bloc->tab[i][colonnes - j - 1];
        }
    }

    modif_bloc(bloc, bloc->num, colonnes, lignes, tab_rsah, bloc->coul);
}