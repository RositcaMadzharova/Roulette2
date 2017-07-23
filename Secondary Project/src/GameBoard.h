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

class GameBoard
{
public:
	GameBoard();
	virtual ~GameBoard();
	bool Draw();
	void DisplayPools();
	bool Clear();
	bool getFlag(){return isActive;}
public:
	LTexture* gameBoard;
	Button* gameBoardPools[POOLS_BUTTON];
	Button* cashOut;
	Button* spin;
	Button* history;
	Button* accounting;
	Button* clearBets;
	bool isActive;
};

#endif /* GAMEBOARD_H_ */
