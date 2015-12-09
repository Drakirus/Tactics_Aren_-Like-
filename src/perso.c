#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "../include/perso.h"

t_perso ensemble_perso[3]=
{
	{"Guerrier",50,50,3,3,{0,0},'A'},
	{"Archer",30,30,3,3,{0,0},'A'},
	{"Mage",20,20,2,2,{0,0},'A'}
};

void creation(t_perso tab_perso[6], int i_position_tableau, char classe[20], char c_team, int x, int y)
{
	t_perso per;
	if(strcmp(classe,"Archer")==0)
	{
		strcpy(per.s_classe,"Archer");
		per.i_HP_max=ensemble_perso[1].i_HP_max;
		per.i_HP=ensemble_perso[1].i_HP;
		per.i_PA=ensemble_perso[1].i_PA;
		per.i_PM=ensemble_perso[1].i_PM;
		per.coord[0]=x;
		per.coord[1]=y;
		per.c_team=c_team;
		tab_perso[i_position_tableau]=per; //On ajoute le perso au tableau.
	}
	else if(strcmp(classe,"Guerrier")==0)
	{
		strcpy(per.s_classe,"Guerrier");
		per.i_HP_max=ensemble_perso[0].i_HP_max;
		per.i_HP=ensemble_perso[0].i_HP;
		per.i_PA=ensemble_perso[0].i_PA;
		per.i_PM=ensemble_perso[0].i_PM;
		per.coord[0]=x;
		per.coord[1]=y;
		per.c_team=c_team;
		tab_perso[i_position_tableau]=per; 
	}
	else if(strcmp(classe,"Mage")==0)
	{
		strcpy(per.s_classe,"Mage");
		per.i_HP_max=ensemble_perso[2].i_HP_max;
		per.i_HP=ensemble_perso[2].i_HP;
		per.i_PA=ensemble_perso[2].i_PA;
		per.i_PM=ensemble_perso[2].i_PM;
		per.coord[0]=x;
		per.coord[1]=y;
		per.c_team=c_team;
		tab_perso[i_position_tableau]=per; 
	}
}