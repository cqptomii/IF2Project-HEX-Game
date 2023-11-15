//
// Created by tomfr on 19/04/2023.
//

#include "Event_party.h"
#include "Fenetres_Menus.h"
#include "Victoire.h"
#include "sauv.h"
#include "stdio.h"
#include "Coord.h"
// Appel des variables globales intialisées dans mon fichier main.c pour les inclure dans le fichier ci-dessous
extern SDL_Renderer* prenderer;
bool double_consec=false;
void events_party( const char *mode_jeu,const bool *sauv){
    // initialisation de l'ensemble des variables nécessaires à la fonction :

    SDL_Texture* pstart = NULL;
    short tour_joueur=0,x,y,i,b,Taille_cas=0;
        // init des variables de verifications
    bool quitter = false;
    bool bouton = false;
    bool passer_tour=false;
    bool *supp_pion= malloc(sizeof(bool));
    *supp_pion=false;
    bool double_coups= false;

    pos_pion casepion[196];
    pos_pion supprimer_pion[1];

    // Mise a nul de notre variable supprimer_pion
    supprimer_pion[0].colonnes=0;
    supprimer_pion[0].lignes=0;
    supprimer_pion[0].joueur=0;
    // Mise à nul du tableau de type pos_pion
    for(i=0;i<196;i+=1){
        casepion[i].colonnes=0;
        casepion[i].lignes=0;
        casepion[i].joueur=0;
    }
    //Fin initialisation

    /*
     * initialisation des deux Matrices
     * Mise à nul des deux matrices
    */
    short Matrice2D[taille][taille];
    short Matrice_victoire[taille][taille];
    for ( i = 0; i < taille ; i+= 1 ) {
        for (b = 0; b < taille; b+= 1) {
            Matrice_victoire[i][b]=0;
            Matrice2D[i][b] = 0;
        }
    }


    if(*sauv){ // verification si sauvegarde
        recup_sauvegarde(casepion,&Taille_cas); // Fonction récuperant la précédente sauvegarde
        for(i=0;i<Taille_cas;i+=1){
            Matrice2D[casepion[i].lignes][casepion[i].colonnes]=casepion[i].joueur;
            recup_xy(casepion,&x,&y,i); // Fonction récuperant les coordonées de la ligne et de la colonne
            if(casepion[i].joueur != 0) {
                affichage_pion(x, y, casepion[i].joueur, supp_pion); // Fonction affichant le pion
            }
        }

    }
    if(*mode_jeu=='A'){ // Mode de jeu aléatoire
        i=0;
        short *nb_pion= malloc(sizeof(short ));
        short *colonne_ale= malloc(sizeof(short ));
        short *ligne_ale= malloc(sizeof(short ));
        *nb_pion= (taille-1)/2;

        while(i<*nb_pion){
            *colonne_ale=(short)(rand()% taille);
            *ligne_ale=(short)(rand()% taille);
            if(Matrice2D[*colonne_ale][*ligne_ale]==0){
                casepion[i].colonnes=*colonne_ale;
                casepion[i].lignes=*ligne_ale;

                if(i%2==0){
                    casepion[i].joueur=1;
                }
                else{
                    casepion[i].joueur=2;
                }

                recup_xy(casepion,&x,&y,i);
                affichage_pion(x,y,casepion[i].joueur,supp_pion);
                Matrice2D[*ligne_ale][*colonne_ale]=casepion[i].joueur;
                i++;
            }
        }
        //liberation de la mémoire des variables dynamiques
        free(nb_pion);free(colonne_ale);free(ligne_ale);Taille_cas=i;
    }

    //
    //Boucle de parcours d'evenements :
    //
    SDL_Event jeu;
    while (victoire == 0 && quitter == false) {
        if ( tour_joueur % 2 == 0 ) {
            gmenu= SDL_LoadBMP("../image/jbleu.bmp");
            changement(gmenu, pstart, 322, 22, 606, 101);
            gmenu=NULL;
        } else {
            gmenu= SDL_LoadBMP("../image/jrouge.bmp");
            changement(gmenu, pstart, 322, 22, 606, 101);
            gmenu=NULL;
        }
            if (SDL_PollEvent(&jeu)) {
                switch (jeu.type) {

                    case SDL_WINDOWEVENT:

                        switch (jeu.window.event) {

                            case SDL_WINDOWEVENT_CLOSE: //fermeture de la fenetre
                                destroyparty();
                                SDL_Quit();
                                quitter = true;
                                break;
                        }
                        break;

                    case SDL_MOUSEMOTION: // mouvement de la souris
                        if (jeu.motion.x > 260 && jeu.motion.x < 505 && jeu.motion.y > 900 && jeu.motion.y < 984) {
                            if (!gmenu && bouton == false) {
                                gmenu= SDL_LoadBMP("../image/changementsauv.bmp");
                                changement(gmenu, pstart, 260, 900, 245, 84);
                                bouton = true;
                            }
                        }
                        else if (jeu.motion.x > 47 && jeu.motion.x < 221 && jeu.motion.y > 903 && jeu.motion.y < 988) {
                            if (!gmenu && bouton == false) {
                                gmenu= SDL_LoadBMP("../image/changementquitter.bmp");
                                changement(gmenu, pstart, 47, 903, 174, 85);
                                bouton = true;
                            }
                        }
                        else if ( jeu.motion.x > 531 && jeu.motion.x < 824 && jeu.motion.y > 900 && jeu.motion.y < 988 ) {
                            if (!gmenu && bouton == false) {
                                gmenu= SDL_LoadBMP("../image/Abandonner.bmp");
                                changement(gmenu, pstart, 531, 900, 293,88);
                                bouton = true;
                            }
                        }
                        else if(jeu.motion.x > 892 && jeu.motion.x < 1166  && jeu.motion.y > 848 && jeu.motion.y < 915){
                            if(*mode_jeu=='S') {
                                gmenu= SDL_LoadBMP("../image/supppion.bmp");
                                changement(gmenu, pstart, 892, 848, 274, 67);
                                bouton = true;
                            }
                        }
                        else if(jeu.motion.x > 894 && jeu.motion.x < 1167 && jeu.motion.y > 925 && jeu.motion.y < 990){
                            if(*mode_jeu=='S') {
                                gmenu= SDL_LoadBMP("../image/doublecoups.bmp");
                                changement(gmenu, pstart, 894, 925, 273, 65);
                                bouton = true;
                            }
                        }
                        else {
                            if (bouton == true && *mode_jeu=='S') {
                                SDL_DestroyTexture(pstart);
                                SDL_FreeSurface(gmenu);
                                gmenu = NULL;
                                pstart = NULL;
                                gmenu= SDL_LoadBMP("../image/revSPE.bmp");
                                changement(gmenu, pstart, 0, 844, 1230, 156);
                                gmenu=NULL;
                                bouton = false;
                            }
                            else if(bouton){
                                SDL_DestroyTexture(pstart);
                                SDL_FreeSurface(gmenu);
                                gmenu = NULL;
                                pstart = NULL;
                                gmenu= SDL_LoadBMP("../image/rev.bmp");
                                changement(gmenu, pstart, 0, 844, 1230, 156);
                                gmenu=NULL;
                                bouton = false;
                            }
                        }
                        break;
                    case SDL_MOUSEBUTTONUP: // clic de la souris
                        if (*mode_jeu == 'S') {
                            if ( jeu.button.x > 892 && jeu.button.x < 1166  && jeu.button.y > 848 && jeu.button.y < 915 && tour_joueur ) { // supprimer une pion enemie
                                *supp_pion=true;
                                supprimer_pion[0].colonnes=-1;
                            }
                            else if (jeu.button.x > 894 && jeu.button.x < 1167 && jeu.button.y > 925 && jeu.button.y < 990 ){ // doubles coups
                                    double_coups = true;
                                    if(passer_tour){
                                        passer_tour=false;
                                        double_consec=true;
                                    }
                            }
                        }
                        if ( jeu.button.x > 260 && jeu.button.x < 505 && jeu.button.y > 900 && jeu.button.y < 984 ) { // Bouton sauvegarde
                            sauvegarde(*mode_jeu,casepion,Taille_cas);
                        }
                        else if ( jeu.button.x > 47 && jeu.button.x < 221 && jeu.button.y > 903 && jeu.button.y < 988 ) { // Bouton quitter
                            destroyparty();
                            SDL_Quit();
                            quitter = true;
                        }
                        else if ( jeu.button.x > 531 && jeu.button.x < 824 && jeu.button.y > 900 && jeu.button.y < 988 ) { // Bouton abandonner
                            if (tour_joueur % 2 == 0) {
                                victoire = 2;
                            } else {
                                victoire = 1;
                            }
                            destroyparty();
                            SDL_Quit();
                        }
                        else {
                            verifevent_clic(jeu, &tour_joueur, casepion,&x,&y,double_coups,*supp_pion,supprimer_pion,passer_tour,Taille_cas);
                            if(casepion[Taille_cas].joueur!=0 || supprimer_pion[0].joueur!=0 ){

                                if (double_coups == false && Matrice2D[casepion[Taille_cas].lignes][casepion[Taille_cas].colonnes] == 0) {

                                    for (i = 0; i < taille; i += 1) {
                                        for (b = 0; b < taille; b += 1) {

                                            if (Matrice2D[i][b] > 31) { // si un pion à été supprimé :
                                                Matrice2D[i][b] -= 1; // chaque tour la valeur est diminué de 1
                                            } else if (Matrice2D[i][b] == 31) {
                                                Matrice2D[i][b] = 0; // pion jouable
                                            }
                                        }
                                    }
                                }

                                remplir_pion(casepion, supprimer_pion,&Taille_cas, Matrice2D, supp_pion, &double_coups,&tour_joueur, &passer_tour, x, y); // Fonctions
                                verif_victoire(tour_joueur,b,i,Matrice2D,Matrice_victoire);
                            }

                        }
                        break;
                }
            }
        SDL_Delay(30);
        }
        destroyparty();
        SDL_DestroyTexture(pstart);
        pstart=NULL;

}
void affichage_pion(int gx,int gy,short joueur,bool *supp_pion){

    SDL_Texture *tpion=NULL;
    //Affichage d'un sprite changeant la couleur de la case
    if(!*supp_pion) {
        if (joueur == 1) {
            gmenu= SDL_LoadBMP("../image/pion_bleu.bmp");
        } else if (joueur == 2) {
            gmenu= SDL_LoadBMP("../image/pion_rouge.bmp");
        }
    }
    else{
        gmenu= SDL_LoadBMP("../image/img_supp.bmp");
        *supp_pion=false;
    }
    if (!gmenu) {
        printf("Erreur lors du chargement du spirte , %s \n", SDL_GetError());
    }
    else {
        tpion = SDL_CreateTextureFromSurface(prenderer, gmenu);
        if (tpion) {
            SDL_Rect cord = {gx, gy, 30, 30};
            SDL_RenderCopy(prenderer, tpion, NULL, &cord);
            SDL_RenderPresent(prenderer);
            tpion=NULL;
            gmenu=NULL;
        }
        else{
            printf("Erreur lors de la creation de la texture : %s, ligne %d",SDL_GetError(),__LINE__);
        }
    }
}