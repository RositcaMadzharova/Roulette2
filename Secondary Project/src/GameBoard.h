/*
 * GameBoard.h
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_
#include "GLOBALS.h"
#include "LTexture.h"
#include "Button.h"
#include "Credits.h"
#include "Text.h"
#include "Sound.h"
#include "Recovery.h"

#include "Screen.h"

class GameBoard: public Screen
{
public:
	GameBoard();
	virtual ~GameBoard();
	bool Draw();
	bool Clear();

	void DisplayStatistics(Credits* credits, int lastWinningNumber);

	int CalcQuadrandClicked(int x, int y);
	void DisplayBets(Credits* credits, int x, int y, int color,
						bool resume = false, Recovery* recovery = NULL);
public:
	Button* gameBoardPools[POOLS_BUTTON];
	Button* cashOut;
	Button* spin;
	Button* history;
	Button* accounting;
	Button* clearBets;

	Sound* sound;
};

#endif /* GAMEBOARD_H_ */
