#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>
#include "../include/list_attack.h"


void displaylistAttack(list_attack *perso_att, int nbatt){
  list_attack *tmp = perso_att;
  int actual = 1;
  while(tmp != NULL){
    if (actual == nbatt || nbatt == 0) {
      printf("\n    %i - ",actual);
      displayAttack(tmp->current_attack);
      tmp =tmp->next;
    }
    actual++;
    if ((tmp != NULL) && nbatt != 0 ) {
      tmp =tmp->next;
    }
  }
}

void pushAttack(list_attack **p, t_attak *new_att){
  list_attack *tmp = malloc(sizeof(list_attack));
  if(!tmp) exit(EXIT_FAILURE);     /* If the allocation failed. */
  tmp->current_attack = new_att;
  tmp->next = *p;
  *p = tmp;
}

int getCountAttack(list_attack *perso_att){
  list_attack *tmp = perso_att;
  int actual = 1;
  while(tmp != NULL){
    tmp =tmp->next;
    actual++;
    if (tmp != NULL)  {
      tmp =tmp->next;
    }
  }
  return actual-1;
}

t_attak *getAttack(list_attack *attack, int nbatt){
  list_attack *tmp = attack;
  int actual=1;
  while(tmp != NULL){
    if (actual == nbatt) {
      return(tmp->current_attack);
    }
    actual++;
    tmp =tmp->next;
  }
  return NULL;
}
