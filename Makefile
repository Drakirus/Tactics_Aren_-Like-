CC=gcc
SRCDIR=./src
INCDIR=./include
FLAG=-Wall
BINDIR=./bin
OBJ=Outil.o save.o placement.o gener_map.o tour.o tableau.o

main: $(OBJ)
        test -d $(BINDIR) || mkdir $(BINDIR)
        $(CC) -o $(BINDIR)/main $(SRCDIR)/main.c $(OBJ) $(FLAG) -I $(INCDIR)
#main.o: $(SRCDIR)/main.c
#       $(CC) -c $(SRCDIR)/main.c $(FLAG) $(SIZE)
Outil.o: $(SRCDIR)/Outil.c
        $(CC) -c $(SRCDIR)/Outil.c -I $(INCDIR)
save.o: $(SRCDIR)/save.c
        $(CC) -c $(SRCDIR)/save.c -I $(INCDIR)
placement.o: $(SRCDIR)/placement.c
        $(CC) -c $(SRCDIR)/placement.c -I $(INCDIR)
gener_map.o: $(SRCDIR)/gener_map.c
        $(CC) -c $(SRCDIR)/gener_map.c -I $(INCDIR)
tour.o: $(SRCDIR)/tour.c
        $(CC) -c $(SRCDIR)/tour.c -I $(INCDIR)
tableau.o: $(SRCDIR)/tableau.c
        $(CC) -c $(SRCDIR)/tableau.c -I $(INCDIR)
clean:
        rm -rf $(BINDIR)
