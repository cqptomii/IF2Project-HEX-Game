//
// Created by tomfr on 01/05/2023.
//

#ifndef PROJET_D_IF_COORD_H
#define PROJET_D_IF_COORD_H
#include "Coord.h"
#include "SDL2/SDL.h"
#include "Event_party.h"
extern short taille;
/**
 *@brief Fonctions qui récupère la ligne du clic et lance la fonction de récuperation de colonne, utiliser dans event_party()
 *@param jeu → variable evenement ( SDL )
 *@param tour_joueur → Variable désignant le tour du joueur → mis en parame*ètre de verif_coord
 *@param case_pion → structure contenant les caracs des pions → mis en paramètre de verif_coord
 *@param x → affecte le decalage initiale sur l'axe des x relatif à la ligne → mis en paramètre de verif_coord
 *@param y → valeur de la ligne sur l'axe des y
 *@param tourdouble_coups → variable verifiant si il y a double coup → mis en paramètre de verif_coord
 *@param supp_pion → variable verifiant si il y a suppresion d'un pion → mis en paramètre de verif_coord
 *@param supprimer → structure contenant la valeur du pion a supprimer si supp_pion=true → mis en paramètre de verif_coord
 *@param passer_tour → variable definissant si il faut passer ou non le tour du joueur → mis en paramètre de verif_coord
 *@param Taille_cas → position du pion allant être affiché --> ( n ème pion posé )
 */
void verifevent_clic(SDL_Event jeu,short *tour_joueur,pos_pion case_pion[],short *x,short *y,bool tourdouble_coups,bool supp_pion,pos_pion supprimer[],bool passer_tour,short Taille_cas);
/**
 *@brief Fonction de récupération de la colonne du clic, utilisé dans verifevent_clic()
 *@param x → valeur de la colonne sur l'axe des x
 *@param jeu → variable evenement ( SDL )
 *@param joueur → Variable désignant le tour du joueur si multiple de 2 : Bleu SINON  Rouge
 *@param ligne → variable comportant la ligne du pions
 *@param case_pion → structure contenant les caracs des pions
*@param tourdouble_coups → variable verifiant si il y a double coup
 *@param supp_pion → variable verifiant si il y a suppresion d'un pion
 *@param supprimer → structure contenant la valeur du pion a supprimer si supp_pion=true
 *@param passer_tour → variable definissant si il faut passer ou non le tour du joueur
 *@param Taille_cas → position du pion allant être affiché --> ( n ème pion posé )
 */
void verif_coord(short *x,SDL_Event jeu,const short *joueur,short ligne,pos_pion case_pion[],bool tourdouble_coups,bool supp_pion,pos_pion supprimer[],bool passer_tour,short Taille_cas);
/**
 *@brief Fonction gérant le changement de tour et l'affectation des caractéristique du pion dans Matrice2D, utilisé dans verif_coord()
 *@param casepion → structure contenant les caracs des pions
 *@param supprimer_pion → structure contenant la valeur du pion a supprimer si supp_pion=true
 *@param Taille_cas → position du pion allant être affiché --> ( n ème pion posé )
 *@param Matrice2D → Matrice où caractérisant le plateau de jeu et la postions des differents pions
 *@param supp_pion → variable verifiant si il y a suppresion d'un pion
 *@param double_coups → variable verifiant si il y a double coup
 *@param tour_joueur → Variable désignant le tour du joueur si multiple de 2 : Bleu SINON  Rouge
 *@param passer_tour → variable definissant si il faut passer ou non le tour du joueur
 *@param x → valeur en x du coin bas gauche de la case du pion
 *@param y → valeur en y du coin bas gauche de la case du pion
 *@param double_consec variable qui gère le cas ou deux doubles coups sont lancée simultanément par les deux joueurs
 */
void remplir_pion(pos_pion casepion[],pos_pion supprimer_pion[], short *Taille_cas,short Matrice2D[taille][taille],bool *supp_pion,bool *double_coups,short *tour_joueur,bool *passer_tour,short x,short y);
#endif //PROJET_D_IF_COORD_H
