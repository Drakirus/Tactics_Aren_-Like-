CC=gcc
CFLAGS=-g -Wall -lSDLmain -lSDL -lSDL_image -lSDL_ttf -lm
EXEC=bin/out
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)
INC= include/

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "\nOn reconstruit $@ a cause de $?"

src/sdl_isometric.o: $(INC)sdl_isometric.h
#src/display.o: $(INC)display.h $(INC)random.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)

mrproper: clean
	@rm -rf $(EXEC)

.PHONY: rien
