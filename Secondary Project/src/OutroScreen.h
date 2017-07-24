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

class OutroScreen {
public:
	OutroScreen();

	friend class Credits ;

	virtual ~OutroScreen();
	bool Draw();
	bool Clear();
	bool getFlag(){return isActive;}
public:
		LTexture* outro;
		Credits* credits;
		bool isActive;
};
#endif /* OUTROSCREEN_H_ */
