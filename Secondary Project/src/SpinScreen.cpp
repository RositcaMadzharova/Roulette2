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
	background->setWidth(SCREEN_W);
	background->setHeight(SCREEN_H);
	background->setAlpha(100);

	//center wheel boarder
	roulette = new LTexture(250, 0);
	roulette->loadFromFile("RouletteBoard.png");
	roulette->setWidth(SCREEN_H);
	roulette->setHeight(SCREEN_H);

	wheel = new LTexture(SCREEN_W / 2 - WHEEL_W / 2,
			SCREEN_H / 2 - WHEEL_H / 2);
	wheel->loadFromFile("wheel2.png");
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

	srand(time(NULL));
	winningNumber = rand() % 37;
	int result = winningNumber;

	background->render(NULL, 0, NULL);
	sound->play(SPINROULETTE);
	SDL_Delay(2000);
	int mFrame = 0;
	double angleWheel = -3 + 9.7 * (posissionToNumberInRoulette[result] - 5);
	double stepWheel = 2;
	double maxR = 310, minR = 210,
			currentR = maxR, minAngle = -95,
			step = M_PI / 36, angleBall = 0;
	do
	{
		angleBall -= (maxR - currentR) / (12 * 200.0 / M_PI);
		currentR -= (maxR - minR) / (10 * 200.0 / M_PI);

		angleBall -= step;
		ball->setX(SCREEN_W / 2 - BALL_W / 2 + cos(angleBall) * maxR);
		ball->setY(SCREEN_H / 2 - BALL_H / 2 + sin(angleBall) * maxR);

		if (mFrame % 3 == 0)
		{
			roulette->render(NULL, 0);
			wheel->render( NULL, angleWheel);
			ball->render( NULL, 0);
		}
		angleWheel += stepWheel;
		maxR -= 0.1;
		mFrame++;
	}
	while (angleBall > minAngle);

	sound->play(WINING_NUMBER);
	SDL_Delay(2000);
	sound->music(result);
	SDL_Delay(1000);

	numberOfSpins++;
	return true;
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
