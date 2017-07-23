/*
 * INFOSCREEN.h
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#ifndef InfoScreen_H_
#define InfoScreen_H_
#include "GLOBALS.h"
#include "LTexture.h"
#include "Button.h"
#include "Text.h"

class InfoScreen
{
public:
	InfoScreen();
	virtual ~InfoScreen();
	bool Draw();
	bool Clear();
	bool getFlag(){return isActive;}
public:
	LTexture* infoBackground;
	Button* infoBack;
	bool isActive;
	GameState SCREENSTATE;
};

#endif /* INFOSCREEN_H_ */
