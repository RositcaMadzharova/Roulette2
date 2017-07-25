/*
 * LWindow.h
 *
 *  Created on: Jul 21, 2017
 *      Author: kakev
 */

#ifndef LWINDOW_H_
#define LWINDOW_H_
#include "GLOBALS.h"
#include "LTexture.h"


class LWindow
	{
public:
		//Intializes internals
		LWindow();

		//Creates window
		bool init();

		//Deallocates internals
		void free();

		//Window dimensions
		int getWidth();
		int getHeight();

		//Static Renderer
		static SDL_Renderer* gRenderer;

		LWindow* getWindow() { return this; }

private:
		//Window data
		SDL_Window* mWindow;

		//Window dimensions
		int mWidth;
		int mHeight;

		Mix_Music* myMusic;


	};


#endif /* LWINDOW_H_ */
