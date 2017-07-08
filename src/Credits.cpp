/*
 * Credits.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#include "Credits.h"



Credits::Credits(int cCredit)
{
	this->currentCredit=cCredit;
	this->betCredit=0;
	this->possibleWin=0;
}

Credits::~Credits()
{
	// TODO Auto-generated destructor stub
}

void Credits::SetBet(int betCredit)
{
	this->betCredit=(currentCredit>0 )? betCredit: 0;
}

int Credits::GetBet()const
{
	return betCredit;
}


int Credits::GetCredit() const
{
	return currentCredit;
}

int Credits::GetPossibleWin() const
{
	return possibleWin;
}

void Credits::SetPossibleWin(int posibleWin)
{
	this->possibleWin=possibleWin;
}

bool Credits::isCashedOut()
{
	//TODO if(button.pressed cashout )
	//set currentcredit =0;
	return false ;
}

Credits::Credits(Credits& right)
{
	this->currentCredit=right.currentCredit;
	this->betCredit=right.currentCredit;
	this->possibleWin=right.possibleWin;
}
