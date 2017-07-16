/*
 * Credits.h
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#ifndef CREDITS_H_
#define CREDITS_H_
#include  "Globals.h"
#include <map>
using namespace std;

class Credits
{
public:
	Credits(int = 0);
	Credits(Credits &);
	virtual ~Credits();
	void AddBet(int);
	void ChangeCredits(int);
	void SetBet(int);	//needless
	int GetBet() const;
	int GetCredit() const;
	int GetPossibleWin() const;
	void SetPossibleWin(int);
	bool isCashedOut();

	static int NumberInCell(int);

	map<int, int> betByNumberCell;
	int betRed;
	int betBlack;
	int betOdd;
	int betEven;

private:
	int currentCredit;
	int betCredit;
	double possibleWin;		//needless
};

#endif /* CREDITS_H_ */
