#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Sprite
{
	protected:
		SDL_Surface *_img;
	
	public:
		Sprite(char *file);
		void render(SDL_Renderer *renderer, int x, int y);
		void close();
};

#endif
