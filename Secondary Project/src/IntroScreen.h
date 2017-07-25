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
#include "Credits.h"
#include "Text.h"

#include "Screen.h"

class IntroScreen: public Screen
{
public:
	IntroScreen();
	virtual ~IntroScreen();
	bool Draw();
	bool Clear();

	void IntroScreenShowCredits(Credits& credits);

	Button* introButtons[INTRO_BUTTONS];
};

#endif /* INTROSCREEN_H_ */
