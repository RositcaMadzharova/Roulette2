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



class GameBoard
{
public:
	GameBoard();
	virtual ~GameBoard();
	bool Draw();
	bool Clear();
	bool getFlag(){return isActive;}

	void DisplayStatistics(Credits* credits , int lastWinningNumber);

	int CalcQuadrandClicked(int x, int y);
	void DisplayBets(Credits* credits , int x, int y, int color,
			bool resume = false);
public:
	LTexture* gameBoard;
	Button* gameBoardPools[POOLS_BUTTON];
	Button* cashOut;
	Button* spin;
	Button* history;
	Button* accounting;
	Button* clearBets;

	Sound* sound;
	bool isActive;
};

#endif /* GAMEBOARD_H_ */
