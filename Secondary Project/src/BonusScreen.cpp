/*
 * BonusScreen.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#include "BonusScreen.h"

BonusScreen::BonusScreen()
{
	bonus = new LTexture( 0 ,0);
	bonus->loadFromFile("EuropeanRouletteFinal.bmp");
	bonus->setWidth(SCREEN_W);
	bonus->setHeight(SCREEN_H);
	bonus->setAlpha(100);
	isActive = false;
	bonusSticker = new LTexture (SCREEN_W * 4 / 6  , SCREEN_H/ 6 );
	bonusSticker->loadFromFile("Lucky.png");
	bonusSticker->setWidth(300);
	bonusSticker->setHeight(300);

}

BonusScreen::~BonusScreen() {
	bonus->free();
	delete bonus;
}

bool BonusScreen::Draw(Credits& credits)
{

	bonus->render(NULL,0,NULL);
	for(int i = 0 ; i < 3 ; i++)
	{
		SDL_SetTextureColorMod(bonusSticker->getTexture(),
				rand()%100+150,rand()%70+70,rand()%100+150);
		bonusSticker->setY((i+1)*SCREEN_H/ 6 );
		bonusSticker->render(NULL, i*45, NULL);
	}

	srand(time(0));
		SDL_Color col = {
				(int)(rand()%200+50),
				(int)(rand()%200+50),
				(int)(rand()%200+50),
				255 };

		Text textYouWin (SCREEN_W / 4, SCREEN_H / 4, SCREEN_W / 4,
				SCREEN_H / 16, 25,"You Win", col,"Intro Inline.otf");

		Text textWinnings(SCREEN_W / 3, SCREEN_H * 2 / 4,
				SCREEN_W / 8, SCREEN_H / 16, 25,
				credits.getCreditsCollected(),{200,200,0}, "Intro Inline.otf");

		Text textCredits(SCREEN_W / 4, SCREEN_H * 3 / 4,
				SCREEN_W / 4, SCREEN_H / 16,
					25, "credits", col , "Intro Inline.otf");
	 SDL_Delay(3000);
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

//void BonusScreen::getBonusCreditsText(Credits& credits)
//{
//	srand(time(0));
//	SDL_Color col = {rand()%200+50,rand()%200+50,rand()%200 +50 };
//	Text textWinnings(SCREEN_W / 3, SCREEN_H * 2 / 4,
//			SCREEN_W / 3,
//			SCREEN_H / 8, 20, credits.getCreditsCollected(),col);
//}
