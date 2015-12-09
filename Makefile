CC=gcc
CFLAGS=-g -Wall -lm
EXEC=bin/out
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)
INC= include/

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "\nOn reconstruit $@ a cause de $?"

src/main.o: $(INC)gener_map.h $(INC)placement.h $(INC)tableau.h $(INC)tour.h
src/placement.o: $(INC)gener_map.h $(INC)placement.h $(INC)tableau.h
src/gener_map.o:
src/tour.o: $(INC)perso.h $(INC)save.h $(INC)gener_map.h
src/tableau.o: $(INC)perso.h
src/save.o: $(INC)gener_map.h $(INC)placement.h $(INC)perso.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)

mrproper: clean
	@rm -rf $(EXEC)

.PHONY: rien
