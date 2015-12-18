/**
 * \file save.c
 * \brief Module gérant la sauvegarde du jeu
 * \author LAVILLE Martin
 * \version 0.1
 * \date 18 décembre 2015
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../include/placement.h"
#include "../include/map.h"
#include "../include/tableau.h"
#define CODE1 5
#define CODE2 1
#define CODE3 0
#define CODE4 2

char rep_save[5] = "save/";
extern t_perso tab_perso[i_taille_tab_perso];
extern int map[i_taille_map][i_taille_map];
extern int i_perso_actuel;

/**
 * \fn void sauv_perso(char * sauv, t_perso perso)
 * \param sauv Chaine de caractère où l'on sauvegarde les caractéristiques d'un personnage
 * \param perso Personnage en question
 * \brief Sauvegarde dans une chaine de caractère les caractéristiques d'un personnage
 *
 */
void sauv_perso(char * sauv, t_perso perso){
	sprintf(sauv, "%s %d %d %d %d %d %d %c",  perso.s_classe, perso.i_HP_max, perso.i_HP, perso.i_PA, perso.i_PM, perso.coord[0], perso.coord[1], perso.c_team);
	//sauver les attack du perso
}

/**
 * \fn void charge()
 * \brief Charge un fichier qui est demandé à l'utilisateur. Ce fichier contiendra une sauvegarde.
 *
 */
void charge(){
	int test1 = 0, test2 = 0, test3 = 0, test4 = 0;
	int i, j, k;
	FILE * fic;
	char nom_fichier[20];
	memset (nom_fichier, 0, sizeof (nom_fichier)); /*Permet de s'assurer que la chaine est vide*/
	char temp[15];
	strcat(nom_fichier, rep_save);
	do{
		printf("Quelle partie charger ?\n");
		/* Permet de lister les fichiers présents dans "save/" */
		DIR * rep = opendir(rep_save);
    		if (rep != NULL){
        		struct dirent * ent;
			while ((ent = readdir(rep)) != NULL){
            			printf("%s\n", ent->d_name);
        		}
        		closedir(rep);
    		}
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
		fscanf(fic, "%s", tab_perso[k].s_classe);
		fscanf(fic, "%i", &tab_perso[k].i_HP_max);
		fscanf(fic, "%i", &tab_perso[k].i_HP);
		fscanf(fic, "%i", &tab_perso[k].i_PA);
		fscanf(fic, "%i", &tab_perso[k].i_PM);
		fscanf(fic, "%i", &tab_perso[k].coord[0]);
		fscanf(fic, "%i", &tab_perso[k].coord[1]);
		fscanf(fic, " %c ", &tab_perso[k].c_team);
		init_attack(&tab_perso[k]);
	}
	fclose(fic);
}

/**
 * \fn void save()
 * \brief Sauvegarde dans un fichier toutes les informations nécessaires au bont déroulement de la partie
 *
 */
void save(){
	int i, j, k;
	FILE * fic;
	char nom_fichier[20];
	memset (nom_fichier, 0, sizeof (nom_fichier)); /*Permet de vider la chaine*/
	char temp[15];
	strcat(nom_fichier, rep_save);
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
