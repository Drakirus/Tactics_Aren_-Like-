#include <stdio.h>
#include <stdlib.h>

void attaque(t_perso tab_perso[6], int i_position_tableau, int map[i_taille_map][i_taille_map])
{
	int b_sortie=0; //Condition de sortie
	while(b_sortie==0)
	{
		int coord_att[2]; //Les coordonnées cible du joueur
		if(strcmp(tab_perso[i_position_tableau].s_classe, "Guerrier")
		{
			printf("Veuillez rentrer les coordonnées du personnages que vous voulez attaquer : ");
			scanf("%i%i", &coord_att[0], &coord_att[1]);
			if(map[coord_att[0]][coord_att[1]]==0 || map[coord_att[0]][coord_att[1]]==1)
			{
				printf("Il n'y a rien à attaquer");
			}
			else
			{

			}
		}
	}
}