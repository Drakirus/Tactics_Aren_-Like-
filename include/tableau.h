#include "perso.h"
#define i_taille_tab_perso 6

t_perso tab_perso[i_taille_tab_perso]; //Contient les données de tous les persos.

void sauv_perso(char * sauv, t_perso perso);
void afficher_tableau(t_perso tab[i_taille_tab_perso]);
int recherche_perso_tab(int x, int y, t_perso tab[i_taille_tab_perso]);
