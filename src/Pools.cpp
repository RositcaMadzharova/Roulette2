/*
 * Pools.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#include "Pools.h"

Pools::Pools(Credits & cr,int posx,int posy,int number) :Button(posx,posy)
{

	this->number=number;
	//static counter
}

Pools::~Pools() {
	// TODO Auto-generated destructor stub
}

bool Pools::isBet()
{
return true;
}

int Pools::GetNumber()
{
	return this->number;
}


SDL_Rect Pools::Draw(SDL_Rect & dest)
{
	SDL_RenderCopy(gRenderer,mTexture,NULL,&dest);
	SDL_RenderPresent(gRenderer);
	return dest;
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
