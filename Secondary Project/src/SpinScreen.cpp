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

	sound = new Sound;
	sound->load();
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

int SpinScreen::Draw()
{
	rouletteBackground->render(NULL,0,NULL);

	srand(time(NULL));
	int result = rand() % 37;
	bool isStoped = false;
	double angleWheel =-3 + 9.7 * (posissionToNumberInRoulette [result] - 5) ;
	double stepWheel = 2 ;

	double maxR = 310 ;
	double minR = 210;
	double currentR=maxR;
	double minAngle = -95;
	double step = M_PI / 36; //128 steps per full circle, so lines are short.
	int mFrame = 0;

	double angleBall = 0;
//	if (lastWiningNumbers.size() >= 18)
//				recovery.lastWiningNumbers.pop();
//			recovery.lastWiningNumbers.push(result);

	//			+ 0.168 * (result - 13);
	//	double angleWheel = 0; //2 * M_PI * result / 37;
	do
	{
		angleBall -= ( maxR-currentR) / (12 * 200.0 / M_PI);
		currentR -= (maxR - minR) / ( 10* 200.0 / M_PI);

		if (currentR < minR) {
			isStoped = true;
		}

		angleBall -= step;
		ball->setX(SCREEN_W/2 - BALL_W / 2 + cos(angleBall) * maxR);
		ball->setY(SCREEN_H/2 - BALL_H / 2 + sin(angleBall) * maxR);

		if(mFrame % 3 == 0)
		{
			roulette->render(NULL,0);
			wheel->render( NULL, angleWheel);
			ball->render( NULL, 0);
		}

		angleWheel += stepWheel;
		maxR -= 0.1;
		mFrame ++;

	}
	while (angleBall  >  minAngle);
	sound->play(WINING_NUMBER);
	SDL_Delay(2000);
	sound->music(result);
	SDL_Delay(1000);
	isStoped = true;

	return result;
}

bool SpinScreen::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	isActive = false;

	return true;
}

void FillTheMapsOfRoulette()
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
