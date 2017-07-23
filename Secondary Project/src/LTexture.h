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

class LTexture {
public:
		//Initializes variables
		LTexture(int _x,int _y);

		//copy constructor
		LTexture ( const LTexture&);

		//Deallocates memory
		virtual ~LTexture();

		//Loads image at specified path
		bool loadFromFile(  std::string path );

		//Deallocates texture
		void free();

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		bool render(  SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE  );

		//Gets image dimensions
		int getWidth();
		int getHeight();
		int getX() const;
		int getY() const;

		//Set possition
		void setX(int x);
		void setY(int y);

		//Set Possition
		virtual void setPosition(int,int);

		//Set Dimention
		void setHeight(int height);
		void setWidth(int width);

		SDL_Texture* getTexture() { return mTexture ; }

	private:
		//The actual  texture
		SDL_Texture* mTexture;



		//Image dimensions
		int x,y;
		int mWidth;
		int mHeight;
};
#endif /* LTEXTURE_H_ */
