//
// Created by tomfr on 19/04/2023.
//

#ifndef PROJET_D_IF_EVENT_PARTY_H
#define PROJET_D_IF_EVENT_PARTY_H
#include "party.h"
/**
 * @brief Structure récupérant la colonne, la ligne et le pion associé  lors de chaque tour de jeu
 * @param lignes → ligne sur laquelle le pion est posée
 * @param colonnes → colonne sur laquelle le pion est posée
 * @param joueur → joueur associé au pion
 */
typedef struct pos_pion pos_pion;
struct pos_pion{
    short lignes;
    short colonnes;
    short joueur;
};
/**
 * @brief Fonction qui verifient l'ensemble des evenements pouvant survenir dans la fenetre party
 * @param mode_jeu → variable definissant le mode de jeu
 * @param sauv → variable determinant si il y a une sauvegarde à charger ou non
 * @param pstart → variable pointant vers la texture des boutons
 * @param quitter → variable verifiant la fermeture du programme, si true → fermeture du programme
 * @param bouton → variable verifiant sur la souris est sur un bouton, si true → les images des boutons ne sont plus blit
 * @param passer_tour → variable verifiant si le tour d'un joueur est passée: Mode de jeu spécial pour les options doubles coups et Supprimer un pion
 * @param supp_pion → variable verifiant si l'on souhaite supprimer un pion, si true → le joueur peut supprimer un pion
 * @param double_coups → variable verifiant si l'on souhaite faire un double coups, si true → on peut poser deux pions ...
 * @param casepion → tableau de structure pos_pion récuperant les informations des pions posé
 * @param supprimer_pion → variable de type pos_pion récuperant les informations du pion à supprimer
 * @param Matrice2D → Matrice de jeux, récuperant la valeur de chaque pion, Bleu : 1 ET Rouge : 2
 * @param Matrice_victoire → Matrice de verification de victoire, Rouge < 0 ET Bleu > 0
 */
void events_party(const char *mode_jeu,const bool *sauv );
/**
 * @brief Fonction qui affiche le pion sur le plateau de jeu
 * @param tpion → Variable pointant vers la texture du pion
 * @param gx → coordonée x du pion affiché
 * @param gy → coordonée y du pion affiché
 * @param joueur → tour du joueur, si multiple de 2 : Bleu SINON Rouge
 * @param supp_pion → verification si suppression de pion ( true ) OU non ( false )
 */
void affichage_pion(int gx,int gy,short joueur,bool *supp_pion);
#endif //PROJET_D_IF_EVENT_PARTY_H
