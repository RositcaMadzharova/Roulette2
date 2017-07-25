/*
 * INTROSCREEN.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: kakev
 */

#include "IntroScreen.h"

IntroScreen::IntroScreen()
		: Screen()
{
	background->loadFromFile("IntroBackgroundFinal.bmp");
	background->setWidth(SCREEN_W);
	background->setHeight(SCREEN_H);

	for (int i = 0; i < INTRO_BUTTONS; i++)
	{
		introButtons[i] = new Button(SCREEN_W / 2 - INTRO_BUTTONS_W / 2,
				SCREEN_H / 13 - INTRO_BUTTONS_H / 2
						+ i * (INTRO_BUTTONS_H + 30));

		introButtons[i]->loadFromFile("1.png");
		introButtons[i]->setWidth(580);
		introButtons[i]->setHeight(50);
	}
}

IntroScreen::~IntroScreen()
{
	for (int i = 0; i < INTRO_BUTTONS; i++)
	{
		introButtons[i]->free();
		delete introButtons[i];
	}
}

bool IntroScreen::Draw()
{
	if (background->render(NULL, 0))
	{
		isActive = true;
	}

	return true;
}

bool IntroScreen::Clear()
{

	SDL_RenderClear(LWindow::gRenderer);
	isActive = false;

	return true;
}

void IntroScreen::IntroScreenShowCredits(Credits& credits)
{
	Clear();
	Draw();

	if (credits.GetCredit())
	{
		Text textCredit(SCREEN_W / 2 - 500 / 2 + 50 + 470,
				SCREEN_H / 10 - INTRO_BUTTONS_H / 2
						+ (INTRO_BUTTONS_H + 10)
						, 230, 40, 20, "Credits: ", { 100,
						200, 100, 255 });

		Text textCreditsNumber(
				SCREEN_W / 2 - 500 / 2 + 50 + 690,
				SCREEN_H / 10 - INTRO_BUTTONS_H / 2
						+ (INTRO_BUTTONS_H + 10)
						, 60, 40, 20, credits.GetCredit(),
				{ 100, 200, 100 });
	}
}
