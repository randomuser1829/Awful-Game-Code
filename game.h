// big nasty fucking file

#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "thinker.h" // <--- uncool

#define FALSE 0
#define TRUE 1

//
// system coolz
//

typedef enum
{
	EV_QUIT,
	EV_WHATTHEFUCK,
} event_t;

typedef enum
{
	GB_NODRAW,
} globaltype_t;

typedef struct
{
	int nodraw;
} sysglobals_t;

void MoveCursor(short x, short y);

void Init();

void Update();
void Draw();

void Quit();

void SendEvent(int eventnum);
void SendMainEvent(int eventnum);

void Warning(const char *text);
void Crash(const char *text);

sysglobals_t GetGlobals();
void SetGlobals(int gtype, int value);

//
// brains smarter than ai
//

#define MAX_REGISTERED_THINKERS 32
#define MAX_THINKERS 1024 // gee, that's alot.

typedef enum
{
	MT_NULL = 0,
	MT_PLAYER
} thinkers_t;

typedef struct
{
	int thinkertype;
	
	int x;
	int y;
	
	char style;
} thinker_t;

void RegisterThinker(const char *name, int thinkernum);
void NeuronActivation(int fromwho);
int ItExists(const char *name);
thinker_t GetThinker(const char *ttype);

//
// world star
//

typedef struct
{
	thinker_t thinkers[MAX_THINKERS];
	int thinkernum;
} world_t;

void SaveWorld(const char *wname); // ???
void LoadWorld(const char *wname);

world_t CurrentWorld();

void AddThinker(int x, int y, const char *thinkernum);

//
// the man who plays
//

typedef struct
{
	int horizontal;
	int vertical;
	
	int interact;
	int menuthing;
} usercmd_t;

typedef enum
{
	CM_MOVEUP,
	CM_MOVELEFT,
	CM_MOVEDOWN,
	CM_MOVERIGHT,
	CM_INTERACT,
	CM_MENUTHING
} cmdswitch_t;

void SwitchUserCmd(int switchnum, int value);
void ResetUserCmd();

#endif
