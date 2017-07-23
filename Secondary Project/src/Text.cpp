/*
 * Text.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#include "Text.h"

std::string toString(double xx)
{
	int x = xx * 100;
	int length = snprintf( NULL, 0, "%d", x);
	assert(length >= 0);
	char* buf = new char[length + 1];
	snprintf(buf, length + 1, "%d", x);
	std::string str(buf);
	delete[] buf;
	if (x >= 100)
		str.insert(str.length() - 2, 1, '.');
	else
	{
		str.insert(str.length() - 1, 1, '0');
		if (x >= 10)
			str.insert(str.length() - 2, 1, '.');
		else
		{
			str.insert(str.length() - 1, 1, '.');
			str.insert(str.length() - 1, 1, '0');
		}
	}
	return str;
}

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
			int font_size,
			std::string massage_text,
			SDL_Color color , std::string massage_te)
{
	TTF_Init();
	textRect = new SDL_Rect;
	textRect->w = w;
	textRect->h = h;
	textRect->x = x;
	textRect->y = y;
	textTexture = loadFromFile(font_size, massage_text, color,massage_te);
	Show();

	delete textRect;
}

Text::Text(int x, int y, int w, int h,
			int font_size,
			int massage_int,
			SDL_Color color , std::string massage_te)
{
	TTF_Init();
	textRect = new SDL_Rect;
	textRect->w = w;
	textRect->h = h;
	textRect->x = x;
	textRect->y = y;
	textTexture = loadFromFile(font_size, toString(massage_int), color,massage_te);
	Show();

	delete textRect;
}

Text::Text(int x, int y, int w, int h,
			int font_size,
			double massage_double,
			SDL_Color color, std::string massage_te)
{
	TTF_Init();
	textRect = new SDL_Rect;
	textRect->w = w;
	textRect->h = h;
	textRect->x = x;
	textRect->y = y;
	textTexture = loadFromFile(font_size, toString(massage_double), color,massage_te);
	Show();

	delete textRect;
}

Text::~Text()
{
	TTF_Quit();
	Clear();
}

SDL_Texture* Text::loadFromFile(int font_size,
								std::string massage_text,
								SDL_Color color ,
								std::string massage_te
								)
{

	TTF_Font* gFont = TTF_OpenFont(massage_te.c_str(), font_size);
//	TTF_Font* gFont = TTF_OpenFont("lazy.ttf", font_size);
//	TTF_Font* gFont = TTF_OpenFont("SFCartoonistHand.ttf", font_size);

	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, massage_text.c_str(),
			color);
	SDL_Texture *textTexture = SDL_CreateTextureFromSurface(
			LWindow::gRenderer,
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

bool Text::Show()
{
	SDL_RenderCopy(LWindow::gRenderer, textTexture, NULL, textRect);
	SDL_RenderPresent(LWindow::gRenderer);
	return true;
}
