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
#include "Text.h"
#include <vector>

class WinScreen {
public:
	WinScreen();
	virtual ~WinScreen();
	bool Draw();
	bool Clear();
	bool WinAnimation();
public:
	LTexture* win ;
	LTexture* coin[COIN_COUNT];
};

#endif /* WINSCREEN_H_ */
