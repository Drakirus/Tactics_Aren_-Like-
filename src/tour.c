/**
 * \file tour.c
 * \brief Module gérant le tour de chaque utilisateur.
 * \author LAVILLE Martin
 * \version 0.1
 * \date 18 décembre 2015
 *
 *
 */

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
#include "../include/lua_ia.h"

extern int map[i_taille_map][i_taille_map];
extern t_perso tab_perso[i_taille_tab_perso];
int nb_perso[2]; //Stocke le nombre de perso de chaque équipe
int i_perso_actuel = 0;
int action = 0;

extern int PA_actuel, PM_actuel; // extern at lua_ia.c
extern int nbIA; //extern a main.c
extern char NomSaveIA[10][50]; //extern a main.c
/**
 * \fn void perso_vivant()
 * \brief Compte le nombre de personnage vivant de chaque équipe et le stocke dans un tableau
 *
 */
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

/**
 * \fn int victoire()
 * \return 1 si l'équipe 1 a gagné, 2 si l'équipe 2, 0 sinon.
 * \brief Vérifie les valeurs du tableau comprenant le nombre de personnages vivant par équipe et retourne si une équipe a gagné
 *
 */
int victoire(){
	if(nb_perso[0] == 0) return 2; /*Vérifie si il reste des personnages de l'équipe 1 renvoie 2 pour signifier que l'équipe 2 a gagné*/
	else if(nb_perso[1] == 0) return 1; /*Inversement*/
	else return 0;
}

/**
 * \fn void actio(t_perso *perso)
 * \param perso Personnage du tableau de perso
 * \brief Effectue une action pour un personnage
 *
 */
void actio(t_perso *perso){
	if(perso->i_HP > 0){

		int PA_actuel = perso->i_PA, PM_actuel = perso->i_PM; /*Permet de ne pas modifier les statistiques du personnage*/
		do{
			afficher_map();
			affichage_perso(*perso);
			printf("%i PA, %i PM\n", PA_actuel, PM_actuel);
			printf("1 - Deplacement\n");
			printf("2 - Attaque\n");
			printf("3 - Passer\n");
			printf("4 - Sauvegarder\n");
			printf("5 - Menu Principal\n");
			scanf("%i", &action);
			switch(action){
				case 1:	deplacement(&PM_actuel);
					break;
				case 2: attaque(&PA_actuel);
					break;
				case 3: printf("Passage de tour\n");
					break;
				case 4: save();
					break;
				case 5: break;
			}
			perso_vivant();
		}while(action != 3 && action != 5 && !victoire());
	}
}

/**
 * \fn void tour()
 * \brief Permet le bon déroulement d'un tour
 *
 */
void tour(){
	/*Tant qu'on a pas utilisé tous les persos, que personne n'a gagné et qu'on ne décide pas de retourner au menu principal*/
	while(i_perso_actuel < i_taille_tab_perso && !victoire() && action != 5){
		actio(&tab_perso[i_perso_actuel]);
		i_perso_actuel++;
	}
}

/**
 * \fn void partie()
 * \brief Permet le bon déroulement de la partie.
 *
 */
void partie(){
	perso_vivant();
	while(!victoire() && action != 5){
		tour();
		i_perso_actuel = 0;
	}
	if(action == 5);
	else printf("Le joueur %i a gagné !\n", victoire());
}

void call_IA_play(char src[50]){
	if(tab_perso[i_perso_actuel].i_HP > 0){

		PA_actuel = tab_perso[i_perso_actuel].i_PA;
		PM_actuel = tab_perso[i_perso_actuel].i_PM; /*Permet de ne pas modifier les statistiques du personnage*/

		afficher_map();
		IA_play("main", src);
		delay(1400);
	}
	i_perso_actuel++;
}
/**
 * \fn void partieIA()
 * \brief Permet le bon déroulement de la partie.
 *
 */
void partieIA(){
	perso_vivant();
	int i;
	while(!victoire()){
		while(i_perso_actuel < i_taille_tab_perso && !victoire()){

			for ( i = 0; i < nbIA; i++){
				call_IA_play(NomSaveIA[i]);
			}

		}
		i_perso_actuel = 0;
	}
	printf("Le joueur %i a gagné !\n", victoire());
}
