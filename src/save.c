#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/placement.h"
#include "../include/map.h"
#include "../include/tableau.h"
#define CODE1 5
#define CODE2 1
#define CODE3 0
#define CODE4 2

extern t_perso tab_perso[i_taille_tab_perso];
extern int map[i_taille_map][i_taille_map];
extern int i_perso_actuel;

void sauv_perso(char * sauv, t_perso perso)
{
	sprintf(sauv, "%s %d %d %d %d %d %d %c",  perso.s_classe, perso.i_HP_max, perso.i_HP, perso.i_PA, perso.i_PM, perso.coord[0], perso.coord[1], perso.c_team);
}

void charge_perso(FILE * fic, t_perso perso){
	fscanf(fic, "%s", perso.s_classe);
	fscanf(fic, "%i", &perso.i_HP_max);
	fscanf(fic, "%i", &perso.i_HP);
	fscanf(fic, "%i", &perso.i_PA);
	fscanf(fic, "%i", &perso.i_PM);
	fscanf(fic, "%i", &perso.coord[0]);
	fscanf(fic, "%i", &perso.coord[1]);
	fscanf(fic, " %c ", &perso.c_team);
}

void charge(){
	int test1 = 0, test2 = 0, test3 = 0, test4 = 0;
	int i, j, k;
	FILE * fic;
	char nom_fichier[20];
	memset (nom_fichier, 0, sizeof (nom_fichier)); /*Permet de vider la chaine*/
	char temp[15];
	strcat(nom_fichier, "save/");
	do{
		printf("Quelle partie charger ? ");
		scanf("%s", temp);
		strcat(nom_fichier, temp); /*Permet d'obtenir un fichier de nom save/nom_fichier*/
		fic = fopen(nom_fichier, "r");
		fscanf(fic, "%i", &test1); /*Permet de s'assurer que l'on charge un fichier qui est bien une sauvegarde*/
		fscanf(fic, "%i", &test2);
		fscanf(fic, "%i", &test3);
		fscanf(fic, "%i", &test4);
		if(fic == NULL || (test1 != CODE1 || test2 != CODE2 || test3 != CODE3 || test4 != CODE4)) printf("Mauvais fichier, ");
	}while(fic == NULL || (test1 != CODE1 || test2 != CODE2 || test3 != CODE3 || test4 != CODE4)); /*Permet d'éviter le chargement d'un fichier vide/n'existant pas/mauvais*/
	fscanf(fic, "%i", &i_perso_actuel);
	for(i = 0; i < i_taille_map ; i++){
         	for(j = 0; j < i_taille_map ; j++){
            		fscanf(fic, "%i", &map[i][j]); /*Chargement de la carte*/
		}
	}
	for(k = 0 ; !feof(fic) ; k++){
			charge_perso(fic, tab_perso[k]);
	}
	fclose(fic);
}

void save(){
	int i, j, k;
	FILE * fic;
	char nom_fichier[20];
	memset (nom_fichier, 0, sizeof (nom_fichier)); /*Permet de vider la chaine*/
	char temp[15];
	strcat(nom_fichier, "save/");
	char sauv[40];
	printf("Nom de la sauvegarde : ");
	scanf("%s", temp);
	strcat(nom_fichier, temp); /*Permet d'obtenir un fichier de nom save/nom_fichier*/
	fic = fopen(nom_fichier, "w");
	fprintf(fic, "%i %i %i %i", CODE1, CODE2, CODE3, CODE4); /*Création d'un code que l'on vérifiera au chargement*/
	fprintf(fic, " %i", i_perso_actuel); //sauvegarde le moment où l'on est rendu dans le tour
	for(i = 0; i < i_taille_map ; i++){
         	for(j = 0; j < i_taille_map ; j++){
            		fprintf(fic, " %i", map[i][j]); //sauvegarde l'état de la map et le placement des personnages
			}
    	}
	for(k = 0 ; k < 6 ; k++){
		sauv_perso(sauv, tab_perso[k]);
		fprintf(fic, " %s", sauv); //sauvegarde l'état du tableau
	}
	printf("Partie sauvegardée dans %s\n", nom_fichier);
	fclose(fic);
}
