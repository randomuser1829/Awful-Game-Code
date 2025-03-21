#include "thinker.h"

void NeuronActivation(int fromwho)
{
	for(int i = 0; i < CurrentWorld().thinkernum; i++)
	{
		int t = CurrentWorld().thinkers[i].thinkertype;
		
		if(t == MT_PLAYER) PlayerNeuron(i);
	}
}
