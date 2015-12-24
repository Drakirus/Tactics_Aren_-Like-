CC=gcc
CFLAGS=-g -Wall -I/usr/include/lua5.1 -llua5.1

EXEC=bin/out
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)
INC= include/

$(EXEC): $(OBJ)
	test -d ./bin || mkdir ./bin
	$(CC) $(CFLAGS) -o $@ $^
	@echo "\nOn reconstruit $@ a cause de $?"

src/main.o: $(INC)map.h $(INC)placement.h $(INC)tableau.h $(INC)tour.h
src/placement.o: $(INC)map.h $(INC)placement.h $(INC)tableau.h
src/map.o:
src/tour.o: $(INC)perso.h $(INC)save.h $(INC)map.h $(INC)action.h
src/tableau.o: $(INC)perso.h
src/save.o: $(INC)map.h $(INC)placement.h $(INC)tableau.h
src/action.o: $(INC)action.h
src/couleur.o: $(INC)couleur.h
src/lua_ia.o:  $(INC)lua_ia.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)

mrproper: clean
	@rm -rf $(EXEC)
rmdoc:
	rm -rf $(DOCDIR)
doc: rmdoc
	doxygen doxytics

ifndef sys
SYS=linux
else
SYS=$(sys)
endif

install-lua:
	wget http://www.lua.org/ftp/lua-5.2.1.tar.gz
	tar -zxvf lua-5.2.1.tar.gz
	rm -rf lua-5.2.1.tar.gz
	cd ./lua-5.2.1 && make $(SYS) install
	cd ..
rm-lua:
	rm -rf lua-5.2.1

.PHONY: local
