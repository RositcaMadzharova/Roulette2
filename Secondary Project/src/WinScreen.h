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

class WinScreen {
public:
	WinScreen();
	virtual ~WinScreen();
	bool Draw();
//	friend class Credits;
	bool Clear();
	void WinAnimation();
	void ShowCredits(Credits*);
//	void ShowCredits(int, bool = true);

private:
	void fillRectPosition();
	LTexture* win ;
	LTexture* coin[COIN_COUNT];

};

#endif /* WINSCREEN_H_ */
