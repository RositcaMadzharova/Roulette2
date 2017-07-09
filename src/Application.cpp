/*
 * Application.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: kakev
 */

#include "Application.h"

Application::Application()
{

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
		initIntro();
}

void Application::initIntro()
{
	MenuState=INTRO_MENU;
	intro=new Background("INTROSCREEN",SCREEN_W,SCREEN_H,"INTRO SCREEN.jpg");
	for(int i=0;i<5;i++){
		introButtons[i]= new Button(SCREEN_W/2-INTRO_BUTTON_W/2,SCREEN_H/5-INTRO_BUTTON_H/2+i*(INTRO_BUTTON_H+20));
		introButtons[i]->loadFromFile(Background::gRenderer,"Pools.png");
		introButtons[i]->setHeight(INTRO_BUTTON_H);
		introButtons[i]->setWidth(INTRO_BUTTON_W);
		SDL_Rect rectButton = {1,1,118,111};
		introButtons[i]->render(Background::gRenderer,&rectButton);

	}

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
	MenuState = INFO;
	info=new Background("INFOSCREEN",SCREEN_W,SCREEN_H,"rouletterules.jpg");
	infoBackToIntro=new Button(300,400);
	infoBackToIntro->loadFromFile(Background::gRenderer,"chessFigures.png");
	infoBackToIntro->setHeight(INTRO_BUTTON_H);
	infoBackToIntro->setWidth(INTRO_BUTTON_W);
	infoBackToIntro->render(Background::gRenderer,NULL);
}

//TODO:
void Application::initGameBoard()
{
	MenuState = GAME_BOARD;
	gameBoard = new Background("GameBoard",SCREEN_BOARD_W,SCREEN_BOARD_H,"tap_resized.jpg");
	cashOut = new Button (700,450);
	cashOut->loadFromFile(Background::gRenderer, "Cash OUT.png");
	cashOut->setHeight(200);
	cashOut->setWidth(100);
	cashOut->render(Background::gRenderer,NULL);


	//draw 5 Pulls
	//TODO: Each Poll needs different credit value.
	Credits cr;
	for(int i=0;i<5;i++){
		gameBoardPools[i]= new Pools(cr, 1, i*70, 1);
		gameBoardPools[i]->loadFromFile(Background::gRenderer,"Pools.png");
		gameBoardPools[i]->setHeight(PULLS_W);
		gameBoardPools[i]->setWidth(PULLS_H);
		SDL_Rect rectButton = {110*i,1,118,111};
		gameBoardPools[i]->render(Background::gRenderer,&rectButton);
	}
}

void Application::initRoulette() {
}

void Application::initOutro()
{

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


void Application::GamePlay()
{
	bool close = false;
	while (!close) {

		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (MenuState)
			{
				case INTRO_MENU:
					if(introButtons[0]->isClicked(&e))
							{
								Free();
								MenuState=INFO;
								initInfo();
							}
					if(introButtons[3]->isClicked(&e))
							{
								Free();
								MenuState=GAME_BOARD;
								initGameBoard();
							}

					break;
				case INFO :
					if(infoBackToIntro->isClicked(&e))
								{
									Free();
									MenuState=INTRO_MENU;
									initIntro();
								}
					break;
				case GAME_BOARD :
					if(cashOut->isClicked(&e)){
						Free();
						MenuState = OUTRO;
						initOutro();
					}
					break;
				default:
					break;
			}



			if (e.type == SDL_QUIT)
			{
				close = true;
			}


		}
	}
}

void Application::Free()
{
	if(MenuState == INTRO_MENU)
	{
		intro->Clear();
		introButtons[0]->free();
		introButtons[1]->free();
		introButtons[2]->free();
		introButtons[3]->free();
		introButtons[4]->free();
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
	if(MenuState == INFO)
	{
		info->Clear();
		infoBackToIntro->free();
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
	if(MenuState ==GAME_BOARD)
	{
		gameBoardPools[0]->free();
		gameBoardPools[1]->free();
		gameBoardPools[2]->free();
		gameBoardPools[3]->free();
		gameBoardPools[4]->free();
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
}

GameState Application::getMenuState() const {
	return MenuState;
}
