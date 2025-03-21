#include "game.h"

sysglobals_t gballs;
thinker_t registeredthinkers[MAX_REGISTERED_THINKERS];
char uh_huh[MAX_REGISTERED_THINKERS];
int registered;

void Init()
{
	RegisterThinker("info_player_start", MT_PLAYER);
	
	LoadWorld("test");
}

void Update()
{
	if(kbhit())
	{
		int ch = getch();
		switch(ch)
		{
		case 27:
			SendMainEvent(EV_QUIT);
			break;
		case 119:
			SwitchUserCmd(CM_MOVEUP, TRUE);
			break;
		case 97:
			SwitchUserCmd(CM_MOVELEFT, TRUE);
			break;
		case 115:
			SwitchUserCmd(CM_MOVEDOWN, TRUE);
			break;
		case 100:
			SwitchUserCmd(CM_MOVERIGHT, TRUE);
			break;
		case 32:
			SwitchUserCmd(CM_INTERACT, TRUE);
			break;
		case 13:
			SwitchUserCmd(CM_MENUTHING, TRUE);
			break;
		}
		
		//printf("%d\n", ch);
	}
	
	for(int i = 0; i < CurrentWorld().thinkernum; i++) NeuronActivation(i);
}

void Draw()
{
	if(gballs.nodraw) return;
	
	for(int i = 0; i < CurrentWorld().thinkernum; i++)
	{
		//int t = CurrentWorld().thinkers[i].thinkertype;
		int x = CurrentWorld().thinkers[i].x;
		int y = CurrentWorld().thinkers[i].y;
		char s = CurrentWorld().thinkers[i].style;
		
		MoveCursor(x, y);
		printf("%c", s);
	}
}

void Quit()
{
	Warning("quitting..."); // at this point, the Warning function has lost its meaning.
	
	// ...do what?
	
	Warning("quit");
}

void SendEvent(int eventnum)
{
	switch(eventnum)
	{
	case EV_WHATTHEFUCK:
		Crash("what the fuck");
		break;
	default:
		Warning("SendEvent: unknown event num");
		break;
	}
}

void Crash(const char *text)
{
	FILE *logger = fopen("crash.log", "w");
	fprintf(logger, text);
	fclose(logger);

	exit(1);
}

sysglobals_t GetGlobals(){return gballs;}
void SetGlobals(int gtype, int value)
{
	if(gtype == GB_NODRAW) gballs.nodraw = value;
}

void RegisterThinker(const char *name, int thinkernum)
{
	registeredthinkers[registered].thinkertype = thinkernum;
	uh_huh[registered] = name;
	switch(thinkernum)
	{
		case MT_PLAYER:
			registeredthinkers[registered].style = '*';
			break;
		default:
			Crash("RegisterThinker: unknown thinkernum!");
			break;
	}
	
	registered++;
}

int ItExists(const char *name)
{
	for(int i = 0; i < registered; i++)
	{
		if(uh_huh[i] == name) return TRUE;
	}
	
	return FALSE;
}

thinker_t GetThinker(const char *ttype)
{
	for(int i = 0; i < registered; i++)
	{
		if(uh_huh[i] == ttype) registeredthinkers[i];
	}
	
	return registeredthinkers[0];
}
