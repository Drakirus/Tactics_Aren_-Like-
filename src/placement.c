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

void placement_perso() //Cette fonction place les personnages des différents équipes dans les trois premières et dernières ligne de la map.
{
	init_tab_perso(tab_perso);
	int i_classe; //Classe du personnage choisie.
	int coord[2];
	int b_sortie=1; //Condition de sortie
	int i_compteur=0;
	int i_nb_perso=0; //Nombre de perso à placer
	t_perso * per;
	per=malloc(sizeof(t_perso));
	int i_equipe=0; //0 pour l'équipe A et 1 pour l'équipe B
	while(i_nb_perso<6) //Ici on veut 6 personnages en tout.
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
			printf("Vous pouvez placer un : 0 - %s\n", ensemble_perso[0].s_classe);
			for(i=1;i<i_nombre_classe;i++)
			{
				printf("\t\t\t\t\t%i - %s\n",i, ensemble_perso[i].s_classe);
			}
			printf("Choisissez la classe du personnage: ");
			scanf("%i", &i_classe); //0 pour un guerrier, 1 pour un archer, 2 pour un mage
			if(i_equipe%2==0)
				creation(per, i_classe, 'A', coord[0], coord[1]);
			else
				creation(per, i_classe, 'B', coord[0], coord[1]);
			tab_perso[i_compteur]=*per; //On ajoute le perso au tableau.
			i_compteur++;
			b_sortie=0;
		}
		b_sortie=1;
		i_equipe++;
		i_nb_perso++;
		afficher_map(map);
	}
}
