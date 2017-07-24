/*
 * Text.h
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#ifndef TEXT_H_
#define TEXT_H_
#include "GLOBALS.h"
#include "LWindow.h"

class Text {

public:
	Text(int x, int y, int w,int h,
			int front_size,
			 std::string massage_text,
			 SDL_Color color ,std::string massage_te = "arial.ttf");
	Text(int x, int y, int w,int h,
			int front_size,
			 double massage_double,
			 SDL_Color color  ,std::string massage_te = "arial.ttf");
	Text(int x, int y, int w,int h,
			int front_size,
			 int massage_int,
			 SDL_Color color  ,std::string massage_te = "arial.ttf");
	virtual ~Text();
	void Clear();
	SDL_Texture * loadFromFile(
			int front_size,
			 std::string massage_text,
			 SDL_Color color,
			 std::string massage_te = "arial.ttf",
			int x = 0,
			int y = 0
			 );
	SDL_Texture * getTexture (){ return textTexture;}
	bool Show();


private:


	SDL_Rect * textRect;
	SDL_Texture *textTexture;
};

#endif /* TEXT_H_ */
