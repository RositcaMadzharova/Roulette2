/*
 * LWindow.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: kakev
 */

#include "LWindow.h"

SDL_Renderer* LWindow::gRenderer = NULL;
LWindow::LWindow()
{

	//Initialize non-existant window
	mWindow = NULL;
	mWidth = 0;
	mHeight = 0;
	myMusic = NULL;
	init();
	PlayMusic();
}

bool LWindow::init()
{

	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cerr << "SDL Audio error: " << SDL_GetError() << endl;
		success = false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cerr << "Audio error: " << Mix_GetError() << endl;
		success = false;
	}
	mWindow = SDL_CreateWindow("Roullete", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
	if (mWindow != NULL)
	{
		mWidth = SCREEN_W;
		mHeight = SCREEN_H;
		success = false;
	}

	gRenderer = SDL_CreateRenderer(mWindow, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n",
				SDL_GetError());
		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
		success = false ;
	}
	 myMusic = Mix_LoadMUS( "Last Summer In Rio.mp3" );

	    if( myMusic == NULL )
	    {
	    	printf("Music could not be opened ! SDL Error: %s\n",
	    					SDL_GetError());
	    	success = false ;

	    }
	    success = true;
	return mWindow != NULL && gRenderer != NULL && success;
}

void LWindow::free()
{
	if (mWindow != NULL)
	{
		SDL_DestroyWindow(mWindow);
		mWidth = 0;
		mHeight = 0;
		IMG_Quit();
		Mix_FreeMusic( myMusic );
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


void LWindow::PlayMusic()
{
	if( Mix_PlayingMusic() == 0 )
		 Mix_PlayMusic( myMusic,  10) ;

}

