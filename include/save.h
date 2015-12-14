#ifndef __SAVE_H__
#define __SAVE_H__

#include "perso.h"

void charge();
void save();
void sauv_perso(char * sauv, t_perso perso);
void charge_perso(FILE * fic, t_perso perso);

#endif
