#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/placement.h"
#include "../include/map.h"
#include "../include/tableau.h"

extern t_perso tab_perso[6];
extern int map[i_taille_map][i_taille_map];

void placement_perso() //Cette fonction place les personnages des différents équipes dans les trois premières et dernières ligne de la map.
{
	char s_classe[20]; //Classe du personnage choisie.
	int i_nb_perso=6;
	int i_nb_guerrier_A=1;
	int i_nb_archer_A=1;
	int i_nb_mage_A=1;
	int i_nb_guerrier_B=1;
	int i_nb_archer_B=1;
	int i_nb_mage_B=1;
	int coord[2];
	int b_sortie=1; //Condition de sortie
	int i_compteur=0;
	t_perso per;
	while(i_nb_perso!=0)
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
			printf("- Il reste %i guerriers à placer.\n", i_nb_guerrier_A);
			printf("- Il reste %i archers à placer.\n", i_nb_archer_A);
			printf("- Il reste %i mages à placer.\n", i_nb_mage_A);
			printf("Choisissez la classe du personnage : ");
			scanf("%s", s_classe); //La classe est donnée par la première lettre de la classe, ou le nom complet.
			if(strcmp(s_classe,"A")==0 || strcmp(s_classe,"archer")==0 || strcmp(s_classe,"Archer")==0) //Pour l'affichage dans gener_map.c.
			{
				if(i_nb_archer_A!=0)
				{
					i_nb_archer_A--;
					i_nb_perso--;
					map[coord[0]][coord[1]]=3;
					creation(per, "Archer", 'A', coord[0], coord[1]);
					tab_perso[i_compteur]=per; //On ajoute le perso au tableau.
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(strcmp(s_classe,"G")==0 || strcmp(s_classe,"Guerrier")==0|| strcmp(s_classe,"guerrier")==0)
			{
				if(i_nb_guerrier_A!=0)
				{
					i_nb_guerrier_A--;
					i_nb_perso--;
					map[coord[0]][coord[1]]=2;
					creation(per, "Guerrier", 'A', coord[0], coord[1]);
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(strcmp(s_classe,"M")==0 || strcmp(s_classe,"Mage")==0 || strcmp(s_classe,"mage")==0)
			{
				if(i_nb_mage_A!=0)
				{
					i_nb_mage_A--;
					i_nb_perso--;
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
			printf("- Il reste %i guerriers à placer.\n", i_nb_guerrier_B);
			printf("- Il reste %i archers à placer.\n", i_nb_archer_B);
			printf("- Il reste %i mages à placer.\n", i_nb_mage_B);
			printf("Choisissez la classe du personnage : ");
			scanf("%s", s_classe);
			if(strcmp(s_classe,"A")==0 || strcmp(s_classe,"archer")==0 || strcmp(s_classe,"Archer")==0)
			{
				if(i_nb_archer_B!=0)
				{
					i_nb_archer_B--;
					i_nb_perso--;
					map[coord[0]][coord[1]]=6;
					creation(per, "Archer", 'B', coord[0], coord[1]);
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(strcmp(s_classe,"G")==0 || strcmp(s_classe,"Guerrier")==0|| strcmp(s_classe,"guerrier")==0)
			{
				if(i_nb_guerrier_B!=0)
				{
					i_nb_guerrier_B--;
					i_nb_perso--;
					map[coord[0]][coord[1]]=5;
					creation(per, "Guerrier", 'B', coord[0], coord[1]);
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(strcmp(s_classe,"M")==0 || strcmp(s_classe,"Mage")==0 || strcmp(s_classe,"mage")==0)
			{
				if(i_nb_mage_B!=0)
				{
					i_nb_mage_B--;
					i_nb_perso--;
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
