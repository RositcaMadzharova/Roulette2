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
#include <ctime>
#include <cstdio>
#include <stdlib.h>

class BonusScreen {
public:
	BonusScreen();
	virtual ~BonusScreen();
	bool Draw();
	bool Clear();
	void getBonusCreditsText(Credits&);


public:
		LTexture* bonus;
		bool isActive;
};

#endif /* BONUSSCREEN_H_ */
