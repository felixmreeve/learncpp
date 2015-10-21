#ifndef _HEAD_H_
#define _HEAD_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Head
{
	protected:
		double _maxVel;
		double _acceleration;
		double _xPos;
		double _yPos;
		double _xVel;
		double _yVel;
		
	public:
		Head(double maxVel, double acceleration, double xPos, double yPos);
		void update(bool aim, int xMouse, int yMouse, const Uint8 *keyState);
		void render(SDL_Renderer *renderer);
		
		void acceleration(double *xAcc, double *yAcc, int xAim, int yAim);
		void keyStateAcceleration(double *xAcc, double *yAcc, const Uint8 *keyState);
		double getTotVel();
		void getPos(double *x, double *y);
};

#endif
