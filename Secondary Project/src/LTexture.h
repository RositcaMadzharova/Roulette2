/*
 * LTexture.h
 *
 *  Created on: Jul 21, 2017
 *      Author: kakev
 */

#ifndef LTEXTURE_H_
#define LTEXTURE_H_
#include "GLOBALS.h"
#include "LWindow.h"

class LTexture
{
public:
	//Initializes variables
	LTexture(int _x, int _y);

	//copy constructor
	LTexture(const LTexture&);

	//Deallocates memory
	virtual ~LTexture();

	//Loads image at specified path
	virtual bool loadFromFile(std::string path);

	//Display texture
	void show();

	void draw(int x ,int y ) ;
	void Copy( LTexture* ptr , LTexture* seconPtr  , double angle);

	//Deallocates texture
	virtual void free();

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	virtual bool render(SDL_Rect* clip = NULL, double angle = 0.0,
						SDL_Point* center = NULL, SDL_RendererFlip flip =
								SDL_FLIP_NONE,
						int w = 0, int h = 0);

	//Gets image dimensions
	int getWidth();
	int getHeight();
	int getX() const;
	int getY() const;

	//Set possition
	void setX(int x);
	void setY(int y);

	//Set Possition
	virtual void setPosition(int, int);

	//Set Dimention
	virtual void setHeight(int height);
	virtual void setWidth(int width);

	SDL_Texture* getTexture()
	{
		return mTexture;
	}

private:
	//The actual  texture
	SDL_Texture* mTexture;

	//Image dimensions
	int x, y;
	int mWidth;
	int mHeight;
};
#endif /* LTEXTURE_H_ */
