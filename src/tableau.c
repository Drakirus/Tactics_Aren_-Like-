#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/perso.h"

#define i_taille_tab_perso 6

void afficher_tableau(t_perso tab[i_taille_tab_perso])
{
	int i;
	for(i=0;i<i_taille_tab_perso;i++)
	{
		printf("%s %i %i %i %i [%i,%i] %c\n", tab[i].s_classe, tab[i].i_HP_max, tab[i].i_HP, tab[i].i_PA, tab[i].i_PM, tab[i].coord[0], tab[i].coord[1], tab[i].c_team);
	}
}

void sauv_perso(char * sauv, t_perso perso)
{
	sprintf(sauv, "%s %d %d %d %d %d %d %c",  perso.s_classe, perso.i_HP_max, perso.i_HP, perso.i_PA, perso.i_PM, perso.coord[0], perso.coord[1], perso.c_team);
}

int recherche_perso_tab(int x, int y, t_perso tab[i_taille_tab_perso]) //A partir de coordonnées, on retourne la position du perso correspondant au coordonnées
{	int i;
	for(i=0; i<i_taille_tab_perso; i++)
	{
		if(x==tab[i].coord[0] && y==tab[i].coord[1])
		{
			return i;
		}
	}
	return -1;
}