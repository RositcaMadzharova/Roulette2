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

#include "Screen.h"

class InfoScreen: public Screen
{
public:
	InfoScreen();
	virtual ~InfoScreen();
	bool Draw();
	bool Clear();

	Button* infoBack;
};

#endif /* INFOSCREEN_H_ */
