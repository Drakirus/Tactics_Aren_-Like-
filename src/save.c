#include <stdio.h>
#include <stdlib.h>
#include "../include/placement.h"
#include "../include/perso.h"
#include "../include/gener_map.h"

#define i_taille_map 10

/* Initialise une matrice à zéro */
void init_mat(int mat[i_taille_map][i_taille_map]){
	int i, j;
	for(i = 0; i < i_taille_map ; i++){
		for(j = 0; j < i_taille_map ; j++){
            		mat[i][j] = 0;
            	}
        }
}

void charge(int grille[i_taille_map][i_taille_map], t_perso table[]){
	int i, j/*, k*/;
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
			fscanf(fic, "%s", table[i].s_classe);
			fscanf(fic, "%i", &table[i].i_HP_max);
			fscanf(fic, "%i", &table[i].i_HP);
			fscanf(fic, "%i", &table[i].i_PA);
			fscanf(fic, "%i", &table[i].i_PM);
			fscanf(fic, "%i", &table[i].coord[0]);
			fscanf(fic, "%i", &table[i].coord[1]);
			fscanf(fic, "%c", &table[i].c_team);
	}
	fclose(fic);
	afficher_map(grille);
}

void save(int mat[i_taille_map][i_taille_map]){
	int i, j;
	char nom_fichier[20];
	printf("Nom de la sauvegarde : ");
	scanf("%s", nom_fichier);
	FILE * fic;
	fic = fopen(nom_fichier, "w");
	for(i = 0; i < i_taille_map ; i++){
         	for(j = 0; j < i_taille_map ; j++){
            		fprintf(fic, "%i ", mat[i][j]);
		}
    	}
	while(){
		nomdelafonctiondeModira(chaine)
		fprintf("%s", chaine);
		suivant();
	}
	printf("Partie sauvegardée dans %s\n", nom_fichier);
	fclose(fic);
}
