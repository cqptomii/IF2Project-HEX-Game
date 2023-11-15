//
// Created by tomfr on 13/04/2023.
//

/*
   Dans ce .c Ensemble des fonctions liées à l'ouverture des fenetres graphiques jusqu'au depart du jeu
*/
/* inclusions des bibliothèques/.h nécéssaire*/
#include "Fenetres_Menus.h"
#include <stdbool.h> // Biblio pour le type bool
#include <SDL2/SDL.h> // Bibliothèque SDL
#include <stdio.h>
// Appel des variables globales intialisées dans mon fichier main.c pour les inclure dans le fichier ci-dessous
extern SDL_Window* gwindow;
extern SDL_Surface* gmenu;
extern SDL_Renderer* prenderer;
extern SDL_Texture* ptexture;
extern short taille;
extern short largeur;
extern short hauteur;


void Menu(bool* lancer_sauv,bool *lancer_jeu){
    // affectation des variables caractérisant les dimensions de notre image
    largeur=635;
    hauteur=622;

    // Initialisation de la SDL + Controle du succes de l'initialisation
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("Erreur lors de l'initialisation de la SDL: %s, ligne: %d\n",SDL_GetError(),__LINE__); // fonction SDL_GetERROR : renvoie l'erreur afin de simplifier le debogage
    }
    else{
        // creation d'une fenetre graphique destinée au Menu envoyé à l'adresse de gwindow
        gwindow = SDL_CreateWindow("Menu d'accueil",
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   largeur,
                                   hauteur,
                                   SDL_WINDOW_SHOWN);
        //Controle du succes de la creation de fenetre
        if(!gwindow){
            printf("Erreur lors de la creation de la fenetre Menu: %s , ligne: %d",SDL_GetError(),__LINE__);// fonction SDL_GetERROR : renvoie l'erreur afin de simplifier le debogage
            cleandata(gwindow, NULL,NULL,NULL);
        }
        else{
            // creation d'une Renderer (surface) usant de l'accélération matérielle afin d'y placer une texture
            prenderer= SDL_CreateRenderer(gwindow,-1,SDL_RENDERER_ACCELERATED); //envoyé à l'adresse de prerender

            //Verification du succes de la creation de la surface
            if(!prenderer){
                printf("Echec de l'allocation d'une renderer : %s , ligne: %d",SDL_GetError(),__LINE__); // fonction SDL_GetERROR : renvoie l'erreur afin de simplifier le debogage
                cleandata(gwindow,prenderer,NULL,NULL);
            }
        }
    }
    if(prenderer){
        gmenu= SDL_LoadBMP("../image/Menu.bmp");// Fonction important l'image
        // verification du succés de l'importation de l'image
        if(!gmenu){
            printf("Echec du chargement du sprite : %s , ligne : %d", SDL_GetError(),__LINE__); // fonction SDL_GetERROR : renvoie l'erreur afin de simplifier le debogage
            cleandata(gwindow,prenderer,gmenu,NULL);
        }
        else{

            ptexture= SDL_CreateTextureFromSurface(prenderer,gmenu); // creation de la texture de notre image
            if(ptexture){
                SDL_RenderCopy(prenderer,ptexture,NULL,NULL); // Copiage de notre
                SDL_RenderPresent(prenderer); // Mise à jour de la surface de notre Menu
                gmenu=NULL;
                eventMenu(lancer_sauv,lancer_jeu); // Fonction verifiants les differents évènements
            }
            else{ // Verification du succés de la creation de la texture
                printf("Echec de telechargement de la texture \n");
                cleandata(gwindow,prenderer,gmenu,ptexture);
            }
        }
    }

}
void eventMenu(bool* lancer_sauv,bool *lancer_jeu){
    //Initialisation des variables pour le fonctionnement de cette fonction
    bool *quitter= malloc(sizeof(bool));
    bool *bouton = malloc(sizeof(bool));
    *bouton=false;
    *quitter=false;
        // Variable de positions
    int *w= malloc(sizeof(int));
    int *l= malloc(sizeof(int));
    int *x = malloc(sizeof(int));
    int *y= malloc(sizeof(int));
    //
    SDL_Texture *pstart=NULL;
    SDL_Event menu;
    while(*quitter==false) {
        if (SDL_PollEvent(&menu)) {

            switch (menu.type) {
                case SDL_WINDOWEVENT: // Verification des évenements liés à la fenetre en elle même :

                    switch (menu.window.event) {
                        case SDL_WINDOWEVENT_CLOSE: // Actions a effectuer lors de la fermeture de la fenetre
                            *quitter = true;
                            *lancer_jeu=false;
                            destroyMenu();
                            SDL_Quit(); // Fonction quittant la SDL
                            break;
                    }
                    break;
                case SDL_MOUSEMOTION: // Verification des évenements liés aux mouvements de la souris
                        if (menu.motion.x > 158 && menu.motion.x < 456 && menu.motion.y > 234 && menu.motion.y < 273){
                            if(!gmenu && *bouton==false) {
                                gmenu= SDL_LoadBMP("../image/commencer.bmp"); // Fonction important notre image
                                *w=298;*l=60;*x=158;*y=234;
                                changement(gmenu,ptexture,*x,*y,*w,*l); // Fonction modifiant l'affichage de notre fenetre
                                *bouton=true;
                            }
                        }
                        else if(menu.motion.x>160 && menu.motion.x<457 && menu.motion.y>323 && menu.motion.y<376){
                            if (!gmenu && *bouton==false) {
                                gmenu= SDL_LoadBMP("../image/reprendre.bmp");
                                *x=160;*y=323;*w=298;*l=60;
                                changement(gmenu,pstart,*x,*y,*w,*l);
                                *bouton=true;
                            }
                        }
                        else if (menu.motion.x>193 && menu.motion.x<438 && menu.motion.y>419 && menu.motion.y<471){
                            if (!gmenu && *bouton==false) {
                                gmenu= SDL_LoadBMP("../image/quitter.bmp");
                                *x=193;*y=419;*w=245;*l= 51;
                                changement(gmenu,pstart,*x,*y,*w,*l);
                                *bouton=true;
                            }
                        }
                        else{
                            if (*bouton==true) {
                                SDL_DestroyTexture(pstart);
                                SDL_FreeSurface(gmenu);
                                gmenu=NULL;
                                pstart = NULL;
                                SDL_RenderCopy(prenderer, ptexture, NULL, NULL);
                                SDL_RenderPresent(prenderer);
                                *bouton=false;
                            }
                        }
                    break;

                case SDL_MOUSEBUTTONUP: // Verification des evenements liés aux clics de la souris
                    if( menu.button.x > 158 && menu.button.x < 456 && menu.button.y > 234 && menu.button.y < 273 ){

                        SDL_DestroyTexture(pstart);
                        pstart=NULL;
                        destroyMenu();
                        *quitter=true;
                        *lancer_jeu=true;
                    }
                    if(menu.button.x > 160 && menu.button.x < 457 &&  menu.button.y > 323 && menu.button.y < 376){

                        SDL_DestroyTexture(pstart);
                        pstart=NULL;
                        destroyMenu();
                        *quitter=true;
                        *lancer_sauv=true;
                        *lancer_jeu=true;
                    }
                    if(menu.button.x > 193 && menu.button.x < 438 && menu.button.y > 419 && menu.button.y < 471){
                            SDL_DestroyTexture(pstart);
                            pstart=NULL;
                            destroyMenu();
                            SDL_Quit();
                            *quitter=true;
                    }
            }
        }
        SDL_Delay(10); // attentes de 1O ms avant de continuer la recherche d'évenements
    }
    free(quitter);free(bouton);free(x);free(y);free(l);free(w); free(pstart);
}
void changement(SDL_Surface* start,SDL_Texture* pstart,int x,int y,int w,int l){

    //Controle de l'importation de notre image :
        if (!start) {
            printf("Erreur lors du chargement du spirte , %s \n", SDL_GetError());
            cleandata(gwindow,prenderer,gmenu,NULL);
        }
        else {
            pstart = SDL_CreateTextureFromSurface(prenderer, start); // Création de la texture de notre image
            if (pstart) {
                SDL_Rect coord = {x, y, w, l}; // coordonées où l'image est collée
                SDL_RenderCopy(prenderer, pstart, NULL, &coord); // Copiage de l'image dans la surface de notre fenetre
                SDL_RenderPresent(prenderer); // Mise à jour de la surface de notre fenetre
            }
            else{ // Message d'erreur, si erreur lors de la creation de la fenetre
                printf("Erreur lors de la creation de la texture : %s, ligne %d",SDL_GetError(),__LINE__);
                cleandata(gwindow,prenderer,gmenu,pstart);
            }
        }
}
void destroyMenu(){
    SDL_DestroyTexture(ptexture); //liberation de la memoire alloué à la texture
    ptexture=NULL;
    SDL_FreeSurface(gmenu); //liberation de la memoire alloué à l'image chargée
    gmenu=NULL;
    SDL_DestroyRenderer(prenderer); // destruction de la surface de notre fenetre → liberer la memoire allouer
    prenderer=NULL;
    SDL_DestroyWindow(gwindow); // destruction de notre fenetre → liberer la memoire allouer
    gwindow=NULL;
    // Mises des pointeurs a NULL afin d'éviter toutes erreurs
}
void mode_jeu(char *mode_jeu,bool *lancer_plateau){
 //Variable caractérisant les dimensions de notre image
  largeur=595;hauteur=635;

 gwindow= SDL_CreateWindow("Choix du mode de jeu :",
                         SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED,
                         largeur,
                         hauteur,
                         SDL_WINDOW_SHOWN); // Creation de notre fenetre  graphique
 if(!gwindow){
     printf("Erreur lors de l'ouverture du menu de mode de jeu : %s,ligne %d",SDL_GetError(),__LINE__);
     cleandata(gwindow,NULL,NULL,NULL);
 }
 else{
     prenderer= SDL_CreateRenderer(gwindow,-1,SDL_RENDERER_ACCELERATED);
     if (!prenderer){
         printf("Echec de la creation de la surface du menu de mode de jeu: %s,ligne %d",SDL_GetError(),__LINE__);
         cleandata(gwindow,prenderer,NULL,NULL);
     }
     else{
         gmenu= SDL_LoadBMP("../image/Mode.bmp");
         if(gmenu== NULL){
             printf("Echec du telechargement de l'image: %s,ligne %d",SDL_GetError(),__LINE__);
             cleandata(gwindow,prenderer,gmenu,NULL);
         }
         else{
             ptexture= SDL_CreateTextureFromSurface( prenderer, gmenu);
             if(ptexture) {
                 SDL_RenderCopy(prenderer, ptexture, NULL, NULL);
                 SDL_RenderPresent(prenderer);
                 gmenu=NULL;
                 event_mode(mode_jeu,lancer_plateau); // Fonction vérifiant les évenements liés a notre Menu : Mode
             }
             else{
                 printf("Echec de la creation de la texture: %s,ligne %d",SDL_GetError(),__LINE__);
                 cleandata(gwindow,prenderer,gmenu,ptexture);
             }
         }
     }
 }
}
void event_mode(char *mode_jeu,bool *lancer_plateau){
    //Variables nécessairent a la gestion des evenments
    bool *quitter= malloc(sizeof(bool));
    bool *bouton = malloc(sizeof(bool));
    *quitter= false;
    *bouton=false;

    int *w= malloc(sizeof(int));
    int *l= malloc(sizeof(int));
    int *x = malloc(sizeof(int));
    int *y= malloc(sizeof(int));
    SDL_Texture* gtextmvt=NULL;
    SDL_Event mode;
    while(*quitter== false){
        if(SDL_PollEvent(&mode)){
            switch (mode.type) {

                case SDL_WINDOWEVENT:

                    switch (mode.window.event) {
                        case SDL_WINDOWEVENT_CLOSE:
                            *quitter=true;
                            destroymode();
                            *lancer_plateau=false;
                            SDL_Quit();
                            break;
                    }
                    break;

                case SDL_MOUSEMOTION:

                    if (mode.motion.x > 160 && mode.motion.x < 447 && mode.motion.y > 227 && mode.motion.y < 305){
                        if(!gmenu && *bouton==false) {
                            gmenu= SDL_LoadBMP("../image/standard.bmp");
                            *x=160;*y=227;*w=287;*l=78;
                            changement(gmenu,gtextmvt,*x,*y,*w,*l);
                            *bouton=true;
                        }
                    }
                    else if (mode.motion.x>160 && mode.motion.x<447 && mode.motion.y>338 && mode.motion.y<417){
                        if(!gmenu && *bouton==false) {
                            gmenu= SDL_LoadBMP("../image/aleatoire.bmp");
                            *x=160;*y=338;*w=287;*l=79;
                            changement(gmenu,gtextmvt,*x,*y,*w,*l);
                            *bouton=true;

                        }
                    }
                    else if(mode.motion.x>159 && mode.motion.x<446 && mode.motion.y>444 && mode.motion.y<522){
                        if(!gmenu && *bouton==false) {
                            gmenu= SDL_LoadBMP("../image/special.bmp");
                            *x=159;*y=444;*w=287;*l=78;
                            changement(gmenu,gtextmvt,*x,*y,*w,*l);
                            *bouton=true;

                        }
                    }
                    else if(mode.motion.x>15 && mode.motion.x<96 && mode.motion.y>549 && mode.motion.y<618){
                        if(!gmenu && *bouton==false) {
                            gmenu= SDL_LoadBMP("../image/9.bmp");
                            *x=15;*y=549;*w=81;*l=69;
                            changement(gmenu,gtextmvt,*x,*y,*w,*l);
                            *bouton=true;
                        }
                    }
                    else if (mode.motion.x>116 && mode.motion.x<197 && mode.motion.y>549 && mode.motion.y<618) {
                        if(!gmenu && *bouton==false) {
                            gmenu= SDL_LoadBMP("../image/10.bmp");
                            *x=116;*y=549;*w=81;*l=69;
                            changement(gmenu,gtextmvt,*x,*y,*w,*l);
                            *bouton=true;
                        }
                    }
                    else if (mode.motion.x>216 && mode.motion.x<297 && mode.motion.y>549 && mode.motion.y<618) {
                        if(!gmenu && *bouton==false) {
                            gmenu= SDL_LoadBMP("../image/11.bmp");
                            *x=216;*y=549;*w=81;*l=69;
                            changement(gmenu,gtextmvt,*x,*y,*w,*l);
                            *bouton=true;
                        }
                    }
                    else if (mode.motion.x>309 && mode.motion.x<391 && mode.motion.y>549 && mode.motion.y<618) {
                        if(!gmenu && *bouton==false) {
                            gmenu= SDL_LoadBMP("../image/12.bmp");
                            *x=309;*y=549;*w=82;*l=69;
                            changement(gmenu,gtextmvt,*x,*y,*w,*l);
                            *bouton=true;
                        }
                    }
                    else if (mode.motion.x>408 && mode.motion.x<489 && mode.motion.y>549 && mode.motion.y<618) {
                        if(!gmenu && *bouton==false) {
                            gmenu= SDL_LoadBMP("../image/13.bmp");
                            *x=408;*y=549;*w=81;*l=69;
                            changement(gmenu,gtextmvt,*x,*y,*w,*l);
                            *bouton=true;
                        }
                    }
                    else if(mode.motion.x>502 && mode.motion.x<584 && mode.motion.y>549 && mode.motion.y<618){
                        if(!gmenu && *bouton==false) {
                            gmenu= SDL_LoadBMP("../image/14.bmp");
                            *x=502;*y=549;*w=82;*l=69;
                            changement(gmenu,gtextmvt,*x,*y,*w,*l);
                            *bouton=true;
                        }
                    }
                    else{
                        if(*bouton==true) {
                            SDL_DestroyTexture(gtextmvt);
                            SDL_FreeSurface(gmenu);
                            gmenu = NULL;
                            gtextmvt = NULL;
                            SDL_RenderCopy(prenderer, ptexture, NULL, NULL);
                            SDL_RenderPresent(prenderer);
                            *bouton=false;
                        }
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    if(mode.button.x > 160 && mode.button.x < 447 && mode.button.y > 227 && mode.button.y < 305)
                    {
                        SDL_DestroyTexture(gtextmvt);
                        gtextmvt = NULL;
                        destroymode();
                        *mode_jeu='P';
                        *quitter=true;
                    }
                    else if ( mode.button.x > 160 && mode.button.x < 447 && mode.button.y > 338 && mode.button.y < 417 ){
                        SDL_DestroyTexture(gtextmvt);
                        gtextmvt = NULL;
                        destroymode();
                        *mode_jeu='A';
                        *quitter=true;
                    }
                    else if( mode.button.x > 159 && mode.button.x < 446 && mode.button.y > 444 && mode.button.y < 522){
                        SDL_DestroyTexture(gtextmvt);
                        gtextmvt = NULL;
                        destroymode();
                        *mode_jeu='S';
                        *quitter=true;
                    }
                    else if (mode.button.x>15 && mode.button.x<96 && mode.button.y>549 && mode.button.y<618)   { taille = 9 ; }
                    else if (mode.button.x>116 && mode.button.x<197 && mode.button.y>549 && mode.button.y<618) { taille = 10; }
                    else if (mode.button.x>216 && mode.button.x<297 && mode.button.y>549 && mode.button.y<618) { taille = 11; }
                    else if (mode.button.x>309 && mode.button.x<391 && mode.button.y>549 && mode.button.y<618) { taille = 12; }
                    else if (mode.button.x>408 && mode.button.x<489 && mode.button.y>549 && mode.button.y<618) { taille = 13; }
                    else if (mode.button.x>502 && mode.button.x<584 && mode.button.y>549 && mode.button.y<618) { taille = 14; }
                break;
            }
        }
        SDL_Delay(30);
    }
    free(x);free(y);free(l);free(w);free(quitter);free(bouton);free(gtextmvt);
}
void destroymode(){
    SDL_DestroyTexture(ptexture);
    ptexture=NULL;
    SDL_FreeSurface(gmenu);
    gmenu=NULL;
    SDL_DestroyRenderer(prenderer);
    prenderer=NULL;
    SDL_DestroyWindow(gwindow);
    gwindow=NULL;
}
void cleandata(SDL_Window *w, SDL_Renderer *r,SDL_Surface *s,SDL_Texture *t){

    if(t){
        SDL_DestroyTexture(t);
        t=NULL;
    }
    if(s){
        SDL_FreeSurface(s);
        s=NULL;
    }
    if(r){
        SDL_DestroyRenderer(r);
        r=NULL;
    }
    if(w){
        SDL_DestroyWindow(w);
        w=NULL;
    }
}