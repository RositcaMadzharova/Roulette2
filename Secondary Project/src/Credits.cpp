/*
 * Credit.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#include "Credits.h"

map<int, char> colorToNumberInRoulette;

Credits::Credits(int cCredit)
{
	this->currentCredit = cCredit;
	this->betCredit = 0;
	this->creditsCollected = 0;
	for (int i = 0; i < NUMBER_OF_SECTORS + 2 + 4; i++) // 2 empty, 4 special
		betByNumberCell[i] = 0;
	FillTheMapsOfRoulette();
	winProfit = 0;
//	textCash = NULL;
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

int Credits::GetBet() const
{
	return betCredit;
}

int Credits::GetCredit() const
{
	return currentCredit;
}

int Credits::GetCreditsCollected() const
{
	return creditsCollected;
}

void Credits::AddCreditsCollected(int creditsCollected)
{
	this->creditsCollected += creditsCollected;
}

void Credits::SetBets(int bet)
{
	this->betCredit = bet;
}


bool Credits::CollectProfit(int roulletteWinningNumber)
{
	bool done;
	 winProfit = betByNumberCell[NumberInCell(
			roulletteWinningNumber)]
			* MULTIPLIER_NUMBER;
	if (roulletteWinningNumber != 0)
	{
		if (roulletteWinningNumber % 2)
			winProfit += betByNumberCell[42]
					* MULTIPLIER_PARITY;
		else
			winProfit += betByNumberCell[39]
					* MULTIPLIER_PARITY;
		if (colorToNumberInRoulette[roulletteWinningNumber] == 'b')
			winProfit += betByNumberCell[41]
					* MULTIPLIER_COLOR;
		else
			winProfit += betByNumberCell[40]
					* MULTIPLIER_COLOR;
	}
	done = winProfit > betCredit;
 	ChangeCredits(winProfit);
	for (int i = 0; i < NUMBER_OF_SECTORS + 2 + 4; i++)
			betByNumberCell[i] = 0;
	betCredit = 0;

	cout << winProfit <<" win Profits "<<endl;
	return done;
}

int Credits::NumberInCell(int i)
{
	if (i == 14)
		return 0;
	if (i > 0 && i <= 13)
		return i * 3;
	if (i > 14 && i <= 26)
		return (i - 13) * 3 - 1;
	if (i > 27 && i <= 39)
		return (i - 26) * i - 2;
	return -100;
}


void Credits::FillTheMapsOfRoulette()
{
	colorToNumberInRoulette[6] = 'b';
	colorToNumberInRoulette[27] = 'r';
	colorToNumberInRoulette[13] = 'b';
	colorToNumberInRoulette[36] = 'r';
	colorToNumberInRoulette[11] = 'b';
	colorToNumberInRoulette[30] = 'r';
	colorToNumberInRoulette[8] = 'b';
	colorToNumberInRoulette[23] = 'r';
	colorToNumberInRoulette[10] = 'b';
	colorToNumberInRoulette[5] = 'r';
	colorToNumberInRoulette[24] = 'b';
	colorToNumberInRoulette[16] = 'r';
	colorToNumberInRoulette[33] = 'b';
	colorToNumberInRoulette[1] = 'r';
	colorToNumberInRoulette[20] = 'b';
	colorToNumberInRoulette[14] = 'r';
	colorToNumberInRoulette[31] = 'b';
	colorToNumberInRoulette[9] = 'r';
	colorToNumberInRoulette[22] = 'b';
	colorToNumberInRoulette[18] = 'r';
	colorToNumberInRoulette[29] = 'b';
	colorToNumberInRoulette[7] = 'r';
	colorToNumberInRoulette[28] = 'b';
	colorToNumberInRoulette[12] = 'r';
	colorToNumberInRoulette[35] = 'b';
	colorToNumberInRoulette[3] = 'r';
	colorToNumberInRoulette[26] = 'b';
	colorToNumberInRoulette[0] = 'g';
	colorToNumberInRoulette[32] = 'r';
	colorToNumberInRoulette[15] = 'b';
	colorToNumberInRoulette[19] = 'r';
	colorToNumberInRoulette[4] = 'b';
	colorToNumberInRoulette[21] = 'r';
	colorToNumberInRoulette[2] = 'b';
	colorToNumberInRoulette[25] = 'r';
	colorToNumberInRoulette[17] = 'b';
	colorToNumberInRoulette[34] = 'r';

}
