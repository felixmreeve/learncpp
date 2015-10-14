#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Circle
{
	protected:
		int _radius;
		int _xPos;
		int _yPos;
		double _increaseRate;
	public:
		Circle(int xPos, int yPos);
		void update();
		void render(SDL_Renderer *renderer);
		void close();
		void place(int x, int y);
};

#endif
