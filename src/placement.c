#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "../include/placement.h"
#include "../include/gener_map.h"
#include "../include/tableau.h"

void placement_perso(int map[i_taille_map][i_taille_map]) //Cette fonction place les personnages des différents équipes dans les trois premières et dernières ligne de la map.
{
	char s_classe[20]; //Classe du personnage choisie.
	int i_nb_perso=6;
	int i_nb_guerrier_A=1;
	int i_nb_archer_A=1;
	int i_nb_mage_A=1;
	int i_nb_guerrier_B=1;
	int i_nb_archer_B=1;
	int i_nb_mage_B=1;
	int cord[2];
	int b_sortie=1; //Condition de sortie
	char sauv[40];
	t_perso tab_perso[6]; //Contient les données de tous les persos.
	int i_compteur=0;
	t_perso per;

	while(i_nb_perso!=0)
	{
		while(b_sortie!=0)
		{
			printf("\nEquipe A, à vous de placer un personnage : \n"); //La phase de choix de l'équipe A
			printf("Choisissez les coordonnées : "); 
			scanf("%i%i", &cord[0], &cord[1]); //Les coordonnées sont comprises entre 0 et 9.
			if(cord[0]>=0 && cord[0]<=3 && cord[1]>=0 && cord[1]<=9 && map[cord[0]][cord[1]]==0)
			{
				b_sortie=0;
			}
		}
		b_sortie=1;

		while(b_sortie!=0)
		{
			printf("Choisissez la classe : \n");
			printf("- Il reste %i guerriers à placer.\n", i_nb_guerrier_A);
			printf("- Il reste %i archers à placer.\n", i_nb_archer_A);
			printf("- Il reste %i mages à placer.\n", i_nb_mage_A);
			printf("Choisissez la classe du personnage : ");
			scanf("%s", s_classe); //La classe est donnée par la première lettre de la classe, ou le nom complet.
			if(strcmp(s_classe,"A")==0 || strcmp(s_classe,"archer")==0 || strcmp(s_classe,"Archer")==0) //Pour l'affichage dans gener_map.c.
			{
				if(i_nb_archer_A!=0)
				{
					i_nb_archer_A--;
					i_nb_perso--;
					map[cord[0]][cord[1]]=3;
					strcpy(per.s_classe,"Archer");
					per.i_HP_max=50;
					per.i_HP=50;
					per.i_PA=3;
					per.i_PM=3;
					per.coord[0]=cord[0];
					per.coord[1]=cord[1];
					per.c_team='A';
					tab_perso[i_compteur]=per; //On ajoute le perso au tableau.
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(strcmp(s_classe,"G")==0 || strcmp(s_classe,"Guerrier")==0|| strcmp(s_classe,"guerrier")==0)
			{
				if(i_nb_guerrier_A!=0)
				{
					i_nb_guerrier_A--;
					i_nb_perso--;
					map[cord[0]][cord[1]]=2;
					strcpy(per.s_classe,"Guerrier");
					per.i_HP_max=50;
					per.i_HP=50;
					per.i_PA=3;
					per.i_PM=3;
					per.coord[0]=cord[0];
					per.coord[1]=cord[1];
					per.c_team='A';
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(strcmp(s_classe,"M")==0 || strcmp(s_classe,"Mage")==0 || strcmp(s_classe,"mage")==0)
			{
				if(i_nb_mage_A!=0)
				{
					i_nb_mage_A--;
					i_nb_perso--;
					map[cord[0]][cord[1]]=4;
					strcpy(per.s_classe,"Mage");
					per.i_HP_max=50;
					per.i_HP=50;
					per.i_PA=3;
					per.i_PM=3;
					per.coord[0]=cord[0];
					per.coord[1]=cord[1];
					per.c_team='A';
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
		}
		b_sortie=1;
		afficher_map(map);


		while(b_sortie!=0)
		{
			printf("\nEquipe B, à vous de placer un personnage : \n"); //On passe à la phase de choix de l'équipe B
			printf("Choisissez les coordonnées : "); 
			scanf("%i%i", &cord[0], &cord[1]); //Les coordonnées sont comprises entre 0 et 9.
			if(cord[0]>=7 && cord[0]<=9 && cord[1]>=0 && cord[1]<=9 && map[cord[0]][cord[1]]==0)
			{
				
				b_sortie=0;
			}
		}
		b_sortie=1;

		while(b_sortie!=0)
		{
			printf("Choisissez la classe : \n");
			printf("- Il reste %i guerriers à placer.\n", i_nb_guerrier_B);
			printf("- Il reste %i archers à placer.\n", i_nb_archer_B);
			printf("- Il reste %i mages à placer.\n", i_nb_mage_B);
			printf("Choisissez la classe du personnage : ");
			scanf("%s", s_classe);
			if(strcmp(s_classe,"A")==0 || strcmp(s_classe,"archer")==0 || strcmp(s_classe,"Archer")==0)
			{
				if(i_nb_archer_B!=0)
				{
					i_nb_archer_B--;
					i_nb_perso--;
					map[cord[0]][cord[1]]=6;
					strcpy(per.s_classe,"Archer");
					per.i_HP_max=50;
					per.i_HP=50;
					per.i_PA=3;
					per.i_PM=3;
					per.coord[0]=cord[0];
					per.coord[1]=cord[1];
					per.c_team='B';
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(strcmp(s_classe,"G")==0 || strcmp(s_classe,"Guerrier")==0|| strcmp(s_classe,"guerrier")==0)
			{
				if(i_nb_guerrier_B!=0)
				{
					i_nb_guerrier_B--;
					i_nb_perso--;
					map[cord[0]][cord[1]]=5;
					strcpy(per.s_classe,"Guerrier");
					per.i_HP_max=50;
					per.i_HP=50;
					per.i_PA=3;
					per.i_PM=3;
					per.coord[0]=cord[0];
					per.coord[1]=cord[1];
					per.c_team='B';
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
			else if(strcmp(s_classe,"M")==0 || strcmp(s_classe,"Mage")==0 || strcmp(s_classe,"mage")==0)
			{
				if(i_nb_mage_B!=0)
				{
					i_nb_mage_B--;
					i_nb_perso--;
					map[cord[0]][cord[1]]=7;
					strcpy(per.s_classe,"Mage");
					per.i_HP_max=50;
					per.i_HP=50;
					per.i_PA=3;
					per.i_PM=3;
					per.coord[0]=cord[0];
					per.coord[1]=cord[1];
					per.c_team='B';
					tab_perso[i_compteur]=per;
					i_compteur++;
					b_sortie=0;
				}
			}
		}
		//sauv_perso(sauv);
		//printf("%s\n", sauv);
		afficher_map(map);
		b_sortie=1;
	}
	afficher_tableau(tab_perso);
}
