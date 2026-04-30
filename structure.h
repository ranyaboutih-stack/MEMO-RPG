#ifndef STRUCTURE_H
#define STRUCTURE_H 

typedef struct{
    char pseudo[50]; 
    char classe[20];  // pour memoriser si il est 'guerrier','magicien'..
    char symbole[10]; // emoji du personnage 
    int armeActive; 
    int ligne; 
    int colonne;  
}Joueur; //fiche idd d un joueur  

typedef struct{
    char typeContenu[30] ; //'zombie', 'coffre'
    char symbole[10] ; // l emoji de la carte quand on la retourne 
    int estCachee ; // cahcer : 1 et visible : 0 
}Case ; 

#endif 



