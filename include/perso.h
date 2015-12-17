#ifndef __PERSO_H__
#define __PERSO_H__

#define i_nombre_classe 3

#include "./list_attack.h"

typedef struct
{
	char s_classe[20];
	int i_HP_max;
	int i_HP;
	int i_PA;
	int i_PM;
	int coord[2];
	char c_team;
	list_attack * att;	
}t_perso;

void afficher_perso(t_perso perso);
void creation(t_perso * per, int i_classe, char c_team, int x, int y);
void initialisation_perso(int a, t_perso * per);
void augmente_nombre(int a, t_perso * per, int i_montant);
void change_nombre(int a, t_perso * per, int i_montant);
int est_mort(t_perso perso);

#endif
