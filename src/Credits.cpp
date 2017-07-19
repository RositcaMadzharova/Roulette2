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

	for (int i = 0; i < NUMBER_OF_SECTORS; i++)
		betByNumberCell[i] = 0;
	betRed = 0;
	betBlack = 0;
	betOdd = 0;
	betEven = 0;

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

int Credits::NumberInCell(int i)
{
	if(i == 14)
		return 0;
	if(i > 0 && i <= 13)
		return i*3;
	if(i > 14 && i <= 26)
		return (i-13)*3 - 1;
	if(i> 27 && i <= 39)
		return (i-26)*i - 2;
	return -1;
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

	for (int i = 0; i < NUMBER_OF_SECTORS; i++)
		betByNumberCell[i] = right.betByNumberCell[i];
	betRed = right.betRed;
	betBlack = right.betBlack;
	betOdd = right.betOdd;
	betEven = right.betEven;
}
