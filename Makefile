CC=gcc
LUA_VERSION=lua-5.3.2
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
DISPLAY=@if test -e temp.errors; then echo $@ "\t\t$(ERROR_STRING)" && cat temp.log; elif test -s temp.log; then echo $@ "\t\t$(WARN_STRING)\n" && cat temp.log; else echo $@ "\t\t$(OK_STRING)"; fi;rm -f temp.errors temp.log

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
	@test -d ./$(LUA_VERSION) || { echo "\t$(ERROR_COLOR)[ERRORS] LUA NOT FOUND \n$(WARN_COLOR)\trun ' make lua '$(NO_COLOR)"; exit 2;}
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
	@if [ -d "./$(LUA_VERSION)" ]; then { echo "\t$(ERROR_COLOR)[ERRORS] LUA is already installed \n$(WARN_COLOR)\trun ' make lua-rm ' to clean lua$(NO_COLOR)"; exit 1; }  fi
	curl -R -O http://www.lua.org/ftp/$(LUA_VERSION).tar.gz
	tar zxf $(LUA_VERSION).tar.gz
	rm $(LUA_VERSION).tar.gz
	cd $(LUA_VERSION) && make $(PLAT) && make local
lua-rm:
	rm -rf lua-* $(OUTERROR)
	$(DISPLAY)
require: # if #include <readline/readline.h> is missing
	apt-get install libreadline-dev $(OUTERROR)
	$(DISPLAY)
.PHONY: rien
