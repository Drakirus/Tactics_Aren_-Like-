CC=gcc
CFLAGS=-g -Wall
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
src/action.o: $(INC)action.h $(INC)perso.h $(INC)map.h $(INC)tableau.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)

mrproper: clean
	@rm -rf $(EXEC)

.PHONY: rien
