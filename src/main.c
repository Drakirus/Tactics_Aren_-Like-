#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/save.h"
#include "../include/placement.h"
#include "../include/tour.h"
#include "../include/map.h"


#include "../include\action.h"
extern int map[i_taille_map][i_taille_map];


int main() {
	srand(time(NULL));
	system("clear");
	int choix_menu = 0;
	do{
		printf("1 - Nouvelle Partie\n");
		printf("2 - Charger une partie\n");
		printf("3 - Quitter\n");
		scanf("%i", &choix_menu);
		switch(choix_menu){
			case 1: initialise_map();
					afficher_map();
					placement_perso();
					tour();
					break; /*Nouvelle Partie*/
			case 2: charge();
					tour();
					break; /*Charger une partie */
			case 3:
					break;
		}
	}while(choix_menu != 3);



/// TEST PIERRE FONCTION ACTION

initialise_map();
obstacle(35);
// placement_perso();
map[0][0]=2;
afficher_map();

int init_x=0, init_y=0;

int **DistancePath = createDistancePath(init_x, init_y);


displayBoard(i_taille_map,i_taille_map,DistancePath);
printf("\ndistanceFrom %i\n", distanceFrom(9, 9, DistancePath));

pile *path = getPath(DistancePath, 9, 9);

int r,c;
int sortir = pop(&path, &r, &c);
while (sortir != -1) {
    sortir = pop(&path, &r, &c);
    printf("r: %i c: %i\n",r,c );
}
freeBoard(DistancePath, i_taille_map);

return 0;
}
