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
int nb_perso[2]; //Stocke le nombre de perso de chaque équipe
int i_perso_actuel = 0;
int action = 0;

/*Compte le nombre de personnage vivant de chaque équipe et le stocke dans un tableau*/
void perso_vivant(){
	int i;
	nb_perso[0] = 0;
	nb_perso[1] = 0;
	for(i = 0 ; i < i_taille_tab_perso ; i++){
		if(tab_perso[i].i_HP > 0){
			if(tab_perso[i].c_team == 'A') nb_perso[0]++;
			if(tab_perso[i].c_team == 'B') nb_perso[1]++;
		}
	}
}

int victoire(){
	if(nb_perso[0] == 0) return 2; /*Vérifie si il reste des personnages de l'équipe 1 renvoie 2 pour signifier que l'équipe 2 a gagné*/
	else if(nb_perso[1] == 0) return 1; /*Inversement*/
	else return 0;
}

void actio(t_perso perso){
	if(perso.i_HP > 0){

		int PA_actuel = perso.i_PA, PM_actuel = perso.i_PM;
		do{
			perso_vivant();
			afficher_map();
			affichage_perso(perso);
			printf("%i PA, %i PM\n", PA_actuel, PM_actuel);
			printf("1 - Deplacement\n");
			printf("2 - Attaque\n");
			printf("3 - Passer\n");
			printf("4 - Sauvegarder\n");
			printf("5 - Menu Principal\n");
			scanf("%i", &action);
			switch(action){
				case 1:	deplacement(PM_actuel);
					break;
				case 2: attaque(tab_perso[i_perso_actuel], PA_actuel); /*Fonction Attaque */
					break;
				case 3: printf("Passage de tour\n");
					break; /*Remise au max des PAs PMs du soldat en cours et on passe au suivant dans la liste*/
				case 4: save();
					break;
				case 5: break;
			}
		}while(action != 3 && action != 5 && !victoire());
	}
}


void tour(){
	/*Tant qu'on a pas utilisé tous les persos, que personne n'a gagné et qu'on ne décide pas de retourner au menu principal*/
	while(i_perso_actuel < i_taille_tab_perso && !victoire() && action != 5){
		actio(tab_perso[i_perso_actuel]);
		i_perso_actuel++;
	}
}

void partie(){
	perso_vivant();
	while(!victoire() && action != 5){
		tour();
		i_perso_actuel = 0;
	}
	if(action == 5);
	else printf("Le joueur %i a gagné !\n", victoire());
}
