
#include "Fenetres_Menus.h"
#include "party.h"
#include "Victoire.h"
#include "stdio.h"
#include "time.h"
SDL_Window* gwindow=NULL;
SDL_Surface* gmenu=NULL;
SDL_Renderer* prenderer=NULL;
SDL_Texture* ptexture=NULL;
short taille=9;
short victoire=0;
short largeur=0;
short hauteur=0;

int main(int argc,char *argv[]) {
    srand(time(NULL)); // initialisation du generateur de nombre aléatoire
    // initialisation des varaibles de verification d'entrer de jeu/ sauvegarde
    bool lancer_sauv = false;
    bool lancer_jeu = false;
    bool lancer_plateau = true;
    char mode; // initialisation de la variable de mode
    Menu(&lancer_sauv, &lancer_jeu); // Fonction Menu
    if (lancer_jeu == true) { // Verification du lancement des modes suivants
        if (lancer_sauv == false) { // Verification du lancement de la sauvgarde
            mode_jeu(&mode, &lancer_plateau);
            if(lancer_plateau) {
                initplateau(&mode, &lancer_sauv);
            }
        }
        else{
            //Recupération du mode de jeu et de la taille du tableau
            FILE *sauv = NULL;
            sauv = fopen("sauv.txt", "r"); // ouverture du fichier
            if(sauv){
                mode = (char) fgetc(sauv); // recuperation du mode de jeu
                fseek(sauv, 1, SEEK_CUR); // on avance d'un caractère dans le fichier
                fscanf(sauv, "%hd", &taille); // récupération de la taille
                fclose(sauv); // fermeture du fichier
                sauv = NULL;
                initplateau(&mode, &lancer_sauv); // Fonction pour lancer le jeu principale
            }
            else{
                printf("Erreur lors de l'ouverture du fichier sauv.txt ligne: %d\n", __LINE__);
            }
            //Fin de la recupération
        }
        if (victoire) {
            affichage_victoire(); // Fonction d'affichage de la victoire
        }
    }
    return 0;
}