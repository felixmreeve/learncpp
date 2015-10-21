#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Circle
{
	protected:
		double _radius;
		int _xPos;
		int _yPos;
		double _increaseRate;
		double _maxRadius;
	public:
		Circle(int xPos, int yPos, double increaseRate, double radius, double maxRadius);
		void update();
		void render(SDL_Renderer *renderer);
		void close();
		int getRadius();
		int getMaxRadius();
};

#endif
