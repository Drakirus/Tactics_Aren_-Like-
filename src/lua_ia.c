int PA_actuel, PM_actuel;
#include "../include/lua_ia.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

extern int i_perso_actuel;
extern t_perso ensemble_perso[i_nombre_classe];
extern t_perso tab_perso[i_taille_tab_perso];
extern int map[i_taille_map][i_taille_map];

void WaitUserInput(){
  fprintf(stderr, green "Press any key to continue..."raz );
  char tmp[10];
  scanf("%s",tmp);

}
// ----------------------
// PLACEMENT
// ----------------------
int placePerso(lua_State *L){

  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 3;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'placePerso' must take %i parameter(s) \n\texemple : "magenta"placePerso(raw, column, selectedPerso)\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }

  int r, c, selectedPerso ;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2) || !lua_isnumber(L, 3)){
    fprintf(stderr, red "\tError in function 'placePerso' must take int parameter\n" raz );
    WaitUserInput();
    return 0;
	}else{
    r = lua_tonumber(L, 1);
    c = lua_tonumber(L, 2);
    selectedPerso = lua_tonumber(L, 3);
  }

  if (recherche_perso_tab(r, c) !=- 1) {
    fprintf(stderr, red "\tError in function 'placePerso' can't place 2 perso at the same coordinates\n" raz );
    WaitUserInput();
    return 0;
  }
  if( selectedPerso < 0 || selectedPerso >= i_nombre_classe ){
    fprintf(stderr, red "\tinvalid perso\n" raz );
    WaitUserInput();
    return 0;
  }

  int i;
  for (i = 0; i < i_taille_tab_perso; i++) {
    if (tab_perso[i].i_HP_max == -1) {
      break;
    }
  }

  int limiteA,limiteB;
  if ( (i % 2) == 0) {
    limiteA = 0;
    limiteB = 3;
  }else{
    limiteA = i_taille_map-3;
    limiteB = i_taille_map;
  }

  if( r < limiteA || r >= limiteB  || c < 0 || c >= i_taille_map ){
    fprintf(stderr, red "\tError in function 'placePerso'\n\tinvalid coordinates\n" raz );
    fprintf(stderr, "\tYour coordinates must be between the lines %i and %i\n",limiteA,limiteB-1);
    WaitUserInput();
    return 0;
  }
  // printf("%i %i %i\n", r , c , selectedPerso );
  t_perso * per;
  per=malloc(sizeof(t_perso));
  if (r < 5) {
    creation(per, selectedPerso, 'A', r, c);
  }else{
    creation(per, selectedPerso, 'B', r, c);
  }
  tab_perso[i]=*per; //On ajoute le perso au tableau.
  return 0;
}
// ----------------------
// Nombre de perso placer
// ----------------------
int nbPalcePerso(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 0;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'nbPalcePerso' must take %i parameter(s) \n\texemple : "magenta"nbperos = nbPalcePerso()\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  int i;
  for (i = 0; i < i_taille_tab_perso; i++) {
    if (tab_perso[i].i_HP_max == -1) {
      break;
    }
  }
  lua_pushnumber(L, (double)i);
  return 1;
}
// ----------------------
// coord du perso actuel
// ----------------------
int getCood(lua_State *L){
  // get number of arguments
  double n = lua_gettop(L);
  int nbParam = 0;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getCood' must take %i parameter(s) \n\texemple : "magenta"r,c = getCood()\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }

  lua_pushnumber(L, tab_perso[i_perso_actuel].coord[0]);
  lua_pushnumber(L, tab_perso[i_perso_actuel].coord[1]);
  return 2;
}
// ----------------------
// Nb pv perso en coord r,c
// ----------------------
int getLife(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getLife' must take %i parameter(s) \n\texemple : "magenta"life = getLife( getCoodPerso() )\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'getLife' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, -2);
    c = lua_tonumber(L, -1);
  }
  if ( recherche_perso_tab(r, c) == -1) {
    lua_pushnumber(L, -1);
    return 1;
  }
  double returnValue = tab_perso[recherche_perso_tab(r, c)].i_HP;
  lua_pushnumber(L, returnValue);
  return 1;
}
// ----------------------
// Nb pv total perso en coord r,c
// ----------------------
int getTotalLife(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getTotalLife' must take %i parameter(s) \n\texemple : "magenta"life = getTotalLife( getCoodPerso() )\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'getTotalLife' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, -2);
    c = lua_tonumber(L, -1);
  }
  if ( recherche_perso_tab(r, c) == -1) {
    lua_pushnumber(L, -1);
    return 1;
  }
  double returnValue = tab_perso[recherche_perso_tab(r, c)].i_HP_max;
  lua_pushnumber(L, returnValue);
  return 1;
}
// ----------------------
// Nb PA perso en coord r,c
// ----------------------
int getTotalPA(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getTotalPA' must take %i parameter(s) \n\texemple : "magenta"pa = getTotalPA( getCoodPerso() )\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'getTotalPA' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, -2);
    c = lua_tonumber(L, -1);
  }
  if ( recherche_perso_tab(r, c) == -1) {
    lua_pushnumber(L, -1);
    return 1;
  }
  double returnValue = tab_perso[recherche_perso_tab(r, c)].i_PA;
  lua_pushnumber(L, returnValue);
  return 1;
}

// ----------------------
// Nb PM perso en coord r,c
// ----------------------
int getTotalPM(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getTotalPM' must take %i parameter(s) \n\texemple : "magenta"pm = getTotalPM( getCoodPerso() )\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'getTotalPM' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, -2);
    c = lua_tonumber(L, -1);
  }
  if ( recherche_perso_tab(r, c) == -1) {
    lua_pushnumber(L, -1);
    return 1;
  }
  double returnValue = tab_perso[recherche_perso_tab(r, c)].i_PM;
  lua_pushnumber(L, returnValue);
  return 1;
}

// ----------------------
// return nom classe perso en coord r,c
// ----------------------
int getClass(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getClass' must take %i parameter(s) \n\texemple : "magenta"name = getClass( getCoodPerso() )\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'getClass' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, -2);
    c = lua_tonumber(L, -1);
  }
  if ( recherche_perso_tab(r, c) == -1) {
    lua_pushstring(L, "Error(character not find)");
    return 1;
  }
  lua_pushstring(L, tab_perso[recherche_perso_tab(r, c)].s_classe );
  return 1;
}

// ----------------------
// return coord r,c de l'enemy le plus proche de r,c
// ----------------------
int getNearestEnemy(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 0;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getNearestEnemy' must take %i parameter(s) \n\texemple : "magenta"enemy = getNearestEnemy()\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  int r, c;

  r = tab_perso[i_perso_actuel].coord[0];
  c = tab_perso[i_perso_actuel].coord[1];

  if( r < 0 || r >= i_taille_map  || c < 0 || c >= i_taille_map ){
    fprintf(stderr, red "\tError in function 'getNearestEnemy'\n\tinvalid coordinates\n" raz );
    fprintf(stderr, "\tYour coordinates must be between the lines 0 and %i\n",i_taille_map);
    WaitUserInput();
    return 0;
  }

  int i=0,j=0;
  int lowerPath = 9999;
  int **DistancePath = createDistancePath( r, c );
  int persoNearest=0;
  for (i = 0; i <  i_taille_map; i++){
    for (j = 0; j < i_taille_map; j++){
      if (recherche_perso_tab(i, j) != -1 && lowerPath > distanceFrom(i, j, DistancePath) && distanceFrom(i, j, DistancePath) != 0 ) {
         persoNearest = recherche_perso_tab(i, j);
         lowerPath =  distanceFrom(i, j, DistancePath);
      }
    }
  }
  freeBoard(DistancePath, i_taille_map);
  lua_pushnumber(L, tab_perso[persoNearest].coord[0]);
  lua_pushnumber(L, tab_perso[persoNearest].coord[1]);
  return 2;
}
// ----------------------
// return 0 pour vide 1 pour obstacle
// 2 si il y a un perso
// ----------------------
int getCellContent(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getCellContent' must take %i parameter(s) \n\texemple : "magenta"content = getCellContent(x, y)\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'getCellContent' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, -2);
    c = lua_tonumber(L, -1);
  }
  if( r < 0 || r >= i_taille_map  || c < 0 || c >= i_taille_map ){
    fprintf(stderr, red "\tError in function 'getCellContent'\n\tinvalid coordinates\n" raz );
    fprintf(stderr, "\tYour coordinates must be between the lines 0 and %i\n",i_taille_map);
    WaitUserInput();
    return 0;
  }
  if (recherche_perso_tab(r, c) == -1 ) {
    lua_pushnumber(L, map[(int)r][(int)c] );
    return 1;
  }
  lua_pushnumber(L, 2 );
  return 1;
}
// ----------------------
// return 1 pour ally 0 pour enemy
// -1 pour rien
// ----------------------
int isAlly(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'isAlly' must take %i parameter(s) \n\texemple : "magenta"Ally = isAlly(x, y)\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'isAlly' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, -2);
    c = lua_tonumber(L, -1);
  }
  if( r < 0 || r >= i_taille_map  || c < 0 || c >= i_taille_map ){
    fprintf(stderr, red "\tError in function 'isAlly'\n\tinvalid coordinates\n" raz );
    fprintf(stderr, "\tYour coordinates must be between the lines 0 and %i\n",i_taille_map);
    WaitUserInput();
    return 0;
  }
  if (recherche_perso_tab(r, c) == -1 ) {
    lua_pushnumber(L, -1 );
    return 1;
  }
  if (tab_perso[recherche_perso_tab(r, c)].c_team == tab_perso[i_perso_actuel].c_team ) {
    lua_pushnumber(L, 1 );
  }else{
    lua_pushnumber(L, 0 );
  }
  return 1;
}
// ----------------------
// return 0 pour ally 1 pour enemy
// -1 pour rien
// ----------------------
int isEnemy(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'isEnemy' must take %i parameter(s) \n\texemple : "magenta"enemy = isEnemy(x, y)\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'isEnemy' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, -2);
    c = lua_tonumber(L, -1);
  }
  if( r < 0 || r >= i_taille_map  || c < 0 || c >= i_taille_map ){
    fprintf(stderr, red "\tError in function 'isEnemy'\n\tinvalid coordinates\n" raz );
    fprintf(stderr, "\tYour coordinates must be between the lines 0 and %i\n",i_taille_map);
    WaitUserInput();
    return 0;
  }
  if (recherche_perso_tab(r, c) == -1 ) {
    lua_pushnumber(L, -1 );
    return 1;
  }
  if (tab_perso[recherche_perso_tab(r, c)].c_team != tab_perso[i_perso_actuel].c_team ) {
    lua_pushnumber(L, 1 );
  }else{
    lua_pushnumber(L, 0 );
  }
  return 1;
}
// ----------------------
// return the path between 2 cell
// ----------------------
int getPathLength(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getPathLength' must take %i parameter(s) \n\texemple : "magenta"path = getPathLength( 9, 0 )\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;
  int i = tab_perso[i_perso_actuel].coord[0];
  int j = tab_perso[i_perso_actuel].coord[1];

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'getPathLength' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, 1);
    c = lua_tonumber(L, 2);
  }

  if( r < 0 || r >= i_taille_map  || c < 0 || c >= i_taille_map || i < 0 || i >= i_taille_map  || j < 0 || j >= i_taille_map){
    fprintf(stderr, red "\tError in function 'getPathLength'\n\tinvalid coordinates\n" raz );
    fprintf(stderr, "\tYour coordinates must be between the lines 0 and %i\n",i_taille_map);
    WaitUserInput();
    return 0;
  }

  int **DistancePath = createDistancePath( (int)r, (int)c );
  lua_pushnumber(L, distanceFrom( (int)i, (int)j, DistancePath) );
  freeBoard(DistancePath, i_taille_map);
  return 1;
}

// ----------------------
// moveToward a perso to coord
// ----------------------
int moveToward(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 3;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'moveToward' must take %i parameter(s) \n\texemple : "magenta"moveToward( 0 , 0 , 1 ) where 0,0 are the coordinates and 1 the number of PA to use\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  int r, c, PA_toUse;
  int i = tab_perso[i_perso_actuel].coord[0];
  int j = tab_perso[i_perso_actuel].coord[1];

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2) || !lua_isnumber(L, 3) ){
    fprintf(stderr, red "\tError in function 'moveToward' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, 1);
    c = lua_tonumber(L, 2);
    PA_toUse = lua_tonumber(L, 3);
  }

  if( r < 0 || r >= i_taille_map  || c < 0 || c >= i_taille_map || i < 0 || i >= i_taille_map  || j < 0 || j >= i_taille_map){
    fprintf(stderr, red "\tError in function 'moveToward'\n\tinvalid coordinates\n" raz );
    fprintf(stderr, "\tYour coordinates must be between the lines 0 and %i\n",i_taille_map);
    WaitUserInput();
    return 0;
  }

  pile *path = NULL;
  int sortir;
  int **DistancePath = createDistancePath(i, j );
  int PA_used = 0;
  path = getPath(DistancePath, r, c);

  if (path == NULL)
    fprintf(stderr, "\tCan not move\n");
  else{
    sortir = pop(&path, &r, &c);
    afficher_map();
    while (sortir != -1) {
      sortir = pop(&path, &r, &c);
      // printf("r: %i c: %i\n",r,c );
      if ( PM_actuel > 0 && recherche_perso_tab(r, c) == -1 && PA_toUse != PA_used ) {
        change_nombre(6, &tab_perso[i_perso_actuel], c);
        change_nombre(5, &tab_perso[i_perso_actuel], r);
        PM_actuel--;
        PA_used++;
        afficher_map();
        delay(400);
      }

    }
  }
  return 0;

}

// ----------------------
// moveAway a perso to coord
// ----------------------
int moveAway(lua_State *L){

}

int IA_play(char function[10], char script[20] ){
  // Create new Lua state and load the lua libraries
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  // register our functions
  lua_register(L, "placePerso", placePerso );
  lua_register(L, "nbPalcePerso", nbPalcePerso );

  lua_register(L, "getCood", getCood );
  lua_register(L, "getClass", getClass );
  lua_register(L, "getTotalPA", getTotalPA );
  lua_register(L, "getTotalPM", getTotalPM );
  lua_register(L, "getLife", getLife );
  lua_register(L, "getTotalLife", getTotalLife );

  lua_register(L, "getNearestEnemy", getNearestEnemy );
  lua_register(L, "getCellContent", getCellContent );
  lua_register(L, "getPathLength", getPathLength );
  lua_register(L, "isAlly", isAlly );
  lua_register(L, "isEnemy", isEnemy );

  lua_register(L, "moveToward", moveToward );

  //run the script
  luaL_dofile(L, script);

  // Push "main" function to the Lua stack
  lua_getglobal(L, function);
  fprintf(stderr, green "\nIn script "raz"\"%s\""green"\nFunction: "raz"\"%s\"\n\n", script, function );
  // Checks if top of the Lua stack is a function.
  if (lua_isfunction(L, -1) == 0) {
    fprintf(stderr, red "\tFunction %s is not found\n" raz, function );
  }
  // Perform the function call (0 arguments, 1 result, 0 Error) */
  if (lua_pcall(L, 0, 1, 0) != 0) {
      fprintf(stderr, red "\tError LUA :"raz" %s\n" , lua_tostring(L, -1) );
      WaitUserInput();
      lua_close(L);
      return -1;
  }
  // double c = lua_tonumber(L, -1); // retrieve the result
  // lua_pop(L, 1); // Pop retrieved value from the Lua stack
  // printf("\nThe number returned by main is %f\n", c);

  // cleanup Lua
  lua_close(L);

  return 0;
}
