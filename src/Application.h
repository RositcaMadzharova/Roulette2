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


//GameState MenuState;

class Application {
public:
	Application();
	void initIntro();
	void initInfo();
	void initGameBoard();
	void initRoulette();
	void initOutro();
	void Free();
	void initWin();
	void GamePlay();

	void WitchState();//will change gamestate
	void SpinRoulette(int, LTexture ball);//some argument time , sector , velocity
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
	Button * cashOut;
	Pools *gameBoardPools[5];
	//TODO MAIN make other class who enherit button

	Background *roulette;// spin roulette
	LTexture *ball;

	Background *outro;// Animation who backs to Intro 10 sec;

	Background *win;// animation 6 seconds
	vector <SDL_Rect*>vCoinFlip;
	Button *coin;
	//TODO OTHER BUTTONS;

	//TODO CREDITS
};

#endif /* APPLICATION_H_ */
