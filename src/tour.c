#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/perso.h"

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
			/*case 3: save(grille); break;*/
			case 4: printf("Passage de tour"); break; /*Remise au max des PAs PMs du soldat en cours et on passe au suivant dans la liste*/
		}
	}while(action != 4);
}

void tour(t_perso * table, int nb_perso){
	int i;
	for(i = 0 ; i < nb_perso ; i++){
		action(table[i]);
	}
}

