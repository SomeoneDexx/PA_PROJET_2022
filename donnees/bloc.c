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

    char n[2];
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
    
    // Allocation du nouveau tableau
    char** tab_rsh = malloc(sizeof(char*) * bloc->colonnes);
    for(int p = 0; p < bloc->colonnes; p++) {
        tab_rsh[p] = malloc(sizeof(char) * bloc->lignes);
    }

    for (int i = 0; i < bloc->lignes; i++){
        for (int j = i; j < bloc->colonnes; j++){
            tab_rsh[j][i] = bloc->tab[bloc->lignes - i - 1][j];
        }
    }
    bloc->tab = tab_rsh;
}

void rotation_sah(bloc_t *bloc){
    // Allocation du nouveau tableau
    char** tab_rsah = malloc(sizeof(char*) * bloc->colonnes);
    for(int p = 0; p < bloc->colonnes; p++) {
        tab_rsah[p] = malloc(sizeof(char) * bloc->lignes);
    }

    for (int i = 0; i < bloc->lignes; i++){
        for (int j = i; j < bloc->colonnes; j++){
            tab_rsah[j][i] = bloc->tab[i][bloc->colonnes - j - 1];
        }
    }
    bloc->tab = tab_rsah;
}