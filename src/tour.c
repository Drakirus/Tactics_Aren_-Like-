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
extern t_perso tab_perso[i_taille_tab_perso];
int nb_perso[2]; //Stocke le nombre de perso de chaque équipe
int i_perso_actuel = 0;

int victoire(){
	if(nb_perso[0] == 0) return 2; /*Vérifie si il reste des personnages de l'équipe 1 renvoie 2 pour signifier que l'équipe 2 a gagné*/
	else if(nb_perso[1] == 0) return 1; /*Inversement*/
	else return 0;
}

int action(t_perso perso){
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
				case 1: printf("Deplacement\n");/*Fonction déplacement*/
					break; 
				case 2: printf("Attaque\n"); /*Fonction Attaque */
					break; 
				case 3: printf("Passage de tour\n");
					break; /*Remise au max des PAs PMs du soldat en cours et on passe au suivant dans la liste*/
				case 4: save();
					break;
			}
		}while(action != 3 && victoire() == 0);
	}
	return victoire(); /*Si une des deux équipes a gagné on renvoie son numéro, renvoie 0 sinon*/
}


int tour(){
	t_perso perso;
	int victoire = 0;
	while(i_perso_actuel < i_taille_tab_perso && victoire == 0){
		afficher_map();
		victoire = action(perso);
		i_perso_actuel++;
	}
	return victoire;
}

void partie(){
	int victoire = 0;
	while(!victoire){
		victoire = tour();
	}
	printf("Le joueur %i a gagné !", victoire); 
}
