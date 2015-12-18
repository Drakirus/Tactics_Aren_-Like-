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

/**
 * \fn void afficher_tableau()
 * \brief On affiche le tableau contenant tous les personnages
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
 * \param x coordonée en abscisse
 * \param y coordonnée en ordonnée
 * \return -1 s'il n'y a personne dans ces coordonées
 * \return i la place du tableau dans lequel le personnage est
 * \brief A partir de coordonnées, on retourne la position du perso dans le tableau correspondant au coordonnées.
 *
 */
int recherche_perso_tab(int x, int y)
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
 * \param tab_perso Le tableau à initialiser
 * \brief On initialise le tableau contenant les personnages, cela évite qu'on retrouve n'importe quoi dedans.
 *
 */
void init_tab_perso(t_perso tab_perso[i_taille_tab_perso])
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
/**
 * \fn freeListAttack();
 * \brief https://www.youtube.com/watch?v=wQP9XZc2Y_c
 *
 */
void freeAllListAttack(){
	int perso = 0;
	int nbPersoAtt;
	while (perso < i_taille_tab_perso) {
		nbPersoAtt = getCountAttack(tab_perso[perso].att);
		while( getAttack(tab_perso[perso].att, nbPersoAtt) != NULL){
			free(getAttack(tab_perso[perso].att, nbPersoAtt));
			nbPersoAtt--;
		}
		perso++;
	}
}
