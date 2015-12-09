#ifndef __map_size__
#define i_taille_map 10
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialise_map(int map[i_taille_map][i_taille_map]);
void obstacle(int i_chance_obstacle, int map[i_taille_map][i_taille_map]);
void afficher_map(int map[i_taille_map][i_taille_map]);
