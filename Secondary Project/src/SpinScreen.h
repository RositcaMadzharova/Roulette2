/*
 * SpinScreen.h
 *
 *  Created on: Jul 23, 2017
 *      Author: kakev
 */

#ifndef SPINSCREEN_H_
#define SPINSCREEN_H_
#include "GLOBALS.h"
#include "LTexture.h"
#include "Sound.h"
#include <map>
using std::map;

#include "Screen.h"

class SpinScreen: public Screen
{
public:
	SpinScreen();
	virtual ~SpinScreen();
	bool Draw();
	bool Clear();

	int GenerateWinningNumber();
	int GetWinningNumber();

	bool IsReadyForBonus();
	private:
	LTexture* roulette;
	LTexture* wheel;
	LTexture* ball;

	Sound* sound;
	private:
	int numberOfSpins;
	int winningNumber;

	void FillTheMapsOfRoulette();
};

#endif /* SPINSCREEN_H_ */
