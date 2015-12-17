#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/tour.h"
#include "../include/perso.h"
#include "../include/map.h"
#include "../include/save.h"
#include "../include/action.h"
#include "../include/tableau.h"

extern int map[i_taille_map][i_taille_map];
extern t_perso tab_perso[i_taille_tab_perso];
int nb_perso[2] = {3,3}; //Stocke le nombre de perso de chaque équipe
int i_perso_actuel = 0;

void delay(int milliseconds){
    long pause;
    clock_t now,then;
    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int victoire(){
	if(nb_perso[0] == 0) return 2; /*Vérifie si il reste des personnages de l'équipe 1 renvoie 2 pour signifier que l'équipe 2 a gagné*/
	else if(nb_perso[1] == 0) return 1; /*Inversement*/
	else return 0;
}

void action(t_perso perso){
	if(perso.i_HP > 0){
		afficher_perso(perso);
		int action = 0;
		int PA_actuel = perso.i_PA, PM_actuel = perso.i_PM;
		printf("%i PA, %i PM\n", PA_actuel, PM_actuel);
		do{
			printf("1 - Deplacement\n");
			printf("2 - Attaque\n");
			printf("3 - Passer\n");
			printf("4 - Sauvegarder\n");
			scanf("%i", &action);
			switch(action){
				case 1:
						deplacement(PM_actuel);
						break;
				case 2: printf("Attaque\n"); /*Fonction Attaque */
					break;
				case 3: printf("Passage de tour\n");
					break; /*Remise au max des PAs PMs du soldat en cours et on passe au suivant dans la liste*/
				case 4: save();
					break;
			}
		}while(action != 3);
	}
}


void tour(){
	while(i_perso_actuel < i_taille_tab_perso){
		afficher_map();
		action(tab_perso[i_perso_actuel]);
		i_perso_actuel++;
	}
}

void partie(){
	int victoire = 0;
	while(!victoire){
		tour();
	}
	printf("Le joueur %i a gagné !", victoire);
}

void deplacement(int PM_actuel){
	pile *path = NULL; // move personnage
	int r,c; // move personnage
	int sortir; // move personnage
	int value_perso;
	path = getMovePerso(&PM_actuel, tab_perso[i_perso_actuel].coord[1], tab_perso[i_perso_actuel].coord[0] );
	if (path == NULL) printf("Déplacement imposible\n");
	else{
		sortir = pop(&path, &r, &c);
		value_perso = map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]];
		afficher_map();
		system("clear");
		delay(500);
		while (sortir != -1) {
			if (map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]] == 0 || value_perso ==  map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]]) {
				map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]] = 0;
  			}
			sortir = pop(&path, &r, &c);
			// printf("r: %i c: %i\n",r,c );
			change_nombre(5,&tab_perso[i_perso_actuel], c);
			change_nombre(6, &tab_perso[i_perso_actuel], r);
			if (map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]] == 0 || value_perso ==  map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]]) {
				map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]] = value_perso;
			}
			system("clear");
			afficher_map();
			delay(400);
		}
	}
}
