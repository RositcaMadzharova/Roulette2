/*
 * Application.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: kakev
 */

#include "Application.h"
#include "Point.h"
#include <vector>

Application::Application() {

	intro = NULL;
	for (unsigned int i = 0; i < 5; i++) {
		introButtons[i] = NULL;
	}
	info = NULL;
	infoBackToIntro = NULL;
	gameBoard = NULL;
	roulette = NULL; // spin roulette
	ball = NULL;
	outro = NULL; // Animation who backs to Intro 10 sec;
	win = NULL; // anima
	initIntro();
}

void Application::initIntro() {
	MenuState = INTRO_MENU;
	intro = new Background("INTROSCREEN", SCREEN_W, SCREEN_H,
			"INTRO SCREEN.jpg");
	for (int i = 0; i < 5; i++) {
		introButtons[i] = new Button(SCREEN_W / 2 - INTRO_BUTTON_W / 2,
				SCREEN_H / 5 - INTRO_BUTTON_H / 2 + i * (INTRO_BUTTON_H + 10));
		introButtons[i]->loadFromFile(Background::gRenderer, "Pools.png");
		introButtons[i]->setHeight(INTRO_BUTTON_H);
		introButtons[i]->setWidth(INTRO_BUTTON_W);
		SDL_Rect rectButton = { 1, 1, 118, 111 };
		introButtons[i]->render(Background::gRenderer, &rectButton);

	}

}

Application::~Application() {

	for (unsigned int i = 0; i < 5; i++) {
		delete introButtons[i];
	}
	delete intro;
	// TODO Auto-generated destructor stub
}

void Application::initInfo() {
	MenuState = INFO;
	info = new Background("INFOSCREEN", SCREEN_W, SCREEN_H,
			"rouletterules.jpg");
	infoBackToIntro = new Button(10, 10);
	infoBackToIntro->loadFromFile(Background::gRenderer, "BackButton.png");
	infoBackToIntro->setHeight(INTRO_BUTTON_H);
	infoBackToIntro->setWidth(INTRO_BUTTON_W);
	infoBackToIntro->render(Background::gRenderer, NULL);
}

void Application::initGameBoard() {
	MenuState = GAME_BOARD;
	gameBoard = new Background("GameBoard", SCREEN_BOARD_W, SCREEN_BOARD_H,
			"EuropeanRoulette.bmp");

	cashOut = new Button(SCREEN_BOARD_W - BUTTON_W,
			SCREEN_BOARD_H - BUTTON_H - 10);
	cashOut->loadFromFile(Background::gRenderer, "Cash OUT.png");
	cashOut->setHeight(BUTTON_W);
	cashOut->setWidth(BUTTON_W);
	cashOut->render(Background::gRenderer, NULL);

	//draw 5 Pulls and PICK PICK >>>>!!!!!!
	//TODO: Each Poll needs different credit value.

	for (int i = 0; i < POOLS_BUTTON; i++) {
		gameBoardPools[i] = new Pools(cr, 100 * i, SCREEN_BOARD_H - 60);
		gameBoardPools[i]->loadFromFile(Background::gRenderer, "Pools.png");
		gameBoardPools[i]->setHeight(PULLS_W);
		gameBoardPools[i]->setWidth(PULLS_H);
		SDL_Rect rectButton = { 113 * i, 1, 118, 111 };
		gameBoardPools[i]->render(Background::gRenderer, &rectButton);
	}

}

void Application::initRoulette() {
}

void Application::initOutro() {

}

void Application::initWin() {
}

int Application::CalcQuadrandClicked(int x, int y) {
	int sequence = 0;
	int clickedCell = -1;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 13; j++) {
			sequence++;

			cout << "||||||||" << sequence;

			//    75*1 75*2 75*3 75*4 ... 75*13
			cout << "[" << 75 * j << "]" << endl;

//					        0[0]  x[75]
//					||||||||1[75] x[75]
//					||||||||2[150]x[75]
//					||||||||3[225]x[75]
//					||||||||4[300]x[75]
//					||||||||5[375]x[75]
//					||||||||6[450]x[75]
//					||||||||7[525]x[75]
//					||||||||8[600]x[75]
//					||||||||9[675]x[75]
//					||||||||10[750]x[75]
//					||||||||11[825]x[75]
//					||||||||12[900]x[75]
//					||||||||13[975]x[75]

			// x >= 70+75*i
			// x <= 140+75*i
			// y >= 280
			// y<=350

			//For first line
			for (int i = 0; i < 13; i++) {

				if (x >= 70 + (75 * i)
						&& x <= (140 + 75 * i)
						&& y >= 280
						&& y <= 350) {
					//cout << i;
					clickedCell = i;
				}


//				if (x >= 70 + (75 * i)
//						&& x <= (140 + 75 * i)
//						&& y >= 355
//						&& y <= 440) {
//					//cout << i;
//					cout << "2nd line" << i+14;
//					clickedCell = i+14;
//				}


			}


		}
	}
	return clickedCell;

}

void Application::DisplayBets(int x, int y, int poolYellow, int poolGreen,
		int poolRed, int poolBlack, int poolBlue,
		vector<Point> v_allBetPoints) {

	if (poolYellow == 1 && poolGreen == 0 && poolRed == 0 && poolBlack == 0
			&& poolBlue == 0) {

		if (y >= 280 && y <= 510) {

			//TODO:
			//for each cell 75x75, display in which cell is clicked

			int clickedCell = CalcQuadrandClicked(x, y);

			int coordX = -1;
			int coordY = -1;

			//for first line
			for (int i = 0; i <= 26; i++) {
				if (clickedCell == i) {
					coordX = 70 + (75 * i) + 10 ;

					//if line 1
					if(i<=13){ coordY = 285; }

				}
			}


			if (coordX != -1 && coordY != -1) {
				Credits cr(1);
				Pools gameBoardPools(cr, coordX, coordY);
				gameBoardPools.loadFromFile(Background::gRenderer, "Pools.png");
				gameBoardPools.setWidth(PULLS_W);
				gameBoardPools.setHeight(PULLS_H);
				cout << x << ":" << y << endl;
				SDL_Rect rec = { 1, 1, 118, 111 };
				gameBoardPools.render(Background::gRenderer, &rec);

				Point p(x, y, "yellow", 1);
				v_allBetPoints.push_back(p);
			}

		}
	}

	if (poolYellow == 0 && poolGreen == 1 && poolRed == 0 && poolBlack == 0
			&& poolBlue == 0) {

		if (y >= 280 && y <= 510) {
			Credits cr(10);
			Pools gameBoardPools(cr, x, y);
			gameBoardPools.loadFromFile(Background::gRenderer, "Pools.png");
			gameBoardPools.setWidth(PULLS_W);
			gameBoardPools.setHeight(PULLS_H);
			cout << x << ":" << y << endl;
			SDL_Rect rec = { 118, 1, 118, 111 };
			gameBoardPools.render(Background::gRenderer, &rec);

			Point p(x, y, "green", 10);
			v_allBetPoints.push_back(p);
		}
	}

	if (poolYellow == 0 && poolGreen == 0 && poolRed == 1 && poolBlack == 0
			&& poolBlue == 0) {
		cout << "REDD";

		if (y >= 280 && y <= 510) {
			Credits cr(20);
			Pools gameBoardPools(cr, x, y);
			gameBoardPools.loadFromFile(Background::gRenderer, "Pools.png");
			gameBoardPools.setWidth(PULLS_W);
			gameBoardPools.setHeight(PULLS_H);
			cout << x << ":" << y << endl;
			SDL_Rect rec = { 236, 1, 118, 111 };
			gameBoardPools.render(Background::gRenderer, &rec);
			Point p(x, y, "red", 20);
			v_allBetPoints.push_back(p);
		}
	}

	if (poolYellow == 0 && poolGreen == 0 && poolRed == 0 && poolBlack == 1
			&& poolBlue == 0) {

		cout << "BLACK";

		if (y >= 280 && y <= 510) {
			Credits cr(100);
			Pools gameBoardPools(cr, x, y);
			gameBoardPools.loadFromFile(Background::gRenderer, "Pools.png");
			gameBoardPools.setWidth(PULLS_W);
			gameBoardPools.setHeight(PULLS_H);
			cout << x << ":" << y << endl;
			SDL_Rect rec = { 472, 1, 118, 111 };
			gameBoardPools.render(Background::gRenderer, &rec);
			Point p(x, y, "black", 100);
			v_allBetPoints.push_back(p);
		}
	}

	if (poolYellow == 0 && poolGreen == 0 && poolRed == 0 && poolBlack == 0
			&& poolBlue == 1) {

		cout << "BLue";

		if (y >= 280 && y <= 510) {
			Credits cr(50);
			Pools gameBoardPools(cr, x, y);
			gameBoardPools.loadFromFile(Background::gRenderer, "Pools.png");
			gameBoardPools.setWidth(PULLS_W);
			gameBoardPools.setHeight(PULLS_H);
			cout << x << ":" << y << endl;
			SDL_Rect rec = { 344, 1, 118, 111 };
			gameBoardPools.render(Background::gRenderer, &rec);
			Point p(x, y, "blue", 100);
			v_allBetPoints.push_back(p);
		}
	}

	//TODO:
	//blue
	//black

}

void Application::GamePlay() {
	bool close = false;

	vector<Point> v_pointsBetInfo;

	while (!close) {

		SDL_Event e;
		while (SDL_PollEvent(&e)) {

			switch (MenuState) {
			case INTRO_MENU:
				if (introButtons[0]->isClicked(&e)) {
					Free();
					MenuState = INFO;
					initInfo();
				}
				if (introButtons[3]->isClicked(&e)) {
					Free();
					MenuState = GAME_BOARD;
					initGameBoard();
				}

				break;
			case INFO:
				if (infoBackToIntro->isClicked(&e)) {
					Free();
					MenuState = INTRO_MENU;
					initIntro();
				}
				break;
			case GAME_BOARD:

//				if (cashOut->isClicked(&e)) {
//				//	Free();
//				//	MenuState = OUTRO;
//				//	initOutro();
//				}

//gameBoardPools[], x, y, Event e, vector<Point> pointsBetInfo

				//TODO: here we are more than 10 times in a second. to be fixed
				int x, y;
				int poolYellow;
				int poolGreen;
				int poolRed;
				int poolBlack;
				int poolBlue;
				//yellow

				if (gameBoardPools[0]->isClicked(&e)) {
					SDL_GetMouseState(&x, &y);
					poolYellow = 1;
					poolGreen = 0;
					poolRed = 0;
					poolBlack = 0;
					poolBlue = 0;
				}

				//green
				if (gameBoardPools[1]->isClicked(&e)) {
					SDL_GetMouseState(&x, &y);
					poolYellow = 0;
					poolGreen = 1;
					poolRed = 0;
					poolBlack = 0;
					poolBlue = 0;
				}

				//red
				if (gameBoardPools[2]->isClicked(&e)) {
					SDL_GetMouseState(&x, &y);
					poolYellow = 0;
					poolGreen = 0;
					poolRed = 1;
					poolBlack = 0;
					poolBlue = 0;

				}
				//black
				if (gameBoardPools[4]->isClicked(&e)) {
					SDL_GetMouseState(&x, &y);
					poolYellow = 0;
					poolGreen = 0;
					poolRed = 0;
					poolBlack = 1;
					poolBlue = 0;
				}
				//blue
				if (gameBoardPools[3]->isClicked(&e)) {
					cout << "blue";

					;
					SDL_GetMouseState(&x, &y);
					poolYellow = 0;
					poolGreen = 0;
					poolRed = 0;
					poolBlack = 0;
					poolBlue = 1;
				}

				if (e.type == SDL_MOUSEBUTTONDOWN) {

					if (e.button.button == SDL_BUTTON_LEFT) {

						SDL_GetMouseState(&x, &x);
						x = e.button.x;
						y = e.button.y;

						cout << x << ":" << y << endl;

						DisplayBets(x, y, poolYellow, poolGreen, poolRed,
								poolBlack, poolBlue, v_pointsBetInfo);

					}
				}

				if (gameBoardPools[3]->isClicked(&e)) {
					//TODO blue
				}
//

				break;
			default:
				break;
			}

			if (e.type == SDL_QUIT) {
				close = true;
			}

		}

		//separate function that traverse vector with Bets and display polls

	}

}

void Application::Free() {
	if (MenuState == INTRO_MENU) {
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
	if (MenuState == INFO) {
		info->Clear();
		infoBackToIntro->free();
		SDL_RenderClear(Background::gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		Background::gRenderer = NULL;
		IMG_Quit();
		SDL_Quit();
	}
	if (MenuState == GAME_BOARD) {
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
}

