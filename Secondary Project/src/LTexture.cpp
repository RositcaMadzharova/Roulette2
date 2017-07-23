/*
 * LTexture.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: kakev
 */

#include "LTexture.h"

LTexture::LTexture(int _x,int _y)
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	setPosition(_x,_y);
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile(  std::string path )
{
	//Get rid of preexisting texture
	free();

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( LWindow::gRenderer, loadedSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	return mTexture != NULL;
}



void LTexture::free()
{
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
//		IMG_Quit();
	}
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

bool LTexture::render(  SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx( LWindow::gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
	SDL_RenderPresent( LWindow::gRenderer);
	return true;
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

int LTexture::getX() const
{
	return x;
}

int LTexture::getY() const
{
	return y;
}

void LTexture::setX(int x)
{
	this->x = x;
}

void LTexture::setY(int y)
{
	this->y = y;
}

void LTexture::setHeight(int height)
{
	mHeight = height;
}

void LTexture::setWidth(int width)
{
	mWidth = width;
}

void LTexture::setPosition( int _x ,int _y)
{
		this->x = _x;
		this->y = _y;
}

LTexture::LTexture(const LTexture& right)
{
	this->x = right.x;
	this->y = right.y;
	this->mWidth = right.mWidth;
	this->mHeight=right.mHeight;
	this->mTexture=right.mTexture;
}

void LTexture::show()
{
	SDL_RenderCopy(LWindow::gRenderer,mTexture,NULL,NULL);
	SDL_RenderPresent(LWindow::gRenderer);
}
