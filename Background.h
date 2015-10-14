#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Background
{
	protected:
		SDL_Surface *_surface;
		int _r;
		int _g;
		int _b;
		int _aim;
	public:
		Background();
		void update();
		void render(SDL_Renderer *renderer);
		void close();
		void drawPoint(int x, int y, int r, int g, int b);
		void changeColour(int *increase, int *decrease);

};

enum RGB { RED, GREEN, BLUE };

#endif
