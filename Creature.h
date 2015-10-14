#ifndef _CREATURE_H_
#define _CREATURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Creature
{
	protected:
		double _maxVel;
		double acceleration;
		double _xPos;
		double _yPos;
		double _xVel;
		double _yVel;
		double _totVel;
	public:
		Creature(double maxVel, double xPos, double yPos);
		void update(bool aim, int mouseX, int mouseY, const Uint8 *keyState);
		void render(SDL_Renderer *renderer);
		void getPos(int *x, int *y);
};
#endif
