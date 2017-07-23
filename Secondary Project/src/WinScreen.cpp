/*
 * WinScreen.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: kakev
 */

#include "WinScreen.h"
vector <SDL_Rect> coinFlipz;
void fillRectPosition();
WinScreen::WinScreen()
{
	win = new LTexture (0,0);
	win->loadFromFile("WinScreen.jpg");
	win->setWidth(SCREEN_W);
	win->setHeight(SCREEN_H);
	for (int i = 0; i < COIN_COUNT; i++)
	{
		coin[i] = new LTexture(rand() % 200 + 100, rand() % SCREEN_W);
		coin[i]->loadFromFile("coin.png");
		coin[i]->setWidth(COIN_W);
		coin[i]->setHeight(COIN_H);
	}

	fillRectPosition();
}

WinScreen::~WinScreen()
{
	win->free();
	delete win;

	for (int i = 0; i < COIN_COUNT; i++)
	{
		coin[i]->free();
		delete coin[i];
	}

}

bool WinScreen::Draw()
{
	if(win->render(NULL,0,NULL))
	{
		WinAnimation();
		return true;
	}
	return false;
}

bool WinScreen::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	return true;
}

bool WinScreen::WinAnimation()
{
	bool isDone = false;
		vector<SDL_Rect> goldCoins;
		for (int i = 0; i < 10; i++)
			goldCoins.push_back(
					{ COIN_W * i, 0, COIN_W, COIN_H });


			for (int i = 0; i < (int) coinFlipz.size(); i++)
			{
				coin[i]->setX(coinFlipz[i].x);
				coin[i]->setY(coinFlipz[i].y);
				SDL_Color color{rand()%255,rand()%255,rand()%255,rand()%255};
				Text winText (SCREEN_W/2 - 300/2 , SCREEN_H/2 - 100/2 , 300 , 100 , 20 ,"YOU WIN", color);
				for (int j = 0; j < 10; j++)
				{
					SDL_RenderCopyEx(LWindow::gRenderer,coin[i]->getTexture(),&goldCoins[j],&coinFlipz[i],-90,NULL,SDL_FLIP_NONE);
					SDL_RenderPresent(LWindow::gRenderer);


					SDL_Delay(5);
				}
//				SDL_Delay(10);
				isDone = true;
			}

//			SDL_Delay(3000);
	return isDone;
}
void fillRectPosition()
{

	SDL_Rect rec = {20,675,90,90};
	coinFlipz.push_back(rec);
	rec.x = 128;
	rec.y = 690;
	rec.w = 95;
	rec.h = 95;
	coinFlipz.push_back(rec);
	rec.x = 230;
	rec.y = 650;
	coinFlipz.push_back(rec);
	rec.x = 358;
	rec.y = 580;
	coinFlipz.push_back(rec);
	rec.x = 485;
	rec.y = 650;
	rec.w = 105;
	rec.h = 105;
	coinFlipz.push_back(rec);
	rec.x = 270;
	rec.y = 445;
	rec.w = 95;
	rec.h = 95;
	coinFlipz.push_back(rec);
	rec.x = 340;
	rec.y = 490;
	rec.w = 90;
	rec.h = 90;
	coinFlipz.push_back(rec);
	rec.x = 200;
	rec.y = 575;
	rec.w = 75;
	rec.h = 75;
	coinFlipz.push_back(rec);
	rec.x = 120;
	rec.y = 635;
	rec.w = 65;
	rec.h = 65;
	coinFlipz.push_back(rec);
	for(int i = 0 ; i < 9 ; i ++)
	{
		rec = coinFlipz[i];
		rec.x = SCREEN_W - rec.x - rec.w + 15;
		coinFlipz.push_back(rec);
	}
}
