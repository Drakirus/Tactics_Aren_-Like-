#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/listes.h"

typedef struct element
{
	t_perso perso;
	struct element * prec;
	struct element * suiv;
} t_element;

t_element * drapeau;
t_element * ec;

void init_liste(void)
/* Initialise la liste à vide */
{	
	drapeau=(t_element *)malloc(sizeof(t_element));
	drapeau->suiv=drapeau;
	drapeau->prec=drapeau;
	ec=drapeau;
}

int liste_vide(void)
/* Rend vrai si la liste est vide, faux sinon */
{	
	return (drapeau->suiv==drapeau);
}

int hors_liste(void)
/* Rend vrai si l'elt courant est hors de la liste, faux sinon */
{	
	return(ec==drapeau);
}

void en_tete(void)
/* Positionne en tete de la liste */
{	
	if(!liste_vide()) 
		ec=drapeau->suiv;
}

void en_queue(void)
/* Positionne en queue de la liste */
{	
	if(!liste_vide()) 
		ec=drapeau->prec;
}

void precedent(void)
/* Positionne sur l'elt precedent*/
{	
	if(!hors_liste()) 
		ec=ec->prec;
}

void suivant(void)
/* Positionne sur l'elt suivant*/
{	
	if(!hors_liste()) 
		ec=ec->suiv;
}

void valeur_elt(t_perso* p)
/* Renvoie dans e la veleur de l'elt courant */
{	
	if(!hors_liste()) 
		*p=ec->perso;
}

void modif_elt(t_perso p)
/* Affecte v à l'elt courant */
{	
	if(!hors_liste()) 
		ec->perso=p;
}

void oter_elt(void)
/* Supprime l'elt courant et positionne sur le precedent */
{	
	t_element * temp;
	if(!hors_liste())
	{
		ec->prec->suiv=ec->suiv;
		ec->suiv->prec=ec->prec;
		temp=ec;
		precedent();
		free(temp);
	}

}

void ajout_droit(t_perso p)
/* Ajoute v a droite de l'elt courant */
{	
	t_element * temp;
	if(liste_vide()||!hors_liste())
	{	
		temp=(t_element*)malloc(sizeof(t_element));
		temp->prec=ec;
		temp->suiv=ec->suiv;
		temp->perso=p;
		ec->suiv->prec=temp;
		ec->suiv=temp;
		ec=temp;
	}
}

void ajout_gauche(t_perso p)
/* Ajoute v a gauche de l'elt courant */
{	
	t_element * temp;
	if(liste_vide()||!hors_liste())
	{	
		temp=(t_element*)malloc(sizeof(t_element));
		temp->suiv=ec;
		temp->prec=ec->prec;
		temp->perso=p;
		ec->prec->suiv=temp;
		ec->prec=temp;
		ec=temp;
	}
}

void pointeur_perso(t_perso * p_elt)
{
	if(!hors_liste()) 
		p_elt=&(ec->perso);
}

void afficher_liste()
{
	t_perso * p_elt;
	en_tete();
	while(!hors_liste())
	{
		pointeur_perso(p_elt);
		printf("%s\n", p_elt->s_classe);
	}
}

/*void sauv_perso(char sauv[40])
{
	t_perso perso;
	char i[2];
	strcat(sauv, valeur_elt(*perso)->s_classe);
	sprintf(i‚ "%d"‚ valeur_elt(*perso)->i_HP_max);
	strcat(sauv, " "i);
	sprintf(i‚ "%d"‚ valeur_elt(*perso)->i_HP);
	strcat(sauv, " "i);
	sprintf(i‚ "%d"‚ valeur_elt(*perso)->i_PA);
	strcat(sauv, " "i);
	sprintf(i‚ "%d"‚ valeur_elt(*perso)->i_PM);
	strcat(sauv, " "i);
	sprintf(i‚ "%d"‚ valeur_elt(*perso)->coord[0]);
	strcat(sauv, " "i);
	sprintf(i‚ "%d"‚ valeur_elt(*perso)->coord[1]);
	strcat(sauv, " "i);
	strcat(sauv, " "valeur_elt(*perso)->c_team);
}*/