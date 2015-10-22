#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"

class Renderable{
	protected:
		float _xPos;
		float _yPos;
	
	public:
		Renderable(int xPos, int yPos);
		bool checkPos(int *x, int *y);
		void getPos(float *x, float *y);
		void renderPoint(SDL_Renderer *renderer, int x, int y);
};

#endif
