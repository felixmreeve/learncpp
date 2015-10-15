#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Background
{
	protected:
		SDL_Surface *_surface;
		double _r;
		double _g;
		double _b;
		int _colourAim;
		double _changeRate;
		double _jumpRatio;
	public:
		Background();
		void update(int jump);
		void render(SDL_Renderer *renderer);
		void close();
		void drawPoint(int x, int y, int r, int g, int b);
		void changeColour(double *increase, double *decrease);

};

enum RGB { RED, GREEN, BLUE };

#endif
