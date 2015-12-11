#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/tour.h"
#include "../include/perso.h"
#include "../include/gener_map.h"
#include "../include/save.h"
#include "../include/attaque.h"
#include "../include/tableau.h"

/*int victoire(t_perso * table){
	int i;
	for(i = 0 ; i < nb_perso ; i++){
		
	}	
}	*/	

void action(int grille[i_taille_map][i_taille_map], int i_perso_actuel){
	if(tab_perso[i_perso_actuel].i_HP > 0){
		afficher_perso(tab_perso[i_perso_actuel]);
		int action = 0;
		int PA_actuel = tab_perso[i_perso_actuel].i_PA, PM_actuel = tab_perso[i_perso_actuel].i_PM;
		printf("%i, %i\n", PA_actuel, PM_actuel);
		do{
			printf("1 - Deplacement\n");
			printf("2 - Attaque\n");
			printf("3 - Passer\n");
			printf("4 - Sauvegarder\n");
			scanf("%i", &action);
			switch(action){
				case 1: printf("Deplacement\n"); break; /*Fonction déplacement*/
				case 2: attaque(tab_perso[i_perso_actuel], grille); break; /*Fonction Attaque */
				case 3: printf("Passage de tour\n"); break; /*Remise au max des PAs PMs du soldat en cours et on passe au suivant dans la liste*/
				case 4: save(grille); break;
			}
		}while(action != 3);
	}
}


void tour(int grille[i_taille_map][i_taille_map], int nb_perso){
	int i_perso_actuel = 0;
	while(i_perso_actuel < nb_perso){
		afficher_map(grille);
		action(grille, i_perso_actuel);
		i_perso_actuel++;
	}
}

