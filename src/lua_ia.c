#include "../include/lua_ia.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

extern int i_perso_actuel;
extern t_perso ensemble_perso[i_nombre_classe];
extern t_perso tab_perso[i_taille_tab_perso];
extern int map[i_taille_map][i_taille_map];

void WaitUserInput(){
  fprintf(stderr, green "\nPress any key to continue...\n"raz );
  char tmp[10];
  scanf("%s",tmp);

}

int average(lua_State *L){
  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 5;
  if (n != nbParam) {
    fprintf(stderr, red "\nError in function 'average' must take %i parameter" raz ,nbParam );
    WaitUserInput();
    return -1;
  }
  double sum = 0;
  int i;
  // loop through each argument
  for (i = 1; i <= n; i++)  {
    // total the arguments
    if (!lua_isnumber(L, i)){
      fprintf(stderr, red "Error in function 'average' must take int parameter" raz );
      WaitUserInput();
      return -1;
		}else{

      sum += lua_tonumber(L, i);
    }
  }
  // push the average
  lua_pushnumber(L, sum / n);
  // push the sum
  lua_pushnumber(L, sum);
  // return the number of results
  return 2;
}

int palcePerso(lua_State *L){

  // get number of arguments
  int n = lua_gettop(L);
  int nbParam = 3;
  if (n != nbParam) {
    fprintf(stderr, red "Error in function 'palcePerso' must take %i parameter(s) \nexemple : "magenta"palcePerso(raw, column, selectedPerso)\n" raz ,nbParam );
    WaitUserInput();
    return -1;
  }

  int r, c, selectedPerso ;

  // total the arguments
  if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2) || !lua_isnumber(L, 3)){
    fprintf(stderr, red "Error in function 'palcePerso' must take int parameter\n" raz );
    WaitUserInput();
    return -1;
	}else{
    r = lua_tonumber(L, 1);
    c = lua_tonumber(L, 2);
    selectedPerso = lua_tonumber(L, 3);
  }

  if (recherche_perso_tab(r, c) !=- 1) {
    fprintf(stderr, red "Error in function 'palcePerso' can't place 2 perso at the same coordinates\n" raz );
    WaitUserInput();
    return -1;
  }
  if( selectedPerso < 0 || selectedPerso >= i_nombre_classe ){
    fprintf(stderr, red "invalid perso\n" raz );
    WaitUserInput();
    return -1;
  }
  if( r < 0 || r >= i_taille_map || c < 0 || c >= i_taille_map ){
    fprintf(stderr, red "invalid coordinates\n" raz );
    WaitUserInput();
    return -1;
  }
  // printf("%i %i %i\n", r , c , selectedPerso );
  t_perso * per;
  per=malloc(sizeof(t_perso));
  if (r < 5) {
    creation(per, selectedPerso, 'A', r, c);
  }else{
    creation(per, selectedPerso, 'B', r, c);
  }
  int i;
  for (i = 0; i < i_taille_tab_perso; i++) {
    if (tab_perso[i].i_HP_max == -1) {
      break;
    }
  }
  tab_perso[i]=*per; //On ajoute le perso au tableau.
  afficher_map();
  return 1;
}

int IA_play(char function[10], char script[20] ){
  // Create new Lua state and load the lua libraries
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  // register our functions
  lua_register(L, "avg", average);
  lua_register(L, "palcePerso", palcePerso);

  //run the script
  luaL_dofile(L, script);

  // Push "main" function to the Lua stack
  lua_getglobal(L, function);
  // Checks if top of the Lua stack is a function.
  if (lua_isfunction(L, -1) == 0) {
    fprintf(stderr, red "\nFunction %s is not found\n" raz, function );
    return -1;
  }
  // Perform the function call (0 arguments, 1 result, 0 Error) */
  fprintf(stderr, red "\nIn script %s : \n\n" raz, script );
  if (lua_pcall(L, 0, 1, 0) != 0) {
      fprintf(stderr, red "\nError running function f:%s\n" raz, lua_tostring(L, -1) );
  }
  // double c = lua_tonumber(L, -1); // retrieve the result
  // lua_pop(L, 1); // Pop retrieved value from the Lua stack
  // printf("\nThe number returned by main is %f\n", c);

  // cleanup Lua
  lua_close(L);

  return 0;
}
