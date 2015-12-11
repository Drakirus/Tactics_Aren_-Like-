#ifndef __map_size__
#define i_taille_map 10
#endif

typedef struct
{
	char s_classe[20];
	int i_HP_max;
	int i_HP;
	int i_PA;
	int i_PM;
	int coord[2];
	char c_team;
}t_perso;

void afficher_perso(t_perso perso);
void creation(t_perso tab_perso[6], int i_position_tableau, char classe[20], char c_team, int x, int y);

float getSlope(float f_a, float f_b);
int shoot(int map[i_taille_map][i_taille_map], int i_player_x, int i_player_y, int i_attaque_x, int i_attaque_y);
