//
// Created by tomfr on 16/04/2023.
//
#ifndef PROJET_D_IF_PARTY_H
#define PROJET_D_IF_PARTY_H
#include "stdbool.h"
#include "stdio.h"
#include "Event_party.h"
//
/* Fonctions dédiées à l'interface de jeu*/
//
/**
 * @brief Fonction qui crée la fenetre de jeu
 * @param mode_jeu → paramètre definissant le mode de jeu  / Et donc l'image que l'on va chargée
 * @param taille → paramètre definissant la taille de notre tableau à deux dimension/ Et donc l'image chargée
 * @param sauvegarde → paramètre condition qui sert à récuperer ou non la sauvegarde d'un ancienne partie
 * @param hauteur → paramètre caractérisant la hauteur de notre fenetre
 * @param largeur → paramètre caractérisant la largeur de notre fenetre
 * @param gwindow → paramètre pointant vers notre fenetre
 * @param prenderer → paramètre pointant vers la surface de notre fenetre
 * @param gmenu → paramètre pointant vers une image
 * @param ptexture → paramètre pointant vers la texture de notre image
 */
void initplateau(const char *mode_jeu,bool *sauvegarde);
/**
 *@brief Fonction detruisant la fenetre de notre plateau de jeu
 * @param ptexture → paramètre pointant vers la texture de la fenetre graphique
 * @param gmenu → paramètre pointant ici vers l'image chargée
 * @param prenderer → paramètre pointant vers la surface de notre fenetre graphique
 * @param gwindow → paramètre pointant ici vers la fenetre Menu
 */
void destroyparty();
#endif //PROJET_D_IF_PARTY_H
