/*
 * LTexture.h
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#ifndef LTEXTURE_H_
#define LTEXTURE_H_
#include "Globals.h"
#include "Background.h"

class LTexture
{
public:
	LTexture(int x = 0, int y = 0);

	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path,
								int width = -1,
								int height = -1);
	virtual ~LTexture();
	virtual void render(SDL_Renderer * gRenderer, SDL_Rect *clip,
						double angle = 0,
						int w = 0, int h = 0);
	virtual void free();
	virtual void Show();
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	virtual void setPosition(int _x, int _y);
	SDL_Texture * mTexture;
	protected:
	int mWidth;
	int mHeight;
	int x;
	int y;
};

#endif /* LTexture_H_ */
