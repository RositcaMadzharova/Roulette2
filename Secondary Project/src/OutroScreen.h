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

class OutroScreen {
public:
	OutroScreen();
	virtual ~OutroScreen();
	bool Draw();
	bool Clear();
	bool getFlag(){return isActive;}
public:
		LTexture* outro;
		bool isActive;
};
#endif /* OUTROSCREEN_H_ */
