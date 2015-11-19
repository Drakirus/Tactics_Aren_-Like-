//Ce module servira à créer la map de base dans laquelle les personnages vont se battre.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define i_taille_map 20 //Nous avons convenu que la map sera un carré de taille 10.


void initialise_map(int map[i_taille_map][i_taille_map]) //Fonction initialisant la map vide
{	int i,j;
	for(i=0;i<i_taille_map;i++)
	{
		for(j=0;j<i_taille_map;j++)
		{
			map[i][j]=0; //0=vide;
		}
	}
}

void obstacle(int i_chance_obstacle, int map[i_taille_map][i_taille_map]) //Fonction insérant les obstacles dans la map. Les obstacles sont placés aléatoirement dans la map.
{
	int i,j;
	int c; //c comme condition.
	int i_place_vide=i_taille_map*(i_taille_map-3)-i_chance_obstacle;
	for(i=0+3;i<i_taille_map-3;i++) //3 correspond aux 3 premières lignes de chaque camp qui servira placer les personnages, il n'y aura pas d'obstacles dans ces zones.
	{
		for(j=0;j<i_taille_map;j++)
		{
			c=rand()%(i_place_vide+i_chance_obstacle);
			if(c<i_place_vide)
			{
				map[i][j]=0;
				i_place_vide--;
			}
			else
			{
				map[i][j]=1; //1=obstacle.
				i_chance_obstacle--;
			}
		}
	}
}

void afficher_map(int map[i_taille_map][i_taille_map]) //Fonction affichant la map
{
	int i,j;
	for(i=0;i<i_taille_map;i++)
	{
		for(j=0;j<i_taille_map;j++)
		{
			if(map[i][j]==0)
				printf("_ ");
			else if(map[i][j]==1)
				printf("* ");
			else if(map[i][j]==2)
				printf("@ ");
			else if(map[i][j]==3)
				printf("0 ");
		}
		printf("\n");
	}
}

float getSlope(float f_a, float f_b){
	if(f_b == 0){
		return 99;
	}
	return f_a/f_b;
}

void shadowcasting(int map[i_taille_map][i_taille_map], int i_player_x, int i_player_y){
	int i,j,cx,cy;
	float f_slope_min, f_slope_max, f_slope;
	for (i = 0; i < i_taille_map; i++) {
		for (j = 0; j < i_taille_map; j++) {
			if (map[i][j] == 1) {
				f_slope_min = getSlope((j-(i_player_y+0.5))	 , (i_taille_map-1-i)+(i_player_x+0.5));
				f_slope_max = getSlope((j+(i_player_y+0.5))	 , (i_taille_map-1-i)-(i_player_x+0.5));
				printf("%f slope min  %f slope max \n", f_slope_min, f_slope_max);
			  for (cy = i; cy >= 0; cy--) {
					for (cx = j; cx < i_taille_map; cx++) {
							f_slope = getSlope((cx), (i_taille_map-1-cy));
							if((f_slope > f_slope_min) && (f_slope < f_slope_max || (f_slope_max < 0 && cx > i_player_x))){
								map[cy][cx] = 3;
							}
					}
				}
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	int map[i_taille_map][i_taille_map];
	initialise_map(map);
	obstacle(5, map);
	map[19][0] = 2;
	afficher_map(map);
	shadowcasting(map, 0, 0);
	afficher_map(map);
	return 0;
}
