/**
 * \file main.c
 * \brief Programme lançant notre version du jeu Tactics Arena.
 * \author CHAMPION Pierre, LAVILLE Martin, MOK Modira
 * \version 0.1
 * \date 18 décembre 2015
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/save.h"
#include "../include/placement.h"
#include "../include/tour.h"
#include "../include/map.h"
#include "../include/tableau.h"
#include "../include/lua_ia.h"
#include "../include/action.h"

/**
 * \fn int main()
 * \brief Menu principal, donne accès au lancement de la partie et au chargement.
 *
 */
int main() {
	srand(time(NULL));
	int choix_menu = 0;
	do{
		// system("clear");
		printf("1 - Nouvelle Partie\n");
		printf("2 - Charger une partie\n");
		printf("3 - IA vs IA\n");
		printf("4 - Quitter\n");
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
					initialise_map();
					afficher_map();
					init_tab_perso(tab_perso);
					IA_play("placing", "ia_test_function.lua");
					IA_play("placing", "ia_test2_function.lua");
					// delay(1000);
				  afficher_map();
					IA_play("main", "ia_test2_function.lua");

					break;
			case 4:
					break;
		}
	}while(choix_menu != 4);
	// freeAllListAttack();
	return 0;
}
