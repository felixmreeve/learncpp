#ifndef _FOOD_H_
#define _FOOD_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Circle.h"

class Food
{
	protected:
		int _xPos;
		int _yPos;
		int _xPrevPos;
		int _yPrevPos;
		int _xMin;
		int _yMin;
		int _xMax;
		int _yMax;
		int _gone;
		int _age;
	public:
		Food(int xMax, int yMax);
		int update();
		void render(SDL_Renderer *renderer);
		void close();
		void place();
		void eaten();
		void getPos(int *x, int *y);
		void getPrevPos(int *x, int *y);
		int getAge();
};
#endif
