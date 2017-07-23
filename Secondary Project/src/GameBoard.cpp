/*
 * GameBoard.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#include "GameBoard.h"

GameBoard::GameBoard()
{
	gameBoard = new LTexture(0,0);
	gameBoard->loadFromFile("EuropeanRouletteFinal.bmp");

	cashOut = new Button (958 , 120);
	cashOut->loadFromFile("1.png");
	cashOut->setWidth(GAME_BOARD_BUTTON_W);
	cashOut->setHeight(GAME_BOARD_BUTTON_H);

	spin = new Button(1035, 725);
	spin->loadFromFile("1.png");
	spin->setWidth(GAME_BOARD_BUTTON_W);
	spin->setHeight(GAME_BOARD_BUTTON_H);

	history = new Button(150, 120);
	history->loadFromFile("1.png");
	history->setWidth(GAME_BOARD_BUTTON_W);
	history->setHeight(GAME_BOARD_BUTTON_H);

	accounting = new Button (555, 120);
	accounting->loadFromFile("1.png");
	accounting->setWidth(GAME_BOARD_BUTTON_W);
	accounting->setHeight(GAME_BOARD_BUTTON_H);

	clearBets = new Button(70, 725);
	clearBets->loadFromFile("1.png");
	clearBets->setWidth(GAME_BOARD_BUTTON_W);
	clearBets->setHeight(GAME_BOARD_BUTTON_H);

	for(int i = 0 ; i < POOLS_BUTTON ; i++)
		{
			gameBoardPools[i]=new Button (344 + i * 120, 700);
			gameBoardPools[i]->loadFromFile("Pools.png");
			gameBoardPools[i]->setHeight(2 * POOLS_W);
			gameBoardPools[i]->setWidth(2 * POOLS_H);
		}

	isActive = false;
}

GameBoard::~GameBoard()
{
	gameBoard->free();
	delete gameBoard;
	for(int i = 0 ; i < POOLS_BUTTON ; i++)
	{
		delete gameBoardPools[i];
	}
	cashOut->free();
	delete cashOut;

	spin->free();
	delete spin;

	history->free();
	delete history;

	accounting->free();
	delete accounting;

	clearBets->free();
	delete clearBets;
}

bool GameBoard::Draw()
{
	gameBoard->render(NULL,0,NULL);

// we have already the buttons dont need to render them :)

//	for(int i = 0 ; i < POOLS_BUTTON ; i++)
//	{
//		SDL_Rect rectButton = { 113 * i + 3, 1, 112, 111 };
//		gameBoardPools[i]->render(&rectButton,0,NULL);
//	}
//	cashOut->render(NULL,0,NULL);
//	spin->render(NULL,0,NULL);
//	history->render(NULL,0,NULL);
//	accounting->render(NULL,0,NULL);
//	clearBets->render(NULL,0,NULL);
	isActive = true;
	return true;
}

void GameBoard::DisplayPools()
{
}

bool GameBoard::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	isActive = false;
	return true;
}
