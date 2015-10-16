#ifndef _FOOD_H_
#define _FOOD_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Player.h"
#include "Circle.h"

class Food
{
	protected:
		int _xPos;
		int _yPos;
		int _xMax;
		int _yMax;
		int _age;
	public:
		Food(int xMax, int yMax);
		int update(Player player);
		void render(SDL_Renderer *renderer);
		void close();
		void place();
		void eaten();
		void getPos(int *x, int *y);
		int getAge();
};
#endif
