#include <stdio.h>
#include <string.h> // pour strcpy
#include "structure.h" // case et joueur
#include "plateau.h" // les fonction 

void initialisation(Case grille[5][5]){
    for(int i =0 ; i<5;i++){ // 'i' ligne
        for(int j = 0 ; j<5; j++){ // 'j' colonne 
            grille[i][j].estCachee = 1; // on cache tt les case au debut
            strcpy(grille[i][j].symbole, "?"); // strcpy(destination, source)
            strcpy(grille[i][j].typeContenu, "estvide");

        }
    }
}

void afficherPlateau(Case grille[5][5], Joueur monHero){
    printf("\n ------le donjon-----\n"); 
    for(int i=0 ; i<5; i++){
        for(int j=0 ; j<5 ; j++){ // on parcours la rille de jeu 
            if(i==monHero.ligne && j == monHero.colonne){
                printf("[J]"); // J = Joueur
            }
            else if(grille[i][j].estCachee ==1){
                printf("[?]");// On ne montre pas ce qu'il y a dessous
            }
            else{
                printf("[%s]",grille[i][j].symbole); // Si la case est découverte, on affiche son contenu
            }
        }
        printf("\n");
    }
}
