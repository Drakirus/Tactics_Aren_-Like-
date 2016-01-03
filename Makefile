CC=gcc

LUA_LIB_DIR = ./lua-5.3.2/install/lib
LUA_INCLUDE = ./lua-5.3.2/install/include
CFLAGS=-Wall -lm -L$(LUA_LIB_DIR) -llua -lm -ldl

EXEC=bin/out
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)
INC= include/

$(EXEC): $(OBJ)
	test -d ./bin || mkdir ./bin
	$(CC) -o $@ $^  $(CFLAGS)
	@echo "\nOn reconstruit $@ a cause de $?"

src/main.o: $(INC)map.h $(INC)placement.h $(INC)tableau.h $(INC)tour.h
src/placement.o: $(INC)map.h $(INC)placement.h $(INC)tableau.h
src/map.o:
src/tour.o: $(INC)perso.h $(INC)save.h $(INC)map.h $(INC)action.h
src/tableau.o: $(INC)perso.h
src/save.o: $(INC)map.h $(INC)placement.h $(INC)tableau.h
src/action.o: $(INC)action.h
src/couleur.o: $(INC)couleur.h
src/lua_ia.o: $(INC)action.h $(INC)lua_ia.h



%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

mrproper: clean
	@rm -rf $(EXEC)
rmdoc:
	rm -rf $(DOCDIR)
doc: rmdoc
	doxygen doxytics
lua:
	curl -R -O http://www.lua.org/ftp/lua-5.3.2.tar.gz
	tar zxf lua-5.3.2.tar.gz
	rm lua-5.3.2.tar.gz
	cd lua-5.3.2 && make linux && make local
require: # if #include <readline/readline.h> is missing
	apt-get install libreadline-dev

.PHONY: rien
