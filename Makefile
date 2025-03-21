all:
	if not exist bin mkdir bin
	cls
	gcc -o bin/game.exe *.c
