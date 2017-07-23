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

class GameBoard
{
public:
	GameBoard(Credits* credits = NULL);
	virtual ~GameBoard();
	bool Draw();
	void DisplayPools();
	bool Clear();
	bool getFlag(){return isActive;}

	void DisplayStatistics(int lastWinningNumber);

	int CalcQuadrandClicked(int x, int y);
	void DisplayBets(int x, int y, int color, bool resume = false);
public:
	LTexture* gameBoard;
	Button* gameBoardPools[POOLS_BUTTON];
	Button* cashOut;
	Button* spin;
	Button* history;
	Button* accounting;
	Button* clearBets;
	Credits * credits;
	bool isActive;
};

#endif /* GAMEBOARD_H_ */
