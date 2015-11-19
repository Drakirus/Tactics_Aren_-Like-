//Ce module servira à créer la map de base dans laquelle les personnages vont se battre.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define i_taille_map 10 //Nous avons convenu que la map sera un carré de taille 10.


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
		}
		printf("\n");
	}
}

int main()
{
	srand(time(NULL));
	int map[i_taille_map][i_taille_map];
	initialise_map(map);
	obstacle(10, map);
	afficher_map(map);
}