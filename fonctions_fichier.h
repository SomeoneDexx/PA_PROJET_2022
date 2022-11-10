#ifndef FONCTIONS_FICHIER_H
#define FONCTIONS_FICHIER_H

char** allouer_tab_blocs(int lignes, int colonnes);
void desallouer_tab_blocs(char** tab_bloc, int lignes);
void afficher_tab_blocs(char** tab_bloc, int lignes, int colonnes);
void taille_fichier(const char* nom_fichier, int* nombre_lignes, int* nombre_colonnes);
char** lire_fichier(const char* nom_fichier);
char** ecrire_fichier(const char* nom_fichier, char** tab, int lignes, int colonnes);

#endif