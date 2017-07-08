/*
 * Button.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#include "Button.h"

Button::Button(int x, int y)
	:LTexture(x,y)
{
}

bool Button::isClicked(int x, int y) {
		if (x >= getX() && x <= getWidth() + getX() && y >= getY()
						&& y <= getY() + getHeight()) {

			return true;
		}

	return false;
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

