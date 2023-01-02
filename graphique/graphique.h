#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 700
#define CELL_SIZE 32

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../donnees/monde.h"

/**
 * \brief Fonction qui initialise le carré "curseur"
 * \param lignes Les lignes du fichier
 * \param colonnes Les colonnes du fichier
*/
SDL_Rect init_grille_curseur(int lignes, int colonnes);

/**
 * \brief Change la couleur du fond du jeu
 * \param ecran Le renderer
 * \param grille_background_color Le couleur à afficher
*/
void set_background_color(SDL_Renderer* ecran, SDL_Color grille_background_color);

/**
 * \brief Change la couleur des lignes du jeu
 * \param ecran Le renderer
 * \param grille_lignes_color Le couleur à afficher
*/
void set_lines_color(SDL_Renderer* ecran, SDL_Color grille_lignes_color);

/**
 * \brief Dessine les lignes
 * \param ecran Le renderer
 * \param lignes Le nombre de lignes à dessiner
 * \param colonnes Le nombre de colonnes à dessiner
*/
void draw_lines(SDL_Renderer* ecran, int lignes, int colonnes);

/**
 * \brief Fonction qui permet de séléctionner une case de la grille
 * \param ecran Le renderer
 * \param selected_cell La case selectionnée
 * \param background_color La couleur du fond
 * \param selected_cell_color La couleur de la case sélectionnée
*/
void select_cell(SDL_Renderer* ecran, SDL_Rect selected_cell, SDL_Color background_color, SDL_Color selected_cell_color);

/**
 * \brief Fonction qui assemble les fonctions précedentes et affiche la grille
 * \param ecran Le renderer
 * \param grille_background_color La couleur du fond
 * \param grille_curseur_color La couleur de la case selectionnée
 * \param grille_ligne_color La couleur des lignes
 * \param case_curseur La case selectionnée
 * \param l Le nombre de lignes
 * \param c Le nombre de colonnes
*/
void complete_grid(SDL_Renderer* ecran, SDL_Color grille_background_color, SDL_Color grille_curseur_color, SDL_Color grille_ligne_color, SDL_Rect case_curseur, int l, int c);

/**
 * \brief Charger les fonts, le texte
 * \param message Le texte à afficher
 * \param renderer Le renderer
 * \param font La font choisie pour le texte
 * \param color La couleur choisie du texte
*/
SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer, TTF_Font *font, SDL_Color color);

/**
 * \brief Charge les textures des blocs
 * \param nomFichier Les fichiers contenant les blocs
 * \param renderer Le renderer
 * \param r La valeur rouge
 * \param g La valeur verte
 * \param b La valeur bleue 
*/
SDL_Texture* charger_image_transparente (const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b);
#endif