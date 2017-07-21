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
#include "Text.h"
#include "Sound.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <map>
#include <queue>
using namespace std;

//GameState MenuState;

class Application
{
public:
	Application();
	void initIntro();
	void initInfo();
	void initGameBoard();
	void initOutro();
	void initWin();
	void initSpin();
	void initBonus();

	void Free();
	void GamePlay();
	void DisplayBets(int x, int y, int color, // int poolYellow , int poolGreen , int poolRed , int poolBlack , int poolBlue,
						vector<Point> v_allBetPoints);

	int CalcQuadrandClicked(int x, int y);

	void SpinAnimation();
	void SpinRoulette(LTexture &ball, int);
	int spinBall();

	bool WinAnimation();

	virtual ~Application();
	GameState getMenuState() const;

	void appendToXML(map<int, int> ); //bets
	void appendToXMLHistory(queue<int>); //history

	map<int, int> readXMLWriteMap(string pathXml);
	queue<int> readXMLWriteQueue(string pathXml);

private:
	GameState MenuState;

	Background * intro;
	//insert credit , volume , info,start new game , resume game
	Button * introButtons[5];
	//	Text text1, text2;
//	Text * creditText[2];

	Background *info;
	Button *infoBackToIntro;

	Background *gameBoard;
	Pools *gameBoardPools[POOLS_BUTTON];
	Pools *betPools[POOLS_BUTTON];
	Button * cashOut;
	Button * spin;
	Button * history;
	Button * accounting;
	Button * clearBets;

	Background * bonus; // Mystery Progresive Jackpot
	int creditsCollected;
	int numberOfSpins;

	//TODO MAIN make other class who enherit button
	Background *roulette;// spin roulette
	LTexture *ball;
	LTexture * wheel; // roulette wheel

	Background *outro; // Animation who backs to Intro 10 sec;

	Background *win; // animation 6 seconds
	LTexture *coin[COIN_COUNT];

	//loaded from XML
	Background * historyBackgound; // last 18 winning numbers

	//loaded from XML then allowed to be changed again
	Background * accountingBackgound; // wins per number, winnings, added credits, cashed out MONEY, % RTP
	int winsPerNumber[37];
	int addedCredits;
	int cashedOutCredits;

	//TODO OTHER BUTTONS;
	//hardcoded limit of 100 Pulls
	//TODO:must be fxed

	vector<Point> v_coordsAllBetPulls;
	Credits credits;

	Sound* click;

	queue<int> lastWiningNumbers;


};

#endif /* APPLICATION_H_ */
