#ifndef _HEAD_H_
#define _HEAD_H_

#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Renderable.h"

class Head: public Renderable
{
	protected:
		float _maxVel;
		float _acceleration;
		float _xVel;
		float _yVel;
		
	public:
		Head(float maxVel, float acceleration, float xPos, float yPos);
		void update(bool aim, int xMouse, int yMouse, const Uint8 *keyState);
		void render(SDL_Renderer *renderer);
		
		void acceleration(float *xAcc, float *yAcc, int xAim, int yAim);
		void keyStateAcceleration(float *xAcc, float *yAcc, const Uint8 *keyState);
		float getTotVel();
};

#endif
