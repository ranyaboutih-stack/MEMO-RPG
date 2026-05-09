#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

#include "menu.h"
#include "structure.h"
#include "plateau.h"

int main(){

    int nbJoueurs ; 

    //  demande le nombre de joueur 
    do{
        printf("Combien d'aventuriers sont prets a entrer dans le donjon ? (Entre 2 et 4) :");
        scanf("%d", &nbJoueurs);
        if(nbJoueurs < 2 || nbJoueurs > 4) {
            printf("Erreur : Il faut entre 2 et 4 joueurs !\n");
        }
    }while (nbJoueurs < 2 || nbJoueurs > 4);

    // je créer l'equipe 

    Joueur mesHeros[4]; // Je cree un tableau de 4 cases. Chaque case contient toutes les infos d'un joueur (pseudo, ligne, colonne...).(je creer donc 1 joueurs ans chaque case)

    for(int i = 0 ; i<nbJoueurs ; i++){
        printf("\nJoueurs %d , quel est ton pseudo ? : ", i+1); 
        scanf("%s", mesHeros[i].pseudo); // // On range le pseudo dans la structure

        // Placement autour du plateau de 5x5 (Symetrie radiale)

        if(i==0){ // Joueur 1 : En haut au milieu
            mesHeros[i].ligne = -1 ;  
            mesHeros[i].colonne = 2 ; 
        }
        else if(i==1){ // Joueur 2 : En bas au milieu
            mesHeros[i].ligne =  5 ; 
            mesHeros[i].colonne = 2 ; 
        }
        else if(i==2){ // Joueur 3 : A gauche au milieu
            mesHeros[i].ligne =  2 ; 
            mesHeros[i].colonne = -1 ; 
        }
        else{ // Joueur 4 : A droite au milieu
        
            mesHeros[i].ligne =  2 ; 
            mesHeros[i].colonne = 5 ;
        }
    }
    printf("\n--- L'equipe est prete ! Le jeu commence ! ---\n");

    Case laGrille[5][5];
    initialisation(laGrille);
    afficherMenuAccueil(); 

    int jeuTermine = 0; // 0=le jeu continue, 1 = quelqu'un a gagné
    int tourActuel = 0; // Permet de savoir à qui c'est le tour (0 = Joueur 1, 1 = Joueur 2, etc.)

    while (jeuTermine == 0){

        // 1. Annonce du joueur
        printf("\n====================================\n");
        printf(" C'est au tour de %s !\n", mesHeros[tourActuel].pseudo);
        printf("====================================\n");

        // 2. Le joueur choisit son arme avant de bouger
        mesHeros[tourActuel].armeActive = choisirArme() ; 
        printf("%s s'equipe de l'arme n°%d...\n", mesHeros[tourActuel].pseudo, mesHeros[tourActuel].armeActive);

        // 3. Afficher le plateau pour ce joueur
        afficherPlateau(laGrille, mesHeros[tourActuel]);

        // 4. Le menu de déplacement (qui remplace l'ancienne action)
        int direction ;
        printf("\n--- OU VEUX-TU ALLER ? ---\n");
        printf("1: Haut ^\n2: Bas v\n3: Gauche <\n4: Droite >\n");
        printf("Ton choix : ");
        scanf("%d", &direction);

        if(direction== 1){
            mesHeros[tourActuel].ligne --; //haut 
        }
        else if(direction==2){
            mesHeros[tourActuel].ligne ++ ; //bas 
        }
        else if(direction == 3) {
            mesHeros[tourActuel].colonne--; // Gauche
        }
        else if(direction ==4){
            mesHeros[tourActuel].colonne ++;
        }

        printf("%s avance d'une case...\n", mesHeros[tourActuel].pseudo);

        if (mesHeros[tourActuel].ligne >= 0 && mesHeros[tourActuel].ligne < 5 && 
            mesHeros[tourActuel].colonne >= 0 && mesHeros[tourActuel].colonne < 5) {
            
            // On retourne la carte !
            laGrille[mesHeros[tourActuel].ligne][mesHeros[tourActuel].colonne].estCachee = 0;
            
            // On réaffiche le plateau pour voir ce qui se cachait en dessous
            afficherPlateau(laGrille, mesHeros[tourActuel]);
            
            // (La prochaine étape sera de vérifier si c'est un monstre ou un trésor ici)
        }


        tourActuel = tourActuel + 1;
        if(tourActuel == nbJoueurs) {
            tourActuel = 0; // On revient au premier joueur
        }

    }
    return 0;
}
