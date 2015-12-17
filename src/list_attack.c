#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>
#include "../include/list_attack.h"


void displaylistAttack(list_attack *perso_att){
  list_attack *tmp = perso_att;
  int actual = 1;

  if(!tmp){
    fprintf(stderr, "pas d'attack ..\n");
  }

  while(tmp != NULL){

    if(tmp->current_attack != NULL){
      printf("\n    %i - ",actual);
      displayAttack(tmp->current_attack);
      printf("\n");
    }
    tmp = tmp->next;
    actual++;
  }
}

list_attack* creer_liste_attack(){
  list_attack *tmp = malloc(sizeof(list_attack));
  if(!tmp)
    exit(EXIT_FAILURE);     /* If the allocation failed. */
  tmp->current_attack = NULL;
  return tmp;
}

void pushAttack(list_attack *p, t_attak *new_att){
  if(p!=NULL) {
    while(p->current_attack != NULL) {
      p = p->next;
    }
    p->current_attack = new_att;
    p->next = creer_liste_attack();
  }
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
