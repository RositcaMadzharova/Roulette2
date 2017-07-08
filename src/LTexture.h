/*
 * LTexture.h
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#ifndef LTEXTURE_H_
#define LTEXTURE_H_
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "Globals.h"
#include <string>
#include <cstdio>
using namespace std;

class LTexture
{
public:
	LTexture(int x = 0, int y = 0);

	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
	virtual ~LTexture();
	virtual void render(SDL_Renderer * gRenderer,SDL_Rect *clip);
	virtual void free();
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	int getX() const;
	int getY() const;
	virtual void setPosition(int _x, int _y);
	void REctold();
	SDL_Texture * mTexture;
protected:

	int mWidth;
    int mHeight;
    int x;
    int y;
};

#endif /* LTexture_H_ */
