#include "game.h"

int shouldQuit;

void SendMainEvent(int eventnum)
{
	switch(eventnum)
	{
	case EV_QUIT:
		shouldQuit = TRUE;
		break;
	default:
		Warning("SendMainEvent: unknown event num");
		break;
	}
}

int main(int argc, char *argv[])
{
	if(argc > 0)
	{
		for(int i = 0; i < argc; i++)
		{
			if(argv[i] == "-nodraw") { SetGlobals(GB_NODRAW, TRUE); Warning("nodraw enabled"); }
		}
	}
	
	Init();

	while(!shouldQuit)
	{
		Update();
		Draw();
		Sleep(1000/35);
	}

	Quit();

	return 0;
}
