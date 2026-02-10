EXE = game
CFLAGS = -Wall -ansi -pedantic
CC = gcc
LIB = libscreen.a

all: $(EXE)

$(EXE): game.o command.o game_actions.o game_loop.o game_reader.o graphic_engine.o object.o player.o space.o
	$(CC) -o $@ $^ $(LIB) 

game.o: game.c
	$(CC) $(CFLAGS) -c $< -o $@

command.o: command.c
	$(CC) $(CFLAGS) -c $< -o $@

game_actions.o: game_actions.c
	$(CC) $(CFLAGS) -c $< -o $@

game_loop.o: game_loop.c
	$(CC) $(CFLAGS) -c $< -o $@

game_reader.o: game_reader.c
	$(CC) $(CFLAGS) -c $< -o $@

graphic_engine.o: graphic_engine.c
	$(CC) $(CFLAGS) -c $< -o $@

object.o: object.c
	$(CC) $(CFLAGS) -c $< -o $@

player.o: player.c
	$(CC) $(CFLAGS) -c $< -o $@

space.o: space.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXE)