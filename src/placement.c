#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/placement.h"
#include "../include/map.h"
#include "../include/tableau.h"

extern t_perso tab_perso[i_taille_tab_perso];
extern int map[i_taille_map][i_taille_map];

int tableau_vide(int tab[3]) //Retourne 1 si toutes les cases sont nulles, 0 sinon
{
	int i=0;
	for(i=0;i<3;i++)
	{
		if(tab[i]!=0)
		{
			return 0;
		}
	}
	return 1;
}

void placement_perso() //Cette fonction place les personnages des différents équipes dans les trois premières et dernières ligne de la map.
{
	int i_classe; //Classe du personnage choisie.
	int coord[2];
	int b_sortie=1; //Condition de sortie
	int i_compteur=0;
	int tab_perso_ini_A[3]={1,1,1}; //Indique le nombre de perso à créer pour l'équipe A
	int tab_perso_ini_B[3]={1,1,1};
	t_perso per;
	while(tableau_vide(tab_perso_ini_A)!=1 || tableau_vide(tab_perso_ini_B)!=1)
	{
		while(b_sortie!=0)
		{
			printf("\nEquipe A, à vous de placer un personnage : \n"); //La phase de choix de l'équipe A
			printf("Choisissez les coordonnées : ");
			scanf("%i%i", &coord[0], &coord[1]); //Les coordonnées sont comprises entre 0 et 9.
			if(coord[0]>=0 && coord[0]<3 && coord[1]>=0 && coord[1]<=9 && map[coord[0]][coord[1]]==0)
			{
				b_sortie=0;
			}
		}
		b_sortie=1;

		while(b_sortie!=0)
		{
			printf("Choisissez la classe : \n");
			printf("- Il reste %i guerriers à placer.\n", tab_perso_ini_A[0]);
			printf("- Il reste %i archers à placer.\n", tab_perso_ini_A[1]);
			printf("- Il reste %i mages à placer.\n", tab_perso_ini_A[2]);
			printf("Choisissez la classe du personnage (0 Pour un guerrier, 1 pour un archer, 2 pour un mage) : ");
			scanf("%i", &i_classe); //0 pour un guerrier, 1 pour un archer, 2 pour un mage
			if(i_classe==1) //Pour l'affichage dans gener_map.c.
			{
				if(tab_perso_ini_A[1]!=0)
				{
					tab_perso_ini_A[1]--;
					map[coord[0]][coord[1]]=3;
					creation(per, "Archer", 'A', coord[0], coord[1]);
					tab_perso[i_compteur]=per; //On ajoute le perso au tableau.
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(i_classe==0)
			{
				if(tab_perso_ini_A[0]!=0)
				{
					tab_perso_ini_A[0]--;
					map[coord[0]][coord[1]]=2;
					creation(per, "Guerrier", 'A', coord[0], coord[1]);
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(i_classe==2)
			{
				if(tab_perso_ini_A[2]!=0)
				{
					tab_perso_ini_A[2]--;
					map[coord[0]][coord[1]]=4;
					creation(per, "Mage", 'A', coord[0], coord[1]);
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
		}
		b_sortie=1;
		afficher_map(map);
		while(b_sortie!=0)
		{
			printf("\nEquipe B, à vous de placer un personnage : \n"); //On passe à la phase de choix de l'équipe B
			printf("Choisissez les coordonnées : ");
			scanf("%i%i", &coord[0], &coord[1]); //Les coordonnées sont comprises entre 0 et 9.
			if(coord[0]>=7 && coord[0]<=9 && coord[1]>=0 && coord[1]<=9 && map[coord[0]][coord[1]]==0)
			{

				b_sortie=0;
			}
		}
		b_sortie=1;
		while(b_sortie!=0)
		{
			printf("Choisissez la classe : \n");
			printf("- Il reste %i guerriers à placer.\n", tab_perso_ini_B[0]);
			printf("- Il reste %i archers à placer.\n", tab_perso_ini_B[1]);
			printf("- Il reste %i mages à placer.\n", tab_perso_ini_B[2]);
			printf("Choisissez la classe du personnage (0 Pour un guerrier, 1 pour un archer, 2 pour un mage) : ");
			scanf("%i", &i_classe); //0 pour un guerrier, 1 pour un archer, 2 pour un mage
			if(i_classe==1)
			{
				if(tab_perso_ini_B[1]!=0)
				{
					tab_perso_ini_B[1]--;
					map[coord[0]][coord[1]]=6;
					creation(per, "Archer", 'B', coord[0], coord[1]);
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(i_classe==0)
			{
				if(tab_perso_ini_B[0]!=0)
				{
					tab_perso_ini_B[0]--;
					map[coord[0]][coord[1]]=5;
					creation(per, "Guerrier", 'B', coord[0], coord[1]);
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(i_classe==2)
			{
				if(tab_perso_ini_B[2]!=0)
				{
					tab_perso_ini_B[2]--;
					map[coord[0]][coord[1]]=7;
					creation(per, "Mage", 'B', coord[0], coord[1]);
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
		}
		afficher_map(map);
		b_sortie=1;
	}
}
