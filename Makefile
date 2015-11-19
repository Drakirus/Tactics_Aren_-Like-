CC=gcc
SRCDIR=./src
INCDIR=./include
FLAG=-Wall
BINDIR=./bin
OBJ=Outil.o


main: $(OBJ)
	test -d $(BINDIR) || mkdir $(BINDIR)
	$(CC) -o $(BINDIR)/main $(SRCDIR)/main.c $(OBJ) $(FLAG) -I $(INCDIR)
#main.o: $(SRCDIR)/main.c
#	$(CC) -c $(SRCDIR)/main.c $(FLAG) $(SIZE)
Outil.o: $(SRCDIR)/Outil.c
	$(CC) -c $(SRCDIR)/Outil.c -I $(INCDIR)
clean:
	rm -rf $(BINDIR)
