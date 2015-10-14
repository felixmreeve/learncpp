#ifndef _FOOD_H_
#define _FOOD_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Player.h"

class Food
{
	protected:
		int _xPos;
		int _yPos;
		int _xMax;
		int _yMax;
	public:
		Food(int xMax, int yMax);
		void update(Player player);
		void render(SDL_Renderer *renderer);
		void close();
		void place();
		void eaten();
};
#endif
