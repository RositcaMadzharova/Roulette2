/*
 * main.cpp
 *
 *  Created on: Jul 8, 2017
 *      Author: kakev
 */
#include "Globals.h"
#include "Background.h"
#include "Button.h"
#include "Pools.h"
#include "Credits.h"

GameState game=INTRO_MENU;

int main(int argc, char *argv[])
{


	Credits cr;
//

		Pools p1(cr,300,330,10);
//	p1.render(gRenderer,NULL);
Background back("Intro Screen",SCREEN_W,SCREEN_H,"chessboard.png");


//	gWindow=SDL_CreateWindow("Main viktor ",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_W,SCREEN_H,0);
//	gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
//	SDL_Surface * background = IMG_Load("chessboard.png");
//	SDL_Texture * texture=SDL_CreateTextureFromSurface(gRenderer,background);
//	SDL_RenderCopy(gRenderer,texture,NULL,NULL);
//	SDL_RenderPresent(gRenderer);

	p1.loadFromFile(Background::gRenderer,"Pools.png");


	SDL_Rect rect ={118,1,118,111};
	p1.setHeight(59);
	p1.setWidth(59);
	p1.render(Background::gRenderer,&rect);


	cout<<p1.getWidth()<<endl;


//Button b1(6,6);
//b1.Show();

bool close=false;
	while(!close)
		{
			SDL_Event e;
			while( SDL_PollEvent( &e ) )
				{
			   if(e.type==SDL_QUIT)
			   	   {
				   close=true;
			   	   }
			   if(p1.isClicked(&e))

			   	   {
				   if(game==INTRO_MENU)
				   	   {
					   	   back.Clear();
					   	Background info("INfo SCreen",SCREEN_W,SCREEN_H,"rouletterules.jpg");
				   	   }


			   	   }
			   if(p1.isHover()){
				   std::cout<<"oha"<<endl;
			   }

				}
		}

return 0;
}
