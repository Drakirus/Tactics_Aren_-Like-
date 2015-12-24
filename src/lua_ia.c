#include "../include/lua_ia.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

int perso_actuel = 0;
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
int getCoodPerso(lua_State *L){
  // get number of arguments
  double n = lua_gettop(L);
  int nbParam = 0;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getCoodPerso' must take %i parameter(s) \n\texemple : "magenta"r,c = getCoodPerso()\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }

  lua_pushnumber(L, tab_perso[perso_actuel].coord[0]);
  lua_pushnumber(L, tab_perso[perso_actuel].coord[1]);
  return 2;
}
// ----------------------
// Nb pv perso en coord r,c
// ----------------------
int getLifePerso(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getLifePerso' must take %i parameter(s) \n\texemple : "magenta"life= getLifePerso( getCoodPerso() )\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'getLifePerso' must take int parameters\n" raz );
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
int getTotalLifePerso(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getTotalLifePerso' must take %i parameter(s) \n\texemple : "magenta"life= getTotalLifePerso( getCoodPerso() )\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'getTotalLifePerso' must take int parameters\n" raz );
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
// return coord r,c de l'enemy le plus proche de r,c
// ----------------------
int getNearestEnemy(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getNearestEnemy' must take %i parameter(s) \n\texemple : "magenta"life= getNearestEnemy( getCoodPerso() )\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2)){
    fprintf(stderr, red "\tError in function 'getNearestEnemy' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, -2);
    c = lua_tonumber(L, -1);
  }
  if( r < 0 || r >= i_taille_map  || c < 0 || c >= i_taille_map ){
    fprintf(stderr, red "\tError in function 'getNearestEnemy'\n\tinvalid coordinates\n" raz );
    fprintf(stderr, "\tYour coordinates must be between the lines 0 and %i\n",i_taille_map);
    WaitUserInput();
    return 0;
  }

  int i=0,j=0;
  int lowerPath = 9999;
  int **DistancePath = createDistancePath( (int)r, (int)c );
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
// et le num de l'équipe
// ----------------------
int getCellContent(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 2;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getCellContent' must take %i parameter(s) \n\texemple : "magenta"life= getCellContent(x, y)\n" raz ,nbParam );
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
  if (tab_perso[recherche_perso_tab(r, c)].c_team == 'A') {
    lua_pushnumber(L, 2 );
  }else{
    lua_pushnumber(L, 3 );
  }
  return 1;
}
// ----------------------
// return the path between 2 cell
// ----------------------
int getPathLength(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 4;
  if (n != nbParam) {
    fprintf(stderr, red "\tError in function 'getPathLength' must take %i parameter(s) \n\texemple : "magenta"path= getPathLength( 0, 0, 9, 0 )\n" raz ,nbParam );
    WaitUserInput();
    return 0;
  }
  double r, c, i, j;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2) || !lua_isnumber(L, 3) || !lua_isnumber(L, 4)){
    fprintf(stderr, red "\tError in function 'getPathLength' must take int parameters\n" raz );
    WaitUserInput();
    return 0;
  }else{
    r = lua_tonumber(L, 1);
    c = lua_tonumber(L, 2);
    i = lua_tonumber(L, 3);
    j = lua_tonumber(L, 4);
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

int IA_play(char function[10], char script[20] ){
  // Create new Lua state and load the lua libraries
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  // register our functions
  lua_register(L, "placePerso", placePerso );
  lua_register(L, "nbPalcePerso", nbPalcePerso );
  lua_register(L, "getCoodPerso", getCoodPerso );
  lua_register(L, "getLifePerso", getLifePerso );
  lua_register(L, "getTotalLifePerso", getTotalLifePerso );
  lua_register(L, "getNearestEnemy", getNearestEnemy );
  lua_register(L, "getCellContent", getCellContent );
  lua_register(L, "getPathLength", getPathLength );

  //run the script
  luaL_dofile(L, script);

  // Push "main" function to the Lua stack
  lua_getglobal(L, function);
  fprintf(stderr, green "\nIn script "raz"\"%s\""green"\nFunction: "raz"\"%s\"\n\n", script, function );
  // Checks if top of the Lua stack is a function.
  if (lua_isfunction(L, -1) == 0) {
    fprintf(stderr, red "\tFunction %s is not found\n" raz, function );
    WaitUserInput();
    lua_close(L);
    return -1;
  }
  // Perform the function call (0 arguments, 1 result, 0 Error) */
  if (lua_pcall(L, 0, 1, 0) != 0) {
      fprintf(stderr, red "\tError running function :"raz" %s\n" , lua_tostring(L, -1) );
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
