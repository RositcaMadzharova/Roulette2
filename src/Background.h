/*
 * Background.h
 *
 *  Created on: Jul 8, 2017
 *      Author: kakev
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include "Globals.h"


class Background  {
public:

	Background (string title= "",int width=0, int height=0,string path="");
	virtual ~Background();
	void Clear();
	void Show();
	bool loadMedia();
	bool Init();
	int getHeight() const;
	void setHeight(int height);
	const string& getPath() const;
	void setPath(const string& path);
	int getWidth() const;
	void setWidth(int width);
	void setTitle(const string& title);
	
	SDL_Surface * loadedSurface=NULL;
	SDL_Texture *Texture = NULL;
	static SDL_Renderer * gRenderer;

	//font objects
	SDL_Surface * fontSurface = NULL;
	SDL_Texture * fontTexture = NULL;

private:
	string _title;
	int _width;
	int _height;
	string _path;
};


#endif /* BACKGROUND_H_ */
