//Ce module servira à créer la map de base dans laquelle les personnages vont se battre.

#include "../include/action.h"

extern int map[i_taille_map][i_taille_map];
/*
* ===========================================
*			FONCTION LIGNE DE VUE
* ===========================================
*/
float getSlope(float f_a, float f_b){
	if(f_b == 0){
		return 99;
	}
	return f_a/f_b;
}

int shoot(int i_player_y, int i_player_x, int i_attaque_y, int i_attaque_x){
	int i,j,cx,cy;
	float f_slope_min, f_slope_max, f_slope;
	for (i = 0; i < i_taille_map; i++) {
		for (j = 0; j < i_taille_map; j++) {
			if (map[i][j] == 1) {
				if (i_player_x <= i && i_player_y <= j ) { // en bas a droite
					f_slope_min = getSlope(((i_player_y+0.5)-j) , (i_player_x+0.5)-(i+1));
					f_slope_max = getSlope(((i_player_y+0.5)-(j+1)) , (i_player_x+0.5)-i);
					// printf("\n %.2f slope min %.2f slope max %i i %i j en bas a droite\n", f_slope_min, f_slope_max,(j),(i)); // ICI
					cx = i_attaque_x;
					cy = i_attaque_y;
					// printf(" %i:x %i:y", cx,cy);
					f_slope = getSlope(((i_player_y)-cx), ((i_player_x)-cy));
					// printf(" slope %.2f \n",f_slope);
					if (cy != i || cx != j) {
						if((f_slope > f_slope_min ) && (f_slope < f_slope_max || (f_slope_max < 0) ) ){
							// printf("slope %f\n", f_slope);
							if (map[cy][cx] != 1) {
								return 1;
							}
						}
					}
				}
				if (i_player_x >= i && i_player_y >= j ) { // en haut a gauche
					f_slope_min = getSlope(((i_player_y+0.5)-j) , (i_player_x+0.5)-(i+1));
					f_slope_max = getSlope(((i_player_y+0.5)-(j+1)) , (i_player_x+0.5)-i);
					// printf("\n %.2f slope min %.2f slope max %i i %i j en haut a gauche\n", f_slope_min, f_slope_max,(j),(i)); // ICI
					cx = i_attaque_x;
					cy = i_attaque_y;
					// printf(" %i:x %i:y", cx,cy);
					f_slope = getSlope(((i_player_y)-cx), ((i_player_x)-cy));
					// printf(" slope %.2f \n",f_slope);
					if (cy != i || cx != j) {
						if((f_slope < f_slope_min || (f_slope_min < 0 ) ) && (f_slope > f_slope_max)){
							// printf("slope %f\n", f_slope);
							if (map[cy][cx] != 1) {
								return 1;
							}
						}
					}
				}
				if (i_player_x >= i && i_player_y <= j ) { // en haut a droite
					f_slope_max = getSlope(((i_player_y-0.5)-j) , (i_player_x+0.5)-(i+1));
					f_slope_min = getSlope(((i_player_y-0.5)-(j-1)) , (i_player_x+0.5)-i);
					// printf("\n %.2f slope min %.2f slope max %i i %i j en haut a droite\n", f_slope_min, f_slope_max,(j),(i)); // ICI
					cx = i_attaque_x;
					cy = i_attaque_y;
					// printf(" %i:x %i:y", cx,cy);
					f_slope = getSlope(((i_player_y)-cx), ((i_player_x)-cy));
					// printf(" slope %.2f \n",f_slope);
					if (cy != i || cx != j) {
						if((f_slope < f_slope_min) && (f_slope > f_slope_max || (f_slope_max > 0) )){
							// printf("slope %f\n", f_slope);
							if (map[cy][cx] != 1) {
								return 1;
							}
						}
					}
				}
				if (i_player_x <= i && i_player_y >= j ) { // en bas a gauche
					f_slope_max = getSlope(((i_player_y+0.5)-j) , (i_player_x-0.5)-(i-1));
					f_slope_min = getSlope(((i_player_y+0.5)-(j+1)) , (i_player_x-0.5)-i);
					// printf("\n %.2f slope min %.2f slope max %i i %i j en bas a gauche \n", f_slope_min, f_slope_max,(j),(i)); // ICI
					cx = i_attaque_x;
					cy = i_attaque_y;
					// printf(" %i:x %i:y", cx,cy);
					f_slope = getSlope(((i_player_y)-cx), ((i_player_x)-cy));
					// printf(" slope %.2f \n",f_slope);
					if (cy != i || cx != j) {
						if((f_slope < f_slope_min ) && (f_slope > f_slope_max || (f_slope_max > 0) )){
							// printf("slope %f\n", f_slope);
							if (map[cy][cx] != 1) {
								return 1;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

/*
*
* ===========================================
*			FIN DE LA FONCTION LIGNE DE VUE
* ===========================================
*			FONCTION PATHFINDING
* ===========================================
*/

void setAdjacent(int **mat, int visited[i_taille_map][i_taille_map], int i, int j, int value) {
	int dx,dy, cx,cy;
	visited[i][j] = 1;
		for (dx = (i <= 0 ? 0 : -1); dx <= (i >= i_taille_map-1 ? 0 : 1); dx++)
			for (dy = (j <= 0 ? 0 : -1); dy <= (j >= i_taille_map-1 ? 0 : 1); dy++)
				if (visited[dx+i][dy+j] == 0 && abs(dx) != abs(dy) && mat[dx+i][dy+j] == 0) {
					mat[dx+i][dy+j] = value;
					for (cx = -1; cx <= 1; cx++)
						for (cy = -1; cy <= 1; cy++)
							if (dy+j+cy>=0 && dx+i+cx>=0 && dy+j+cy<i_taille_map && dx+i+cx<i_taille_map)
								if (mat[dx+i+cx][dy+j+cy] == 0 ){
									visited[dx+i][dy+j] = 2;
									cx = cy = 2; // sortir des boucles
								}
				}
}

int smallestVisited(int **a, int visited[i_taille_map][i_taille_map]){
	int i,j;
	 int small=9999;
	 for(i=0;i<i_taille_map;i++)
	 	for(j=0;j<i_taille_map;j++)
			if(a[i][j]<small && visited[i][j] == 2)
				small=a[i][j];
	 return small;

}

int **createDistancePath(int init_x, int init_y){

	int r=i_taille_map, c=i_taille_map;
	int **map_path_finding =allocateBoard(r,c,map);

	int visited[i_taille_map][i_taille_map] = {{0}};

	int row=0, columns=0, actual=0;
	visited[init_x][init_y] = 2;

	for ( row=0; row<i_taille_map; row++)
			for( columns=0; columns<i_taille_map; columns++){
				actual = map_path_finding[row][columns];
				if (visited[row][columns] == 2 && (actual == smallestVisited(map_path_finding, visited))) {   // && (map_path_finding[row][columns] == smallestVisited(map_path_finding, visited))
					setAdjacent(map_path_finding, visited, row, columns, ++actual );
					row=0;
					columns=0;
						// displayBoard(i_taille_map,i_taille_map,map_path_finding);
						// printf("--------------------------\n" );
						// afficher_map(visited);
						// printf("--------------------------\n" );
			}
						// printf("%i\n", smallestVisited(map_path_finding, visited));
		}
		return map_path_finding;
}

void displayBoard(int r, int c, int **arr){
	int i,j;
	for (i = 0; i <  r; i++){
			for (j = 0; j < c; j++){
					if (arr[i][j] != -1)
						if(arr[i][j]	>=10)
							printf("%d ", arr[i][j]);
						else
							printf("%d  ", arr[i][j]);
					else
						printf("   ");
			}
			printf("\n" );
	}
}

int **allocateBoard(int r, int c, int from[r][c]){
	int **arr;
	int i,j;

	arr = (int **)malloc(r * sizeof(int *));
	 for (i=0; i<r; i++)
				arr[i] = (int *)malloc(c * sizeof(int));

	for (i = 0; i < r; i++)
			for (j = 0; j < c; j++){
					if (from[i][j] == 0)
						arr[i][j] = from[i][j]; // *(*(arr+i)+j)
					else
						arr[i][j]=-1;
			}
	return arr;
}

int distanceFrom(int to_x, int to_y, 	int **DistancePath){
		return DistancePath[to_x][to_y];
}

void freeBoard(int **arr, int Rows){
    int row;
    // free de toutes les lignes
    for (row = 0; row < Rows; row++) {
     	free(arr[row]);
    }
		// free de toutes les colones
    free(arr);
 }

pile *getPath(int **DistancePath, int i, int j){
	pile *path = NULL;
	int dx,dy;
	int actual = DistancePath[i][j];
	actual--;
	while(DistancePath[i][j] != 0){
		for (dx = (i <= 0 ? 0 : -1); dx <= (i >= i_taille_map-1 ? 0 : 1); dx++)
			for (dy = (j <= 0 ? 0 : -1); dy <= (j >= i_taille_map-1 ? 0 : 1); dy++){

				// printf("%i %i\n",dx+i, dy+j);
				actual = DistancePath[i][j];
				actual--;
				if (abs(dx) != abs(dy) && actual == DistancePath[dx+i][dy+j]) {
					// DistancePath[dx+i][dy+j] = value;
					i = dx+i;
					j = dy+j;
					dx = 2;
					dy = 2;
					push(&path, i, j);
					// printf("%i %i\n",i, j );
				}
			}
	}
	return path;
}
 /*
 *
 * ===========================================
 * FIN DE LA FONCTION PATHFINDING
 * ===========================================
  * FONCTION GESTION PILE
 * ===========================================
 */

 void push(pile **p, int r, int c){
	 pile *tmp = malloc(sizeof(pile));
	 if(!tmp) exit(EXIT_FAILURE);     /* Si l'allocation a échouée. */
	 tmp->row = r;
	 tmp->column = c;
	 tmp->prec = *p;
	 *p = tmp;
 }

 int pop(pile **p, int * r, int * c){
        pile *tmp;
        if(!*p) return -1;     /* Retourne -1 si la pile est vide. */
        tmp = (*p)->prec;
				*r = (*p)->row;
				*c = (*p)->column;
        free(*p);
        *p = tmp;       /* Le pointeur pointe sur le dernier élément. */
				return 1;
}
/*
*
* ===========================================
* FIN GESTION PILE
* ===========================================
*/
