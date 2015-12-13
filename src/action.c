//Ce module servira à créer la map de base dans laquelle les personnages vont se battre.

#include "../include/action.h"
#include "../include/tableau.h"
#include "../include/map.h"
#include "../include/perso.h"
extern int map[i_taille_map][i_taille_map];


/*
* ===========================================
*	FONCTION D'ATTAQUE
* ===========================================
*/
void attaque(t_perso per)
{
	int b_sortie=0; //Condition de sortie
	int **DistancePath;
	while(b_sortie==0)
	{
		int coord_att[2]; //Les coordonnées cibles du joueur
		if(strcmp(per.s_classe, "Guerrier")==0)
		{
			printf("Veuillez rentrer les coordonnées du personnages que vous voulez attaquer : ");
			scanf("%i%i", &coord_att[0], &coord_att[1]);
			printf("%i %i\n", per.coord[0], per.coord[1]);
			DistancePath = createDistancePath(per.coord[0], per.coord[1]);
			displayBoard(i_taille_map,i_taille_map,DistancePath);
			if(distanceFrom(coord_att[0], coord_att[1], DistancePath)!=1)
			{
				printf("Le guerrier ne peut attaquer si loin!\n");
			}
			else
			{
				if(map[coord_att[0]][coord_att[1]]==0 || map[coord_att[0]][coord_att[1]]==1) //On vérifie qu'il attaque bien une cible convenable
				{
					printf("Il n'y a rien à attaquer\n");
				}
				else
				{
					printf("Vous avez infligé 5 points de dégats. \n");
					int i_pos_perso_attaque=recherche_perso_tab(coord_att[0], coord_att[1]); //position du perso attaqué
					augmente_nombre(2, &tab_perso[i_pos_perso_attaque], -5); //Inflige les points de dégâts au perso
					afficher_perso(tab_perso[i_pos_perso_attaque]);
					b_sortie=1;
				}
			}
		}
	}
}


/*
* ===========================================
*	FONCTION LIGNE DE VUE
  http://krosmaster.herazade.com/
	http://www.roguebasin.com/index.php?title=FOV_using_recursive_shadowcasting
* ===========================================
*/
float getSlope(float f_a, float f_b){ // Basic division function (with check)
	if(f_b == 0){
		return 99;
	}
	return f_a/f_b;
}

int shoot(int i_player_y, int i_player_x, int i_attaque_y, int i_attaque_x){
	/*
	* function that calculate if the sight line is obstruct by a obstacle.
	* return 0, if the shoot is possible or 1 if not!
	*
	*/
	int i,j,cx,cy;
	float slope_a, slope_b, slope_actual;
	for (i = 0; i < i_taille_map; i++)
		for (j = 0; j < i_taille_map; j++) {

			if (map[i][j] == 1) {
				if (i_player_x <= i && i_player_y <= j ) { // bottom right
					slope_a = getSlope(((i_player_y+0.5)-j) , (i_player_x+0.5)-(i+1));
					slope_b = getSlope(((i_player_y+0.5)-(j+1)) , (i_player_x+0.5)-i);
					// printf("\n %.2f slope min %.2f slope max %i i %i j en bas a droite\n", slope_a, slope_b,(j),(i)); // ICI
					cx = i_attaque_x;
					cy = i_attaque_y;
					// printf(" %i:x %i:y", cx,cy);
					slope_actual = getSlope(((i_player_y)-cx), ((i_player_x)-cy));
					// printf(" slope %.2f \n",slope_actual);
					if (cy != i || cx != j)
						if((slope_actual > slope_a ) && (slope_actual < slope_b || (slope_b < 0) ) ){
							// printf("slope %f\n", slope_actual);
							if (map[cy][cx] != 1)
								return 1;
						}
				}
				if (i_player_x >= i && i_player_y >= j ) { // top left
					slope_a = getSlope(((i_player_y+0.5)-j) , (i_player_x+0.5)-(i+1));
					slope_b = getSlope(((i_player_y+0.5)-(j+1)) , (i_player_x+0.5)-i);
					// printf("\n %.2f slope min %.2f slope max %i i %i j en haut a gauche\n", slope_a, slope_b,(j),(i)); // ICI
					cx = i_attaque_x;
					cy = i_attaque_y;
					// printf(" %i:x %i:y", cx,cy);
					slope_actual = getSlope(((i_player_y)-cx), ((i_player_x)-cy));
					// printf(" slope %.2f \n",slope_actual);
					if (cy != i || cx != j)
						if((slope_actual < slope_a || (slope_a < 0 ) ) && (slope_actual > slope_b)){
							// printf("slope %f\n", slope_actual);
							if (map[cy][cx] != 1)
								return 1;
						}
				}
				if (i_player_x >= i && i_player_y <= j ) { //top right
					slope_b = getSlope(((i_player_y-0.5)-j) , (i_player_x+0.5)-(i+1));
					slope_a = getSlope(((i_player_y-0.5)-(j-1)) , (i_player_x+0.5)-i);
					// printf("\n %.2f slope min %.2f slope max %i i %i j en haut a droite\n", slope_a, slope_b,(j),(i)); // ICI
					cx = i_attaque_x;
					cy = i_attaque_y;
					// printf(" %i:x %i:y", cx,cy);
					slope_actual = getSlope(((i_player_y)-cx), ((i_player_x)-cy));
					// printf(" slope %.2f \n",slope_actual);
					if (cy != i || cx != j)
						if((slope_actual < slope_a) && (slope_actual > slope_b || (slope_b > 0) )){
							// printf("slope %f\n", slope_actual);
							if (map[cy][cx] != 1)
								return 1;
						}
				}
				if (i_player_x <= i && i_player_y >= j ) { // bottom left
					slope_b = getSlope(((i_player_y+0.5)-j) , (i_player_x-0.5)-(i-1));
					slope_a = getSlope(((i_player_y+0.5)-(j+1)) , (i_player_x-0.5)-i);
					// printf("\n %.2f slope min %.2f slope max %i i %i j en bas a gauche \n", slope_a, slope_b,(j),(i)); // ICI
					cx = i_attaque_x;
					cy = i_attaque_y;
					// printf(" %i:x %i:y", cx,cy);
					slope_actual = getSlope(((i_player_y)-cx), ((i_player_x)-cy));
					// printf(" slope %.2f \n",slope_actual);
					if (cy != i || cx != j)
						if((slope_actual < slope_a ) && (slope_actual > slope_b || (slope_b > 0) )){
							// printf("slope %f\n", slope_actual);
							if (map[cy][cx] != 1)
								return 1;
						}
				}

			}
		}
	return 0;
}

/*
* ===========================================
*	FONCTION PATHFINDING
* http://www.redblobgames.com/pathfinding/tower-defense/
* ===========================================
*/

void setAdjacent(int **mat, int visited[i_taille_map][i_taille_map], int i, int j, int value) {
	/*
	* setAdjacent is a function call by (only) *createDistancePath*, it takes a *X* and *Y* coordinates, and print *value* to here direct neighbor.
	* *mat* is the output matix. This function check if it can place a neighbor or not (overflow), and if the new neighbor can have other(exemple : the corner).
	*/
	int dx,dy, cx,cy;
	visited[i][j] = 1;
		for (dx = (i <= 0 ? 0 : -1); dx <= (i >= i_taille_map-1 ? 0 : 1); dx++)
			for (dy = (j <= 0 ? 0 : -1); dy <= (j >= i_taille_map-1 ? 0 : 1); dy++)
				if (visited[dx+i][dy+j] == 0 && abs(dx) != abs(dy) && mat[dx+i][dy+j] != -1) {
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
	/*
	* *smallestVisited* return the number of the smallest cells in the matix *a*.
	* THIS number need to be one of the following batch of *setAdjacent* (visited == 2)
	*/
	int i,j;
	 int small=9999;
	 for(i=0;i<i_taille_map;i++)
	 	for(j=0;j<i_taille_map;j++)
			if(a[i][j]<small && visited[i][j] == 2)
				small=a[i][j];
	 return small;

}

int **createDistancePath(int init_x, int init_y){
	/*
	* *createDistancePath* return a matrix fill of distances, the center point have *init_x* and *init_y* coordinate.
	* if the matrix return have for one coordinate a value of 0 it mean that the cells is unreachable, (surrender by obstacle or stand on it)
	*/
	int r=i_taille_map, c=i_taille_map;
	int **map_path_finding =allocateBoard(r,c,map);

	int visited[i_taille_map][i_taille_map] = {{0}};

	int row=0, columns=0, actual=0;
	visited[init_x][init_y] = 2;

	for ( row=0; row<i_taille_map; row++)
			for( columns=0; columns<i_taille_map; columns++){
				actual = map_path_finding[row][columns];
				if (visited[row][columns] == 2 && (actual == smallestVisited(map_path_finding, visited))) {   // need to check if the actual coordinate are the next one to have neighbor
					setAdjacent(map_path_finding, visited, row, columns, ++actual );
					row=0;
					columns=0;
			}
		}
		return map_path_finding;
}

void displayBoard(int r, int c, int **arr){ // Display a matrix of size r,c for debuging
	int i,j;
	for (i = 0; i <  r; i++){
		for (j = 0; j < c; j++){
			if (arr[i][j] == -1)
				printf("   ");
			else
			if(arr[i][j]	>=10)
				printf("%d ", arr[i][j]);
			else
				printf("%d  ", arr[i][j]);

		}
		printf("\n" );
	}
}

int **allocateBoard(int r, int c, int from[r][c]){// create a pointer array to a pointer array and return it
	int **arr;
	int i,j;

	arr = (int **)malloc(r * sizeof(int *));
	 for (i=0; i<r; i++)
		arr[i] = (int *)malloc(c * sizeof(int));

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++){
			if (from[i][j] == 1)
				arr[i][j]=-1;
			else
				arr[i][j] = 0; // *(*(arr+i)+j)
		}
	return arr;
}

int distanceFrom(int to_x, int to_y, 	int **DistancePath){ //My teammates have so much chance
		return DistancePath[to_x][to_y];
}

void freeBoard(int **arr, int Rows){ //free the  dynamically allocated memory
  int row;
  // free de toutes les lignes
  for (row = 0; row < Rows; row++) {
   	free(arr[row]);
  }
	// free de toutes les colones
  free(arr);
 }

pile *getPath(int **DistancePath, int i, int j){
	/*
	* this function return the shortest path to a *i* *j* coordinate, where *DistancePath* is the distances matrix.
	* the path (coordinate) is stored in a pile and return.
	*/
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
 * ===========================================
  * FONCTION GESTION PILE
 * ===========================================
 */

 void push(pile **p, int r, int c){
	 pile *tmp = malloc(sizeof(pile));
	 if(!tmp) exit(EXIT_FAILURE);     /* If the allocation failed. */
	 tmp->row = r;
	 tmp->column = c;
	 tmp->prec = *p;
	 *p = tmp;
 }

 int pop(pile **p, int * r, int * c){
    pile *tmp;
    if(!*p) return -1;     /* Returns -1 if the pile is empty. */
    tmp = (*p)->prec;
		*r = (*p)->row;
		*c = (*p)->column;
    free(*p);
    *p = tmp;       /* The pointer points to the last element. */
		return 1;
}
/*
*
* ===========================================
* AUTRE ...
* ===========================================
*/
