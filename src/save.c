#include <stdio.h>
#include <stdlib.h>
#include "../include/placement.h"
#include "../include/map.h"
#include "../include/tableau.h"

extern t_perso tab_perso[i_taille_tab_perso];
extern int map[i_taille_map][i_taille_map];
extern int i_perso_actuel;

void charge(){
	int i, j, k;
	FILE * fic;
	char nom_fichier[20];
	do{
		printf("Quelle partie charger ? ");
		scanf("%s", nom_fichier);
		fic = fopen(nom_fichier, "r");
		if(fic == NULL) printf("Mauvais fichier, ");
	}while(fic == NULL);
	fscanf(fic, "%i", &i_perso_actuel);
	for(i = 0; i < i_taille_map ; i++){
         	for(j = 0; j < i_taille_map ; j++){
            		fscanf(fic, "%i", &map[i][j]);
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
			//afficher_perso(tab_perso[k]);
	}
	fclose(fic);
	afficher_map();
}

void save(){
	int i, j, k;
	char nom_fichier[20];
	char sauv[40];
	printf("Nom de la sauvegarde : ");
	scanf("%s", nom_fichier);
	FILE * fic;
	fic = fopen(nom_fichier, "w");
	fprintf(fic, "%i", i_perso_actuel); //sauvegarde le moment du tour où l'on est rendu dans le tour
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
