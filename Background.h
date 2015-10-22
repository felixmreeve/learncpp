#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Background
{
	protected:
		SDL_Surface *_surface;
		float _r;
		float _g;
		float _b;
		int _colourAim;
		float _changeRate;
		float _jumpRatio;
	public:
		Background();
		void update(int jump);
		void render(SDL_Renderer *renderer);
		void close();
		void drawPoint(int x, int y, int r, int g, int b);
		void changeColour(float *increase, float *decrease);

};

enum RGB { RED, GREEN, BLUE };

#endif
