#ifndef BLOCS_H
#define BLOCS_H

enum couleur { ROUGE, VERT_F, VERT_C, ROSE, BRUN, JAUNE, BLEU_F, BLEU_C, VIOLET, MAGENTA, CYAN, ORANGE, BLANC, GRIS_C, GRIS_F, NOIR};

typedef struct Bloc bloc_t;
struct Bloc
{
    int l; // Largeur du bloc
    int h; // Hauteur du bloc
    char** tab; // Tableau de taille l*h
    enum couleur coul; // Couleur du bloc
};

char** allouer_bloc(int x, int y, enum couleur coul);
void desallouer_bloc(char** tab, int l);
void afficher_bloc(bloc_t bloc);
void taille_bloc(const char* nom_fichier, bloc_t* bloc);
char** lire_bloc(const char* nom_fichier, int ind);
void modif_bloc(int x, int y, enum couleur coul);
void rotation_sh(bloc_t bloc);
void rotation_sah(bloc_t bloc);

#endif