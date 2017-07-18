/*
 * Globals.h
 *
 *  Created on: Jul 8, 2017
 *      Author: kakev
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <ctime>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


const double DENOMINATION = 0.01;

enum GameState
{
	INTRO_MENU = 1,
	INFO,
	GAME_BOARD,
	SPIN,
	OUTRO,
	WIN,
	HISTORY,
	BONUS,
	ACCOUNTING
};

//main renderer
//static SDL_Renderer * gRenderer = NULL;
//main window
static SDL_Window * gWindow = NULL;
//texture for background
//static SDL_Texture *gTexture = NULL;
const int SCREEN_W = 1300;
const int SCREEN_H = 800;

const int SCREEN_BOARD_W = 1200;
const int SCREEN_BOARD_H = 750;

const int SCREEN_ROULETTE_W = 800;
const int SCREEN_ROULETTE_H = 800;

const int INTRO_BUTTON_W = 60;
const int INTRO_BUTTON_H = 60;

const int INTRO_BUTTONS = 5;
const int POOLS_BUTTON = 5;

const int COIN_COUNT = 20;

const int COIN_W = 110;
const int COIN_H = 110;

const int BALL_W = 50;
const int BALL_H = 50;

const int BUTTON_W = 200;
const int BUTTON_H = 100;

const int PULLS_W = 60;
const int PULLS_H = 60;

const int NUMBER_OF_SECTORS = 37;
const int MULTIPLIER_NUMBER = 36;
const int MULTIPLIER_COLOR = 2;
const int MULTIPLIER_PARITY = 2;


const int ADD_CREDIT_BUTTON_VALUE = 100;

//help variables used in function Application::CalcQuadrandClicked
const int TABLE_CELL_WIDTH = 75;
const int TABLE_ROW = 3;
const int TABLE_COLUMN = 13;
const int TABLE_START_X_POS = 76;
const int TABLE_END_X_POS = 151;
const int TABLE_START_Y_POS = 280;
const int TABLE_END_Y_POS = 350;

const int TABLE_SPECIAL_CELLS_COUNT = 4;
const int TABLE_SPECIAL_CELL_START_X_POS = 300;
const int TABLE_SPECIAL_CELL_STEP_X = 150;
const int TABLE_SPECIAL_CELL_END_X_POS = 450;
const int TABLE_SPECIAL_CELL_START_Y_POS = 585;
const int TABLE_SPECIAL_CELL_END_Y_POS = 650;


#endif /* GLOBALS_H_ */
