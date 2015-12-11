

#include "perso.h"

void init_liste(void);
int liste_vide(void);
int hors_liste(void);
void en_tete(void);
void en_queue(void);
void precedent(void);
void suivant(void);
void valeur_elt(t_perso* p);
void modif_elt(t_perso p);
void oter_elt(void);
void ajout_droit(t_perso p);
void ajout_gauche(t_perso p);
//void sauv_perso(char sauv[40]);
void pointeur_perso(t_perso * p_elt);
void afficher_liste();