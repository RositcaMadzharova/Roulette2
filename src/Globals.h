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
#include <string>
#include <ctime>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


 enum GameState{
	INTRO_MENU=1,INFO,GAME_BOARD,SPIN,OUTRO,WIN
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
const int SCREEN_BOARD_H = 428;

const int INTRO_BUTTON_W = 59;
const int INTRO_BUTTON_H = 59;

const int POOLS_BUTTON = 5;

const int BUTTON_W=200;
const int BUTTON_H= 100;

const int PULLS_W = 60;
const int PULLS_H = 60;

#endif /* GLOBALS_H_ */
