/*
 * INFOSCREEN.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#include "InfoScreen.h"

InfoScreen::InfoScreen()
{
	infoBackground= new LTexture (0,0);
	infoBackground->loadFromFile("rouletterules.jpg");
	infoBackground->setWidth(SCREEN_W);
	infoBackground->setHeight(SCREEN_H);
	infoBack = new Button (INFO_BUTTON_X,INFO_BUTTON_Y);
	infoBack->loadFromFile("BackButton.png");
	infoBack->setWidth(INFO_BUTTON_W);
	infoBack->setHeight(INFO_BUTTON_H);

	isActive = false;
	SCREENSTATE = INFO_SCREEN;
}

InfoScreen::~InfoScreen()
{
	infoBackground->free();
	delete infoBackground;
	infoBack->free();
	delete infoBack;
}

bool InfoScreen::Draw()
{
	if(infoBackground->render(NULL,0,NULL)
		&& infoBack->render(NULL,0,NULL))
	{
		Text textDenomination(SCREEN_W * 3 / 5, SCREEN_H - 40, 200, 20, 30,
				"*DENOMINATION IS 0.01 in BGN", { 30, 30, 30, 255 });
		isActive=true;
	}
	return true;
}

bool InfoScreen::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	isActive=false;
	return true;
}
