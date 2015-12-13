#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/save.h"
#include "../include/placement.h"
#include "../include/tour.h"
#include "../include/map.h"

int main() {
	srand(time(NULL));
	system("clear");
  	int choix_menu = 0;
	do{
		printf("1 - Nouvelle Partie\n");
		printf("2 - Charger une partie\n");
		printf("3 - Quitter\n");
		scanf("%i", &choix_menu);
		switch(choix_menu){
			case 1: initialise_map();
					afficher_map();
					placement_perso();
					tour();
					break; /*Nouvelle Partie*/
			case 2: charge();
					tour();
					break; /*Charger une partie */
			case 3:
					break;
		}
	}while(choix_menu != 3);
	return 0;
}
