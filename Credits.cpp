/*
 * Credits.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#include "Credits.h"

Credits::Credits(int cCredit)
{
	this->currentCredit = cCredit;
	this->betCredit = 0;
	this->possibleWin = 0;

	for (int i = 0; i < NUMBER_OF_SECTORS + 2 + 4; i++) // 2 empty, 4 special
		betByNumberCell[i] = 0;
}

Credits::~Credits()
{
}

void Credits::AddBet(int bet)
{
	betCredit += bet;
}

void Credits::ChangeCredits(int change)
{
	currentCredit += change;
}

void Credits::SetBet(int betCredit)
{
	this->betCredit = (currentCredit > 0) ? betCredit : 0;
}

int Credits::GetBet() const
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
	this->possibleWin = possibleWin;
}

bool Credits::isCashedOut()
{
	//TODO if(button.pressed cashout )
	//set currentcredit =0;
	return false;
}

Credits::Credits(Credits& right)
{
	this->currentCredit = right.currentCredit;
	this->betCredit = right.currentCredit;
	this->possibleWin = right.possibleWin;

	for (int i = 0; i < NUMBER_OF_SECTORS + 2 + 4; i++)
		betByNumberCell[i] = right.betByNumberCell[i];
}
