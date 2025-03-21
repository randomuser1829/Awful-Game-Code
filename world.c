#include "game.h"

world_t meinworld;

void SaveWorld(const char *wname) // ???
{
	FILE *file;
	char fname[80]; // let's hope there's no world filename with 80 fucking characters
	
	Warning("writing world...");
	
	strcpy(fname, "maps/");
	strcat(fname, wname);
	strcat(fname, ".wld");
	
	file = fopen(fname, "w");
	if(file == NULL)
	{
		Warning("cannot find world");
		return;
	}
	
	Warning("i made a world");
}

void LoadWorld(const char *wname)
{
	FILE *file;
	char fname[80];
	char fline[64];
	char *token;
	int tempwho;
	
	Warning("reading world...");
	
	strcpy(fname, "maps/");
	strcat(fname, wname);
	strcat(fname, ".wld");
	
	file = fopen(fname, "r");
	if(file == NULL)
	{
		Warning("cannot find world");
		return;
	}
	
	memset(&meinworld, 0, sizeof(meinworld));
	
	int tx;
	int ty;
	
	while(fgets(fline, 64, file))
	{
		tx = 0;
		ty = 0;
		token = strtok(fline, " ");
		tempwho = 0;
		while(token != NULL)
		{
			if(tempwho == 0) tx = token - '0';
			else if(tempwho == 1) ty = token - '0';
			else if(tempwho == 2)
			{
				if(ItExists(token))
				{
					AddThinker(tx, ty, token);
				}
			}
			tempwho++;
			token = strtok(fline, " ");
		}
	}
	
	Warning("loaded world");
}

world_t CurrentWorld() {return meinworld;}

void AddThinker(int x, int y, const char *thinkernum)
{
	meinworld.thinkers[meinworld.thinkernum] = GetThinker(thinkernum);
	meinworld.thinkers[meinworld.thinkernum].x = x;
	meinworld.thinkers[meinworld.thinkernum].y = y;
	
	meinworld.thinkernum++;
}
