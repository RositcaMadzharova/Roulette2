/*
 * Credits.h
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#ifndef CREDITS_H_
#define CREDITS_H_

class Credits
{
public:
	Credits(int=0);
	Credits (Credits &);
	virtual ~Credits();
	void SetBet(int);
	int GetBet() const ;
	int GetCredit() const ;
	int GetPossibleWin() const;
	void SetPossibleWin(int);
	bool isCashedOut();
private:
	int currentCredit;
	int betCredit;
	double possibleWin;
};

#endif /* CREDITS_H_ */
