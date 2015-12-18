/**
 * \file attack.c
 * \brief Module gérant les créations de chaque attaque
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
#include "../include/attack.h"

/**
 * \fn void displayAttack(t_attak * att)
 * \param att
 * \return
 * \brief
 *
 */
void displayAttack(t_attak * att){
	printf("Attaque/Sort '%s' à pour range : max %i min %i, %i cost",att->attack_name, att->range_max, att->range_min, att->cost_PA);
	if (att->splash_range > 1)
		printf("\n\tC'est une attaque de zone sur %i case ",att->splash_range);
	if (att->only_line)
		printf(" --> uniquement en face du personnage ");
	if (att->trait.HP < 0)
		printf("\n\tFait %i dégats ",att->trait.HP);
	if (att->trait.HP > 0)
		printf("\n\tSoigne de %i pv",att->trait.HP);
	if (att->trait.HP_max != 0)
		printf("\n\tChange les pv max à %i ",att->trait.HP_max);
	if (att->trait.PA != 0)
		printf("\n\tChange les P d'action à %i ",att->trait.PA);
	if (att->trait.PM != 0)
		printf("\n\tChange les P de mouvement à %i ",att->trait.PM);
	if (att->trait.coord_r != 0 || att->trait.coord_c != 0)
		printf("\n\tFait reculer le perso de %ix%i ",att->trait.coord_r, att->trait.coord_c);
	if (att->trait.team != -1)
		printf("\n\tChange le perso dans l'équipe %i ",att->trait.team);
  printf("\n");
}

/**
 * \fn t_attak *createAttack(char attack_name[20],int range_max,int range_min,int cost_PA,int splash_range,int only_line,int num_trait,...)
 * \param attack_name
 * \param range_max
 * \param range_min
 * \param cost_PA
 * \param splash_range
 * \param only_line
 * \param num_trait
 * \param ...
 * \return
 * \brief
 *
 */
t_attak *createAttack(
  char attack_name[20],
  int range_max,
  int range_min,
  int cost_PA,
  int splash_range,
  int only_line,
	int num_trait,
	...
){
  t_attak * newAttak = NULL;
  newAttak = (t_attak *)malloc(sizeof(t_attak));

  strcpy(newAttak->attack_name,attack_name);
  newAttak->range_max=range_max;
  newAttak->range_min=range_min;
  newAttak->splash_range=splash_range;
  newAttak->only_line=only_line;
  newAttak->cost_PA=cost_PA;

	newAttak->trait.HP=0;
	newAttak->trait.HP_max=0;
	newAttak->trait.PA=0;
	newAttak->trait.PM=0;
	newAttak->trait.coord_r=0;
	newAttak->trait.coord_c=0;
	newAttak->trait.team=-1;

	va_list trait;
	num_trait+=num_trait;
	va_start(trait, num_trait);
	int i;
	int tmp_value;
	char tmp[20];
	for (i = 0; i < num_trait; i++) {
			if (i % 2 == 0) {
				sprintf(tmp, "%s", va_arg(trait, char*));
			}else{

				if (strcmp(tmp, "HP") == 0) {
					tmp_value = va_arg(trait, int);
					newAttak->trait.HP = tmp_value;
				}else

				if (strcmp(tmp, "HP_max") == 0) {
					tmp_value = va_arg(trait, int);
					newAttak->trait.HP_max = tmp_value;
				}else

				if (strcmp(tmp, "PA") == 0) {
					tmp_value = va_arg(trait, int);
					newAttak->trait.PA = tmp_value;
				}else

				if (strcmp(tmp, "PM") == 0) {
					tmp_value = va_arg(trait, int);
					newAttak->trait.PM = tmp_value;
				}else

				if (strcmp(tmp, "coord_r") == 0) {
					tmp_value = va_arg(trait, int);
					newAttak->trait.coord_r = tmp_value;
				}else

				if (strcmp(tmp, "coord_c") == 0) {
					tmp_value = va_arg(trait, int);
					newAttak->trait.coord_c = tmp_value;
				}else

				if (strcmp(tmp, "team") == 0) {
					tmp_value = va_arg(trait, int);
					newAttak->trait.team = tmp_value;
				}

				else{
					tmp_value = va_arg(trait, int);
				}

			}
  }
	va_end(trait);
  return newAttak;
}
