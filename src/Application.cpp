/*
 * Application.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: kakev
 */

#include "Application.h"

Application::Application()
{
	MenuState=INTRO_MENU;

		 intro = NULL;
		 for(unsigned int i=0;i<5;i++)
		 {
			 introButtons[i] = NULL;
		 }
		info = NULL;
		infoBackToIntro = NULL;
		gameBoard = NULL;
		roulette = NULL;// spin roulette
		ball = NULL;
		outro = NULL;// Animation who backs to Intro 10 sec;
		win = NULL;// anima
}

void Application::initIntro()
{
	intro=new Background("INTROSCREEN",SCREEN_W,SCREEN_H,"INTRO SCREEN.jpg");
	introButtons[0]= new Button(SCREEN_W/2-INTRO_BUTTON_W/2,SCREEN_H/5-INTRO_BUTTON_H/2);
	introButtons[0]->loadFromFile(Background::gRenderer,"Pools.png");
	introButtons[0]->setHeight(INTRO_BUTTON_H);
	introButtons[0]->setWidth(INTRO_BUTTON_W);
	SDL_Rect rectButton = {1,1,118,111};
	introButtons[0]->render(Background::gRenderer,&rectButton);



}

Application::~Application()
{

	for(unsigned int i=0;i<5;i++)
	{
		delete introButtons[i] ;
	}
	delete intro;
	// TODO Auto-generated destructor stub
}

void Application::initInfo()
{
	info=new Background("INFOSCREEN",SCREEN_W,SCREEN_H,"rouletterules.jpg");
	infoBackToIntro=new Button(300,400);
	infoBackToIntro->loadFromFile(Background::gRenderer,"chessFigures.png");
	infoBackToIntro->setHeight(INTRO_BUTTON_H);
	infoBackToIntro->setWidth(INTRO_BUTTON_W);
	infoBackToIntro->render(Background::gRenderer,NULL);


}

void Application::initGameBoard() {
}

void Application::initRoulette() {
}

void Application::initOutro() {
}

void Application::initWin() {
}

void Application::WitchState()
{

	switch (MenuState){
	case INTRO_MENU :
		initIntro();
		introButtons[0]->isHover();
		break;
	case INFO :
		initInfo();
		break;
	default:
		break;
	}
}

void Application::SwitchState(SDL_Event &e)
{
	WitchState();
	if(introButtons[0]->isClicked(&e) && MenuState==INTRO_MENU)
	{
		MenuState=INFO;
		WitchState();
		intro->Clear();
		introButtons[0]->free();
	}
	if(infoBackToIntro->isClicked(&e) && MenuState==INFO)
	{
		MenuState=INTRO_MENU;
		WitchState();
		info->Clear();
		infoBackToIntro->free();
		SDL_DestroyRenderer(Background::gRenderer);
	}
}

GameState Application::getMenuState() const {
	return MenuState;
}
