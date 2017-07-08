/*
 * Pools.h
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#ifndef POOLS_H_
#define POOLS_H_
#include "Globals.h"
#include "Button.h"
#include "Credits.h"

class Pools :public Button{
public:
	Pools();
	Credits cr;
	Pools(Credits& ,int x=0,int y=0,int number=0);
	virtual ~Pools();
	bool isBet();
	int GetNumber();
	int PossibleWin();
private:
	static bool bet;
	int number;
};

#endif
