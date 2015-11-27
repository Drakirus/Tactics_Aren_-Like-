#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define taille_grille 10

void affiche_map(int map[taille_grille][taille_grille]{
		int i, j;
		for(i = 0; i < taille_grille ; i++){
			for(j = 0 ;  j < taille_grille ; j++){
				printf("%i ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
}

void tour(t_perso * table, int nb_perso){
	int i;
	for(i = 0 ; i < nb_perso ; i++){
		action(table[i]);
	}
}


void action(t_perso perso){
	int action = 0;
	do{
		printf("1 - Deplacement\n");
		printf("2 - Attaque\n");
		printf("3 - Passer\n");
		scanf("%i", &action);
		switch(action){
			case 1: printf("Deplacement"); break; /*Fonction déplacement*/
			case 2: printf("Attaque"); break; /*Fonction Attaque */
			case 3: save(grille); break;
			case 4: printf("Passage de tour") break; /*Remise au max des PAs PMs du soldat en cours et on passe au suivant dans la liste*/
		}
	}while(choix_menu != 4);
}