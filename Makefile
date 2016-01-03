CC=gcc

LUA_LIB_DIR = ./lua-5.3.2/install/lib
LUA_INCLUDE = ./lua-5.3.2/install/include
CFLAGS=-Wall -lm -L$(LUA_LIB_DIR) -llua -lm -ldl -I$(LUA_INCLUDE)

EXEC=bin/out
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)
INC= include/

NO_COLOR=\033[0m
OK_COLOR=\033[32;01m
ERROR_COLOR=\033[31;01m
WARN_COLOR=\033[33;01m

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING=$(WARN_COLOR)[WARNINGS]$(NO_COLOR)

OUTERROR=2> temp.log || touch temp.errors
DISPLAY=@if test -e temp.errors; then echo $@ "\t$(ERROR_STRING)" && cat temp.log; elif test -s temp.log; then echo $@ "\t$(WARN_STRING)\n" && cat temp.log; else echo $@ "\t$(OK_STRING)"; fi;rm -f temp.errors temp.log

$(EXEC): $(OBJ)
	@test -d ./bin || mkdir ./bin
	@$(CC) -o $@ $^  $(CFLAGS) $(OUTERROR)
	$(DISPLAY)

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
	@$(CC) $(CFLAGS) -o $@ -c $< $(OUTERROR)
	$(DISPLAY)

ifndef plat
PLAT=linux
else
PLAT=$(plat)
endif

clean:
	@rm -f $(OBJ) $(OUTERROR)
	$(DISPLAY)
mrproper: clean lua-rm
	@rm -rf $(EXEC) $(OUTERROR)
	$(DISPLAY)
rmdoc:
	rm -rf $(DOCDIR) $(OUTERROR)
	$(DISPLAY)
doc: rmdoc
	doxygen doxytics $(OUTERROR)
	$(DISPLAY)
lua:
	test -d ./lua-5.3.2 || curl -R -O http://www.lua.org/ftp/lua-5.3.2.tar.gz
	test -d ./lua-5.3.2 || tar zxf lua-5.3.2.tar.gz || rm lua-5.3.2.tar.gz
	cd lua-5.3.2 && make $(PLAT) && make local
lua-rm:
	rm -rf lua-5.3.2 $(OUTERROR)
	$(DISPLAY)
require: # if #include <readline/readline.h> is missing
	apt-get install libreadline-dev $(OUTERROR)
	$(DISPLAY)
.PHONY: rien
