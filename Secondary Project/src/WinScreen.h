/*
 * WinScreen.h
 *
 *  Created on: Jul 23, 2017
 *      Author: kakev
 */

#ifndef WINSCREEN_H_
#define WINSCREEN_H_
#include "LWindow.h"
#include "LTexture.h"
#include "GLOBALS.h"
#include "Credits.h"
#include "Text.h"
#include <vector>

#include "Screen.h"

class WinScreen: public Screen
{
public:
	WinScreen();
	virtual ~WinScreen();
	bool Draw();
	bool Clear();
	void WinAnimation();
	void ShowCredits(Credits*);

private:
	void fillRectPosition();
	LTexture* coin[COIN_COUNT];
};

#endif /* WINSCREEN_H_ */
