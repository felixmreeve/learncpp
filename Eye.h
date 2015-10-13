#ifndef _EYE_H_
#define _EYE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Eye
{
	protected:
		double _xPos;
		double _yPos;
		double _xCenter;
		double _yCenter;
	public:
		Eye(double xPos, double yPos);
		void update(int xAim, int yAim);
		void render(SDL_Renderer *renderer);
};
#endif
