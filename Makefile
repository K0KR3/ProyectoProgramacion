
EXE = game
CFLAGS = -Wall -ansi -pedantic
CC = gcc

all: $(EXE)

$(EXE): space.o player.o object.o command.o
		$(CC) -o space.o player.o object.o command.o

space.o: space.c 
		$(CC) $(CFLAGS) -c space.o

player.o: player.c 
		$(CC) $(CFLAGS) -c player.o

object.o: object.c 
		$(CC) $(CFLAGS) -c object.o

command.o: command.c 
		$(CC) $(CFLAGS) -c command.o

clean: 
		rm -f *.o $(EXE) 

	