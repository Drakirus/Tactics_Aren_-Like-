#ifndef __TABLEAU_H__
#define __TABLEAU_H__

#include "perso.h"
#define i_taille_tab_perso 10

t_perso tab_perso[i_taille_tab_perso]; //Contient les données de tous les persos.

void afficher_tableau();
int recherche_perso_tab(int x, int y);
void init_tab_perso(t_perso tab_perso[i_taille_tab_perso]);
void freeAllListAttack();
#endif
