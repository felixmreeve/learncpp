#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Sprite.h"

class Player
{
	protected:
		double _maxVel;
		double _acceleration;
		double _xPos;
		double _yPos;
		double _xVel;
		double _yVel;
		
		//Sprite _sprite;
	public:
		Player(double maxVel, double acceleration, double xPos, double yPos);
		void update(bool aim, int xMouse, int yMouse, const Uint8 *keyState);
		void render(SDL_Renderer *renderer);
		void close();
		void updateHead(bool aim, int xMouse, int yMouse, const Uint8 *keyState);
		void acceleration(double *xAcc, double *yAcc, int aimX, int aimY);
		void keyStateAcceleration(double *xAcc, double *yAcc, const Uint8 *keyState);
		double getTotVel();
		void getPos(int *x, int *y);
};
#endif
