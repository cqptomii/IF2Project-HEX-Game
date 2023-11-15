//
// Created by tomfr on 27/04/2023.
//

#ifndef PROJET_D_IF_VICTOIRE_H
#define PROJET_D_IF_VICTOIRE_H
#include "stdlib.h"
#include "stdio.h"
#include "Fenetres_Menus.h"
extern SDL_Surface *gmenu;
extern short victoire;
extern short taille;
extern short hauteur;
extern short largeur;
/**
 *@brief Fonction de verification de victoire
 *@param enter_verif → variable d'entrer de l'algo, True : si 1 pion sur la première ligne ( rouge ) / première colonne ( Bleu )
 *@param tour_joueur → variable determinant le tour du joueur -> l'algo associer à lire
 *@param b → variable de parcours
 *@param i → variable de parcours
 *@param Matrice2D → Matrice de jeux, récuperant la valeur de chaque pion, Bleu : 1 ET Rouge : 2
 *@param Matrice_victoire → Matrice de verification de victoire, Rouge < 0 ET Bleu > 0
 */
void verif_victoire(short tour_joueur,short b,short i,short Matrice2D[taille][taille],short Matrice_victoire[taille][taille]);
/**
 *@brief Fonction affichant la fenetre de victoire
 *@param gvictoire → variable pointant sur la fenetre victoire
 *@param rvictoire → variable pointant sur la surface de la fenetre victoire
 *@param tvictoire → variable pointant vers la texture de l'image importé
 *@param Tvictoire → variable pointant vers la texture de l'image changer
 *@param quitter → variable de verification de la fermeture de la fenetre : true -> fermeture de la fenetre
 *@param bouton → variable verifiant si la souris sur un bouton ( true ) sinon  ( False )
 *@param largeur → variable caractérisant la largeur de la fenetre
 *@param hauteur → variable caractérisant la hauteur de la fenetre
 */
void affichage_victoire();
/**
 *@brief commande de préprocesseur servant à obtenir le minimum entre deux valeur
 */
#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#endif //PROJET_D_IF_VICTOIRE_H