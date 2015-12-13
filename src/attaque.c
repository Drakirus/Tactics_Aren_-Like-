#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tableau.h"
#include "../include/gener_map.h"
#include "../include/action.h"

extern int map[i_taille_map][i_taille_map];

void attaque(t_perso per)
{
	int b_sortie=0; //Condition de sortie
	while(b_sortie==0)
	{
		int coord_att[2]; //Les coordonnées cibles du joueur
		if(strcmp(per.s_classe, "Guerrier")==0)
		{
			printf("Veuillez rentrer les coordonnées du personnages que vous voulez attaquer : ");
			scanf("%i%i", &coord_att[0], &coord_att[1]);
			int **DistancePath=**createDistancePath(map, per.coord[0], per.coord[1]);
			if(distanceFrom(coord_att[0], coord_att[1],DistancePath)>2)
			{
				printf("Le guerrier ne peut attaquer si loin!\n");
			}
			else
			{
				if(map[coord_att[0]][coord_att[1]]==0 || map[coord_att[0]][coord_att[1]]==1) //On vérifie qu'il attaque bien une cible convenable
				{
					printf("Il n'y a rien à attaquer\n");
				}
				else
				{
					printf("Vous avez infligé 5 points de dégats. \n");
					int i_pos_perso_attaque=recherche_perso_tab(coord_att[0], coord_att[1], tab_perso); //position du perso attaqué
					augmente_nombre(2, &tab_perso[i_pos_perso_attaque], -5);
					afficher_perso(tab_perso[i_pos_perso_attaque]);
					b_sortie=1;
				}
			}
		}
	}
}