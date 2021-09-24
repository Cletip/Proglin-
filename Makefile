
CC=gcc
CFLAGS=-Wall
LDFLAGS=-lm
EXEC=main

#pour SRC qui contient la liste des fichiers sources du projet (ici tous ler .c). OBJ pour la liste des fichiers objet.

SRC=$(wildcard *.c)
OBJ= $(SRC:.c=.o)



all: $(EXEC)



main:main.o fonction.o
	$(CC) -o $@ $^ $(LDFLAGS)



# uniquement pour une exeption

main.o: main.h

# règle général pour les fichiers
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

# clean est la cible d'une règle ne présentant aucune dépendance, on pallie ce
# problème avec .PHONY (les dépendances seront systématiquement reconstruites.)
.PHONY: clean mrproper run

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

run: $(EXEC)
	./$(EXEC)
