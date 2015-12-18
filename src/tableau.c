/**
 * \file tableau.c
 * \brief Module créant et gérant le tableau contenant les personnages. Il se remplit lors de la création des personnages.
 * \author MOK Modira
 * \version 0.1
 * \date 18 décembre 2015
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tableau.h"

t_perso tab_perso[i_taille_tab_perso]; //Contient les données de tous les persos.

/**
 * \fn void afficher_tableau()
 * \return
 * \brief
 *
 */
void afficher_tableau()
{
	int i;
	for(i=0;i<i_taille_tab_perso;i++)
	{
		printf("%s %i %i %i %i [%i,%i] %c\n", tab_perso[i].s_classe, tab_perso[i].i_HP_max, tab_perso[i].i_HP, tab_perso[i].i_PA, tab_perso[i].i_PM, tab_perso[i].coord[0], tab_perso[i].coord[1], tab_perso[i].c_team);
	}
}


/**
 * \fn int recherche_perso_tab(int x, int y)
 * \param x
 * \param y
 * \return
 * \brief
 *
 */
int recherche_perso_tab(int x, int y) //A partir de coordonnées, on retourne la position du perso dans le tableau correspondant au coordonnées. Retourne -1 s'il n'y a personne
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

/**
 * \fn void init_tab_perso(t_perso tab_perso[i_taille_tab_perso])
 * \param tab_perso
 * \return
 * \brief
 *
 */
void init_tab_perso(t_perso tab_perso[i_taille_tab_perso]) //On initialise le tableau contenant les personnages, cela évite qu'on retrouve n'importe quoi dedans.
{
	int i;
	for(i=0;i<i_taille_tab_perso;i++)
	{
		strcpy(tab_perso[i].s_classe,"");
		tab_perso[i].i_HP_max=-1;
		tab_perso[i].i_HP=-1;
		tab_perso[i].i_PA=-1;
		tab_perso[i].i_PM=-1;
		tab_perso[i].coord[0]=-1;
		tab_perso[i].coord[1]=-1;
		tab_perso[i].c_team=' ';

	}
}