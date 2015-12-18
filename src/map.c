/**
 * \file main.c
 * \brief Ce module permet de créer la carte de jeu ainsi que gérer l'affichage de celle-ci.
 * \author CHAMPION Pierre, LAVILLE Martin, MOK Modira
 * \version 0.1
 * \date 18 décembre 2015
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/tableau.h"
#include "../include/map.h"
#include "../include/couleur.h"

extern int i_perso_actuel;
extern t_perso tab_perso[i_taille_tab_perso];
int map[i_taille_map][i_taille_map];

/**
 * \fn int main()
 *	\brief lance le jeu
 *
 *
 */
void obstacle(int i_chance_obstacle) //Fonction insérant les obstacles dans la map. Les obstacles sont placés aléatoirement dans la map.
{
	int i,j;
	int c; //c comme condition.
	int i_place_vide=i_taille_map*(i_taille_map-3)-i_chance_obstacle;
	for(i=0+3;i<i_taille_map-3;i++) //3 correspond aux 3 premières lignes de chaque camp qui servira placer les personnages, il n'y aura pas d'obstacles dans ces zones.
	{
		for(j=0;j<i_taille_map;j++)
		{
			c=rand()%(i_place_vide+i_chance_obstacle);
			if(c<i_place_vide)
			{
				map[i][j]=0;
				i_place_vide--;
			}
			else
			{
				map[i][j]=1; //1=obstacle.
				i_chance_obstacle--;
			}
		}
	}
}

void initialise_map() //Fonction initialisant la map vide avec des obstacles
{	int i,j;
	for(i=0;i<i_taille_map;i++)
	{
		for(j=0;j<i_taille_map;j++)
		{
			map[i][j]=0; //0=vide;
		}
	}
	obstacle(10);
}

void afficher_map() //Fonction affichant la map
{
	char perso[4]; //Pour le changement de couleur
	system("clear");
	int i,j;
	printf("    0   1   2   3   4   5   6   7   8   9\n");
	for(i=0;i<i_taille_map;i++)
	{
		printf("%i  ", i);
		for(j=0;j<i_taille_map;j++)
		{
			if(recherche_perso_tab(i, j)!=-1 && tab_perso[recherche_perso_tab(i, j)].i_HP>0) //On regarde s'il y a un perso ou non. S'il n'y en a pas, il faut vérifier qu'il soit mort ou non
			{
				perso[0]=tab_perso[recherche_perso_tab(i, j)].s_classe[0];
				perso[1]=tab_perso[recherche_perso_tab(i, j)].s_classe[1];
				perso[2]=tab_perso[recherche_perso_tab(i, j)].s_classe[2];
				perso[3]= '\0';
				if(recherche_perso_tab(i,j)==i_perso_actuel) //Si c'est le perso actuel, on met son fond en rouge (en surbrillance)
					color(red, "Screen");
				if(tab_perso[recherche_perso_tab(i, j)].c_team=='A') //Tous les personnages de l'équipe A sont affichés en cyan
					color(cyan, perso);
				else if(tab_perso[recherche_perso_tab(i, j)].c_team=='B') //Tous les personnages de l'équipe B sont affichés en green
					color(green, perso);
				printf(" ");
			}
			else if(map[i][j]==1) //1 : obstacles
				printf(" *  ");
			else
				printf(" _  ");
		}
		printf("\n");
	}
}
