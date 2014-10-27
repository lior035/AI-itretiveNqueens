#ifndef Iter_Algo
#define Iter_Algo

#include "board.h"

class iterativeAlgo
{
	board * addres;

public:
	void updateAdd(board * br);
	board * getAdd ();
	void runAlgo();
};

#endif