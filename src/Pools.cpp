/*
 * Pools.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#include "Pools.h"
Pools::Pools(){}
Pools::Pools(Credits & cr,int posx,int posy, int number)
	:Button(posx, posy)
{

	this->number=number;
	//static counter
}

Pools::~Pools() {
	// TODO Auto-generated destructor stub
}

bool Pools::isBet()
{
return false;
}

int Pools::GetNumber()
{
	return this->number;
}


int Pools::PossibleWin()
{
	if(GetNumber()<37)
	{
		//cr.SetPossibleWin(cred.GetBet()*36);

	}
	//TODO  red/black , odd/even

	return cr.GetPossibleWin();
}
