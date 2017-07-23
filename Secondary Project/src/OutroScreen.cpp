/*
 * OutroScreen.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: kakev
 */

#include "OutroScreen.h"

OutroScreen::OutroScreen()
{
	outro = new LTexture( 0, 0);
	outro->loadFromFile("OutroScreen2.jpg");
	outro->setWidth(SCREEN_W);
	outro->setHeight(SCREEN_H);

	isActive = false;
}

OutroScreen::~OutroScreen()
{
	outro->free();
	delete outro;
}

bool OutroScreen::Draw()
{
	double scale = 0.6;
	if(outro->render(NULL,0)){


	Text textMoney((SCREEN_W / 8 + 520 + 180) * scale, 400 * scale, 220 * scale,
						200 * scale, 15,
						"BGN",{ 255, 255, 255 });

		Text textThankYou(SCREEN_W / 8 * scale, 30 * scale, 900 * scale,
				200 * scale, 20,
				"THANK YOU FOR PLAYING", { 0, 200, 0, 155 });

		Text textYouHave(SCREEN_W / 8 * scale, 400 * scale, 500 * scale,
				200 * scale, 15,
				"You have",{ 255, 255, 255 });



		Text textMoneyNumber((SCREEN_W / 8 + 520) * scale, 400 * scale, 180 * scale,
				200 * scale, 15,
				500 * DENOMINATION, { 200, 10, 10, 255 });
		SDL_Delay(10000);
		return true;
	}
	return false;
}


bool OutroScreen::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	isActive = false;

	return isActive;
}
