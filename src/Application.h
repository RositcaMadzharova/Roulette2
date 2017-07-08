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


GameState MenuState;

class Application {
public:

	Application();
	void WhitchState(GameState& MenuState);
	void SpinRoulette(int, LTexture ball);//some argument time , sector , velocity
	virtual ~Application();
private:
	Background Intro;
	Button IntroButtons[5];
	Background Info;
	Button InfoBackToIntro;
	Background GameBoard;
	//TODO MAIN make other class who enherit button
	Background Roulette;// spin roulette
	LTexture ball;
	Background Outro;// Animation who backs to Intro 10 sec;
	Background Win;// animation 6 seconds

	//TODO CREDITS
};

#endif /* APPLICATION_H_ */
