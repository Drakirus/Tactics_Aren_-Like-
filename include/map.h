#ifndef __GENER_MAP_H__
#define __GENER_MAP_H__


#define i_taille_map 10
#include "../include/couleur.h"
#include "../include/attack.h"
void initialise_map();
void obstacle(int i_chance_obstacle);
void afficher_map();
void afficher_map_accessible(int **DistancePath, int map_shadowcasting[i_taille_map][i_taille_map],int range_max, int range_min , int ligne , int r_start, int c_start );
#endif
