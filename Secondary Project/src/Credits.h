/*
 * Credit.h
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#ifndef CREDITS_H_
#define CREDITS_H_
#include "GLOBALS.h"
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

	int GetPossibleWin() const;

	void SetPossibleWin(int);

	int getCreditsCollected() const;

	void setCreditsCollected(int creditsCollected);

	//37-41 - even, red, black, odd
	map<int, int> betByNumberCell;

private:
	int currentCredit;
	int betCredit;
	int creditsCollected;
};

#endif /* CREDIT_H_ */
