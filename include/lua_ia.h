#ifndef _LUA_H_
#define _LUA_H_

#include <stdio.h>
#include <stdlib.h>

#include "./map.h"
#include "./action.h"
#include "./tableau.h"
#include "./list_attack.h"


#include "lua.h" // ../lua-5.3.2/install/include/
#include "lualib.h"
#include "lauxlib.h"

int IA_play(char function[10], char script[20] );

#endif
