#ifndef _ACTION_H_
#define _ACTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "map.h"
#include "perso.h"


typedef struct pile{
  int row;
  int column;
  struct pile *prec;
 }pile;

int **allocateBoard(int r, int c, int from[r][c]);

float getSlope(float f_a, float f_b);
int shoot(int i_player_x, int i_player_y, int i_attaque_x, int i_attaque_y);

int setAdjacent(int **mat, int i, int j, int value);
int **createDistancePath(int init_x, int init_y);
void displayBoard(int r, int c, int **arr);
int **allocateBoard(int r, int c, int from[r][c]);
int distanceFrom(int to_x, int to_y, 	int **DistancePath);
void freeBoard(int **arr, int Rows);

int pop(pile **p, int * r, int * c);
void push(pile **p, int r, int c);

pile *getPath(int **DistancePath, int i, int j);

void deplacement(int * PM_actuel);
void delay(int milliseconds);
pile *getMovePerso(int * PM_tour, int start_r,int start_c);
void attaque(int * PA_tour);


void shadowcasting(int matrix[i_taille_map][i_taille_map], int i_player_x, int i_player_y);
#endif
