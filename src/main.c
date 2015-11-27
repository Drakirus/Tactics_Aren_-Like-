#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Outil.h"
#include "save.h"
#include "placement.h"
#include "gener_map.h"
#include "tour.h"

int main() {
	srand(time(NULL));
	int grille[i_taille_map][i_taille_map];
	initialise_map(grille);
  	int choix_menu = 0;
	do{
		printf("1 - Nouvelle Partie\n");
		printf("2 - Charger une partie\n");
		printf("3 - Quitter\n");
		scanf("%i", &choix_menu);
		switch(choix_menu){
			case 1: initialise_map(grille); placement_perso(grille); save(grille); break; /*Nouvelle Partie*/
			case 2: charge(grille); break; /*Charger une partie */
			case 3: break;
		}
	}while(choix_menu != 3);
	return 0;
}