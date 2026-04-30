#include <stdio.h>
#include "menu.h"
#include "structure.h"
#include "plateau.h"

int main(){

    Joueur monHeros ;
    monHeros.ligne = 0 ; 
    monHeros.colonne = 0 ; 

    Case laGrille[5][5]; //on crrer la variable qui contient nos 25 cartes 
    initialisation(laGrille); // on appelle la fonction pour mettre les '?' et les 'est vide' partt 

    afficherMenuAccueil(); 

    monHeros.armeActive = choisirArme(); 

    printf("tu pars a l'aventure avec l'arme : %d et tu attaque\n",monHeros.armeActive);
    
    int actionChoisie = 0; 
    while(actionChoisie !=3){

        afficherPlateau(laGrille, monHeros);//on affiche la grille (On lui donne la grille ET le héros pour qu'il sache où dessiner le [J])


        actionChoisie = choisirAction(); 

        if(actionChoisie==1){
            int direction ; 
            printf("\n--- DEPLACEMENT ---\n");
            printf("1: Haut ^\n2: Bas v\n3: Gauche <\n4: Droite >\n");
            printf("Ton choix : ");
            scanf("%d", &direction);

            if(direction == 1 && monHeros.ligne > 0) {
                monHeros.ligne--; // On monte (ligne - 1)
            }
            else if(direction == 2 && monHeros.ligne <4){
                monHeros.ligne ++ ; 
            }
            else if(direction==3 && monHeros.colonne>0){
                monHeros.colonne --;
            }
            else if(direction == 4 && monHeros.colonne<4){
                monHeros.colonne++ ; 
            }
            else{
                printf("impossible mur ou direction invalide"); 

            }
            printf("Tu te déplaces...\n");



        }
        else if(actionChoisie==2){
            printf("UN MONSTRE APPARAIT ! Tu sors ton arme %d et tu attaque !\n " , monHeros.armeActive) ; 

        }
        else if(actionChoisie ==3 ){
            printf("GAME OVER\n"); 
        }

    }
    return 0 ; 
}