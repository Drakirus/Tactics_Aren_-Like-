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

t_perso ensemble_perso[3]={
	{"Guerrier",50,50,3,3,{0,0},'A'},
	{"Archer",30,30,3,3,{0,0},'A'},
	{"Mage",20,20,2,2,{0,0},'A'}
};

