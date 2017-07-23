#ifndef GLOBALS_H_
#define GLOBALS_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <ctime>
#include <cstdio>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <assert.h>
using namespace std;

// INTRO SCREEN
const int SCREEN_W =1300;
const int SCREEN_H = 800;
const int INTRO_BUTTONS = 5;
const int INTRO_BUTTONS_W = 600;
const int INTRO_BUTTONS_H = 50;
const int ADD_CREDIT_BUTTON_VALUE = 100;

//INFO SCREEN
const int INFO_BUTTON_X = 10;
const int INFO_BUTTON_Y = 10;
const int INFO_BUTTON_H =60;
const int INFO_BUTTON_W= 60;

//GAME BOARD SCREEN
const int POOLS_BUTTON = 5;
const int SCREEN_BOARD_W = 1200;
const int SCREEN_BOARD_H = 750;
const int POOLS_W = 30;
const int POOLS_H = 30;
const int BUTTON_W = 200;
const int BUTTON_H = 100;
const int GAME_BOARD_BUTTON_W = 170;
const int GAME_BOARD_BUTTON_H = 90;
const int NUMBER_OF_SECTORS = 37;
const int DENOMINATION = 0.01;

//SPIN SCREEN
const int BALL_W = 60;
const int BALL_H = 60;
const int WHEEL_W = 560;
const int WHEEL_H = 560;

//WIN SCREEN
const int COIN_COUNT = 20;
const int COIN_W = 110;
const int COIN_H = 110;

//BONUS SCREEN
const int SPINS_TO_BONUS = 2;


#endif
