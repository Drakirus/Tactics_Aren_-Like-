#ifndef _SDL_H_
#define _SDL_H_
#include <ESDL.h>
#include <math.h>

#define SCREEN_WIDTH 1280 /**< Largeur de la fenêtre */
#define SCREEN_HEIGHT 720 /**< Hauteur de la fenêtre */
#define HEIGHT_DECOR 82 /**< Hauteur d'un décor */
#define TILE_H 48 /**< Hauteur d'une tile */
#define TILE_W 96 /**< Largeur d'une tile */

#define N 10 /**< Taille de la map */
#define DOWN_RIGHT 1
#define DOWN_LEFT 2
#define UP_LEFT 3
#define UP_RIGHT 4

typedef enum{diamond, staggered, slide}type_Map;
extern int idCursor;
void toIso(type_Map tMap, int * x, int * y);
int offsetX(type_Map tMap);
int offsetY();
void getIndexMap(type_Map tMap, int posX, int posY, int * x, int * y);
void drawTile(t_context * context , type_Map tMap, int posX, int posY);
void drawTileplace(t_context * context , type_Map tMap, int posX, int posY);
void drawDecor(t_context * context , type_Map tMap, int posX, int posY);
void showCursor(t_context * context, type_Map tMap, int x, int y);
void drawMap(t_context * context, type_Map tMap);
void dragNdrop(t_context * context, type_Map tMap);
void GetClick(t_context * context, type_Map tMap, int* x, int* y);
void moveSpriteTo(t_context * context, type_Map tMap, int to, int idSprite );
int MenuPerso(t_context * context);
int menuInGame(t_context * context);
int menuStart(t_context * context);
void drawTileplaceACC(t_context * context , type_Map tMap, int posX, int posY);
#endif
