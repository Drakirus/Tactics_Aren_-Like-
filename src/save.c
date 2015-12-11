#include <stdio.h>
#include <stdlib.h>
#include "../include/placement.h"
#include "../include/gener_map.h"
#include "../include/tableau.h"

extern t_perso tab_perso[6];


/* Initialise une matrice à zéro */
void init_mat(int mat[i_taille_map][i_taille_map]){
	int i, j;
	for(i = 0; i < i_taille_map ; i++){
		for(j = 0; j < i_taille_map ; j++){
            		mat[i][j] = 0;
            	}
        }
}

void charge(int grille[i_taille_map][i_taille_map]){
	int i, j, k;
	FILE * fic;
	char nom_fichier[20];
	do{
		printf("Quelle partie charger ? ");
		scanf("%s", nom_fichier);
		fic = fopen(nom_fichier, "r");
		if(fic == NULL) printf("Mauvais fichier, ");
	}while(fic == NULL);
	for(i = 0; i < i_taille_map ; i++){
         	for(j = 0; j < i_taille_map ; j++){
            		fscanf(fic, "%i", &grille[i][j]);
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
			afficher_perso(tab_perso[k]);
	}
	fclose(fic);
	afficher_map(grille);
}

void save(int mat[i_taille_map][i_taille_map]){
	int i, j,k;
	char nom_fichier[20];
	char sauv[40];
	printf("Nom de la sauvegarde : ");
	scanf("%s", nom_fichier);
	FILE * fic;
	fic = fopen(nom_fichier, "w");
	for(i = 0; i < i_taille_map ; i++){
         	for(j = 0; j < i_taille_map ; j++){
            		fprintf(fic, " %i", mat[i][j]);
		}
    }
	for(k = 0 ; k < 6 ; k++){
		sauv_perso(sauv, tab_perso[k]);
		fprintf(fic, " %s", sauv);
	}
	printf("Partie sauvegardée dans %s\n", nom_fichier);
	fclose(fic);
}
