CC = gcc
CFLAGS = -W -Wall -ansi -std=c99 -g
LIBS = -L./SDL2_ttf/.libs
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf
INCLUDES = -I./SDL2_ttf
EXEC = pentamino
SRC = main.c donnees/bloc.c donnees/grille.c donnees/fonctions_fichier.c donnees/souris.c donnees/monde.c evenements/evenements.c graphique/graphique.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)
pentamino: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
doc: 
	doxygen pentamino.doc
	make -C latex
clean:
	rm -rf *.o *~ $(OBJ)
mrproper: clean
	rm -rf $(EXEC)