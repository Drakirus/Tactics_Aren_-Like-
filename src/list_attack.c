/**
 * \file list_attack.c
 * \brief Module contenant les attaques de chaque personnage sous forme de liste.
 * \author CHAMPION Pierre
 * \version 0.1
 * \date 18 décembre 2015
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>
#include "../include/list_attack.h"

/**
 * \fn void displaylistAttack(list_attack *perso_att)
 * \param perso_att
 * \return
 * \brief
 *
 */
void displaylistAttack(list_attack *perso_att){
  list_attack *tmp = perso_att;
  int actual = 1;

  if(!tmp){
    fprintf(stderr, "pas d'attack ..\n");
  }

  while(tmp->current_attack != NULL){

    if(tmp->current_attack != NULL){
      printf("\n    %i - ",actual);
      displayAttack(tmp->current_attack);
      printf("\n");
    }
    tmp = tmp->next;
    actual++;
  }
}

/**
 * \fn list_attack* creer_liste_attack()
 * \return
 * \brief
 *
 */
list_attack* creer_liste_attack(){
  list_attack *tmp = malloc(sizeof(list_attack));
  if(!tmp)
    exit(EXIT_FAILURE);     /* If the allocation failed. */
  tmp->current_attack = NULL;
  return tmp;
}

/**
 * \fn void pushAttack(list_attack *p, t_attak *new_att)
 * \param p
 * \param new_att
 * \return
 * \brief
 *
 */
void pushAttack(list_attack *p, t_attak *new_att){
  if(p!=NULL) {
    while(p->current_attack != NULL) {
      p = p->next;
    }
    p->current_attack = new_att;
    p->next = creer_liste_attack();
  }
}

/**
 * \fn int getCountAttack(list_attack *perso_att)
 * \param pers_att
 * \return
 * \brief
 *
 */
int getCountAttack(list_attack *perso_att){
  list_attack *tmp = perso_att;
  int actual = 1;
  while(tmp->current_attack != NULL){
    tmp =tmp->next;
    actual++;
    if (tmp->current_attack != NULL)  {
      tmp =tmp->next;
    }
  }
  return actual;
}

/**
 * \fn t_attak *getAttack(list_attack *attack, int nbatt)
 * \param attack
 * \param nbatt
 * \return
 * \brief
 *
 */
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
