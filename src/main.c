/**
 * \file main.c
 * \brief Programme lançant notre version du jeu Tactics Arena.
 * \author CHAMPION Pierre, LAVILLE Martin, MOK Modira
 * \version 0.1
 * \date 18 décembre 2015
 *
 *
 */
 int idCursor = -1; /**< Identifiant du curseur */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>
#include "../include/save.h"
#include "../include/placement.h"
#include "../include/tour.h"
#include "../include/map.h"
#include "../include/tableau.h"
#include "../include/lua_ia.h"
#include "../include/action.h"
#include "../include/SDL_isometric.h"

char rep_saveIA[10] = "IA_save/";
int nbIA = 0;
char NomSaveIA[10][50];
type_Map tMap = diamond;
t_context *ingame;

void initIAFile();
/**
 * \fn int main()
 * \brief Menu principal, donne accès au lancement de la partie et au chargement.
 *
 */

int main() {
	
	// menuStart(ingame);
	// drawMap(ingame, tMap);
	// SDL_generate(ingame);

	SDL_initWindow(SCREEN_WIDTH, SCREEN_HEIGHT, 0, "Tactics Arena", "M_ICON.png", 1, "global.ttf", 20, 0);
	ingame = SDL_newContext("Tactics Arena", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	srand(time(NULL));
	int choix_menu = 0;
	int i;
	do{
		// system("clear");
		printf("1 - Nouvelle Partie\n");
		printf("2 - Charger une partie\n");
		printf("3 - IA vs IA\n");
		printf("4 - Quitter\n");
		// scanf("%i", &choix_menu);
		choix_menu = menuStart(ingame);
		switch(choix_menu){
			SDL_generate(ingame);
			case 1: 
					initialise_map();
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
					initIAFile();
					for ( i = 0; i < nbIA; i++){
						IA_play("placing", NomSaveIA[i]);
					}
				  afficher_map();
					partieIA();
					break;
			case 4:
					break;
		}
	}while(choix_menu != 4);
	// freeAllListAttack();
	SDL_freeContext(ingame);
	return 0;
}

void initIAFile(){
	printf("\nCombien d'IA à charger ?\n");
	scanf("%i", &nbIA);

	int i;
	char tmp[50];
	for ( i = 0; i < nbIA; i++) {
		printf("\nIA : %i\nQuelle IA charger ? (sans .lua)\n\n",i+1);

		DIR * rep = opendir(rep_saveIA);
		if (rep != NULL){
			struct dirent * ent;
			while ((ent = readdir(rep)) != NULL){
				if (strcmp(ent->d_name,".") != 0 && strcmp(ent->d_name,"..") != 0) {
					printf("\t%s\n", ent->d_name);
				}
			}
			closedir(rep);
		}
		memset (tmp, 0, sizeof (tmp));
		scanf("%s", tmp);
		memset (NomSaveIA[i], 0, sizeof (NomSaveIA));
		strcpy(NomSaveIA[i], rep_saveIA);
		strcat(NomSaveIA[i], tmp);
		strcat(NomSaveIA[i], ".lua");
	}
}
