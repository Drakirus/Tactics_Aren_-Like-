#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "perso.h"
#include "gener_map.h"

void action(t_perso perso, int grille[i_taille_map][i_taille_map]){
	int action = 0;
	do{
		printf("1 - Deplacement\n");
		printf("2 - Attaque\n");
		printf("3 - Passer\n");
		printf("4 - Sauvegarder\n");
		scanf("%i", &action);
		switch(action){
			case 1: printf("Deplacement\n"); break; /*Fonction déplacement*/
			case 2: printf("Attaque\n"); break; /*Fonction Attaque */
			case 3: printf("Passage de tour\n"); break; /*Remise au max des PAs PMs du soldat en cours et on passe au suivant dans la liste*/
			case 4: save(grille); break;
			
		}
	}while(action != 4);
}

void tour(t_perso * table, int grille[i_taille_map][i_taille_map], int nb_perso){
	int i;
	for(i = 0 ; i < nb_perso ; i++){
		action(table[i], grille);
	}
}

