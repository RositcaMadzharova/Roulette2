/*
 * SpinScreen.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: kakev
 */

#include "SpinScreen.h"

map<int, int> posissionToNumberInRoulette;

SpinScreen::SpinScreen()
		: Screen()
{
	numberOfSpins = 1;

	background->loadFromFile("EuropeanRouletteFinal.bmp");
	background->setWidth(SCREEN_W );
	background->setHeight(SCREEN_H);
	background->setAlpha(100);

	//center wheel boarder
	roulette = new LTexture(211, (-12));
	roulette->loadFromFile("RouletteBoard.png");

	int blaq = 780 ;
//	????????????????????????????????????????????
	roulette->setWidth(blaq);
	roulette->setHeight(blaq);

	wheel = new LTexture(SCREEN_W / 2 - WHEEL_W / 2,
			SCREEN_H / 2 - WHEEL_H / 2);

	wheel->loadFromFile("wheel.png");

	wheel->setWidth(WHEEL_W);
	wheel->setHeight(WHEEL_H);

	ball = new LTexture(SCREEN_W, SCREEN_H);
	ball->loadFromFile("BALL.png");
	ball->setWidth(BALL_W);
	ball->setHeight(BALL_H);

	sound = new Sound;

	FillTheMapsOfRoulette();
}

SpinScreen::~SpinScreen()
{
	roulette->free();
	delete roulette;

	wheel->free();
	delete wheel;

	ball->free();
	delete ball;

}



bool SpinScreen::Draw()
{
	winningNumber = 5 ;//ra  nd() % 37;
	int result = winningNumber;

	background->render(NULL, 0, NULL);


		srand(time(NULL));
		sound->play(SPINROULETTE);

	//	for sound sinc
		SDL_Delay(2000);


	double angleWheel =   9.7 * (posissionToNumberInRoulette[result] - 7);

	double stepWheel = 2;
	double maxR = 310,
			minAngle = -95,
			step = M_PI / 36, angleBall = 0;
	do
	{
		angleBall -= step;

		ball->Copy(wheel , roulette  , angleWheel);

		ball->draw( SCREEN_W / 2 - BALL_W / 2 + cos(angleBall) * maxR
				, SCREEN_H / 2 - BALL_H / 2 + sin(angleBall) * maxR );

		angleWheel += stepWheel;
		maxR -= 0.1;
//		mFrame++;
	}
	while (angleBall > minAngle);

	sound->play(WINING_NUMBER);
	SDL_Delay(2000);
	sound->music(result);
	SDL_Delay(1000);

	numberOfSpins++;

	isActive = true;
//	SDL_RenderClear(LWindow::gRenderer);
	return isActive;
}

bool SpinScreen::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	isActive = false;

	return true;
}

int SpinScreen::GenerateWinningNumber()
{
	return winningNumber;
}

int SpinScreen::GetWinningNumber()
{
	return winningNumber;
}

bool SpinScreen::IsReadyForBonus()
{
	if (numberOfSpins % SPINS_TO_BONUS == 0)
	{
		numberOfSpins = 1;
		return true;
	}
	return false;
}

void SpinScreen::FillTheMapsOfRoulette()
{

	posissionToNumberInRoulette[27] = 36;
	posissionToNumberInRoulette[13] = 35;
	posissionToNumberInRoulette[36] = 34;
	posissionToNumberInRoulette[11] = 33;
	posissionToNumberInRoulette[30] = 32;
	posissionToNumberInRoulette[8] = 31;
	posissionToNumberInRoulette[23] = 30;
	posissionToNumberInRoulette[10] = 29;
	posissionToNumberInRoulette[5] = 28;
	posissionToNumberInRoulette[24] = 27;
	posissionToNumberInRoulette[16] = 26;
	posissionToNumberInRoulette[33] = 25;
	posissionToNumberInRoulette[1] = 24;
	posissionToNumberInRoulette[20] = 23;
	posissionToNumberInRoulette[14] = 22;
	posissionToNumberInRoulette[31] = 21;
	posissionToNumberInRoulette[9] = 20;
	posissionToNumberInRoulette[22] = 19;
	posissionToNumberInRoulette[18] = 18;
	posissionToNumberInRoulette[29] = 17;
	posissionToNumberInRoulette[7] = 16;
	posissionToNumberInRoulette[28] = 15;
	posissionToNumberInRoulette[12] = 14;
	posissionToNumberInRoulette[35] = 13;
	posissionToNumberInRoulette[3] = 12;
	posissionToNumberInRoulette[26] = 11;
	posissionToNumberInRoulette[0] = 10;
	posissionToNumberInRoulette[32] = 9;
	posissionToNumberInRoulette[15] = 8;
	posissionToNumberInRoulette[19] = 7;
	posissionToNumberInRoulette[4] = 6;
	posissionToNumberInRoulette[21] = 5;
	posissionToNumberInRoulette[2] = 4;
	posissionToNumberInRoulette[25] = 3;
	posissionToNumberInRoulette[17] = 2;
	posissionToNumberInRoulette[34] = 1;
	posissionToNumberInRoulette[6] = 0;
}
