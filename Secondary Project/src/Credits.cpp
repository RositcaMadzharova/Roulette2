/*
 * Credit.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#include "Credits.h"

Credits::Credits(int cCredit)
{
	this->currentCredit = cCredit;
	this->betCredit = 0;
	this->creditsCollected = 0;
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

int Credits::GetBet() const
{
	return betCredit;
}

int Credits::GetCredit() const
{
	return currentCredit;
}


int Credits::getCreditsCollected() const {
	return creditsCollected;
}

void Credits::setCreditsCollected(int creditsCollected) {
	this->creditsCollected = creditsCollected;
}
