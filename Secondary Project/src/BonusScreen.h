/*
 * BonusScreen.h
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#ifndef BONUSSCREEN_H_
#define BONUSSCREEN_H_
#include "Text.h"
#include "Credits.h"
#include "Sound.h"
#include "GLOBALS.h"

#include "Screen.h"

class BonusScreen: public Screen
{
public:
	BonusScreen();
	virtual ~BonusScreen();
	bool Draw();
	bool Clear();

	bool getBonusCreditsText(Credits*);

public:
	LTexture* bonusSticker;
	Sound* sound;
};

#endif /* BONUSSCREEN_H_ */
