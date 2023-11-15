//
// Created by tomfr on 27/04/2023.
//
#include "Victoire.h"
#include "stdlib.h"
#include "stdio.h"
#include "Fenetres_Menus.h"
void verif_victoire(short tour_joueur,short b,short i,short Matrice2D[taille][taille],short Matrice_victoire[taille][taille]){
    bool enter_verif = false;

    //
    //Fin allocation du tableau a deux dimensions
    if (tour_joueur % 2 != 0) { // algo pour le joueur bleu
        for (i = 0; i < taille ; i += 1) {    // Verification de la presence d'un pion sur la première colonne
            if (Matrice2D[i][0] == 1) {
                Matrice_victoire[i][0] = 1;
                enter_verif = true;
            }
        }
        if (enter_verif) {
            for (b = 1; b < taille; b += 1) {
                for (i = 0; i < taille; i += 1) {
                    if(Matrice2D[i][b]>30){ // cas d'un pion supprimée
                        Matrice_victoire[i][b]=0;
                    }
                    else if(Matrice2D[i][b] == 1) {

                        if (i == taille - 1) { // Cas particulier sur la dernière ligne du tableau

                            if (Matrice2D[i][b - 1] == 1 && Matrice2D[i - 1][b] == 1) {
                                Matrice_victoire[i][b] = MIN(Matrice_victoire[i][b - 1],Matrice_victoire[i - 1][b]);
                            }
                            else if(Matrice2D[i][b-1]==1){
                                Matrice_victoire[i][b]=Matrice_victoire[i][b-1];
                            }
                            else if(Matrice2D[i-1][b]==1){
                                Matrice_victoire[i][b]=Matrice_victoire[i-1][b];
                            }

                            if (Matrice_victoire[i][b] != 0) {
                                Matrice_victoire[i][b] += 1;
                            }
                        }
                        else if(i == 0){ // cas particulier sur la première ligne du tableau
                            if(Matrice2D[i][b-1]==1 && Matrice2D[i+1][b-1]==1){
                                Matrice_victoire[i][b]= MIN(Matrice_victoire[i][b - 1], Matrice_victoire[i + 1][b - 1]);
                            }
                            else if(Matrice2D[i][b-1]==1){
                                Matrice_victoire[i][b]=Matrice_victoire[i][b-1];
                            }
                            else if(Matrice2D[i+1][b-1]==1){
                                Matrice_victoire[i][b]=Matrice_victoire[i+1][b-1];
                            }

                            if(Matrice_victoire[i][b]!=0) {
                                Matrice_victoire[i][b] += 1;
                            }
                        }
                        else{
                            // Algorithme standard, verif de 5 cases adjacentes afin de prendre en comptes les cas particuliers
                            if(Matrice2D[i][b-1]==1 && Matrice2D[i+1][b-1]==1 && Matrice2D[i-1][b]==1){
                                Matrice_victoire[i][b]= MIN(Matrice_victoire[i][b-1],Matrice_victoire[i+1][b-1]);
                                Matrice_victoire[i][b]= MIN(Matrice_victoire[i][b],Matrice_victoire[i-1][b]);
                            }
                            else if(Matrice2D[i][b-1]==1 && Matrice2D[i+1][b-1]==1){
                               Matrice_victoire[i][b]= MIN(Matrice_victoire[i][b-1],Matrice_victoire[i+1][b-1]);
                            }
                            else if (Matrice2D[i+1][b-1]==1 && Matrice_victoire[i-1][b]==1){
                               Matrice_victoire[i][b]= MIN(Matrice_victoire[i+1][b-1],Matrice_victoire[i-1][b]);
                            }
                            else if(Matrice2D[i][b-1]==1 && Matrice2D[i-1][b]==1 ){
                               Matrice_victoire[i][b]= MIN(Matrice_victoire[i][b-1],Matrice_victoire[i-1][b]);
                            }
                            else if(Matrice2D[i][b-1]==1){
                               Matrice_victoire[i][b]= Matrice_victoire[i][b-1];
                            }
                            else if(Matrice2D[i+1][b-1]==1){
                               Matrice_victoire[i][b]= Matrice_victoire[i+1][b-1];
                            }
                            else if(Matrice2D[i-1][b]==1){
                               Matrice_victoire[i][b]= Matrice_victoire[i-1][b];
                            }
                            else if(Matrice2D[i+1][b]==1){
                                Matrice_victoire[i][b]=Matrice_victoire[i+1][b];
                            }
                            else if(Matrice2D[i-1][b+1]==1){
                                Matrice_victoire[i][b]=Matrice_victoire[i-1][b+1];
                            }
                            else if(Matrice2D[i+1][b+1]==1){
                                Matrice_victoire[i][b]=Matrice_victoire[i+1][b+1];
                            }
                            if(Matrice_victoire[i][b]!=0) {
                                Matrice_victoire[i][b] += 1;
                            }
                   }
                 }
                   }
                }

            }
            for(i=0;i<taille;i+=1){  // verification de la présence d'un pion sur la dernière ligne liée
                if(Matrice_victoire[i][taille-1]>0 && Matrice2D[i][taille-1]==1){
                    victoire=1;
                }
            }
        }else {// algo pour le joueur rouge
            for(i = 0; i < taille; i += 1) { // verification de la présence d'un pion sur la première ligne
              if (Matrice2D[0][i] == 2) {
                  Matrice_victoire[0][i] = -1;
                  enter_verif = true;
              }
            }
            if (enter_verif) {
                for (b = 1; b < taille; b += 1) {
                    for (i = 0; i < taille; i += 1) { // cas d'un pion supprimée
                        if(Matrice2D[b][i]>30){
                            Matrice_victoire[b][i]=0;
                        }
                        else if(Matrice2D[b][i]==2) {
                            if (i == taille - 1) { // Cas particulier sur la dernière ligne du tableau

                                if (Matrice2D[b][i - 1] == 2 && Matrice2D[b-1][i] == 2) {
                                    Matrice_victoire[b][i] = MIN(Matrice_victoire[b][i - 1],Matrice_victoire[b - 1][i]);
                                }
                                else if(Matrice2D[b][i-1]==2){
                                    Matrice_victoire[b][i]=Matrice_victoire[b][i-1];
                                }
                                else if(Matrice2D[b-1][i]==2){
                                    Matrice_victoire[b][i]=Matrice_victoire[b-1][i];
                                }

                                if (Matrice_victoire[b][i] != 0) {
                                    Matrice_victoire[b][i] -= 1;
                                }
                            }
                            else if(i == 0){ // cas particulier sur la première ligne du tableau
                                if(Matrice2D[b-1][i]==2 && Matrice2D[b-1][i+1]==2){
                                    Matrice_victoire[b][i]= MIN(Matrice_victoire[b-1][i], Matrice_victoire[b-1][i+1]);
                                }
                                else if(Matrice2D[b-1][i]==2){
                                    Matrice_victoire[b][i]=Matrice_victoire[b-1][i];
                                }
                                else if(Matrice2D[b-1][i+1]==2){
                                    Matrice_victoire[b][i]=Matrice_victoire[b-1][i+1];
                                }
                                else if( Matrice2D[b][i+2]==2){
                                    Matrice_victoire[b][i]=Matrice_victoire[b-1][i+2];
                                }

                                if(Matrice_victoire[b][i]!=0) {
                                    Matrice_victoire[b][i] -= 1;
                                }
                            }
                            else {

                                if (Matrice2D[b - 1][i] == 2 && Matrice2D[b - 1][i + 1] == 2 && Matrice2D[b][i + 1] == 2) {
                                    Matrice_victoire[b][i] = MIN(Matrice_victoire[b - 1][i],Matrice_victoire[b - 1][i + 1]);
                                    Matrice_victoire[b][i] = MIN(Matrice_victoire[b][i], Matrice_victoire[b][i + 1]);
                                }
                                else if (Matrice2D[b - 1][i] == 2 && Matrice2D[b - 1][i + 1] == 2) {
                                    Matrice_victoire[b][i] = MIN(Matrice_victoire[b - 1][i],Matrice_victoire[b - 1][i + 1]);
                                }
                                else if (Matrice2D[b - 1][i + 1] == 2 && Matrice2D[b][i + 1] == 2) {
                                    Matrice_victoire[b][i] = MIN(Matrice_victoire[b - 1][i + 1],Matrice_victoire[b][i + 1]);
                                }
                                else if (Matrice2D[b - 1][i] == 2 && Matrice2D[b][i + 1] == 2) {
                                    Matrice_victoire[b][i] = MIN(Matrice_victoire[b - 1][i],Matrice_victoire[b][i + 1]);
                                }
                                else if (Matrice2D[b - 1][i] == 2) {
                                    Matrice_victoire[b][i] = Matrice_victoire[b - 1][i];
                                }
                                else if (Matrice2D[b - 1][i + 1] == 2) {
                                    Matrice_victoire[b][i] = Matrice_victoire[b - 1][i + 1];
                                }
                                else if (Matrice2D[b][i + 1] == 2 ) {
                                    Matrice_victoire[b][i] = Matrice_victoire[b][i + 1];
                                }
                                else if (Matrice2D[b][i - 1] == 2 ) {
                                    Matrice_victoire[b][i] = Matrice_victoire[b][i - 1];
                                }
                                else if (Matrice2D[b + 1][i - 1] == 2) {
                                    Matrice_victoire[b][i] = Matrice_victoire[b + 1][i - 1];
                                }
                                else if (Matrice2D[b+1][i+1]==2){
                                    Matrice_victoire[b][i] = Matrice_victoire[b+1][i+1]; 
                                }
                                if (Matrice_victoire[i][b] != 0) {
                                    Matrice_victoire[i][b]--;
                                }
                            }
                        }
                }
            }

        }
        for(i=0;i<taille;i+=1){ // Verification de la présence d'un pion sur la dernière ligne
            if(Matrice_victoire[taille-1][i]<0 && Matrice2D[taille-1][i]==2){
                victoire=2;
            }
        }
    }
}
void affichage_victoire(){
    SDL_Window *gvictoire=NULL;
    SDL_Renderer *rvictoire=NULL;
    SDL_Texture *tvictoire=NULL;
    SDL_Texture *Tvictoire=NULL;
    bool *quitter= malloc(sizeof(bool));
    bool *bouton= malloc(sizeof(bool));
    *bouton=false;
    *quitter=false;
    largeur=547;hauteur=280;
    gvictoire= SDL_CreateWindow("Victoire !! ",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                largeur,hauteur,
                                SDL_WINDOW_SHOWN);
    if(!gvictoire){
        printf("erreur lors de la creation de la fenetre  de victoire :%s , ligne :%d \n",SDL_GetError(),__LINE__);
    }
    else{
        rvictoire= SDL_CreateRenderer(gvictoire, -1, SDL_RENDERER_ACCELERATED);
        if (!rvictoire){
            printf("erreur lors de la creation de la surface de la fenetre de victoire %s, %d:",SDL_GetError(),__LINE__);
        }
        else{
            if(victoire==2){
                gmenu= SDL_LoadBMP("../image/victoirerouge.bmp");
            }
            else if (victoire==1){
                gmenu= SDL_LoadBMP("../image/victoirebleu.bmp");
            }
            if (!gmenu) {
                printf("Erreur de l'initialisation de l'image: %s , %d \n",SDL_GetError(),__LINE__);
            }
            else{
                tvictoire = SDL_CreateTextureFromSurface(rvictoire, gmenu);
                if (!tvictoire) {
                    printf("Erreur lors de la creation de la texture: %s , %d \n",SDL_GetError(),__LINE__);
                }
                else{
                    SDL_RenderCopy(rvictoire, tvictoire, NULL, NULL);
                    SDL_RenderPresent(rvictoire);
                    gmenu=NULL;
                    tvictoire=NULL;
                 SDL_Event vicjeu;
                 while(*quitter==false){
                     if(SDL_PollEvent(&vicjeu)){
                         switch (vicjeu.type) {
                             case SDL_WINDOWEVENT:
                                 switch (vicjeu.window.event) {
                                     case SDL_WINDOWEVENT_CLOSE:
                                         SDL_FreeSurface(gmenu);
                                         gmenu=NULL;
                                         SDL_DestroyTexture(tvictoire);
                                         tvictoire=NULL;
                                         SDL_DestroyRenderer(rvictoire);
                                         rvictoire=NULL;
                                         SDL_DestroyWindow(gvictoire);
                                         gvictoire=NULL;
                                         *quitter=true;
                                         break;
                                 }
                             break;
                             case SDL_MOUSEBUTTONUP:
                                 if(vicjeu.motion.y>209 && vicjeu.motion.y<259 && vicjeu.motion.x>208 && vicjeu.motion.x<337){
                                     SDL_FreeSurface(gmenu);
                                     gmenu=NULL;
                                     SDL_DestroyTexture(Tvictoire);
                                     Tvictoire=NULL;
                                     SDL_DestroyRenderer(rvictoire);
                                     rvictoire=NULL;
                                     SDL_DestroyWindow(gvictoire);
                                     gvictoire=NULL;
                                     *quitter=true;
                                 }
                                 break;
                         }
                     }
                     SDL_Delay(30);
                 }

                }
            }
        }
    }

}