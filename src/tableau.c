#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tableau.h"
//#include "../include/perso.h"
#define i_taille_tab_perso 6

t_perso tab_perso[i_taille_tab_perso]; //Contient les données de tous les persos.

void afficher_tableau()
{
	int i;
	for(i=0;i<i_taille_tab_perso;i++)
	{
		printf("%s %i %i %i %i [%i,%i] %c\n", tab_perso[i].s_classe, tab_perso[i].i_HP_max, tab_perso[i].i_HP, tab_perso[i].i_PA, tab_perso[i].i_PM, tab_perso[i].coord[0], tab_perso[i].coord[1], tab_perso[i].c_team);
	}
}

void sauv_perso(char * sauv, t_perso perso)
{
	sprintf(sauv, "%s %d %d %d %d %d %d %c",  perso.s_classe, perso.i_HP_max, perso.i_HP, perso.i_PA, perso.i_PM, perso.coord[0], perso.coord[1], perso.c_team);
}

int recherche_perso_tab(int x, int y) //A partir de coordonnées, on retourne la position du perso correspondant au coordonnées. Retourne -1 s'il n'y a personne
{	int i;
	for(i=0; i<i_taille_tab_perso; i++)
	{
		if(x==tab_perso[i].coord[0] && y==tab_perso[i].coord[1])
		{
			return i;
		}
	}
	return -1;
}
