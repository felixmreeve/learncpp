#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"
#include "Renderable.h"

class Circle: public Renderable
{
	protected:
		float _radius;
		float _increaseRate;
		float _maxRadius;
	public:
		Circle(int xPos, int yPos, float increaseRate, float radius, float maxRadius);
		void update();
		void render(SDL_Renderer *renderer);
		void close();
		int getRadius();
		int getMaxRadius();
};

#endif
