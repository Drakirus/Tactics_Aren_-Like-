#include<stdio.h>
#include<stdlib.h>

typedef struct element
{
	int valeur;
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

void valeur_elt(int* v)
/* Renvoie dans e la veleur de l'elt courant */
{	
	if(!hors_liste()) 
		*v=ec->valeur;
}

void modif_elt(int v)
/* Affecte v à l'elt courant */
{	
	if(!hors_liste()) 
		ec->valeur=v;
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

void ajout_droit(int v)
/* Ajoute v a droite de l'elt courant */
{	
	t_element * temp;
	if(liste_vide()||!hors_liste())
	{	
		temp=(t_element*)malloc(sizeof(t_element));
		temp->prec=ec;
		temp->suiv=ec->suiv;
		temp->valeur=v;
		ec->suiv->prec=temp;
		ec->suiv=temp;
		ec=temp;
	}
}

void ajout_gauche(int v)
/* Ajoute v a gauche de l'elt courant */
{	
	t_element * temp;
	if(liste_vide()||!hors_liste())
	{	
		temp=(t_element*)malloc(sizeof(t_element));
		temp->suiv=ec;
		temp->prec=ec->prec;
		temp->valeur=v;
		ec->prec->suiv=temp;
		ec->prec=temp;
		ec=temp;
	}
}
