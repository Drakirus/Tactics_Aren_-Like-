#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define i_taille_map 10

void charge(){
	int mat[i_taille_map][i_taille_map]
	int i, j;
	FILE * fic;
	char nom_fichier[20];
	do{
		printf("Quel partie charger ?");
		scanf("%s", nom_fichier);
		fic = fopen(nom_fichier, "r");
		if(fic == NULL) printf("Mauvais fichier");
	}while(fic == NULL);
	for(i = 0; i < i_taille_map ; i++){
         	for(j = 0; j < i_taille_map ; j++){
            		fscanf(fic, "%i", &mat[i][j]);
		}
	}
	fclose(fic);
}

void save(int mat[i_taille_map][i_taille_map], char nom_fichier[20]){
	int i, j;
	FILE * fic;
	
	fic = fopen(nom_fichier, "w");
	for(i = 0; i < i_taille_map ; i++){
         	for(j = 0; j < i_taille_map ; j++){
            		fprintf(fic, "%i ", mat[i][j]);
		}
		fprintf(fic, "\n");
    	}
	fprintf(fic, "\n");
	fclose(fic);
}
