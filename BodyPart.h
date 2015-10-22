#ifndef _BODYPART_H_
#define _BODYPART_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Renderable.h"

class BodyPart : public Renderable
{
	public:
		BodyPart(float xPos, float yPos);
		void update(float xPos, float yPos);
		void render(SDL_Renderer *renderer);
		
};

#endif
