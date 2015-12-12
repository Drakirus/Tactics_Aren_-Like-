#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/tour.h"
#include "../include/perso.h"
#include "../include/map.h"
#include "../include/save.h"
#include "../include/action.h"
#include "../include/tableau.h"

extern int map[i_taille_map][i_taille_map];

/*int victoire(){
	int i;
	for(i = 0 ; i < nb_perso ; i++){

	}
}*/

void action(int i_perso_actuel){
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
				case 2: attaque(tab_perso[i_perso_actuel]); break; /*Fonction Attaque */
				case 3: printf("Passage de tour\n"); break; /*Remise au max des PAs PMs du soldat en cours et on passe au suivant dans la liste*/
				case 4: save(); break;
			}
		}while(action != 3);
	}
}


void tour(){
	int i_perso_actuel = 0;
	while(i_perso_actuel < i_taille_tab_perso){
		afficher_map();
		action(i_perso_actuel);
		i_perso_actuel++;
	}
}
