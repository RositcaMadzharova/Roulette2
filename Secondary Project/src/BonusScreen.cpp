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

}

BonusScreen::~BonusScreen() {
	bonus->free();
	delete bonus;
}

bool BonusScreen::Draw()
{

	bonus->render(NULL,0,NULL);
	srand(time(0));
		SDL_Color col = {(int)(rand()%200+50),(int)(rand()%200+50),(int)(rand()%200+50) , 255 };

		Text textYouWin (SCREEN_W / 4, SCREEN_H / 4, SCREEN_W / 4,
				SCREEN_H / 16, 25,"You Win", col,"Intro Inline.otf");

		Text textWinnings(SCREEN_W / 3, SCREEN_H * 2 / 4,
				SCREEN_W / 6,
				SCREEN_H / 16, 25,855,{200,200,0} , "Intro Inline.otf");

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
