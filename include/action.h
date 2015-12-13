#ifndef __map_size__
#define i_taille_map 10
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pile{
  int row;
  int column;
  struct pile *prec;
 }pile;

int **allocateBoard(int r, int c, int from[r][c]);

float getSlope(float f_a, float f_b);
int shoot(int map[i_taille_map][i_taille_map], int i_player_x, int i_player_y, int i_attaque_x, int i_attaque_y);

void setAdjacent(int **mat, int visited[i_taille_map][i_taille_map], int i, int j, int value);
int smallestVisited(int **a, int visited[i_taille_map][i_taille_map]);
int **createDistancePath(int map[i_taille_map][i_taille_map], int init_x, int init_y);
void displayBoard(int r, int c, int **arr);
int **allocateBoard(int r, int c, int from[r][c]);
int distanceFrom(int to_x, int to_y, 	int **DistancePath);
void freeBoard(int **arr, int Rows);

int pop(pile **p, int * r, int * c);
void push(pile **p, int r, int c);

pile *getPath(int **DistancePath, int i, int j);
