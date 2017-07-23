/*
 * INTROSCREEN.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: kakev
 */

#include "IntroScreen.h"

IntroScreen::IntroScreen()
{
	introBackground = new LTexture(0,0);
	introBackground->loadFromFile("IntroBackgroundFinal.bmp");
	introBackground->setWidth(SCREEN_W);
	introBackground->setHeight(SCREEN_H);

	for (int i = 0 ; i < INTRO_BUTTONS ; i++)
	{
		introButtons[i]= new Button (  SCREEN_W / 2 - INTRO_BUTTONS_W / 2,
				SCREEN_H / 13 - INTRO_BUTTONS_H / 2 + i * (INTRO_BUTTONS_H + 30));

	introButtons[i]->loadFromFile("1.png");
	introButtons[i]->setWidth(580);
	introButtons[i]->setHeight(50);
	}
	isActive=false;
}

IntroScreen::~IntroScreen()
{
	introBackground->free();
	delete introBackground;
	introBackground = NULL;
	for(int i = 0 ; i < INTRO_BUTTONS ; i++)
	{
		introButtons[i]->free();
		delete introButtons[i];
	}
}

bool IntroScreen::Draw()
{
if(introBackground->render(NULL,0,NULL))
{
	isActive = true;
}

return true;
}

bool IntroScreen::Clear()
{

SDL_RenderClear(LWindow::gRenderer);
isActive=false;

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
