//
// Created by tomfr on 01/05/2023.
//
#include "Coord.h"
extern bool double_consec;
bool espace=false;
void verifevent_clic(SDL_Event jeu,short *tour_joueur, pos_pion case_pion[],short *x,short *valy,bool tourdouble_coups,bool supp_pion,pos_pion supprimer[],bool passer_tour,const short Taille_cas){
    short ligne;
    // Verification de la ligne :
    if (jeu.button.y > 228 && jeu.button.y < 253) {
        ligne=0;*valy = 228;*x = 105;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if (jeu.button.y > 265 && jeu.button.y < 290) {
        ligne = 1;*valy = 265;*x = 129;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if (jeu.button.y > 302 && jeu.button.y < 327) {
        ligne = 2;*valy = 302;*x = 154;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if (jeu.button.y > 340 && jeu.button.y < 365) {
        ligne = 3;*valy = 340;*x = 178;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if (jeu.button.y > 377 && jeu.button.y < 402) {
        ligne = 4;*valy = 377;*x = 203;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if (jeu.button.y > 414 && jeu.button.y < 439) {
        ligne = 5;*valy = 414;*x = 227;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if (jeu.button.y > 452 && jeu.button.y < 477) {
        ligne = 6;*valy = 452;*x = 252;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if (jeu.button.y > 489 && jeu.button.y < 514) {
        ligne = 7;*valy = 489;*x = 276;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if ( jeu.button.y > 526 && jeu.button.y < 551 ) {
        ligne = 8;*valy = 524;*x = 301;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if ( jeu.button.y > 563 && jeu.button.y < 588 && taille >=10 ) {
        ligne = 9;*valy = 563;*x = 325;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if ( jeu.button.y > 600 && jeu.button.y < 625 && taille >= 11 ) {
        ligne = 10;*valy = 600;*x = 350;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if ( jeu.button.y > 638 && jeu.button.y < 663 && taille >= 12 ) {
        ligne = 11;*valy = 638;*x = 375;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if ( jeu.button.y > 675 && jeu.button.y < 700 && taille >= 13 ) {
        ligne = 12;*valy = 675;*x = 400;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
    else if ( jeu.button.y > 712 && jeu.button.y < 737 && taille == 14 ) {
        ligne = 13;*valy = 712;*x = 424;
        verif_coord(x,jeu,tour_joueur,ligne,case_pion,tourdouble_coups,supp_pion,supprimer,passer_tour,Taille_cas);
    }
}
void verif_coord(short *valx,SDL_Event jeu,const short *joueur,short ligne,pos_pion case_pion[],bool tourdouble_coups, bool supp_pion,pos_pion supprimer[],bool passer_tour,short Taille_cas){
    short nb,colonne=-1;
    if(*joueur%2==0){
        nb=1;
    }
    else{
        nb=2;
    }
    // verification de la colonne
    if( jeu.button.x > *valx && jeu.button.x < (*valx+50) ) {
        colonne = 0;*valx+=10;
    }
    else if( jeu.button.x > (*valx+50) && jeu.button.x < (*valx+(2*50)) ) {
        colonne = 1; *valx += 59;
    }
    else if( jeu.button.x > (*valx+(2*50)) && jeu.button.x < (*valx+(3*50)) ) {
        colonne = 2; *valx += (2*50)+8;
    }
    else if ( jeu.button.x > (*valx+(3*50)) && jeu.button.x < (*valx+(4*50)) ){
        colonne = 3; *valx += (3*50)+7;
    }
    else if( jeu.button.x > (*valx+(4*50)) && jeu.button.x < (*valx+(5*50)) ) {
        colonne = 4; *valx += (4*50)+6;
    }
    else if( jeu.button.x > (*valx+(5*50)) && jeu.button.x < (*valx+(6*50)) ){
        colonne = 5; *valx += (5*50)+5;
    }
    else if( jeu.button.x > (*valx+(6*50)) && jeu.button.x < (*valx+(7*50)) ) {
        colonne = 6; *valx += (6*50)+5;
    }
    else if( jeu.button.x > (*valx+(7*50)) && jeu.button.x < (*valx+(8*50)) ){
        colonne = 7; *valx += (7*50)+5;
    }
    else if ( jeu.button.x > (*valx+(8*50)) && jeu.button.x < (*valx+(9*50)) && taille >= 9 ){
        colonne = 8; *valx += (8*50)+4;
    }
    else if( jeu.button.x > (*valx+(9*50)) && jeu.button.x < (*valx+(10*50)) && taille >= 10  ) {
        colonne = 9; *valx += (9*50)+3;
    }
    else if ( jeu.button.x > (*valx+(10*50)) && jeu.button.x < (*valx+(11*50))&& taille >= 11 ){
        colonne = 10; *valx += (10*50)+1;
    }
    else if( jeu.button.x > (*valx+(11*50)) && jeu.button.x < (*valx+(12*50)) && taille >= 12){
        colonne = 11;*valx += (11*50);
    }
    else if ( jeu.button.x > (*valx+(12*50)) && jeu.button.x < (*valx+(13*50)) && taille >= 13){
        colonne = 12; *valx += (12*50);
    }
    else if( jeu.button.x > (*valx+(13*50)) && jeu.button.x < (*valx+(14*50)) && taille == 14  ){
        colonne = 13;*valx+=(13*50);
    }
    // affectation des caracs du pion dans la structure
    if(!supp_pion && !tourdouble_coups || tourdouble_coups && !passer_tour || tourdouble_coups && passer_tour && double_consec && !espace ) {
        case_pion[Taille_cas].colonnes = colonne;
        case_pion[Taille_cas].lignes = ligne;
        case_pion[Taille_cas].joueur = nb;
    }
    else if(supp_pion){ // cas lors de la suppression d'un pion
        short suppAffect;
        supprimer[0].colonnes=colonne;
        supprimer[0].lignes=ligne;
        supprimer[0].joueur=nb;
        for(suppAffect=0;suppAffect<Taille_cas;suppAffect++){
            if(supprimer[0].colonnes == case_pion[suppAffect].colonnes && supprimer[0].lignes == case_pion[suppAffect].lignes){
                case_pion[suppAffect].joueur=0;
            }
        }
    }
    // Verification 6 cases adjacente lors de doubles coups
    else if (tourdouble_coups && passer_tour || tourdouble_coups && passer_tour && espace){
        if(colonne != case_pion[Taille_cas-1].colonnes -1 || ligne != case_pion[Taille_cas-1].lignes){
            if(colonne != case_pion[Taille_cas-1].colonnes -1 || ligne != case_pion[Taille_cas-1].lignes+1){
                if(colonne != case_pion[Taille_cas-1].colonnes  || ligne != case_pion[Taille_cas-1].lignes+1){
                    if(colonne != case_pion[Taille_cas-1].colonnes || ligne != case_pion[Taille_cas-1].lignes-1){
                        if(colonne != case_pion[Taille_cas-1].colonnes+1 || ligne != case_pion[Taille_cas-1].lignes-1){
                            if( colonne != case_pion[Taille_cas-1].colonnes +1 || ligne != case_pion[Taille_cas-1].lignes){
                                case_pion[Taille_cas].colonnes = colonne;
                                case_pion[Taille_cas].lignes = ligne;
                                case_pion[Taille_cas].joueur = nb ;
                            }
                           }
                    }
                }
            }
        }
        else{
            case_pion[Taille_cas].joueur=0; // si clic sur une des 6 cases adjacentes
        }

    }

}
void remplir_pion(pos_pion casepion[],pos_pion supprimer_pion[], short *Taille_cas,short Matrice2D[taille][taille],bool *supp_pion,bool *double_coups,short *tour_joueur,bool *passer_tour,short x,short y){
    if (casepion[*Taille_cas].colonnes>=0 && !Matrice2D[casepion[*Taille_cas].lignes][casepion[*Taille_cas].colonnes] && !*supp_pion) {

        Matrice2D[casepion[*Taille_cas].lignes][casepion[*Taille_cas].colonnes] = casepion[*Taille_cas].joueur;
        affichage_pion(x, y, casepion[*Taille_cas].joueur, supp_pion); // Fonction qui affiche le pion sur le plateau
        if(!*double_coups){ // sans double coups
            if(!*passer_tour) {
                *tour_joueur+=1;
                *Taille_cas += 1;
            }
            else{
                *tour_joueur+=2;
                *Taille_cas+=1;
                *passer_tour=false;
            } 
        }
        //Avec doubles coups
        else if(*double_coups && *passer_tour) { // 2ème pion
            if(!espace) {
                *Taille_cas += 1;
                *tour_joueur += 1;
                *double_coups = false;
                double_consec=false;
            }
            else if(espace) { // 3ᵉ pion si deux doubles coups sont lancés à la suite
                *Taille_cas+=1;
                espace=false;
            }
        }
        else if(*double_coups && !*passer_tour){ // 1er pion double coups
            *Taille_cas+=1;
            *passer_tour=true;
            if(double_consec){ espace=true; }
        }
    }
    else if(*supp_pion && supprimer_pion[0].colonnes>=0 && Matrice2D[supprimer_pion[0].lignes][supprimer_pion[0].colonnes]==1 || Matrice2D[supprimer_pion[0].lignes][supprimer_pion[0].colonnes]==2){
    //Suppression d'un pion
        Matrice2D[supprimer_pion[0].lignes][supprimer_pion[0].colonnes] = 33;
        affichage_pion(x,y,supprimer_pion[0].joueur,supp_pion);
        *tour_joueur +=1;
        supprimer_pion[0].joueur=0;
    }
}