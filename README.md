Tactics Arena [![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/Drakirus/Tactics_Arena_Like?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)
======
	Voici le projet de CHAMPION Pierre, LAVILLE Martin et MOK Modira.

### Trello (Organisation)
	https://trello.com/b/JkJAWVmc


### Fonction action exemple d'utilisation

```

#include "../include\action.h"

* ===========================================
*			 FONCTION LIGNE DE VUE
* ===========================================
*/

initialise_map();
obstacle(10);

afficher_map();
if (shoot(0, 0, 9,9)) {
	printf("tir impossible \n");
}else{
	printf("tir possible \n");
}

/*
* ===========================================
*			 FONCTION PATHFINDING
* ===========================================
*/



initialise_map();
obstacle(35);
int init_x=2, init_y=2;

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

```
