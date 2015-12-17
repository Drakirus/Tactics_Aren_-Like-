#ifndef _ATTACK_H_
#define _ATTACK_H_

typedef struct attak t_attak;
typedef struct list_caract t_list_caract;

struct list_caract{
  int HP_max;
  int HP;
  int PA;
  int PM;
  int coord_r;
  int coord_c;
  int team;
};

struct attak{
  char attack_name[20];
	int range_max;
  int range_min;
	int cost_PA;
  int splash_range;
  int only_line;
	t_list_caract trait;
};

t_attak *createAttack(
  char attack_name[20],
  int range_max,
  int range_min,
  int cost_PA,
  int splash_range,
  int only_line,
	int num_trait,
	...
);
void displayAttack(t_attak * att);


#endif
