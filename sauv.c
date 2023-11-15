//
// Created by tomfr on 20/04/2023.
//
#include "Event_party.h"
#include "sauv.h"
extern  short taille;
void sauvegarde(char mod_jeu,pos_pion cas_pion[],int Taill_cas){
    short *i= malloc(sizeof(short ));
    FILE *sauv=NULL;
    sauv=fopen("sauv.txt","w+"); // ouverture du fichier en lecture + ecriture / en supprimant le texte lors de l'ouverture
    if(sauv){
        if(taille<10 && Taill_cas<10){
            fprintf(sauv, "%c 0%d 0%d ", mod_jeu, taille, Taill_cas);
        }
        else if(taille>=10){
            fprintf(sauv, "%c %d 0%d ", mod_jeu, taille, Taill_cas);
        }
        else if (Taill_cas>=10){
            fprintf(sauv, "%c 0%d %d ", mod_jeu, taille, Taill_cas);
        }
        else {
            fprintf(sauv, "%c %d %d ", mod_jeu, taille, Taill_cas);
        }
        for(*i=0;*i<Taill_cas;*i+=1){
            if(cas_pion[*i].lignes<10 && cas_pion[*i].colonnes<10){
                fprintf(sauv, "0%d 0%d %d ", cas_pion[*i].lignes, cas_pion[*i].colonnes, cas_pion[*i].joueur);
            }
            else if(cas_pion[*i].lignes>=10){
                fprintf(sauv, "0%d %d %d ", cas_pion[*i].lignes, cas_pion[*i].colonnes, cas_pion[*i].joueur);
            }
            else if(cas_pion[*i].colonnes>=10){
                fprintf(sauv, "%d 0%d %d ", cas_pion[*i].lignes, cas_pion[*i].colonnes, cas_pion[*i].joueur);
            }
            else {
                fprintf(sauv, "%d %d %d ", cas_pion[*i].lignes, cas_pion[*i].colonnes, cas_pion[*i].joueur);
            }
        }
        fclose(sauv);
        sauv=NULL;
    }
    else{
        printf("erreur lors de l'ouverture du fichier de sauvegarde \n");
    }
}
void recup_sauvegarde(pos_pion case_pion[],short *Taille_cas ){
    short *i= malloc(sizeof(short ));
    int Variable[3]={0};
    FILE *sauv=NULL;
    sauv=fopen("sauv.txt","r"); // Ouverture du fichier sauv.txt en lecture seul
    if(sauv){
        //Recuperation Taille du plateau :
        fseek(sauv, 5, SEEK_SET);
        fscanf(sauv,"%d",&Variable[0]);
        *Taille_cas=(short)Variable[0];
        fseek(sauv,1,SEEK_CUR);
        //Recuperation des lignes et colonnes et joueurs associés aux pions
        for(*i=0;*i<*Taille_cas;*i+=1) {
            fscanf(sauv,"%d %d %d",&Variable[0],&Variable[1],&Variable[2]);
            fseek(sauv,1,SEEK_CUR);
            case_pion[*i].lignes=(short)Variable[0];
            case_pion[*i].colonnes= (short) Variable[1];
            case_pion[*i].joueur=(short) Variable[2];
        }
        //Fin
        fclose(sauv); // Fermeture fichier sauv.txt
        sauv=NULL;
    }
    else{
        printf("Erreur lors de l'ouverture du fichier sauv.txt, ligne :%d \n",__LINE__); // controle de l'ouverture ou non du fichier
    }
}
void recup_xy(pos_pion casepion[],short *x,short *y,short i){
    switch (casepion[i].lignes) {
        case 0:
            *y=228;*x=105;
            break;
        case 1:
            *y=265;*x=129;
            break;
        case 2:
            *y=302;*x=154;
            break;
        case 3:
            *y=340;*x=178;
            break;
        case 4:
            *y=377;*x=203;
            break;
        case 5:
            *y=414;*x=227;
            break;
        case 6:
            *y=452;*x=252;
            break;
        case 7:
            *y=489;*x=276;
            break;
        case 8:
            *y=524;*x=301;
            break;
        case 9:
            *y=563;*x=325;
            break;
        case 10:
            *y=600;*x=350;
            break;
        case 11:
            *y=638;*x=375;
            break;
        case 12:
            *y=675;*x=400;
            break;
        case 13:
            *y=712;*x=424;
            break;
    }
    switch (casepion[i].colonnes) {
        case 0:
            *x+=10;
            break;
        case 1:
            *x+=59;
            break;
        case 2:
            *x+=108;
            break;
        case 3:
            *x+=157;
            break;
        case 4:
            *x+=206;
            break;
        case 5:
            *x+=255;
            break;
        case 6:
            *x+=305;
            break;
        case 7:
            *x+=355;
            break;
        case 8:
            *x+=405;
            break;
        case 9:
            *x+=455;
            break;
        case 10:
            *x+=505;
            break;
        case 11:
            *x+=554;
            break;
        case 12:
            *x+=603;
            break;
        case 13:
            *x+=652;
            break;
    }
}