#ifndef _EYE_H_
#define _EYE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Eye
{
	protected:
		float _xPos;
		float _yPos;
		float _xCenter;
		float _yCenter;
	public:
		Eye(float xPos, float yPos);
		void update(int xAim, int yAim);
		void render(SDL_Renderer *renderer);
};
#endif
