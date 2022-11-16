CC = gcc
CFLAGS = -W -Wall -ansi -std=c99 -g
LIBS = -L./SDL2_ttf/.libs
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf
INCLUDES = -I./SDL2_ttf
EXEC = pentamino
SRC = main.c blocs.c fenetre.c grille.c fonctions_fichier.c
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
	rm -rf *.o *~
mrproper: clean
	rm -rf $(EXEC)