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
	SDL_Surface * loadedSurface=NULL;
	SDL_Texture *Texture = NULL;
	static SDL_Renderer * gRenderer;
private:
	string _title;
	int _width;
	int _height;
	string _path;

};


#endif /* BACKGROUND_H_ */
