#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perso.h"

void afficher_tableau(t_perso tab[6])
{
	int i;
	for(i=0;i<6;i++)
	{
		printf("%s %i %i %i %i [%i,%i] %c\n", tab[i].s_classe, tab[i].i_HP_max, tab[i].i_HP, tab[i].i_PA, tab[i].i_PM, tab[i].coord[0], tab[i].coord[1], tab[i].c_team);
	}
}

void sauv_perso(char sauv[40], t_perso tab[6], int i_position)
{
	char i[2];
	sprintf(sauv, "%s %d %d %d %d %d %d %c",  tab[i_position].s_classe, tab[i_position].i_HP_max, tab[i_position].i_HP, tab[i_position].i_PA, tab[i_position].i_PM, tab[i_position].coord[0], tab[i_position].coord[1], tab[i_position].c_team);
}