#include "../include/SDL_isometric.h"
#include "../include/map.h"

#include "../include/tableau.h"
extern type_Map tMap;
extern t_context *ingame;
extern int i_perso_actuel;
extern t_perso tab_perso[i_taille_tab_perso];


extern int map[i_taille_map][i_taille_map];
/**
 * Convertis les coordonnées cartésiennes en coordonnées isométriques
 * @param tMap Type de la carte
 * @param x Position horizontale cartésienne
 * @param y Position verticale cartésienne
 */
void toIso(type_Map tMap, int * x, int * y){

	if(tMap == diamond){
		* x = (* x - * y * 2) / 2;
		* y = (* x + * y * 2) / 2;
	}else if(tMap == slide || tMap == staggered){

		if(tMap == slide){
			* x = (* x + * y);
		}else{
			* x = * x + ((* y / TILE_H % 2 == 0) ? 0 : 1 ) * (TILE_W/2);
		}

		* y = (* y / 2);
	}

}

/**
 * Décalage en X
 * @param tMap Type de la carte
 */
int offsetX(type_Map tMap){

	if(tMap == diamond)
		return (SCREEN_WIDTH - TILE_W) / 2; // Diamond map
	else
		return (SCREEN_WIDTH - (N + 1)  * TILE_W) / 2; // Slide AND Staggered map
}

/**
 * Décalage en Y
 */
int offsetY(){
	return (SCREEN_HEIGHT - N * TILE_H) /2;
}

/**
 * Récupère les indices x et y de la tile en posX / posY
 * @param tMap Type de la carte
 * @param posX Coordonnée X pointée
 * @param posY Coordonnée Y pointée
 * @param x Pointeur sur l'indice x
 * @param x Pointeur sur l'indice y
 */
void getIndexMap(type_Map tMap, int posX, int posY, int * x, int * y){
	posX -= offsetX(tMap);

	if(tMap == diamond){

		posX -= TILE_W / 2; // Diamond map
		posY -= offsetY();

		* x = floor( ( (float)posX/ (TILE_W/2) + (float)posY/(TILE_H/2)) / 2 );;
		* y = floor( ( (float)posY/ (TILE_H/2) - (float)posX/(TILE_W/2)) / 2 );;

	}

}

/**
 * Dessine une tile aux coordonnées posX et posY
 * @param context Contexte dans lequel dessiner
 * @param tMap Type de la carte
 * @param posX Coordonnées X de la tile à dessiner
 * @param posY Coordonnées Y de la tile à dessiner
 */
void drawTile(t_context * context , type_Map tMap, int posX, int posY){
	int x = posX / TILE_W, y = posY / TILE_H;

	toIso(tMap, &posX, &posY); // Convertis les coordonnées en coordonnées isométriques

	posX += offsetX(tMap);
	posY += offsetY();

	if(y == N-1 || ( x == 0 && (tMap == slide || tMap == staggered) )){
		SDL_newImage(context, NULL, "base_Cube.png", posX, posY);
	}

	if(tMap == diamond){
		if(x == N-1){
			SDL_newImage(context, NULL, "base_Cube.png", posX, posY);
		}else{
			SDL_newImage(context, NULL, "base_Tile.png", posX, posY);
		}
	}else if(tMap == slide){
		if(x != 0){
			SDL_newImage(context, NULL, "base_Tile.png", posX, posY);
		}
	}else if(tMap == staggered){
		if((x == N - 1 && y % 2 != 0)){
			SDL_newImage(context, NULL, "base_Cube.png", posX, posY);
		}else{
			SDL_newImage(context, NULL, "base_Tile.png", posX, posY);
		}
	}

	SDL_setOnLayer(context, IMG, context->nbImg - 1, 1);
}

void drawTileplace(t_context * context , type_Map tMap, int posX, int posY){
	int x = posX / TILE_W, y = posY / TILE_H;

	toIso(tMap, &posX, &posY); // Convertis les coordonnées en coordonnées isométriques

	posX += offsetX(tMap);
	posY += offsetY();

	if(y == N-1 || ( x == 0 && (tMap == slide || tMap == staggered) )){
		SDL_newImage(context, NULL, "blue_Tile.png", posX, posY);
	}

	if(tMap == diamond){
			SDL_newImage(context, NULL, "blue_Tile.png", posX, posY);
	}else if(tMap == slide){
		if(x != 0){
			SDL_newImage(context, NULL, "blue_Tile.png", posX, posY);
		}
	}else if(tMap == staggered){
		if((x == N - 1 && y % 2 != 0)){
			SDL_newImage(context, NULL, "blue_Tile.png", posX, posY);
		}else{
			SDL_newImage(context, NULL, "blue_Tile.png", posX, posY);
		}
	}

	SDL_setOnLayer(context, IMG, context->nbImg - 1, 1);
}

void drawTileplaceA(t_context * context , type_Map tMap, int posX, int posY){
	int x = posX / TILE_W, y = posY / TILE_H;

	toIso(tMap, &posX, &posY); // Convertis les coordonnées en coordonnées isométriques

	posX += offsetX(tMap);
	posY += offsetY();

	if(y == N-1 || ( x == 0 && (tMap == slide || tMap == staggered) )){
		SDL_newImage(context, NULL, "red_Tile.png", posX, posY);
	}

	if(tMap == diamond){
			SDL_newImage(context, NULL, "red_Tile.png", posX, posY);
	}else if(tMap == slide){
		if(x != 0){
			SDL_newImage(context, NULL, "red_Tile.png", posX, posY);
		}
	}else if(tMap == staggered){
		if((x == N - 1 && y % 2 != 0)){
			SDL_newImage(context, NULL, "red_Tile.png", posX, posY);
		}else{
			SDL_newImage(context, NULL, "red_Tile.png", posX, posY);
		}
	}

	SDL_setOnLayer(context, IMG, context->nbImg - 1, 3);
}
void drawTileplaceB(t_context * context , type_Map tMap, int posX, int posY){
	int x = posX / TILE_W, y = posY / TILE_H;

	toIso(tMap, &posX, &posY); // Convertis les coordonnées en coordonnées isométriques

	posX += offsetX(tMap);
	posY += offsetY();

	if(y == N-1 || ( x == 0 && (tMap == slide || tMap == staggered) )){
		SDL_newImage(context, NULL, "pur_Tile.png", posX, posY);
	}

	if(tMap == diamond){
			SDL_newImage(context, NULL, "pur_Tile.png", posX, posY);
	}else if(tMap == slide){
		if(x != 0){
			SDL_newImage(context, NULL, "pur_Tile.png", posX, posY);
		}
	}else if(tMap == staggered){
		if((x == N - 1 && y % 2 != 0)){
			SDL_newImage(context, NULL, "pur_Tile.png", posX, posY);
		}else{
			SDL_newImage(context, NULL, "pur_Tile.png", posX, posY);
		}
	}

	SDL_setOnLayer(context, IMG, context->nbImg - 1, 3);
}
/**
 * Dessine un décor
 * @param context Contexte dans lequel dessiner
 * @param tMap    Type de la map
 * @param posX Coordonnées X de la tile à dessiner
 * @param posY Coordonnées Y de la tile à dessiner
 */
void drawDecor(t_context * context , type_Map tMap, int posX, int posY){

	toIso(tMap, &posX, &posY); // Convertis les coordonnées en coordonnées isométriques

	posX += offsetX(tMap);
	posY += offsetY() - HEIGHT_DECOR / 2;

	SDL_newImage(context, NULL, "rock.png", posX, posY);
	SDL_setOnLayer(context, IMG, context->nbImg - 1, 5);	

}

/**
 * Affiche un curseur à la position indiquée
 * @param context Contexte dans lequel dessiner
 * @param tMap Type de la map
 * @param x Indice X de la map
 * @param y Indice Y de la map
 */
void showCursor(t_context * context, type_Map tMap, int x, int y){
	int posX, posY;

	posX = x * TILE_W;
	posY = y * TILE_H;

	toIso(tMap, &posX, &posY);

	posX += offsetX(tMap);
	posY += offsetY();

	if(idCursor == - 1){
		idCursor = context->nbImg;
		SDL_newImage(context, NULL, "cursor.png", posX, posY); // Initialise le curseur si pas encore dessiné
	}else{
		SDL_editImage(context, idCursor, posX, posY); // Met à jour la position du curseur
	}

	SDL_setOnLayer(context, IMG, idCursor, 2);
}

/**
 * Affiche un curseur à la position pointée
 * @param context Contexte dans lequel dessiner
 * @param tMap    Type de la map
 */
int showMouseCursor(t_context * context, type_Map tMap){
	int x = 0, y = 0, mX = 0, mY = 0;

	if(idCursor == -1){
		showCursor(context, tMap, x, y); // Affiche en surbillance la zone pointée
		return 1;
	}

	if(idCursor < 0) return 0;

	getIndexMap(tMap, context->contextImg[idCursor].x + context->contextImg[idCursor].buffer->w / 2, context->contextImg[idCursor].y + context->contextImg[idCursor].buffer->h / 2, &x, &y);
	getIndexMap(tMap,  SDL_getmousex(),  SDL_getmousey(), &mX, &mY);

	if(mX != x || mY != y){

		if(mX >= 0 && mX < N && mY >= 0 && mY < N){
				showCursor(context, tMap, mX, mY); // Affiche en surbillance la zone pointée
				return 1;
		}
	}
	return 0;
}

/**
 * Dessine une carte
 * @param context Contexte dans lequel dessiner
 * @param tMap    Type de la map
 */
void drawMap(t_context * context, type_Map tMap){
	int x, y;
	int posX = 0, posY = 0;

	for (x = 0; x < N; x++){
			for (y = 0; y < N; y++){

				posX =  x * TILE_W;
				posY =  y * TILE_H;

				drawTile(context, tMap, posX, posY);

				if(map[x][y] == 1){
					drawDecor(context, tMap, posX, posY);	
				}

			}
	}

}

/**
 * Glisser et déposer
 * @param context Contexte dans lequel dessiner
 * @param tMap    Type de la carte
 */
void dragNdrop(t_context * context, type_Map tMap){
	int x, y, posX, posY;
	int mousePressed = SDL_isMousePressed(SDL_BUTTON_LEFT);
	int overObj = -1;

	if(mousePressed){ // Clic sur une zone
			overObj = SDL_ismouseover(context, SPRITE);

			if(overObj >= 0){
				
				while(mousePressed){
					SDL_drag(context, SPRITE, overObj); // Glisse l'objet
					showMouseCursor(context, tMap);
					mousePressed = SDL_isMousePressed(SDL_BUTTON_LEFT);
					SDL_Delay(20);
				}

				mousePressed = -1;
			}

	}

	if(mousePressed == - 1){ // Objet relaché

		if(overObj >= 0){
			getIndexMap(tMap, SDL_getmousex(), SDL_getmousey(), &x, &y);

			posX = x * TILE_W;
			posY = y * TILE_H;

			toIso(tMap, &posX, &posY); // Convertis les coordonnées en coordonnées isométriques

			posX += offsetX(tMap);
			posY += offsetY() - context->contextSprite[overObj].sp_height / 2;

			SDL_drop(context, SPRITE, overObj, posX, posY); // Dépose l'objet
			SDL_generate(context);
		}
	}else{
		SDL_Delay(20);
	}

}

void GetClickPlace(t_context * context, type_Map tMap, int* x, int* y){
	// int posW =SCREEN_WIDTH-313;
	// int posH =SCREEN_HEIGHT-178;
	int a,b;
	int mousePressed = SDL_isMousePressed(SDL_BUTTON_LEFT);
	int overObj = -1;
	while (1) {
		
		//Display current tile on map
		if(showMouseCursor(context, tMap)){
			SDL_generate(context);
		}
		// If user request exit, we need to quit while()
		if (SDL_isKeyPressed(SDLK_q)) break;
		if (SDL_requestExit()) break;
		
		
		mousePressed = SDL_isMousePressed(SDL_BUTTON_LEFT);
		if(mousePressed){ // Clic sur une zone
			

				overObj = SDL_ismouseover(context, IMG);
				if(overObj >= 0){
										
					getIndexMap(tMap, SDL_getmousex(), SDL_getmousey(), &a, &b);
					*x=a;
					*y=b;
					// printf("%i %i\n", x,y);
					return;
				}
				
		}
		// SDL_Delay(20);
	}
}

void GetClick(t_context * context, type_Map tMap, int* x, int* y){
	int posW =SCREEN_WIDTH-313;
	int posH =SCREEN_HEIGHT-178;
	int a,b;
	int mousePressed = SDL_isMousePressed(SDL_BUTTON_LEFT);
	int overObj = -1;
	SDL_newImage(context, NULL, "menu.png", posW,  posH);
	SDL_newText(context, NULL, "1 - Annuler", colorBlack, posW + 90, posH + 80);
	// SDL_setOnLayer(context, TEXT, context->nbText - 1, 100);
	while (1) {
		
		//Display current tile on map
		if(showMouseCursor(context, tMap)){
			SDL_generate(context);
		}
		// If user request exit, we need to quit while()
		if (SDL_isKeyPressed(SDLK_q)) break;
		if (SDL_requestExit()) break;
		
		
		mousePressed = SDL_isMousePressed(SDL_BUTTON_LEFT);
		if(mousePressed){ // Clic sur une zone
			

				overObj = SDL_ismouseover(context, IMG);
				if(overObj >= 0){
					
					overObj = SDL_ismouseover(context, TEXT);
					if(overObj >= 0){
						*x=-1;
						*y=-1;
						// printf("%i %i\n", x,y);
						SDL_delImage(context, context->nbImg-1 );
						// SDL_delImage(context, context->nbImg-1 );
						// SDL_delText(context, context->nbText-1 );
						SDL_delText(context, context->nbText-1 );
						
						return;
					}
					
					getIndexMap(tMap, SDL_getmousex(), SDL_getmousey(), &a, &b);
					*x=a;
					*y=b;
					// printf("%i %i\n", x,y);
					return;
				}
				
		}
		// SDL_Delay(20);
	}
}

int choseAttak(t_context * context, list_attack *perso_att){
	int posW =0;
	int posH =SCREEN_HEIGHT-120;
	int actual = 1;
	t_attak * att;
	list_attack *tmp = perso_att;
	int NBtext = context->nbText;
	
	char Attaque[70];
	char TmpAttaque[70];
	while(tmp->current_attack != NULL){

		if(tmp->current_attack != NULL){
			// printf("\n    %i - ",actual);
			// displayAttack(tmp->current_attack);
			att = tmp->current_attack;
			sprintf(Attaque,"'%s' range : max %i min %i, %i cost",att->attack_name, att->range_max, att->range_min, att->cost_PA);
			if (att->splash_range > 1){
				
				sprintf(TmpAttaque,"\n\tC'est une attaque de zone sur %i case ",att->splash_range);
				strcat(Attaque, TmpAttaque);
			}
			if (att->only_line){
				
				sprintf(TmpAttaque,"en Ligne ");
				strcat(Attaque, TmpAttaque);
			}
			if (att->trait.HP < 0){
				
				sprintf(TmpAttaque,"\n\tFait %i degats ",att->trait.HP);
				strcat(Attaque, TmpAttaque);
			}
			if (att->trait.HP > 0){
				
				sprintf(TmpAttaque,"\n\tSoigne de %i pv",att->trait.HP);
				strcat(Attaque, TmpAttaque);
			}
			if (att->trait.HP_max != 0){
				
				sprintf(TmpAttaque,"\n\tChange les pv max a %i ",att->trait.HP_max);
				strcat(Attaque, TmpAttaque);
			}
			if (att->trait.PA != 0){
				
				sprintf(TmpAttaque,"\n\tChange les P d'action à %i ",att->trait.PA);
				strcat(Attaque, TmpAttaque);
			}
			if (att->trait.PM != 0){
				sprintf(TmpAttaque,"\n\tChange les P de mouvement à + %i ",att->trait.PM);
				strcat(Attaque, TmpAttaque);
			}
			if (att->trait.coord_r != 0 || att->trait.coord_c != 0){
				
				sprintf(TmpAttaque,"\n\tFait reculer le perso de %ix%i ",att->trait.coord_r, att->trait.coord_c);
				strcat(Attaque, TmpAttaque);
			}
			// printf("\n");
			// printf("\n");
		}
		tmp = tmp->next;
		actual++;
		SDL_newText(context, NULL, Attaque, colorGreenLight, posW + 0, posH + actual*30);
	}
	SDL_generate(context);
	int i;
	int idReturn;
	while (1) {
		SDL_Delay(50);
		if (SDL_isMousePressed(SDL_BUTTON_LEFT)) {
			
			
			idReturn = SDL_ismouseover(context, TEXT)-NBtext;
			
			// SDL_delText(context, context->nbText-5 );
			for (i = 1; i <= actual-1 ; i++) {
				SDL_delText(context, context->nbText-1);
			}
			printf("%i\n",  idReturn+1 );
			return idReturn+1;
		}
	}
	return -1;
}

void moveSpriteTo(t_context * context, type_Map tMap, int to, int idSprite ){

	int nbAnimMax = 10; // TWEAK HERE : nombre d'animation pour parcourir 1 case
	int pixelByAnim = 5; // TWEAK HERE : nombre de pixel par animation

	int currentAnim = context->contextSprite[idSprite].animation; // animation actuelle
	int maxAnimSet = (context->contextSprite[idSprite].buffer->w / context->contextSprite[idSprite].sp_width); // calcul ne nombre d'animation pour faire le boucle
	int nbAnim = 0;

	while (nbAnim != nbAnimMax) {

		if(to == UP_LEFT){
    		
    		SDL_editSprite(context, idSprite, (context->contextSprite[idSprite].x - pixelByAnim ) , (context->contextSprite[idSprite].y - pixelByAnim / 2), 4, ++currentAnim, 0); //haut gauche
		
		}else if(to == UP_RIGHT){
	  		
	  		SDL_editSprite(context, idSprite, (context->contextSprite[idSprite].x + pixelByAnim ) , (context->contextSprite[idSprite].y - pixelByAnim / 2), 2, ++currentAnim, 0); //haut droite
		
		}else if(to == DOWN_LEFT){
			
			SDL_editSprite(context, idSprite, (context->contextSprite[idSprite].x - pixelByAnim ) , (context->contextSprite[idSprite].y + pixelByAnim / 2), 3, ++currentAnim, 0); //bas gauche
		
		}else if(to == DOWN_RIGHT){
	  		
	  		SDL_editSprite(context, idSprite, (context->contextSprite[idSprite].x + pixelByAnim ) , (context->contextSprite[idSprite].y + pixelByAnim / 2), 1, ++currentAnim, 0); //bas droite
		
		}else{
			nbAnim = nbAnimMax;
		}

		nbAnim++;
		if (currentAnim+1 >= maxAnimSet) {
			currentAnim = 0;
		}

		SDL_generate(context);
		SDL_Delay(15);
	}

}
int MenuPerso(t_context * context){
	int posW =SCREEN_WIDTH-313;
	int posH =SCREEN_HEIGHT-178;
	SDL_newImage(context, NULL, "menu.png", posW,  posH);
	
	// SDL_newText(context, NULL, "5 - Menu Principal", colorBlack, posW + 90, posH + 130);
	SDL_newText(context, NULL, "4 - Voleur", colorBlack, posW + 90, posH + 110);
	SDL_newText(context, NULL, "3 - Mage", colorBlack, posW + 90, posH + 85);
	SDL_newText(context, NULL, "2 - Archer", colorBlack, posW + 90,posH + 60);
	SDL_newText(context, NULL, "1 - Guerrier", colorBlack, posW + 90, posH + 35);
	int idReturn;
	SDL_generate(context);
	
	while (1) {
		SDL_Delay(50);
		if (SDL_isMousePressed(SDL_BUTTON_LEFT)) {
			
			SDL_delImage(context, context->nbImg-1 );
			
			idReturn = context->nbText-SDL_ismouseover(context, TEXT);
			
			// SDL_delText(context, context->nbText-5 );
			SDL_delText(context, context->nbText-4 );
			SDL_delText(context, context->nbText-3 );
			SDL_delText(context, context->nbText-2 );
			SDL_delText(context, context->nbText-1 );
			return idReturn;
		}
	}
}
int menuInGame(t_context * context){
	int posW =SCREEN_WIDTH-313;
	int posH =SCREEN_HEIGHT-178;
	SDL_newImage(context, NULL, "menu.png", posW,  posH);
	int i = i_perso_actuel;
	char Info[50];
	sprintf(Info,"%s %i/%iHP [%i,%i] %c\n", tab_perso[i].s_classe, tab_perso[i].i_HP_max, tab_perso[i].i_HP, tab_perso[i].coord[0], tab_perso[i].coord[1], tab_perso[i].c_team);
	SDL_newText(context, NULL, Info, colorRed, posW + 47, posH + 5);
	SDL_newText(context, NULL, "5 - Menu Principal", colorBlack, posW + 90, posH + 130);
	SDL_newText(context, NULL, "4 - Sauvegarder", colorBlack, posW + 90, posH + 105);
	SDL_newText(context, NULL, "3 - Passer", colorBlack, posW + 90, posH + 80);
	SDL_newText(context, NULL, "2 - Attaquer", colorBlack, posW + 90,posH + 55);
	SDL_newText(context, NULL, "1 - Deplacer", colorBlack, posW + 90, posH + 30);
	
	SDL_generate(context);
	int idReturn;
	while (1) {
		SDL_Delay(50);
		if (SDL_isMousePressed(SDL_BUTTON_LEFT)) {
			SDL_delImage(context, context->nbImg-1 );
			
			idReturn = context->nbText-SDL_ismouseover(context, TEXT);
			
			SDL_delText(context, context->nbText-6 );
			SDL_delText(context, context->nbText-5 );
			SDL_delText(context, context->nbText-4 );
			SDL_delText(context, context->nbText-3 );
			SDL_delText(context, context->nbText-2 );
			SDL_delText(context, context->nbText-1 );
			return idReturn;
		}
	}
}

int menuStart(t_context * context){
	int i;
	for(i = 0; i < context->nbSet; i++){
		SDL_freeSet(context, i); // Free all set
	}
	int posW = (SCREEN_WIDTH-313)/2;
	int posH = (SCREEN_HEIGHT-178)/2;
	SDL_newImage(context, NULL, "menu.png", posW,  posH);
	
	// SDL_newText(context, NULL, "5 - Menu Principal", colorBlack, posW + 90, posH + 130);
	SDL_newText(context, NULL, "4 - Quitter", colorBlack, posW + 90, posH + 110);
	SDL_setOnLayer(context, TEXT, context->nbText - 1, 100);
	
	SDL_newText(context, NULL, "3 - IA vs IA", colorBlack, posW + 90, posH + 85);
	SDL_setOnLayer(context, TEXT, context->nbText - 1, 100);

	SDL_newText(context, NULL, "2 - Charger une partie", colorBlack, posW + 90,posH + 60);
	SDL_setOnLayer(context, TEXT, context->nbText - 1, 100);
	
	SDL_newText(context, NULL, "1 - Nouvelle Partie", colorBlack, posW + 90, posH + 35);
	SDL_setOnLayer(context, TEXT, context->nbText - 1, 100);
	// SDL_printLayer(context);
	
	int idReturn;
	SDL_generate(context);
	
	while (1) {
		SDL_Delay(50);
		if (SDL_isMousePressed(SDL_BUTTON_LEFT)) {
			
			SDL_delImage(context, context->nbImg-1 );
			
			idReturn = context->nbText-SDL_ismouseover(context, TEXT);
			
			// SDL_delText(context, context->nbText-5 );
			SDL_delText(context, context->nbText-4 );
			SDL_delText(context, context->nbText-3 );
			SDL_delText(context, context->nbText-2 );
			SDL_delText(context, context->nbText-1 );
			return idReturn;
		}
	}
}
