/*
 * Screen.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#include "Screen.h"

Screen::Screen()
{
	background = new LTexture(0, 0);
	isActive = false;
}

Screen::~Screen()
{
	background->free();
	delete background;
}
