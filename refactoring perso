#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct perso t_perso;
typedef struct attak t_attak;

struct perso{
	char classe[20];
	int HP_max;
	int HP;
	int PA;
	int PM;
  int coord_r;
	int coord_c;
	int team;
  int placed;
};

struct attak{
  char attack_name[20];
  int range_max;
  int range_min;
  int splash_range;
  int only_line;
};

t_perso *createUniter(
  char classe[20],
  int HP_max,
  int HP,
  int PA,
  int PM,
  int coord_r,
  int coord_c,
  int team
){
  t_perso * newPerso = NULL;
  newPerso = (t_perso *)malloc(sizeof(t_perso));

  strcpy(newPerso->classe,classe);
  newPerso->HP_max=HP_max;
  newPerso->HP=HP;
  newPerso->PA=PA;
  newPerso->PM=PM;
  newPerso->coord_r=coord_r;
  newPerso->coord_c=coord_c;
  newPerso->team=team;
  newPerso->placed=0;
  return newPerso;
}


t_attak *createAttack(
  char attack_name[20],
  int range_max,
  int range_min,
  int splash_range,
  int only_line
){
  t_attak * newAttak = NULL;
  newAttak = (t_attak *)malloc(sizeof(t_attak));

  strcpy(newAttak->attack_name,attack_name);
  newAttak->range_max=range_max;
  newAttak->range_min=range_min;
  newAttak->splash_range=splash_range;
  newAttak->only_line=only_line;
  return newAttak;
}

void attak(t_perso * a, int dmg){
  a->HP -=dmg;
}

int main(int argc, char const *argv[]) {

  t_perso * guerrier = createUniter("Guerrier",50,49,2,3,0,0,1);

  printf("%s %i/%i %ipm %ipa %ix%i team %i placed %i\n",
  guerrier->classe, guerrier->HP_max, guerrier->HP, guerrier->PA, guerrier->PM, guerrier->coord_r, guerrier->coord_c, guerrier->team, guerrier->placed );

  attak(guerrier,5);
  guerrier->placed=1;
  free(guerrier);
  printf("%s %i/%i %ipm %ipa %ix%i team %i placed %i\n",
  guerrier->classe, guerrier->HP_max, guerrier->HP, guerrier->PA, guerrier->PM, guerrier->coord_r, guerrier->coord_c, guerrier->team, guerrier->placed );

  t_attak * att = createAttack("basic hit", 1,0,1,0);

  printf("%s range max %i min %i / %i splash_range line ? %i\n",
  att->attack_name, att->range_max, att->range_min, att->splash_range, att->only_line );
  return 0;
}
