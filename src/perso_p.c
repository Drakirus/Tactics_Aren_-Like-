//Ce module servira à créer la map de base dans laquelle les personnages vont se battre.

#include "../include\perso_p.h"

float getSlope(float f_a, float f_b){
	if(f_b == 0){
		return 99;
	}
	return f_a/f_b;
}

int shoot(int map[i_taille_map][i_taille_map], int i_player_y, int i_player_x, int i_attaque_y, int i_attaque_x){
	int i,j,cx,cy;
	float f_slope_min, f_slope_max, f_slope;
	for (i = 0; i < i_taille_map; i++) {
		for (j = 0; j < i_taille_map; j++) {
			if (map[i][j] == 1) {

				if (i_player_x <= i && i_player_y <= j ) { // en bas a droite

					f_slope_min = getSlope(((i_player_y+0.5)-j)	 , (i_player_x+0.5)-(i+1));
					f_slope_max = getSlope(((i_player_y+0.5)-(j+1))	 , (i_player_x+0.5)-i);
					// printf("\n %.2f slope min  %.2f slope max %i i %i j  en bas a droite\n", f_slope_min, f_slope_max,(j),(i));   // ICI

					cx = i_attaque_x;
					cy = i_attaque_y;
							// printf(" %i:x %i:y", cx,cy);
					f_slope = getSlope(((i_player_y)-cx), ((i_player_x)-cy));
					// printf(" slope %.2f \n",f_slope);
					if (cy != i || cx != j) {

						if((f_slope > f_slope_min ) && (f_slope < f_slope_max || (f_slope_max < 0) )  ){
							// printf("slope %f\n", f_slope);
							if (map[cy][cx] != 1) {
								return 1;
							}
						}
					}
				}

				if (i_player_x >= i && i_player_y >= j ) { // en haut a gauche

					f_slope_min = getSlope(((i_player_y+0.5)-j)	 , (i_player_x+0.5)-(i+1));
					f_slope_max = getSlope(((i_player_y+0.5)-(j+1))	 , (i_player_x+0.5)-i);
					// printf("\n %.2f slope min  %.2f slope max %i i %i j  en haut a gauche\n", f_slope_min, f_slope_max,(j),(i));   // ICI

					cx = i_attaque_x;
					cy = i_attaque_y;
							// printf(" %i:x %i:y", cx,cy);
					f_slope = getSlope(((i_player_y)-cx), ((i_player_x)-cy));
					// printf(" slope %.2f \n",f_slope);
					if (cy != i || cx != j) {

						if((f_slope < f_slope_min  || (f_slope_min < 0 ) ) && (f_slope > f_slope_max)){
							// printf("slope %f\n", f_slope);
							if (map[cy][cx] != 1) {
								return 1;
							}
						}
					}
				}

				if (i_player_x >= i && i_player_y <= j ) { // en haut a droite

					f_slope_max = getSlope(((i_player_y-0.5)-j)	 , (i_player_x+0.5)-(i+1));
					f_slope_min = getSlope(((i_player_y-0.5)-(j-1))	 , (i_player_x+0.5)-i);
					// printf("\n %.2f slope min  %.2f slope max %i i %i j  en haut a droite\n", f_slope_min, f_slope_max,(j),(i));   // ICI
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

					f_slope_max = getSlope(((i_player_y+0.5)-j)	 , (i_player_x-0.5)-(i-1));
					f_slope_min = getSlope(((i_player_y+0.5)-(j+1))	 , (i_player_x-0.5)-i);
					// printf("\n %.2f slope min  %.2f slope max %i i %i j  en bas a gauche \n", f_slope_min, f_slope_max,(j),(i));   // ICI

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
