//
// Created by tomfr on 13/04/2023.
//

#ifndef PROJET_D_IF_FONCTIONS_SDL_H
#define PROJET_D_IF_FONCTIONS_SDL_H
#include "stdbool.h"
#include "SDL2/SDL.h"

//

//Fonctions dédiées au Menu d'entrée

//

/**
 * @brief Fonctions initiant la SDL / Creant la fenetre graphique dédiés au menu
 *
 * @param *lancer_sauv → Si TRUE lance la sauvegarde SINON ne lance pas la sauvegarde
 * @param *lancer_jeu → Si TRUE lance la suite du programme SINON : Fin programme
 * @param hauteur → paramètre caracterisant la hauteur de la fenetre graphique
 * @param largeur → paramètre caracterisant la largeur de la fenetre graphique
 * @param gwindow → paramètre pointant vers la fenetre graphique ressort NULL si echec de la creation de la fenetre
 * @param prenderer → paramètre pointant vers la surface graphique de notre fenetre ressort NULL si echec de la creation de la surface
 * @param ptexture → paramètre pointant vers la texture de notre fenetre graphique ressort NULL si creation de la texture
 * @param gmenu → paramètre pointant vers l'image graphique affiché ressort NULL si echec de l'importation de l'image
 *
 * SDL_CreateWindow() → Fonction permettant de créer une fenetre graphique / Renvoie NULL si echec
 * SDL_CreateRenderer() → Fonction permettant de créer une surface (ici utilisant l'accélération matérielle : Carte graphique) / Renvoie NULL si echec
 * SDL_CreateTextureFromSurface() → Fonction permettant de créer une texture pour notre image chargée
 * SDL_RenderCopy() → Fonction copiant la texture crée sur notre surface
 * SDL_RenderPresent() → Fonction actualisant la surface graphique de la fenetre
 */
void Menu(bool *lancer_sauv,bool *lancer_jeu);

/**
 * @brief Fonction définissant et gérant l'ensemble des evenements liés à notre Menu
 *
 * @param *lancer_sauv → Si TRUE lance la sauvegarde SINON ne lance pas la sauvegarde
 * @param *lancer_jeu → Si TRUE lance la suite du programme SINON : Fin programme
 * @param quitter → Si TRUE on met fin au programme SINON le programme continue
 * @param bouton → SI TRUE : la souris est sur un des boutons du Menu SINON la souris n'est sur aucun bouton
 * @param pstart → Paramètre pointant vers la texture de nos boutons
 * @param w, l, x, y → Paramètres définissant la taille de chaque bouton : w = width / l = largeur / x = coord en x / y = coord en y
 *
 * SDL_Event → directive créant un evenement nommés
 * SDL_POLLEVENT() → Fonction qui récupère les evenements de la fenetre: Renvoie NULL si aucun evenement
 * SDL_DELAY() → Fonction permettant de laisser du temps entre deux verification d'evenement afin de ne pas utiliser trop de mémoire
 * */
void eventMenu(bool *lancer_sauv,bool *lancer_jeu);

/**
 * @brief Fonction qui vient creer une texture à partir d'une image et actualiser le renderer, utilisé dans l'ensemble du programme pour chaque changement d'image
 *
 * @param Start → Paramètre pointant vers l'image chargée
 * @param pstart → Paramètre pointant vers la texture de notre image
 * @param x, y, w, l → Paramètres définissant la taille de chaque bouton : w = width / l = largeur / x = coord en x / y = coord en y
 *
 *SDL_Rect → Directive créant un rectangle à partir de 4 paramètres: Largeur/Longueur / Coordonnées x et y du point haut gauche
 * */
void changement(SDL_Surface* start,SDL_Texture *pstart,int x,int y,int w,int l);

/**
 * @brief Fonction qui detruis la fenetre Menu et les differentes images importées , utilisé lors de la femerture du Menu OU si on quiite le programme
 * @param ptexture → paramètre pointant vers la texture de la fenetre graphique
 * @param gmenu → paramètre pointant ici vers l'image chargée
 * @param prenderer → paramètre pointant vers la surface de notre fenetre graphique
 * @param gwindow → paramètre pointant ici vers la fenetre Menu
 */

void destroyMenu();

//

//Fonctions dédiées au Menu de Mode de jeu

//
/***************************************************************************************************************************************************************/
/**
 * @brief Fonction qui crée l'interface graphique dédiés aux differents modes de jeu
 * @param mode_jeu → paramètre pointant vers le mode de jeux choisi
 * @param lancer_plateau → paramètre vérifiant le lancement ou non de notre plateau de jeu
 * @param largeur → paramètre caractérisant la largeur de notre fenetre graphique
 * @param hauteur → paramètre caractérisant la hauteur de notre fenete graphique
 * @param gwindow → paramètre pointant vers notre fenetre
 * @param prenderer → paramètre pointant vers la surface de notre fenetre
 * @param gmenu → paramètre pointant vers une image
 * @param ptexture → paramètre pointant vers la texture de notre image
 */
void mode_jeu(char *mode_jeu,bool *lancer_plateau);
/**
 * @brief Fonctions verifiant les evenements survenant dans notre fenetre mode : utiliser dans la fonction mode_jeu
 * @param mode_jeu → paramètre pointant vers le mode de jeux choisi
 * @param lancer_plateau → paramètre vérifiant le lancement ou non de notre plateau de jeu
 */
void event_mode(char *mode_jeu,bool *lancer_plateau);
/**
 * @brief Fonction qui détruis notre fenetre graphique mode , utiliser si le menu mode est quitter OU si le choix d'une mode de jeu est effectuer
 * @param ptexture → paramètre pointant vers la texture de la fenetre graphique
 * @param gtextmvt → paramètre pointant vers la texture de l'image modifié
 * @param gmenu → paramètre pointant ici vers l'image chargée
 * @param prenderer → paramètre pointant vers la surface de notre fenetre graphique
 * @param gwindow → paramètre pointant ici vers la fenetre Menu
 */
void destroymode();
void cleandata(SDL_Window *w, SDL_Renderer *r,SDL_Surface *s,SDL_Texture *t);
#endif //PROJET_D_IF_FONCTIONS_SDL_H
