/*
 * Application.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: kakev
 */

#include "Application.h"
#include "Point.h"

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
	//draw 5 Pulls
	//TODO: Each Poll needs different credit value.
	Credits cr;
	for (int i = 0; i < 5; i++) {
		gameBoardPools[i] = new Pools(cr, 100 * i, SCREEN_BOARD_H - 60, 1);
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

void Application::WitchState() {

	switch (MenuState) {
	case INTRO_MENU:
		initIntro();
		introButtons[0]->isHover();

		break;
	case INFO:
		initInfo();
		break;

	case GAME_BOARD:
		initGameBoard();
		break;

	default:
		break;
	}
}

void Application::DisplayBets() {
	for (int i = 0; i < v_coordsAllBetPulls.size(); i++) {

		//get value of Poll from vector
		Credits cr(v_coordsAllBetPulls.at(i).m_value);
		pollsBet[i] = new Pools(cr, v_coordsAllBetPulls.at(i).X,
				v_coordsAllBetPulls.at(i).Y);
		pollsBet[i]->loadFromFile(Background::gRenderer, "Pools.png");
		pollsBet[i]->setHeight(PULLS_W);
		pollsBet[i]->setWidth(PULLS_H);
		SDL_Rect rectButton;
		//get different coordinates
		if (v_coordsAllBetPulls.at(i).m_PullColor == "yellow") {
			rectButton = {1, 1, 118, 111};
		}

		if (v_coordsAllBetPulls.at(i).m_PullColor == "green") {
			rectButton = {118, 1, 118, 111};
		}

		if (v_coordsAllBetPulls.at(i).m_PullColor == "red") {
			rectButton = {236, 1, 118, 111};
		}

		if (v_coordsAllBetPulls.at(i).m_PullColor == "blue") {
			rectButton = {354, 1, 118, 111};
		}

		if (v_coordsAllBetPulls.at(i).m_PullColor == "black") {
			rectButton = {460, 1, 118, 111};
		}

		pollsBet[i]->render(Background::gRenderer, &rectButton);

	}

}

void Application::GamePlay() {

	int currentX = 0;
	int currentY = 0;
	int pullYellow = 0;
	int pullGreen = 0;
	int pullRed = 0;
	int pullBlue = 0;
	int pullBlack = 0;

	bool close = false;
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

				if (gameBoardPools[0]->isClicked(&e)) {
					pullYellow = 1;
					pullGreen = 0;
					pullRed = 0;
					pullBlue = 0;
					pullBlack = 0;
				}

				if (gameBoardPools[1]->isClicked(&e)) {
					pullYellow = 0;
					pullGreen = 1;
					pullRed = 0;
					pullBlue = 0;
					pullBlack = 0;

				}

				if (gameBoardPools[2]->isClicked(&e)) {
					pullYellow = 0;
					pullGreen = 0;
					pullRed = 1;
					pullBlue = 0;
					pullBlack = 0;

				}

				if (gameBoardPools[3]->isClicked(&e)) {
					pullYellow = 0;
					pullGreen = 0;
					pullRed = 0;
					pullBlue = 1;
					pullBlack = 0;
				}

				if (gameBoardPools[4]->isClicked(&e)) {
					pullYellow = 0;
					pullGreen = 0;
					pullRed = 0;
					pullBlue = 0;
					pullBlack = 1;

				}

				if (e.type == SDL_MOUSEBUTTONDOWN) {

					if (e.button.button == SDL_BUTTON_LEFT) {

						SDL_GetMouseState(&currentX, &currentY);
						currentX = e.button.x;
						currentY = e.button.y;

						cout << currentX << ":" << currentY << endl;

						//yellow
						if (pullYellow == 1 && pullGreen == 0 && pullRed == 0
								&& pullBlue == 0 && pullBlack == 0) {

							if (currentY <= 250) {
								Point pYellow(currentX, currentY, "yellow", 1);
								v_coordsAllBetPulls.push_back(pYellow);
							}
						}

						//green
						if (pullYellow == 0 && pullGreen == 1 && pullRed == 0
								&& pullBlue == 0 && pullBlack == 0) {

							if (currentY <= 250) {
								Point pGreen(currentX, currentY, "green", 10);
								v_coordsAllBetPulls.push_back(pGreen);
							}
						}

						//red
						if (pullYellow == 0 && pullGreen == 0 && pullRed == 1
								&& pullBlue == 0 && pullBlack == 0) {

							if (currentY <= 250) {
								Point pRed(currentX, currentY, "red", 20);
								v_coordsAllBetPulls.push_back(pRed);
							}
						}

						//blue
						if (pullYellow == 0 && pullGreen == 0 && pullRed == 0
								&& pullBlue == 1 && pullBlack == 0) {

							if (currentY <= 250) {
								Point pBlue(currentX, currentY, "blue", 50);
								v_coordsAllBetPulls.push_back(pBlue);
							}
						}

						//blue
						if (pullYellow == 0 && pullGreen == 0 && pullRed == 0
								&& pullBlue == 0 && pullBlack == 1) {

							if (currentY <= 250) {
								Point pBlack(currentX, currentY, "black", 100);
								v_coordsAllBetPulls.push_back(pBlack);
							}
						}

					}
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
		DisplayBets();

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

GameState Application::getMenuState() const {
	return MenuState;
}
