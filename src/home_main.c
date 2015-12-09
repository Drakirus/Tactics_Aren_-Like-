#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

#include "../include\gener_map.h"
#include "../include\perso_p.h"

int main()
{
	srand(time(NULL));
	int map[i_taille_map][i_taille_map];
	initialise_map(map);
	obstacle(10, map);

  printf("%i\n", shoot(map, 0, 0, 9,9));
  map[0][0] = 2;
  map[9][9] = 2;
  afficher_map(map);
	/*while (1) {

			mapdisp[x][y] = 0;
			system("@cls||clear");
			mapdisp[x][y] = 2;
			shadowcasting(mapdisp, x, y);
			afficher_map(mapdisp);
			switch(getch()) {
			    case 'z':    // key up
							x--;
			        break;
			    case 's':    // key down
							x++;
			        break;
			    case 'd':    // key right
							y++;
			        break;
			    case 'q':    // key left
							y--;
			        break;
					case 'a':    // key left
							return 0;
			}
			for( i = 0; i < i_taille_map; i++){
				for( j = 0; j < i_taille_map; j++)	{
					mapdisp[i][j] = map[i][j];
				}
			}

	}*/
	return 0;
}
