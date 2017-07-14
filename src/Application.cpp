/*
 * Application.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: pEftimov
 */

#include "Application.h"

Application::Application()
{

	intro = NULL;
	for (unsigned int i = 0; i < INTRO_BUTTONS; i++)
	{
		introButtons[i] = NULL;
	}
	info = NULL;
	infoBackToIntro = NULL;
	gameBoard = NULL;
	roulette = NULL; // spin roulette
	ball = NULL;
	outro = NULL; // Animation who backs to Intro 10 sec;
	win = NULL; // anima
	cashOut = NULL;
	spin = NULL;

	for (unsigned int i = 0; i < POOLS_BUTTON; i++)
	{
		gameBoardPools[i] = NULL;
		betPools[i] = NULL;
	}

	for (unsigned int i = 0; i < COIN_COUNT; i++)
	{
		coin[i] = NULL;
	}

	initIntro();
}

Application::~Application()
{

	for (unsigned int i = 0; i < 5; i++)
	{
		delete introButtons[i];
	}
	delete intro;
}

void Application::initIntro()
{
	MenuState = INTRO_MENU;
	intro = new Background("INTROSCREEN", SCREEN_W, SCREEN_H,
			"IntroBackground.jpg");
	for (int i = 0; i < INTRO_BUTTONS; i++)
	{
		introButtons[i] = new Button(SCREEN_W / 2 - 500 / 2,
				SCREEN_H / 10 - INTRO_BUTTON_H / 2 + i * (INTRO_BUTTON_H + 10));
		introButtons[i]->loadFromFile(Background::gRenderer, "1.png");
		introButtons[i]->setWidth(500);
		introButtons[i]->setHeight(50);
		SDL_Rect rectButton = { 0, 0, 1000, 300 };
		introButtons[i]->render(Background::gRenderer, &rectButton, 0, 500, 50);
	}
}

void Application::initInfo()
{
	MenuState = INFO;
	info = new Background("INFOSCREEN", SCREEN_W, SCREEN_H,
			"rouletterules.jpg");
	infoBackToIntro = new Button(10, 10);
	infoBackToIntro->loadFromFile(Background::gRenderer, "BackButton.png");
	infoBackToIntro->setHeight(INTRO_BUTTON_H);
	infoBackToIntro->setWidth(INTRO_BUTTON_W);
	infoBackToIntro->render(Background::gRenderer, NULL);
}

void Application::initGameBoard()
{
	MenuState = GAME_BOARD;
	//display background
	gameBoard = new Background("GameBoard", SCREEN_BOARD_W, SCREEN_BOARD_H,
			"EuropeanRouletteFinal.bmp");

	//display cashout button
	cashOut = new Button(SCREEN_BOARD_W - BUTTON_W - 50, 77);
	cashOut->loadFromFile(Background::gRenderer, "Cash OUT.png");
	cashOut->setWidth(210);
	cashOut->setHeight(120);
//	cashOut->render(Background::gRenderer, NULL);

	//this will be spin button need picture ;
	spin = new Button(SCREEN_BOARD_W - BUTTON_W - 58, SCREEN_BOARD_H - 105);
	spin->loadFromFile(Background::gRenderer, "Cash OUT.png");
	spin->setWidth(213);
	spin->setHeight(125);
//	spin->render(Background::gRenderer, NULL);

	//draw 5 Pulls and PICK PICK >>>>!!!!!!
	//TODO: Each Poll needs different credit value.
	for (int i = 0; i < POOLS_BUTTON; i++)
	{
		gameBoardPools[i] = new Pools(cr, 113 * i + SCREEN_BOARD_W - 865,
				SCREEN_BOARD_H - 90);
		gameBoardPools[i]->loadFromFile(Background::gRenderer, "Pools.png");
		gameBoardPools[i]->setHeight(2 * PULLS_W);
		gameBoardPools[i]->setWidth(2 * PULLS_H);
//		SDL_Rect rectButton = { 113 * i + 3, 1, 118, 111 };
//		gameBoardPools[i]->render(Background::gRenderer, &rectButton);
	}

}

void Application::initRoulette()
{
}

void Application::initOutro()
{

}

void Application::initWin()
{
	MenuState = WIN;
	win = new Background("Win", SCREEN_ROULETTE_W, SCREEN_ROULETTE_H,
			"CoinBag.png");
	for (int i = 0; i < COIN_COUNT; i++)
	{
		coin[i] = new LTexture(rand() % 200 + 100, rand() % SCREEN_ROULETTE_W);
		coin[i]->loadFromFile(Background::gRenderer, "coin.png");
		coin[i]->setWidth(COIN_W);
		coin[i]->setHeight(COIN_H);
	}
	WinAnimation();
}

void Application::initSpin()
{
	MenuState = SPIN;
	roulette = new Background("spin", SCREEN_ROULETTE_W, SCREEN_ROULETTE_H,
			"RouletteBoard.png");
	wheel = new LTexture(SCREEN_ROULETTE_W / 10, SCREEN_ROULETTE_H / 10);
	wheel->loadFromFile(Background::gRenderer, "wheel2.png");
	wheel->setWidth(640);
	wheel->setHeight(640);
	wheel->render(Background::gRenderer, NULL, 0);
	ball = new Button(SCREEN_ROULETTE_W, SCREEN_ROULETTE_H);
	ball->loadFromFile(Background::gRenderer, "BALL.png");
	ball->setWidth(BALL_W);
	ball->setHeight(BALL_H);
	//ball->render(Background::gRenderer, NULL);
}

//return the number of cell
//cells: From 0 to 39
// cell[i] = 0 (if i==13);
// cell[i] = 3*i (if i/13==0, i!= 0);
// cell[i] = 3*i-1 (if i/13==1, i!=13);
// cell[i] = 3*i-2 (if i/13==2, i!=26);
//get parameters: positionX, positionY
int Application::CalcQuadrandClicked(int x, int y)
{
	//help variable that starts from 0 to 39 in the loops below
	int sequence = -1;
	int clickedCell = -1;

	//for 3 lines
	for (int line = 0; line < 3; line++)
	{
		//for each cell in each line
		for (int i = 0; i < 13; i++)
		{
			sequence++;

			//step is 75 ; start position of table is from x=70 and y=140
			if (x >= 76 + (75 * i)
					&& x <= (151 + 75 * i)
					&& y >= 280 + (75 * line)
					&& y <= 350 + (75 * line))
			{

				clickedCell = sequence;
			}
		}
	}

	cout << "clickedCell:" << clickedCell << endl;
	return clickedCell;
}

void Application::DisplayBets(int x, int y, int color,
								vector<Point> v_allBetPoints)
{

	int coordX = -1;
	int coordY = -1;

	int clickedCell = CalcQuadrandClicked(x, y);
	string colors[POOLS_BUTTON] = { "yellow", "green", "red", "blue", "black" };
	int value[POOLS_BUTTON] = { 2, 10, 20, 50, 100 };

	for (int j = 0; j < POOLS_BUTTON; j++)
		if (color == j + 1)
		{

			//for all 39 cells
			for (int i = 0; i <= 39; i++)
			{
				if (i == 0 || i == 26)
					continue;
				if (clickedCell == i)
				{
					coordX = 77 + (i - ((i / 13) * 13)) * 75 + i % 13;
					coordY = 285 + (i / 13) * 77;
				}
			}

			if (coordX != -1 && coordY != -1)
			{
				Credits cr(value[j]);
				Pools gameBoardPools(cr, coordX, coordY);
				gameBoardPools.loadFromFile(Background::gRenderer, "Pools.png");
				gameBoardPools.setWidth(PULLS_W);
				gameBoardPools.setHeight(PULLS_H);
				cout << x << ":" << y << endl;
				SDL_Rect rec =
						{ j * 112 + 3, 1, 112, 111 };
				gameBoardPools.render(Background::gRenderer, &rec);

				Point p(x, y, colors[j], value[j]);
				v_allBetPoints.push_back(p);
			}
		}
}

bool Application::WinAnimation()

{
	bool isDone = false;
	short int timeout = 6000;
	vector<SDL_Rect> goldCoins;
	for (int i = 0; i < 10; i++)
		goldCoins.push_back( { COIN_W * i, 0, COIN_W, COIN_H });

	while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout))
	{

		for (int i = 0; i < COIN_COUNT; i++)
		{
			coin[i]->setX(rand() % 350 + 140);
			coin[i]->setY(rand() % 110 + 20);

			for (int j = 0; j < 10; j++)
			{
				coin[i]->render(Background::gRenderer, &goldCoins[j]);
				SDL_Delay(10);
			}
			SDL_Delay(60);
			isDone = true;
		}
	}
	return isDone;
}

int Application::spinBall()
{
	srand(time(NULL));
	int result = rand() % 37;

	double angleBall = 0;
	double angleWheel = 0; //2 * M_PI * result / 37;

	double radius = 330;
	const double minRaduis = 210;
	double andleEnd = 82 * M_PI;
	double stepBall = M_PI / 36;
	double stepWheel = 0.2;

	do
	{
		const double MAGIC_NUMBER = 0.08;

		SDL_Delay(3);

		ball->setX(
				SCREEN_ROULETTE_W / 2 - BALL_W / 2 + cos(angleBall) * radius);
		ball->setY(
				SCREEN_ROULETTE_H / 2 - BALL_H / 2 + sin(angleBall) * radius);

		wheel->render(Background::gRenderer, NULL, -angleWheel);
		ball->render(Background::gRenderer, NULL, 0);
		angleWheel += stepWheel;
		if (angleWheel < andleEnd)
			angleBall += stepBall - MAGIC_NUMBER * (minRaduis / radius);
		else
			angleBall -= M_PI / 900;
		radius -= 0.1;
	}
	while (angleWheel < andleEnd + 10 * M_PI);
//	while (radius > minRaduis);

	delete wheel;
	wheel = new LTexture(SCREEN_ROULETTE_W, SCREEN_ROULETTE_H);
	wheel->loadFromFile(Background::gRenderer, "wheel2.png");

//	wheel->setWidth(640);
//	wheel->setHeight(640);
	wheel->render(Background::gRenderer, NULL, result * 2 * M_PI / 37);
	SDL_Delay(100);

	return result;
}

void Application::GamePlay()
{
	bool close = false;

	vector<Point> v_pointsBetInfo;

	while (!close)
	{

		SDL_Event e;
		while (SDL_PollEvent(&e))
		{

			switch (MenuState)
			{
			case INTRO_MENU:
				if (introButtons[0]->isClicked(&e))
				{
					Free();
					MenuState = INFO;
					initInfo();
				}
				if (introButtons[3]->isClicked(&e))
				{
					Free();
					MenuState = GAME_BOARD;
					initGameBoard();
				}
				break;
			case INFO:
				if (infoBackToIntro->isClicked(&e))
				{
					Free();
					MenuState = INTRO_MENU;
					initIntro();
				}
				break;
			case GAME_BOARD:

//				if (cashOut->isClicked(&e))
//				{
//				//	Free();
//				//	MenuState = OUTRO;
//				//	initOutro();
//				}

				//Test of Win
				if (cashOut->isClicked(&e))
				{
					Free();
					initWin();
					Free();
					initGameBoard();
				}

				//TODO: here we are more than 10 times in a second. to be fixed
				int x, y;
				int color;

				for (int i = 0; i < POOLS_BUTTON; i++)
					if (gameBoardPools[i]->isClicked(&e))
					{
						SDL_GetMouseState(&x, &y);
						color = i + 1;
					}
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						SDL_GetMouseState(&x, &x);
						x = e.button.x;
						y = e.button.y;

						cout << x << ":" << y << endl;

						DisplayBets(x, y, color, v_pointsBetInfo);
					}
				}

				if (spin->isClicked(&e))
				{
					Free();
					initSpin();
				}
				if (cashOut->isClicked(&e))
				{
					Free();
					initOutro();
				}

				break;

			case SPIN:
				cout << spinBall() << endl;
				Free();
				initGameBoard();

				break;
			default:
				break;
			}

			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_SPACE)
			{
				close = true;
			}

		}

		//separate function that traverse vector with Bets and display polls

	}

}

void Application::Free()
{
	if (MenuState == INTRO_MENU)
	{
		intro->Clear();
		for (int i = 0; i < INTRO_BUTTONS; i++)
			introButtons[i]->free();
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
	if (MenuState == INFO)
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
	if (MenuState == GAME_BOARD)
	{
		gameBoard->Clear();
		for (int i = 0; i < POOLS_BUTTON; i++)
			gameBoardPools[i]->free();
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
	if (MenuState == WIN)
	{
		win->Clear();
		for (int i = 0; i < COIN_COUNT; i++)
		{
			coin[i]->free();
		}
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
	if (MenuState == SPIN)
	{
		roulette->Clear();
		wheel->free();
		ball->free();
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();

	}
}

