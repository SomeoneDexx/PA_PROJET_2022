#include <stdlib.h>
#include <stdio.h>

char** allouer_tab_cases(int lignes, int colonnes) { 
    char** tab = NULL;
    tab = malloc(sizeof(char*) * lignes);
    
    for(int i = 0; i < lignes; i++) {
        tab[i] = malloc(sizeof(char) * colonnes);

        for(int j = 0; j < colonnes; j++) {
            tab[i][j] = ' '; 
        }
    }

    return tab;
}

void desallouer_tab_cases(char** tab, int lignes) {
    for(int i = 0; i < lignes; i++) {
        free(tab[i]);
    }
    
    free(tab);
}

void afficher_tab_cases(char** tab, int lignes, int colonnes) {
    for(int i = 0; i < lignes; i++) {
        for(int j = 0; j < colonnes; j++) {
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
}

void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol) {
    FILE* fileOpen = NULL;
    fileOpen = fopen(nomFichier, "r"); 

    char c;
    int lineCount = 0, columnCount = 0, max = 0;

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
                columnCount++;
            }

            if(max <= columnCount) {
                max = columnCount;
            }
        }

        *nbLig = lineCount;
        *nbCol = max;

        fclose(fileOpen);
    }
}

char** lire_fichier(const char* nomFichier) {
    FILE* fileOpen = NULL;
    fileOpen = fopen(nomFichier, "r"); 

    int lignes, colonnes;
    taille_fichier(nomFichier, &lignes, &colonnes);
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

void ecrire_fichier(const char* nomFichier, char** tab, int lignes, int colonnes) {
    FILE* fileOpen = NULL;
    fileOpen = fopen(nomFichier, "w");

    for(int i = 0; i < lignes; i++) {
        for(int j = 0; j < colonnes; j++) {
            fputc(tab[i][j], fileOpen);
        }

        fputc('\n', fileOpen);
    }

    fclose(fileOpen);
}
