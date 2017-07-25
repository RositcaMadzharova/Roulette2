/*
 * Credit.h
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#ifndef CREDITS_H_
#define CREDITS_H_
#include "GLOBALS.h"
#include "Text.h"
#include <map>

class Credits
{
public:
	Credits(int = 0);
	virtual ~Credits();
	void AddBet(int);
	void ChangeCredits(int);
	int GetBet() const;
	int GetCredit() const;
	void SetBets(int bet);
	int GetWinProfit(){	return winProfit;}
	int GetCreditsCollected() const;
	void AddCreditsCollected(int creditsCollected);

	bool CollectProfit(int roulletteWinningNumber);

	//37-41 - even, red, black, odd
	map<int, int> betByNumberCell;

private:
	int currentCredit;
	int betCredit;
	int creditsCollected;

	int winProfit;
	void FillTheMapsOfRoulette();
	int NumberInCell(int i);

};

#endif /* CREDIT_H_ */
