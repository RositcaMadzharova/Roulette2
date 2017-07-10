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
	intro=new Background("INTROSCREEN",SCREEN_W,SCREEN_H,"IntroScreen.jpg");
	for(int i=0;i<5;i++)
	{
		introButtons[i]= new Button(SCREEN_W*3/4-INTRO_BUTTON_W/2,SCREEN_H/5-INTRO_BUTTON_H/2+i*(INTRO_BUTTON_H+30));
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
	infoBackToIntro=new Button(10,10);
	infoBackToIntro->loadFromFile(Background::gRenderer,"BackButton.png");
	infoBackToIntro->setHeight(INTRO_BUTTON_H);
	infoBackToIntro->setWidth(INTRO_BUTTON_W);
	infoBackToIntro->render(Background::gRenderer,NULL);
}

void Application::initGameBoard()
{
	MenuState = GAME_BOARD;
	gameBoard = new Background("GameBoard",SCREEN_W,SCREEN_H,"tap_resized.jpg");
	cashOut = new Button (700,450);
	cashOut->loadFromFile(Background::gRenderer, "Cash OUT.png");
	cashOut->setHeight(200);
	cashOut->setWidth(100);
	cashOut->render(Background::gRenderer,NULL);
	//draw 5 Pulls
	//TODO: Each Poll needs different credit value.
	Credits cr;
	for(int i=0;i<5;i++)
	{
		gameBoardPools[i]= new Pools(cr, 1,SCREEN_H*3/5+10+ i*60, 1);
		gameBoardPools[i]->loadFromFile(Background::gRenderer,"Pools.png");
		gameBoardPools[i]->setHeight(PULLS_W);
		gameBoardPools[i]->setWidth(PULLS_H);
		SDL_Rect rectButton = {113*i,1,118,111};
		gameBoardPools[i]->render(Background::gRenderer,&rectButton);
	}

}

void Application::initRoulette() {
}

void Application::initOutro()
{

}

void Application::initWin()
{
	const int step = 240;
	SDL_Rect rect = {0,0,step,step};

	for(int i = 0;i < 3;i++)
	{
		rect.x = i*step;
		for(int j = 0;j < 3;j++)
		{
			rect.y = j*step;
			vCoinFlip.push_back(&rect);
		}
	}

	MenuState = WIN;
	gameBoard = new Background("WIN",SCREEN_W,SCREEN_H,"WIN STATE.png");
	coin = new Button (SCREEN_W/2 ,SCREEN_H/2);
	coin->loadFromFile(Background::gRenderer, "CoinRotate.png");
	coin->setHeight(step);
	coin->setWidth(step);
	//for(int i = 0; i < 9; i++)
	//{
		coin->render(Background::gRenderer,vCoinFlip[3]);
	//}


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
								initInfo();
							}
					if(introButtons[1]->isClicked(&e))
							{
								Free();
								initInfo();//VOLUME
							}
					if(introButtons[2]->isClicked(&e))
							{
								Free();
								initInfo();//INSERT CREDIT
							}

					if(introButtons[3]->isClicked(&e))
							{
								Free();
								initGameBoard();//START NEW GAME
							}

					if(introButtons[4]->isClicked(&e))
							{
								Free();
								initGameBoard();//RESUME from XML
							}
					break;
				case INFO :
					if(infoBackToIntro->isClicked(&e))
								{
									Free();
									initIntro();
								}
					break;
				case GAME_BOARD :
					if(cashOut->isClicked(&e)){
						Free();
//!!!
						initWin();
						//initOutro();
					}
					break;
				case WIN:
					if(coin->isClicked(&e))
					{
						Free();
						coin->render(Background::gRenderer,vCoinFlip[0]);
						initWin();
					}
					//initWin();
					//SDL_Delay(6000);
					//Free();
					//initGameBoard();
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
	if(MenuState == GAME_BOARD)
	{
		gameBoard->Clear();
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
	if(MenuState == WIN)
	{
		win->Clear();
		coin->free();
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
