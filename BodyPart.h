#ifndef _BODYPART_H_
#define _BODYPART_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class BodyPart
{
	protected:
		double _xPos;
		double _yPos;
	public:
		BodyPart(double xPos, double yPos);
		void update(double xPos, double yPos);
		void render(SDL_Renderer *renderer);
		
		void getPos(int *x, int *y);
};

#endif
