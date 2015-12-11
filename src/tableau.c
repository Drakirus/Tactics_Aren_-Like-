#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tableau.h"
//#include "../include/perso.h"

t_perso tab_perso[6]; //Contient les données de tous les persos.

void afficher_tableau(t_perso tab[6])
{
	int i;
	for(i=0;i<6;i++)
	{
		printf("%s %i %i %i %i [%i,%i] %c\n", tab[i].s_classe, tab[i].i_HP_max, tab[i].i_HP, tab[i].i_PA, tab[i].i_PM, tab[i].coord[0], tab[i].coord[1], tab[i].c_team);
	}
}

void sauv_perso(char * sauv, t_perso perso)
{
	sprintf(sauv, "%s %d %d %d %d %d %d %c",  perso.s_classe, perso.i_HP_max, perso.i_HP, perso.i_PA, perso.i_PM, perso.coord[0], perso.coord[1], perso.c_team);
}
