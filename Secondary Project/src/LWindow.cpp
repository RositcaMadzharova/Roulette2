/*
 * LWindow.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: kakev
 */

#include "LWindow.h"

SDL_Renderer* LWindow::gRenderer= NULL;
LWindow::LWindow()
{
	//Initialize non-existant window
	mWindow = NULL;
	mWidth = 0;
	mHeight = 0;
}

bool LWindow::init()
{

	mWindow = SDL_CreateWindow( "Roullete", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN );
	if( mWindow != NULL )
	{
		mWidth = SCREEN_W;
		mHeight = SCREEN_H;
	}

	gRenderer = SDL_CreateRenderer( mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	if( gRenderer == NULL )
	{
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		SDL_DestroyWindow( mWindow );
		mWindow = NULL;
	}
	return mWindow != NULL && gRenderer != NULL;
}

void LWindow::free()
{
	if( mWindow != NULL )
	{
		SDL_DestroyWindow( mWindow );
		mWidth = 0;
		mHeight = 0;
		IMG_Quit();
	}

}

int LWindow::getWidth()
{
	return mWidth;
}

int LWindow::getHeight()
{
	return mHeight;
}



