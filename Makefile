CC=gcc
CFLAGS=-g -Wall -lm
EXEC=bin/out
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)
INC= include/

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "    On reconstruit $@ a cause de $?"

src/home_main.o: $(INC)perso_p.h $(INC)gener_map.h
src/perso.o: $(INC)perso.h
src/gener_map.o: $(INC)gener_map.h
#src/display.o: $(INC)display.h $(INC)random.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)

mrproper: clean
	@rm -rf $(EXEC)
