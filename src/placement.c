#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/placement.h"
#include "../include/map.h"
#include "../include/tableau.h"
#include "../include/perso.h"

extern t_perso ensemble_perso[i_nombre_classe];
extern t_perso tab_perso[i_taille_tab_perso];
extern int map[i_taille_map][i_taille_map];

int tableau_vide(int tab[i_nombre_classe]) //Retourne 1 si toutes les cases sont nulles, 0 sinon
{
	int i=0;
	for(i=0;i<i_nombre_classe;i++)
	{
		if(tab[i]!=0)
		{
			return 0;
		}
	}
	return 1;
}

void CBperso(int i_a_placer, int i_classe) // Indique le nombre de perso qu'il reste à placer
{
	printf("%i - Il reste %i %s à placer.\n", i_classe, i_a_placer, ensemble_perso[i_classe].s_classe);
}

void placement_perso() //Cette fonction place les personnages des différents équipes dans les trois premières et dernières ligne de la map.
{
	int i_classe; //Classe du personnage choisie.
	int coord[2];
	int b_sortie=1; //Condition de sortie
	int i_compteur=0;
	int tab_perso_ini_A[i_nombre_classe]={1,1,1}; //Indique le nombre de perso à créer pour l'équipe A
	int tab_perso_ini_B[i_nombre_classe]={1,1,1};
	t_perso * per;
	per=malloc(sizeof(t_perso));
	int i_equipe=0; //0 pour l'équipe A et 1 pour l'équipe B
	while(tableau_vide(tab_perso_ini_A)!=1 || tableau_vide(tab_perso_ini_B)!=1)
	{
		while(b_sortie!=0)
		{
			if(i_equipe%2==0)
			{
				printf("\nEquipe A, à vous de placer un personnage : \n"); //La phase de choix de l'équipe A
				printf("Choisissez les coordonnées : ");
				scanf("%i%i", &coord[0], &coord[1]); //Les coordonnées sont comprises entre 0 et 9.
				if(coord[0]>=0 && coord[0]<3 && coord[1]>=0 && coord[1]<=9 && map[coord[0]][coord[1]]==0)
				{
					b_sortie=0;
				}
			}
			else
			{
				printf("\nEquipe B, à vous de placer un personnage : \n"); //On passe à la phase de choix de l'équipe B
				printf("Choisissez les coordonnées : ");
				scanf("%i%i", &coord[0], &coord[1]); //Les coordonnées sont comprises entre 0 et 9.
				if(coord[0]>=7 && coord[0]<=9 && coord[1]>=0 && coord[1]<=9 && map[coord[0]][coord[1]]==0)
				{

					b_sortie=0;
				}
			}
		}
		b_sortie=1;

		while(b_sortie!=0)
		{
			printf("Choisissez la classe : \n");
			int i;
			for(i=0;i<i_nombre_classe;i++)
			{
				CBperso(tab_perso_ini_A[i], i);
			}
			if(i_equipe%2==0)
			{
				printf("Choisissez la classe du personnage: ");
				scanf("%i", &i_classe); //0 pour un guerrier, 1 pour un archer, 2 pour un mage
				if(tab_perso_ini_A[i_classe]!=0)
				{
					tab_perso_ini_A[i_classe]--;
					creation(per, i_classe, 'A', coord[0], coord[1]);
					tab_perso[i_compteur]=*per; //On ajoute le perso au tableau.
					i_compteur++;
					b_sortie=0;
				}
			}
			else
			{
				printf("Choisissez la classe du personnage: ");
				scanf("%i", &i_classe); //0 pour un guerrier, 1 pour un archer, 2 pour un mage
				if(tab_perso_ini_B[i_classe]!=0)
				{
					tab_perso_ini_B[i_classe]--;
					creation(per, i_classe, 'B', coord[0], coord[1]);
					tab_perso[i_compteur]=*per; //On ajoute le perso au tableau.
					i_compteur++;
					b_sortie=0;
				}
			}
		}
		b_sortie=1;
		i_equipe++;
		afficher_map(map);
	}
}
