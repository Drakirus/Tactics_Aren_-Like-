#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define taille_grille 10

void affiche_map(int map[taille_grille][taille_grille]){
		system("clear");
		int i, j;
		for(i = 0; i < taille_grille ; i++){
			for(j = 0 ;  j < taille_grille ; j++){
				printf("%i ", map[i][j]);
			}
			printf("\n");	
		}
		printf("\n");
}