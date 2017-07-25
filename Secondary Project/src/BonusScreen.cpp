/*
 * BonusScreen.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#include "BonusScreen.h"

BonusScreen::BonusScreen()
		: Screen()
{
	background->loadFromFile("EuropeanRouletteFinal.bmp");
	background->setWidth(SCREEN_W);
	background->setHeight(SCREEN_H);
	background->setAlpha(100);
	isActive = false;
	bonusSticker = new LTexture(SCREEN_W * 4 / 6, SCREEN_H / 6);
	bonusSticker->loadFromFile("Lucky.png");
	bonusSticker->setWidth(300);
	bonusSticker->setHeight(300);
	sound = new Sound;
}

BonusScreen::~BonusScreen()
{
	delete sound;
}

bool BonusScreen::Draw()
{
	background->render(NULL, 0, NULL);
	SDL_Delay(2000);
	sound->play(WIN);

	srand(time(0));
	SDL_Color col = {
			rand() % 200 + 50,
			rand() % 200 + 50,
			rand() % 200 + 50,
			255 };

	Text textYouWin(SCREEN_W / 4, SCREEN_H / 4, SCREEN_W / 4,
			SCREEN_H / 8, 30, "You Win", col, "Intro Inline.otf");

	Text textCredits(SCREEN_W / 4, SCREEN_H * 3 / 4,
			SCREEN_W / 4, SCREEN_H / 8,
			30, "credits", col, "Intro Inline.otf");
	for (int i = 0; i < 3; i++)
	{
		SDL_SetTextureColorMod(bonusSticker->getTexture(),
				rand() % 100 + 150, rand() % 70 + 70, rand() % 100 + 150);
		bonusSticker->setY((i + 1) * SCREEN_H / 6 + rand() % 50);
		bonusSticker->render(NULL, i * 45, NULL);

		SDL_Delay(500);
	}

	//always false because we dont have active screen
	isActive = false;
	return true;
}

bool BonusScreen::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	isActive = false;

	return true;
}

bool BonusScreen::getBonusCreditsText(Credits* credits)
{
	srand(time(0));
	Text textWinnings(SCREEN_W / 3, SCREEN_H * 2 / 4,
			SCREEN_W / 8, SCREEN_H / 12, 40,
			credits->GetCreditsCollected(),
			{ 200, 200, 0 }, "Intro Inline.otf");
	SDL_Delay(1500);
	return true;
}
