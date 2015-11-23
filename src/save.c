#include <stdio.h>
#include <stdlib.h>

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

void charge(int grille[i_taille_map][i_taille_map]){
	int i, j;
	FILE * fic;
	char nom_fichier[20];
	do{
		printf("Quel partie charger ? ");
		scanf("%s", nom_fichier);
		fic = fopen(nom_fichier, "r");
		if(fic == NULL) printf("Mauvais fichier, ");
	}while(fic == NULL);
	for(i = 0; i < i_taille_map ; i++){
         	for(j = 0; j < i_taille_map ; j++){
            		fscanf(fic, "%i", &grille[i][j]);
		}
	}
	fclose(fic);
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
		fprintf(fic, "\n");
    	}
	fprintf(fic, "\n");
	printf("Partie sauvegardée dans %s\n", nom_fichier);
	fclose(fic);
}