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

t_perso tab_perso[6]; //Contient les données de tous les persos.

void creation(t_perso tab_perso[6], int i_position_tableau, char classe[20], char c_team, int x, int y);
