/*
 * INFOSCREEN.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#include "InfoScreen.h"

InfoScreen::InfoScreen()
{
	background->loadFromFile("rouletterules.jpg");
	background->setWidth(SCREEN_W);
	background->setHeight(SCREEN_H);
	infoBack = new Button(SCREEN_W - INFO_BUTTON_W - 10, 0);
	infoBack->loadFromFile("BackButton.png");
	infoBack->setWidth(INFO_BUTTON_W);
	infoBack->setHeight(INFO_BUTTON_H);

	sound = new Sound;

	isActive = false;
}

InfoScreen::~InfoScreen()
{
	delete sound;

	infoBack->free();
	delete infoBack;
}

bool InfoScreen::Draw()
{
	if (background->render(NULL, 0)
			&& infoBack->render(NULL, 180))
	{
		Text textDenomination(SCREEN_W * 3 / 5, SCREEN_H - 40, 200, 20, 30,
				"*DENOMINATION IS 0.01 in BGN", { 30, 30, 30, 255 });
		isActive = true;
	}
	return true;
}

bool InfoScreen::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	isActive = false;
	return true;
}
