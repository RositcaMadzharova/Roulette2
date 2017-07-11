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
			"tap_resized.jpg");
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


void Application::DisplayBets(int x, int y, int pY, int pGr, int pRed, vector<Point> v_allBetPoints)
{


	if (pY == 1 && pGr == 0 &&  pRed == 0) {

		if (y < 220) {
			Credits cr(1);
			Pools gameBoardPools(cr, x, y);
			gameBoardPools.loadFromFile(
					Background::gRenderer, "Pools.png");
			gameBoardPools.setWidth(PULLS_W);
			gameBoardPools.setHeight(PULLS_H);
			cout << x << ":" << y << endl;
			SDL_Rect rec = { 1, 1, 118, 111 };
			gameBoardPools.render(Background::gRenderer,
					&rec);

			Point p (x,y,"yellow",1);
			v_allBetPoints.push_back(p);

		}
	}

	if (pY == 0 && pGr == 1 && pRed == 0) {

		if (y < 220) {
			Credits cr(10);
			Pools gameBoardPools(cr, x, y);
			gameBoardPools.loadFromFile(
					Background::gRenderer, "Pools.png");
			gameBoardPools.setWidth(PULLS_W);
			gameBoardPools.setHeight(PULLS_H);
			cout << x << ":" << y << endl;
			SDL_Rect rec = { 118, 1, 118, 111 };
			gameBoardPools.render(Background::gRenderer,
					&rec);

			Point p (x,y,"green",10);
			v_allBetPoints.push_back(p);
		}
	}


	if (pY == 0 && pGr == 0 && pRed == 1) {

		if (y < 220) {
			Credits cr(20);
			Pools gameBoardPools(cr, x, y);
			gameBoardPools.loadFromFile(
					Background::gRenderer, "Pools.png");
			gameBoardPools.setWidth(PULLS_W);
			gameBoardPools.setHeight(PULLS_H);
			cout << x << ":" << y << endl;
			SDL_Rect rec = { 236, 1, 118, 111 };
			gameBoardPools.render(Background::gRenderer,
					&rec);
			Point p (x,y,"red",20);
					v_allBetPoints.push_back(p);
		}
	}

	//TODO:
	//blue
	//black

}


void Application::GamePlay() {
	bool close = false;

	vector<Point> v_allBetPoolsInfo;


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

				int x, y;
				int pY;
				int pGr;
				int pRed;
				//yellow
				if (gameBoardPools[0]->isClicked(&e)) {
					SDL_GetMouseState(&x, &y);
					pY = 1;
					pGr = 0;
					pRed = 0;
				}

				//green
				if (gameBoardPools[1]->isClicked(&e)) {
					SDL_GetMouseState(&x, &y);
					pY = 0;
					pGr = 1;
					pRed = 0;
				}

				//red
				if (gameBoardPools[2]->isClicked(&e)) {
					SDL_GetMouseState(&x, &y);
					pY = 0;
					pGr = 0;
					pRed = 1;
				}

				if (e.type == SDL_MOUSEBUTTONDOWN) {

					if (e.button.button == SDL_BUTTON_LEFT) {

						SDL_GetMouseState(&x, &x);
						x = e.button.x;
						y = e.button.y;

						cout << x << ":" << y << endl;


						DisplayBets(x, y, pY, pGr, pRed, v_allBetPoolsInfo);

					}
				}

				if (gameBoardPools[3]->isClicked(&e)) {
					//TODO blue
				}

				if (gameBoardPools[4]->isClicked(&e)) {
					//TODO black
				}

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


