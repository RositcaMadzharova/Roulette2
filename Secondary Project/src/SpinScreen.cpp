/*
 * SpinScreen.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: kakev
 */

#include "SpinScreen.h"

map<int, int> posissionToNumberInRoulette;
void FillTheMapsOfRoulette();

SpinScreen::SpinScreen()
{
	rouletteBackground = new LTexture (0,0);
	rouletteBackground->loadFromFile("EuropeanRouletteFinal.bmp");
	rouletteBackground->setWidth(SCREEN_W);
	rouletteBackground->setHeight(SCREEN_H);
	rouletteBackground->setAlpha(100);

	//center wheel boarder
	roulette = new LTexture(250,0);
	roulette->loadFromFile("RouletteBoard.png");
	roulette->setWidth(SCREEN_H);
	roulette->setHeight(SCREEN_H);

	wheel = new LTexture(SCREEN_W / 2 - WHEEL_W / 2 , SCREEN_H / 2 - WHEEL_H / 2);
	wheel->loadFromFile("wheel2.png");
	wheel->setWidth(WHEEL_W);
	wheel->setHeight(WHEEL_H);

	ball = new LTexture(SCREEN_W, SCREEN_H);
	ball->loadFromFile("BALL.png");
	ball->setWidth(BALL_W);
	ball->setHeight(BALL_H);

	isActive = false;

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
	rouletteBackground->render(NULL,0,NULL);
	bool isStoped = false;
	double angleWheel = 0; //2 * M_PI * result / 37;
	double stepWheel = 2;
	double angleBall = 6;
	double maxR = 310 ;
	double minR = 210;
	double currentR=maxR;
	double maxAngle = 10;
	double minAngle = -95;

	int mFrame = 0;

	double step = M_PI / 36; //128 steps per full circle, so lines are short.

	do
	{
		angleBall -= ( maxR-currentR) / (12 * 200.0 / M_PI);
		if (angleBall < maxAngle) {
			currentR -= (maxR - minR) / ( 10* 200.0 / M_PI);
		}
		if (currentR < minR) {
			isStoped = true;
		}

		angleBall -= step;
		ball->setX(SCREEN_W/2 - BALL_W / 2 + cos(angleBall) * maxR);
		ball->setY(SCREEN_H/2 - BALL_H / 2 + sin(angleBall) * maxR);

		if(mFrame % 3 == 0)
		{
			roulette->render(NULL,0);
			wheel->render( NULL, +angleWheel);
			ball->render( NULL, 0);
		}

		angleWheel += stepWheel;
		maxR -= 0.1;
		mFrame ++;

	}
	while (angleBall  >  minAngle);
	SDL_Delay(1000);
	isStoped = true;
	return isStoped;
}

bool SpinScreen::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	isActive = false;

	return true;
}

void FillTheMapsOfRoulette()
{
	posissionToNumberInRoulette[6] = 0;
	posissionToNumberInRoulette[27] = 1;
	posissionToNumberInRoulette[13] = 2;
	posissionToNumberInRoulette[36] = 3;
	posissionToNumberInRoulette[11] = 4;
	posissionToNumberInRoulette[30] = 5;
	posissionToNumberInRoulette[8] = 6;
	posissionToNumberInRoulette[23] = 7;
	posissionToNumberInRoulette[10] = 8;
	posissionToNumberInRoulette[5] = 9;
	posissionToNumberInRoulette[24] = 10;
	posissionToNumberInRoulette[16] = 11;
	posissionToNumberInRoulette[33] = 12;
	posissionToNumberInRoulette[1] = 13;
	posissionToNumberInRoulette[20] = 14;
	posissionToNumberInRoulette[14] = 15;
	posissionToNumberInRoulette[31] = 16;
	posissionToNumberInRoulette[9] = 17;
	posissionToNumberInRoulette[22] = 18;
	posissionToNumberInRoulette[18] = 19;
	posissionToNumberInRoulette[29] = 20;
	posissionToNumberInRoulette[7] = 21;
	posissionToNumberInRoulette[28] = 22;
	posissionToNumberInRoulette[12] = 23;
	posissionToNumberInRoulette[35] = 24;
	posissionToNumberInRoulette[3] = 25;
	posissionToNumberInRoulette[26] = 26;
	posissionToNumberInRoulette[0] = 27;
	posissionToNumberInRoulette[32] = 28;
	posissionToNumberInRoulette[15] = 29;
	posissionToNumberInRoulette[19] = 30;
	posissionToNumberInRoulette[4] = 31;
	posissionToNumberInRoulette[21] = 32;
	posissionToNumberInRoulette[2] = 33;
	posissionToNumberInRoulette[25] = 34;
	posissionToNumberInRoulette[17] = 35;
	posissionToNumberInRoulette[34] = 36;
}
//bool SpinScreen::Draw()
//{
//	srand(time(NULL));
//	int result = rand() % 37;
//
////	if (lastWiningNumbers.size() >= 18)
////		lastWiningNumbers.pop();
////	lastWiningNumbers.push(result);
////
////	appendToXMLHistory(lastWiningNumbers);
//	rouletteBackground->render(NULL,0,NULL);
//
//
////
//	double angleBall = -0.03
//			+ 0.168 * (result - 13);
//	double angleWheel = 0; //2 * M_PI * result / 37;
//
//	double radius = 330;
//	const double minRaduis = 210;
//	double andleEnd = 82 * M_PI;
//	double stepBall = M_PI / 36;
//	double stepWheel = 0.2;
//
//	bool isTimeToDraw = false;
//	bool isTimeToDraw2 = true;
//
//	do
//	{
//		const double MAGIC_NUMBER = 0.08;
//
////		SDL_Delay(3);
//
//		isTimeToDraw = !isTimeToDraw;
//		if (isTimeToDraw)
//			isTimeToDraw2 = !isTimeToDraw2;
//		if (isTimeToDraw && isTimeToDraw2)
//		{
//		isTimeToDraw2 = !isTimeToDraw2;
//
//
//		}
//		if( mFrame % 3 == 0 )
//		{
//
//			roulette->render(NULL,0,NULL);
//			wheel->render( NULL, -angleWheel);
//		}
//		if( mFrame % 2 == 0 )
//		{
//			ball->setX(
//					SCREEN_W / 2 - BALL_W / 2 + cos(angleBall) * radius);
//			ball->setY(
//					SCREEN_H / 2 - BALL_H / 2 + sin(angleBall) * radius);
//
//			ball->render( NULL, 0);
//		}
//		mFrame++;
//		angleWheel += stepWheel;
//		if (angleWheel < andleEnd)
//			angleBall += stepBall - MAGIC_NUMBER * (minRaduis / radius);
//		else
//			angleBall -= M_PI / 900;
//		radius -= 0.1;
//
//	}
//	while (angleWheel < andleEnd + 10 * M_PI);
//	ball->render( NULL, 0);
////	SDL_Delay(4000);
//
//	isActive = false;
//
//	return 5; //result;
//}
