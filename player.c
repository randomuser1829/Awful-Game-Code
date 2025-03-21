#include "game.h"

usercmd_t usercmd;

void SwitchUserCmd(int switchnum, int value)
{
	if(switchnum == CM_MOVEUP) {if(value == TRUE) usercmd.vertical = 1;else usercmd.vertical = 0;}
	else if(switchnum == CM_MOVELEFT) {if(value == TRUE) usercmd.horizontal = -1;else usercmd.horizontal = 0;}
	else if(switchnum == CM_MOVEDOWN) {if(value == TRUE) usercmd.vertical = -1;else usercmd.vertical = 0;}
	else if(switchnum == CM_MOVERIGHT) {if(value == TRUE) usercmd.horizontal = 1;else usercmd.horizontal = 0;}
	
	else if(switchnum == CM_INTERACT) usercmd.interact = value;
	else if(switchnum == CM_MENUTHING) usercmd.menuthing = value;
}

void ResetUserCmd()
{
	usercmd.horizontal = 0;
	usercmd.vertical = 0;
	
	usercmd.interact = FALSE;
	usercmd.menuthing = FALSE;
}

void PlayerNeuron(int myguy)
{
	CurrentWorld().thinkers[myguy].x += usercmd.horizontal;
	CurrentWorld().thinkers[myguy].y -= usercmd.vertical;
}
