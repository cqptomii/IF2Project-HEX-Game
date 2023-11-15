//
// Created by tomfr on 14/04/2023.
//

// Directives de preproccesseur afin d'eviter d'appeller plusieurs fois les variables globales

#include "party.h"
#include "Event_party.h"
#include "Fenetres_Menus.h"
// Appel des variables globales intialisées dans mon fichier main.c pour les inclure dans le fichier ci-dessous
extern SDL_Window* gwindow;
extern SDL_Surface* gmenu;
extern SDL_Renderer* prenderer;
extern SDL_Texture* ptexture;
extern short victoire;
extern short taille;
extern short hauteur;
extern short largeur;

void initplateau(const char *mode_jeu,bool *sauvegarde) {
    //variables caractérisant les dimensions de la fenetre
    largeur = 1230;hauteur = 1000;

    gwindow = SDL_CreateWindow("Jeu de HEX",
                               SDL_WINDOWPOS_CENTERED,
                               10,
                               largeur,
                               hauteur,
                               SDL_WINDOW_SHOWN);

    if (!gwindow) {
        printf("Erreur lors de la creation de la fenetre de jeu : %s, ligne %d", SDL_GetError(), __LINE__);
    }
    prenderer = SDL_CreateRenderer(gwindow, -1, SDL_RENDERER_ACCELERATED);
    if (!prenderer) {
        printf("Erreur lors de la creation de la surface de la fenetre de jeu : %s, ligne %d", SDL_GetError(),
               __LINE__);
    }
    else {
        switch (taille) { // Switch qui importe la bonne image selon la taille et le mode de jeu choisi
            case 9:
                if (*mode_jeu == 'S') {
                    gmenu= SDL_LoadBMP("../image/Taille9SPE.bmp");
                }
                else {
                    gmenu= SDL_LoadBMP("../image/Taille9.bmp");
                }
                break;
            case 10:
                if (*mode_jeu == 'S') {
                    gmenu= SDL_LoadBMP("../image/Taille10SPE.bmp");
                }
                else {
                    gmenu= SDL_LoadBMP("../image/Taille10.bmp");
                }
                break;
            case 11:
                if (*mode_jeu == 'S') {
                    gmenu= SDL_LoadBMP("../image/Taille11SPE.bmp");
                }
                else {
                    gmenu= SDL_LoadBMP("../image/Taille11.bmp");
                }
                break;
            case 12:
                if (*mode_jeu == 'S') {
                    gmenu= SDL_LoadBMP("../image/Taille12SPE.bmp");
                }
                else {
                    gmenu= SDL_LoadBMP("../image/Taille12.bmp");
                }
                break;
            case 13:
                if (*mode_jeu == 'S') {
                    gmenu= SDL_LoadBMP("../image/Taille13SPE.bmp");
                }
                else {
                    gmenu= SDL_LoadBMP("../image/Taille13.bmp");
                }
                break;
            case 14:
                if (*mode_jeu == 'S') {
                    gmenu= SDL_LoadBMP("../image/Taille14SPE.bmp");
                }
                else {
                    gmenu= SDL_LoadBMP("../image/Taille14.bmp");
                }
            break;
            default:
                if (*mode_jeu == 'S') {
                    gmenu= SDL_LoadBMP("../image/Taille9SPE.bmp");
                }
                else {
                    gmenu= SDL_LoadBMP("../image/Taille9.bmp");
                }
                break;
        }

        if (!gmenu) {
            printf("Erreur de l'initialisation de l'image: %s , %d \n",SDL_GetError(),__LINE__);
        }
        else {
            ptexture = SDL_CreateTextureFromSurface(prenderer, gmenu);
            if (!ptexture) {
                printf("Erreur lors de la creation de la texture: %s , %d \n",SDL_GetError(),__LINE__);
            }
            else{
                SDL_RenderCopy(prenderer, ptexture, NULL, NULL);
                SDL_RenderPresent(prenderer);
            }
            events_party(mode_jeu,sauvegarde); // Fonction qui vérifie les évenements de la fenetre party
        }
    }

}
void destroyparty(){
    SDL_DestroyTexture(ptexture);
    ptexture=NULL;
    SDL_FreeSurface(gmenu);
    gmenu=NULL;
    SDL_DestroyRenderer(prenderer);
    prenderer=NULL;
    SDL_DestroyWindow(gwindow);
    gwindow=NULL;
}