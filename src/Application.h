/*
 * Application.h
 *
 *  Created on: Jul 9, 2017
 *      Author: kakev
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "Globals.h"
#include "Pools.h"
#include "Button.h"
#include "Background.h"
#include "Point.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
using namespace std;

//GameState MenuState;

class Application {
public:
	Application();
	void initIntro();
	void initInfo();
	void initGameBoard();
	void initRoulette();
	void initOutro();
	void initWin();
	void initSpin();

	void Free();
	void GamePlay();
	void DisplayBets(int x , int y  , int color, // int poolYellow , int poolGreen , int poolRed , int poolBlack , int poolBlue,
					 vector<Point> v_allBetPoints);


	int CalcQuadrandClicked(int x, int y);

	void SpinAnimation ();
	void SpinRoulette(LTexture &ball,int);
	int spinBall();

	bool WinAnimation();

	virtual ~Application();
	GameState getMenuState() const;

private:
	GameState MenuState;

	Background * intro;
	//insert credit , volume , info,start new game , resume game
	Button * introButtons[5];

	Background *info;
	Button *infoBackToIntro;

	Background *gameBoard;
	Pools *gameBoardPools[POOLS_BUTTON];
	Pools *betPools [POOLS_BUTTON];
	Button * cashOut;
	Button * spin;


	//TODO MAIN make other class who enherit button
	Background *roulette;// spin roulette
	LTexture *ball;
	LTexture * wheel; // roulette wheel


	Background *outro;// Animation who backs to Intro 10 sec;

	Background *win;// animation 6 seconds
	LTexture *coin [COIN_COUNT];

	//TODO OTHER BUTTONS;
	//hardcoded limit of 100 Pulls
	//TODO:must be fxed


	vector<Point> v_coordsAllBetPulls;
	Credits cr;

};

#endif /* APPLICATION_H_ */
