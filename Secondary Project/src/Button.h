/*
 * Button.h
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include "LTexture.h"
#include "Sound.h"



class Button : public LTexture{
public:
	Button(int x = 0, int y = 0);
	virtual bool isHover();
	virtual bool isClicked(SDL_Event *);
	virtual bool isRightClicked(SDL_Event *);
	virtual ~Button();
};

#endif /* BUTTON_H_ */
