//
// Created by tomfr on 20/04/2023.
//

#ifndef PROJET_D_IF_SAUV_H
#define PROJET_D_IF_SAUV_H
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
/**
 *@brief Fonctions qui effectue la sauvegarde de la partie, utilisé dans event_party
 *@param sauv → variable pointant vers le fichier qui va être ouvert
 *@param mod_jeu → variable contenant le mode de jeu qui va être ecris dans le fichier
 *@param cas_pion → structure contenant les caracs des pions, qui vont être écrites dans le fichier
 *@param Taill_cas → position du pion allant être affiché --> ( n ème pion posé ), qui va être ecrit dan le fichier
 */
void sauvegarde(char mod_jeu,pos_pion cas_pion[],int Taill_cas);
/**
 *@brief Fonction qui recupère les donées de la sauvegarde, utilisé dans event_menu()
 *@param case_pion → structure contenant les caracs des pions, qui va être recuperer à l'aide du fichier txt
 *@param Taille_cas → position du pion allant être affiché --> ( n ème pion posé ) qui va être recuperer à partir du fichier txt
 */
void recup_sauvegarde(pos_pion case_pion[],short *Taille_cas );
/**
 *@brief Fonctions qui recupère les coordonées x et y de chaque pion afin d'afficher les pions sur le plateau
 *@param casepion → structure contenant les caracs des pions, qui fournies les caracs lignes/colonnes/joueur
 *@param x → valeur du coin gauche de la case sur l'axe des x  --> permettra d'afficher le pion
 *@param y → valeur du coin bas gauche de la case sur l'axe y  --> permettra d'afficher le pion
 *@param i → variable de parcours
 */
void recup_xy(pos_pion casepion[],short *x,short *y,short i);
#endif //PROJET_D_IF_SAUV_H
