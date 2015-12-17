#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/perso.h"

t_perso ensemble_perso[i_nombre_classe]=
{
	{"Guerrier",50,50,3,3,{0,0},'X', NULL},
	{"Archer",30,30,3,3,{0,0},'X', NULL},
	{"Mage",20,20,2,2,{0,0},'X', NULL},
	{"Voleur",30,30,4,3,{0,0},'X', NULL},
	{"Dovakhiin",150,150,20,20,{0,0},'X', NULL}
};

/*Sert pour les tests*/
void afficher_perso(t_perso perso){
	printf("%s %i/%iHP %i %i [%i,%i] %c\n", perso.s_classe, perso.i_HP, perso.i_HP_max, perso.i_PA, perso.i_PM, perso.coord[0], perso.coord[1], perso.c_team);
}

/*Affichage dans la console*/
void affichage_perso(t_perso perso){
	printf("%s %i/%iHP [%i,%i] \n", perso.s_classe, perso.i_HP, perso.i_HP_max, perso.coord[0], perso.coord[1]);
	// displaylistAttack(perso.att);
}

void initialisation_perso(int a, t_perso * per) //On affecte à un t_perso les données initiales présentes dans ensemble_perso
{
	strcpy(per->s_classe,ensemble_perso[a].s_classe);
	per->i_HP_max=ensemble_perso[a].i_HP_max;
	per->i_HP=ensemble_perso[a].i_HP;
	per->i_PA=ensemble_perso[a].i_PA;
	per->i_PM=ensemble_perso[a].i_PM;
	per->coord[0]=ensemble_perso[a].coord[0];
	per->coord[1]=ensemble_perso[a].coord[1];
	per->c_team=ensemble_perso[a].c_team;

	init_attack(per);
}
// attention : il faut que le perso passe en param ait sa classe de correctement fixee
int init_attack(t_perso *per){
	per->att = creer_liste_attack();
	if(per->s_classe[0] == 'G'){ //guerrier
		pushAttack(per->att, createAttack("Coup d'épée", 1, 0, 3, 1, 0, 1, "HP", -5));// copie d'une attack par defaut d'un guerrier
	}else if(per->s_classe[0] == 'A'){ //guerrier
		pushAttack(per->att, createAttack("Tir à l'arc", 5, 2, 3, 1, 0, 3, "HP", -3,"coord_r",-2,"coord_c",-2));// copie d'une attack par defaut d'un archer
	}else if(per->s_classe[0] == 'M'){ //guerrier
		pushAttack(per->att, createAttack("Boule De Feu", 3, 0, 4, 3, 1, 1, "HP", -2));// copie d'une attack par defaut d'un mage
		pushAttack(per->att,createAttack("Sort de Soin", 3, 0, 2, 1, 0, 1, "HP", 2));
	}else{
		return 0;
	}
	return 1;
}

void augmente_nombre(int a, t_perso * per, int i_montant) //Augmente ou soustrait une valeur numérique d'un perso, 1=i_HP_max, 2=i_HP, 3=i_PA, 4=i_PM, 5=coord[0], 6=coord[1]
{
	switch(a)
	{
		case 1 : (*per).i_HP_max+=i_montant; break;
		case 2 : (*per).i_HP+=i_montant; break;
		case 3 : (*per).i_PA+=i_montant; break;
		case 4 : (*per).i_PM+=i_montant; break;
		case 5 : (*per).coord[0]+=i_montant; break;
		case 6 : (*per).coord[1]+=i_montant; break;
	}
}

void change_nombre(int a, t_perso * per, int i_montant) //Change une valeur numérique d'un perso, 1=i_HP_max, 2=i_HP, 3=i_PA, 4=i_PM, 5=coord[0], 6=coord[1]
{
	switch(a)
	{
		case 1 : per->i_HP_max=i_montant; break;
		case 2 : per->i_HP=i_montant; break;
		case 3 : per->i_PA=i_montant; break;
		case 4 : per->i_PM=i_montant; break;
		case 5 : per->coord[0]=i_montant; break;
		case 6 : per->coord[1]=i_montant; break;
	}
}

void creation(t_perso * per, int i_classe, char c_team, int x, int y) //On change juste les coordonnées et l'équipe du personnage.
{
	initialisation_perso(i_classe, per);
	per->coord[0]=x;
	per->coord[1]=y;
	per->c_team=c_team;
}

/*retourne 1 si le le personnage est mort, 0 sinon */
int est_mort(t_perso perso){
	if(perso.i_HP == 0) return 1;
	else return 0;
}
