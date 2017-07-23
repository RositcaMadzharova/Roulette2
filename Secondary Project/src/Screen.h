/*
 * Screen.h
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include "GLOBALS.h"
#include "LTexture.h"
#include "Button.h"

class Screen {
public:
	Screen();
	virtual ~Screen();
	virtual bool Draw() = 0;
	virtual bool Clear() = 0;
	virtual bool getFlag() {return isActive;}
private:
	LTexture* board;
	bool isActive;
};

#endif /* SCREEN_H_ */
