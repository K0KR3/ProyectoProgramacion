cat > Makefile <<'EOF'
all: game

game: game_loop.o game.o game_actions.o game_reader.o graphic_engine.o space.o player.o object.o command.o
	gcc -o game game_loop.o game.o game_actions.o game_reader.o graphic_engine.o space.o player.o object.o command.o libscreen.a

game_loop.o: game_loop.c
	gcc -Wall -ansi -pedantic -c game_loop.c

game.o: game.c
	gcc -Wall -ansi -pedantic -c game.c

game_actions.o: game_actions.c
	gcc -Wall -ansi -pedantic -c game_actions.c

game_reader.o: game_reader.c
	gcc -Wall -ansi -pedantic -c game_reader.c

graphic_engine.o: graphic_engine.c
	gcc -Wall -ansi -pedantic -c graphic_engine.c

space.o: space.c
	gcc -Wall -ansi -pedantic -c space.c

player.o: player.c
	gcc -Wall -ansi -pedantic -c player.c

object.o: object.c
	gcc -Wall -ansi -pedantic -c object.c

command.o: command.c
	gcc -Wall -ansi -pedantic -c command.c

clean:
	rm -f *.o game
EOF




	
