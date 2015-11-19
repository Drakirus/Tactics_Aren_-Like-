CC=gcc
SRCDIR=./src
INCDIR=./include
FLAG=-Wall
BINDIR=./bin
OBJ=Outil.o

ifndef size
SIZE=-DN=4
else
SIZE=-DN=$(size)
endif

ifeq ($(size),1)
SIZE=-DN=4
endif



main: $(OBJ)
	test -d $(BINDIR) || mkdir $(BINDIR)
	$(CC) -o $(BINDIR)/main $(SRCDIR)/main.c $(OBJ) $(FLAG) $(SIZE) -I $(INCDIR)
#main.o: $(SRCDIR)/main.c
#	$(CC) -c $(SRCDIR)/main.c $(FLAG) $(SIZE)
Outil.o: $(SRCDIR)/Outil.c
	$(CC) -c $(SRCDIR)/Outil.c -I $(INCDIR)
clean:
	rm -rf $(BINDIR)
