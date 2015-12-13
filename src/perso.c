#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/perso.h"

extern int map[i_taille_map][i_taille_map];


t_perso ensemble_perso[3]=
{
	{"Guerrier",50,50,3,3,{0,0},'X'},
	{"Archer",30,30,3,3,{0,0},'X'},
	{"Mage",20,20,2,2,{0,0},'X'}
};

void afficher_perso(t_perso perso){
	printf("%s %i/%iHP %i %i [%i,%i] %c\n", perso.s_classe, perso.i_HP, perso.i_HP_max, perso.i_PA, perso.i_PM, perso.coord[0], perso.coord[1], perso.c_team);
}

void initialisation_perso(int a, t_perso per) //On affecte à un t_perso les données initiales présentes dans ensemble_perso
{
	per.i_HP_max=ensemble_perso[a].i_HP_max;
	per.i_HP=ensemble_perso[a].i_HP;
	per.i_PA=ensemble_perso[a].i_PA;
	per.i_PM=ensemble_perso[a].i_PM;
	per.coord[0]=ensemble_perso[a].coord[0];
	per.coord[1]=ensemble_perso[a].coord[1];
	per.c_team=ensemble_perso[a].c_team;
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

void creation(t_perso perso, char classe[20], char c_team, int x, int y)
{
	t_perso per;
	if(strcmp(classe,"Archer")==0)
	{
		strcpy(per.s_classe,"Archer");
		initialisation_perso(1, per);
		per.coord[0]=x;
		per.coord[1]=y;
		per.c_team=c_team;
	}
	else if(strcmp(classe,"Guerrier")==0)
	{
		strcpy(per.s_classe,"Guerrier");
		initialisation_perso(0, per);
		per.coord[0]=x;
		per.coord[1]=y;
		per.c_team=c_team;
	}
	else if(strcmp(classe,"Mage")==0)
	{
		strcpy(per.s_classe,"Mage");
		initialisation_perso(2, per);
		per.coord[0]=x;
		per.coord[1]=y;
		per.c_team=c_team;
	}
}


