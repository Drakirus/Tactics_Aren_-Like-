//Ce module servira à créer la map de base dans laquelle les personnages vont se battre.

#include "../include/action.h"
#include "../include/tableau.h"
#include "../include/map.h"
#include "../include/perso.h"
extern int map[i_taille_map][i_taille_map];
extern int i_perso_actuel;

/*
* ===========================================
*	FONCTION DE DÉPLACEMENT
* ===========================================
*/

void delay(int milliseconds){
    long pause;
    clock_t now,then;
    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void deplacement(int PM_actuel){
	pile *path = NULL; // move personnage
	int r,c; // move personnage
	int sortir; // move personnage
	int value_perso;
	path = getMovePerso(&PM_actuel, tab_perso[i_perso_actuel].coord[1], tab_perso[i_perso_actuel].coord[0] );
	if (path == NULL) printf("Déplacement imposible\n");
	else{
		sortir = pop(&path, &r, &c);
		value_perso = map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]];
		afficher_map();
		system("clear");
		while (sortir != -1) {
			if (map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]] == 0 || value_perso ==  map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]]) {
				map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]] = 0;
  			}
			sortir = pop(&path, &r, &c);
			// printf("r: %i c: %i\n",r,c );
			change_nombre(5,&tab_perso[i_perso_actuel], c);
			change_nombre(6, &tab_perso[i_perso_actuel], r);
			if (map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]] == 0 || value_perso ==  map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]]) {
				map[tab_perso[i_perso_actuel].coord[1]][ tab_perso[i_perso_actuel].coord[0]] = value_perso;
			}
			system("clear");
			afficher_map();
			delay(400);
		}
	}
}

pile *getMovePerso(int * PM_tour, int start_r,int start_c){
	if (*PM_tour == 0) {
		return NULL;
	}
	int coord_r,coord_c;
	pile *path;
	int **DistancePath = createDistancePath(start_r, start_c);
	int distanceOfPath;
	do {
		printf("Choisissez les coordonnées (x y) (-1 -1 pour annuler): ");
		scanf("%i%i", &coord_r, &coord_c);
		if (coord_r == -1 || coord_c == -1) {
			return NULL;
		}
		if (coord_r < i_taille_map && coord_c < i_taille_map && coord_r>=0 && coord_c>=0) {
			distanceOfPath = distanceFrom(coord_r, coord_c, DistancePath);
		}
		if ( distanceOfPath > *PM_tour) {
			printf("\n trop loin\n");
		}
	} while(coord_r > i_taille_map || coord_c > i_taille_map || coord_r<0 || coord_c<0 || distanceOfPath > *PM_tour ||  map[coord_r][coord_c] != 0);

 if (distanceOfPath>0) {
	 *PM_tour -=distanceOfPath;
	//  displayBoard(i_taille_map, i_taille_map,DistancePath);
	 path = getPath(DistancePath, coord_r, coord_c);
	 freeBoard(DistancePath, i_taille_map);
	 return path;
 }
 freeBoard(DistancePath, i_taille_map);
 return NULL;
}
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
			DistancePath = createDistancePath(per.coord[0], per.coord[1]);
			if(distanceFrom(coord_att[0], coord_att[1], DistancePath)!=1)
			{
				printf("Le guerrier ne peut attaquer si loin!\n");
			}
			else if(distanceFrom(coord_att[0], coord_att[1], DistancePath)==0)
			{
				printf("Je ne pense pas que vous soyez assez bête pour vous attaquer vous même si?\n");
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
		else if(strcmp(per.s_classe, "Archer")==0)
		{
			printf("Veuillez rentrer les coordonnées du personnages que vous voulez attaquer : ");
			scanf("%i%i", &coord_att[0], &coord_att[1]);
			int **DistancePath = createDistancePath(per.coord[0], per.coord[1]);
			if(distanceFrom(coord_att[0], coord_att[1], DistancePath)>3)
			{
				printf("L'archer ne peut attaquer si loin!\n");
			}
			else if(distanceFrom(coord_att[0], coord_att[1], DistancePath)==0)
			{
				printf("Je ne pense pas que vous soyez assez bête pour vous attaquer vous même si?\n");
			}
			else if (shoot(per.coord[0], per.coord[1], coord_att[0], coord_att[1])!=0)
			{
				printf("Un obstacle vous empêche d'atteindre votre cible.\n");
			}
			else
			{
				if(map[coord_att[0]][coord_att[1]]==0 || map[coord_att[0]][coord_att[1]]==1) //On vérifie qu'il attaque bien une cible convenable
				{
					printf("Il n'y a rien à attaquer\n");
				}
				else
				{
					printf("Vous avez infligé 4 points de dégats. \n");
					int i_pos_perso_attaque=recherche_perso_tab(coord_att[0], coord_att[1]); //position du perso attaqué
					augmente_nombre(2, &tab_perso[i_pos_perso_attaque], -3); //Inflige les points de dégâts au perso
					afficher_perso(tab_perso[i_pos_perso_attaque]);
					b_sortie=1;
				}
			}
		}
		else if(strcmp(per.s_classe, "Mage")==0)
		{
			printf("Veuillez rentrer les coordonnées du personnages que vous voulez attaquer : ");
			scanf("%i%i", &coord_att[0], &coord_att[1]);
			int **DistancePath = createDistancePath(per.coord[0], per.coord[1]);
			if(distanceFrom(coord_att[0], coord_att[1], DistancePath)>4)
			{
				printf("Le mage ne peut attaquer si loin!\n");
			}
			else
			{
				printf("Vous avez infligé 3 points de dégats. \n");
				int i_pos_perso_attaque, i, j;
				for(i=-1;i<2;i++)
				{
					for(j=-1;j<2;j++)
					{
						if(recherche_perso_tab(coord_att[0]+i,coord_att[1]+j)!=-1) //On regarde s'il y a un perso ou non (recher_perso_tab retourne -1 s'il n'y a personne)
						{
							i_pos_perso_attaque=recherche_perso_tab(coord_att[0]+i, coord_att[1]+j);
							augmente_nombre(2, &tab_perso[i_pos_perso_attaque], -3);
							afficher_perso(tab_perso[i_pos_perso_attaque]);
						}
					}
				}
				b_sortie=1;
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
	* function that calculate if the sight line is obstructed by a obstacle.
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

int setAdjacent(int **mat, int i, int j, int value) {
	/*
	* setAdjacent is a function call by (only) *createDistancePath*, it takes a *X* and *Y* coordinates, and print *value* to here direct neighbor.
	* *mat* is the output matix. This function checks if it can place a neighbor or not (overflow), and if the new neighbor can have other(exemple : the corner).
	*/
	int dx,dy;
	int nbUpdate = 0;
		for (dx = (i <= 0 ? 0 : -1); dx <= (i >= i_taille_map-1 ? 0 : 1); dx++)
			for (dy = (j <= 0 ? 0 : -1); dy <= (j >= i_taille_map-1 ? 0 : 1); dy++){
				// printf("coord adja %i %i\n",dx+i,dy+j );
				if (abs(dx) != abs(dy) && mat[dx+i][dy+j] == -1) {
					mat[dx+i][dy+j] = value;
					nbUpdate++;
				}
			}
	return nbUpdate;
}


int **createDistancePath(int init_x, int init_y){
	/*
	* *createDistancePath* return a matrix fill of distances, the center point have *init_x* and *init_y* coordinate.
	* if the matrix return have for one coordinate a value of 0 it mean that the cells is unreachable, (surrender by obstacle or stand on it)
	*/
	int **map_path_finding =allocateBoard(i_taille_map,i_taille_map,map);

	int row=0, columns=0, actual=0, nbUpdate = 1;

	map_path_finding[init_x][init_y] = 0;

	// init mat : point de départ = valeur_actuelle
	// displayBoard(i_taille_map,i_taille_map,map_path_finding);


	// tant que cible non atteinte ou matrice pas pleine
while(nbUpdate != 0){
	nbUpdate = 0;
	// parcours de la matrice
	for ( row=0; row<i_taille_map; row++)
			for( columns=0; columns<i_taille_map; columns++){

	// si case = valeur_actuelle
				if (map_path_finding[row][columns] == actual) {
					// fprintf(stderr, "%i == %i",map_path_finding[row][columns],  actual);
					// case_adjacente = vleur_actuelle +1
					nbUpdate += setAdjacent(map_path_finding, row, columns, actual+1);

					// displayBoard(i_taille_map,i_taille_map,map_path_finding);
					// printf("\n");

				}
		}
			// fprintf(stderr, "update %i\n", nbUpdate);
			actual++;
	}
		return map_path_finding;
}

void displayBoard(int r, int c, int **arr){ // Display a matrix of size r,c for debuging
	int i,j;
	for (i = 0; i <  r; i++){
		for (j = 0; j < c; j++){
			if (arr[i][j] == -2)
				printf("   ");
			else
			if(arr[i][j]	>=10)
				printf("%2d ", arr[i][j]);
			else
				printf("%2d ", arr[i][j]);

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
				arr[i][j]=-2;
			else
				arr[i][j] = -1; // *(*(arr+i)+j)
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
	push(&path, i, j);
	while(DistancePath[i][j] != 0){
		for (dx = (i <= 0 ? 0 : -1); dx <= (i >= i_taille_map-1 ? 0 : 1); dx++)
			for (dy = (j <= 0 ? 0 : -1); dy <= (j >= i_taille_map-1 ? 0 : 1); dy++){

				actual = DistancePath[i][j];
				actual--;
				if (abs(dx) != abs(dy) && actual == DistancePath[dx+i][dy+j]) {
					i = dx+i;
					j = dy+j;
					dx = 2;
					dy = 2;
					push(&path, i, j);
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

