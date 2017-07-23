/*
 * INTROSCREEN.h
 *
 *  Created on: Jul 19, 2017
 *      Author: kakev
 */

#ifndef IntroScreen_H_
#define IntroScreen_H_
#include "LWindow.h"
#include "LTexture.h"
#include "Button.h"
#include "GLOBALS.h"

class IntroScreen
{
public:
	 IntroScreen();
	 virtual ~IntroScreen();
	 bool Draw();
	 bool Clear();
	 bool getFlag(){return isActive;}
public:
	 LTexture* introBackground;
	 Button* introButtons[INTRO_BUTTONS];

	 //bool for mouseEvents
	 bool isActive;

	 //ENUM For screens
	 GameState SCREENSTATE;
};

#endif /* INTROSCREEN_H_ */
