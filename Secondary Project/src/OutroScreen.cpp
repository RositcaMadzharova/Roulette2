/*
 * OutroScreen.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: kakev
 */

#include "OutroScreen.h"

OutroScreen::OutroScreen()
		: Screen()
{
	background->loadFromFile("OutroScreen2.jpg");
	background->setWidth(SCREEN_W);
	background->setHeight(SCREEN_H);
	isActive = false;
}

OutroScreen::~OutroScreen()
{

}

bool OutroScreen::Draw()
{
	double scale = 0.6;
	if (background->render(NULL, 0))
	{
		Text textMoney((SCREEN_W / 8 + 520 + 180) * scale, 400 * scale,
				220 * scale,
				200 * scale, 15, "BGN", { 255, 255, 255 });

		Text textThankYou(SCREEN_W / 8 * scale, 30 * scale, 900 * scale,
				200 * scale, 20, "THANK YOU FOR PLAYING", { 0, 200, 0, 155 });

		Text textYouHave(SCREEN_W / 8 * scale, 400 * scale, 500 * scale,
				200 * scale, 15, "You have", { 255, 255, 255 });
		return true;
	}
	return false;
}

void OutroScreen::Show(Credits* credits)
{
	double scale = 0.6;
	Text textMoneyNumber((SCREEN_W / 8 + 520) * scale, 400 * scale, 180 * scale,
			200 * scale, 15, credits->GetCredit() * DENOMINATION, { 200, 10, 10,
					255 });
}

bool OutroScreen::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	isActive = false;

	return isActive;
}
