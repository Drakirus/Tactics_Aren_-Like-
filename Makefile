CC=gcc

LUA_LIB_DIR = ./lua-5.3.2/install/lib
LUA_INCLUDE = ./lua-5.3.2/install/include
CFLAGS=-Wall -lm -L$(LUA_LIB_DIR) -llua -lm -ldl -I$(LUA_INCLUDE)

EXEC=bin/out
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)
INC= include/

OK_COLOR=\033[32;01m
NO_COLOR=\033[0m

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)

$(EXEC): $(OBJ)
	@test -d ./bin || mkdir ./bin
	$(CC) -o $@ $^  $(CFLAGS)
	@printf "\n$@ \t $(OK_STRING)\n"

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
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "$@ \t $(OK_STRING)\n"

ifndef plat
PLAT=linux
else
PLAT=$(plat)
endif

clean:
	@rm -f $(OBJ)
	@printf "\n$@ \t $(OK_STRING)\n"
mrproper: clean
	@rm -rf $(EXEC)
	@printf "\n$@ \t $(OK_STRING)\n"
rmdoc:
	rm -rf $(DOCDIR)
	@printf "\n$@ \t $(OK_STRING)\n"
doc: rmdoc
	doxygen doxytics
	@printf "\n$@ \t $(OK_STRING)\n"
lua:
	test -d ./lua-5.3.2 || curl -R -O http://www.lua.org/ftp/lua-5.3.2.tar.gz
	test -d ./lua-5.3.2 || tar zxf lua-5.3.2.tar.gz;rm lua-5.3.2.tar.gz
	cd lua-5.3.2 && make $(PLAT) && make local
	@printf "\n$@ \t $(OK_STRING)\n"
lua-rm:
	rm -rf lua-5.3.2
	@printf "\n$@ \t $(OK_STRING)\n"
require: # if #include <readline/readline.h> is missing
	apt-get install libreadline-dev
	@printf "\n$@ \t $(OK_STRING)\n"
.PHONY: rien
