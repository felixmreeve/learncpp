#include "Background.h"
#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"

Background::Background():
	_surface( SDL_CreateRGBSurface( 0, GC::SCREEN_WIDTH, GC::SCREEN_HEIGHT, 32, 0, 0, 0, 0 ) ),
	_r( 255 ),
	_g( 0 ),
	_b( 0 ),
	_aim( RED )
{}

void Background::update()
{
	printf("%d\n", _r);
	printf("%d\n", _g);
	printf("%d\n", _b);
	if(_r>=255) _aim = GREEN;
	if(_g>=255) _aim = BLUE;
	if(_b>=255) _aim = RED;
	
	switch(_aim){
		case RED:
			printf("red\n");
			changeColour(&_r, &_b);
			break;
		case GREEN:
			printf("green\n");
			changeColour(&_g, &_r);
			break;
		case BLUE:
			printf("red\n");
			changeColour(&_b, &_g);
			break;
	}
	
	Uint32 color = SDL_MapRGB(_surface->format, _r, _g, _b);
	
	SDL_FillRect(_surface, NULL, color);
}

void Background::render(SDL_Renderer *renderer){
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, _surface);
	SDL_RenderCopy(renderer, tex, NULL, NULL);
	SDL_DestroyTexture(tex);
}

void Background::close()
{
	SDL_FreeSurface(_surface);
}

void Background::drawPoint(int x, int y, int r, int g, int b)
{
	/** draws the given colour to the surface at the specified position.
	 *  
	 *  SDL_Surface *img: surface to draw pixel to
	 *  int x:            x position to draw pixel
	 *  int y:            y position to draw pixel
	 *  SDL_Color col:    desired colour to draw
	 */
	Uint32 pixel = SDL_MapRGB(_surface->format, r, g, b);
	Uint32 *pixels = (Uint32*)_surface->pixels;
	pixels[x + y*_surface->w] = pixel;
}

void Background::changeColour(int *increase, int *decrease)
{
	(*increase)++;
	(*decrease)--;
}
