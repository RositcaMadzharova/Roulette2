/*
 * Text.h
 *
 *  Created on: Jul 17, 2017
 *      Author: kakev
 */

#ifndef TEXT_H_
#define TEXT_H_
#include "Globals.h"
#include "Background.h"

class Text {
public:
	Text(int x, int y, int w,int h,
			int front_size,
			 std::string massage_text,
			 SDL_Color color );
	Text(int x, int y, int w,int h,
			int front_size,
			 int massage_int,
			 SDL_Color color );
	virtual ~Text();
	SDL_Texture * loadFromFile(
			int front_size,
			 std::string massage_text,
			 SDL_Color color);
	SDL_Texture * getTexture (){ return textTexture;}



private:
	SDL_Rect * textRect;
	SDL_Texture *textTexture;
};

#endif /* TEXT_H_ */
