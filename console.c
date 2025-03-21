#include "game.h"

FILE *logfile;

void MoveCursor(short x, short y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {x, y};

	SetConsoleCursorPosition(handle, coord);
}

void Warning(const char *text)
{
	if(!GetGlobals().nodraw) return;
	
	printf("%s\n", text);
}
