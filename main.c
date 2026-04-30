#include <stdio.h>
#include "menu.h"
#include "structure.h"

int main(){

    Joueur monHeros ;
    monHeros.ligne = 0 ; 
    monHeros.colonne = 0 ; 
    afficherMenuAccueil(); 

    monHeros.armeActive = choisirArme(); 

    printf("tu pars a l'aventure avec l'arme : %d\n",monHeros.armeActive);
    
    int actionChoisie = 0; 
    while(actionChoisie !=3){
        actionChoisie = choisirAction(); 

        if(actionChoisie==1){
            printf(" tu avance dans le donjon "); 
        }
        else if(actionChoisie==2){
            printf("UN MONSTRE APPARAIT ! Tu sors ton arme %d et tu attaque ! " , actionChoisie) ; 

        }
        else if(actionChoisie ==3 ){
            printf("GAME OVER"); 
        }

    }
     
    return 0 ; 
}