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

class SpinScreen {
public:
	SpinScreen();
	virtual ~SpinScreen();
	bool Draw();
	bool Clear();
	bool getFlag(){return isActive;}

	int GenerateWinningNumber();
	int GetWinningNumber();

	bool IsReadyForBonus();
public:
	LTexture* rouletteBackground;
	LTexture* roulette;
	LTexture* wheel;
	LTexture* ball ;
	Sound* sound;
	bool isActive;

private:
	int numberOfSpins;
	int winningNumber;

	void FillTheMapsOfRoulette();
};

#endif /* SPINSCREEN_H_ */
