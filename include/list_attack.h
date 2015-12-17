#ifndef _LIST_ATTACK_H_
#define  _LIST_ATTACK_H_

#include <stdarg.h>
#include "./attack.h"

typedef struct list_attack list_attack;

struct list_attack{
	t_attak * current_attack;
	struct list_attack *next;
};

void displaylistAttack(list_attack *perso_att, int nbatt);
void pushAttack(list_attack **p, t_attak *new_att);
int getCountAttack(list_attack *perso_att);
t_attak *getAttack(list_attack *attack, int nbatt);

#endif
