#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/save.h"
#include "../include/placement.h"
#include "../include/tour.h"
#include "../include/map.h"
//#include "../include/list_attack.h"


/*list_attack * attakGuerrier = NULL; // on les regroupe dans une liste
list_attack * attakArcher = NULL; // on les regroupe dans une liste
list_attack * sortMage = NULL; // on les regroupe dans une liste*/


int main() {

/*	pushAttack(&attakGuerrier, createAttack("Coup d'épée", 1, 0, 3, 1, 0, 1, "HP", -5) );
	pushAttack(&attakArcher, createAttack("Tir à l'arc", 5, 2, 3, 1, 0, 3, "HP", -3,"coord_r",-2,"coord_c",-2) );
	pushAttack(&sortMage, createAttack("Boule De Feu", 3, 0, 4, 3, 1, 1, "HP", -2) );
	pushAttack(&sortMage, createAttack("Sort de Soin", 3, 0, 2, 1, 0, 1, "HP", 2) );*/


	srand(time(NULL));
	int choix_menu = 0;
	do{
		system("clear");
		printf("1 - Nouvelle Partie\n");
		printf("2 - Charger une partie\n");
		printf("3 - Quitter\n");
		scanf("%i", &choix_menu);
		switch(choix_menu){
			case 1: initialise_map();
					afficher_map();
					placement_perso();
					partie();
					break; /*Nouvelle Partie*/
			case 2:	charge();
					partie();
					break; /*Charger une partie */
			case 3:
					break;
		}
	}while(choix_menu != 3);
	return 0;
}
