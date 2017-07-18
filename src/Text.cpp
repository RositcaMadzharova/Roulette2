/*
 * Text.cpp
 *
 *  Created on: Jul 17, 2017
 *      Author: kakev
 */

#include "Text.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;


std::string toString(int x)
{
	int length = snprintf( NULL, 0, "%d", x);
	assert(length >= 0);
	char* buf = new char[length + 1];
	snprintf(buf, length + 1, "%d", x);
	std::string str(buf);
	delete[] buf;
	return str;
}

Text::Text(int x, int y, int w, int h,
			int front_size,
			std::string massage_text,
			SDL_Color color)
{
	TTF_Init();
	textRect = new SDL_Rect;
	textRect->w = w;
	textRect->h = h;
	textRect->x = x;
	textRect->y = y;
	textTexture = loadFromFile(front_size, massage_text, color);
}

Text::Text(int x, int y, int w, int h,
			int front_size,
			int massage_int,
			SDL_Color color)
{
	TTF_Init();
	textRect = new SDL_Rect;
	textRect->w = w;
	textRect->h = h;
	textRect->x = x;
	textRect->y = y;
	textTexture = loadFromFile(front_size, toString(massage_int), color);
}

Text::~Text()
{
	TTF_Quit();
	Clear();
}

SDL_Texture* Text::loadFromFile(
								int front_size,
								std::string massage_text,
								SDL_Color color)
{

	TTF_Font* gFont = TTF_OpenFont("arial.ttf", front_size);
//	TTF_Font* gFont = TTF_OpenFont("SFCartoonistHand.ttf", front_size);

	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, massage_text.c_str(),
			color);
	SDL_Texture *textTexture = SDL_CreateTextureFromSurface(
			Background::gRenderer,
			textSurface);
	//Get rid of old surface
	SDL_FreeSurface(textSurface);
	//Return success
	return textTexture;
}

void Text::Clear()
{
	delete textRect;
	SDL_DestroyTexture(textTexture);
}

void Text::Show()
{
	SDL_RenderCopy(Background::gRenderer, textTexture, NULL, textRect);
	SDL_RenderPresent(Background::gRenderer);
}