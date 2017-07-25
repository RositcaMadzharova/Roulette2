/*
 * OutroScreen.h
 *
 *  Created on: Jul 23, 2017
 *      Author: kakev
 */

#ifndef OUTROSCREEN_H_
#define OUTROSCREEN_H_
#include "LTexture.h"
#include "Text.h"
#include "Credits.h"

#include "Screen.h"

class OutroScreen: public Screen
{
public:
	OutroScreen();
	virtual ~OutroScreen();
	bool Draw();
	bool Clear();

	void Show(Credits* credits);
};
#endif /* OUTROSCREEN_H_ */
