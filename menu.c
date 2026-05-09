#include <stdio.h> 
#include "structure.h"
#include "menu.h" 

void afficherMenuAccueil(){
    printf("\033[35m ----------------------- BIENVENUE DANS CY-MEMO-RPG -------------------------\033[0m\n\n") ; 
}

int choisirArme(){ 
    int choix = 0 ; 
    do {
        printf("Quelle arme choisi-tu pour avacer ?\n"); 
        printf("1. Bouclier\n"); 
        printf("2. Torche\n"); 
        printf("3. Arc \n"); 
        printf("4. Hache\n"); 
        printf("Ton choix (tape un chiffre de 1 a 4):  "); 
        
        scanf("%d", &choix) ; 

        if(choix < 1 || choix >4){
            printf("ERREUR 404 , tu dois taper  1,2,3 ou 4 ! \n");
        }
    }while(choix < 1 || choix >4); 
    
    return choix ; 
}

int choisirAction(){
    int choix = 0 ; 

    do {
        printf(" -------- C EST TON TOUR --------\n"); 
        printf("tu veux faire quoi ?\n");
        printf("1. me deplacer \n"); 
        printf("2. combattre \n"); 
        printf("3. quitter le jeu \n");
        printf("Ton choix (tape 1, 2 ou 3) :  ");

        scanf("%d", &choix); 

        if(choix < 1 || choix >3 ){
            printf("ERREURs 404 veuiller taper 1, 2 ou 3 ");

        }
    }while(choix <1 || choix>3) ; 

    return choix ; 
}

