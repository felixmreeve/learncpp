#include "Background.h"
#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"

Background::Background():
	_surface( SDL_CreateRGBSurface(0, GC::SCREEN_WIDTH, GC::SCREEN_HEIGHT, 32, 0, 0, 0, 0) ),
	_r( 255 ),
	_g( 0 ),
	_b( 0 ),
	_colourAim( RED ),
	_changeRate( 0.1 )
{}

void Background::update()
{
	if(_r>=255) _colourAim = GREEN;
	if(_g>=255) _colourAim = BLUE;
	if(_b>=255) _colourAim = RED;
	
	switch(_colourAim){
		case RED:
			changeColour(&_r, &_b);
			break;
		case GREEN:
			changeColour(&_g, &_r);
			break;
		case BLUE:
			changeColour(&_b, &_g);
			break;
	}
	Uint32 color = SDL_MapRGB(_surface->format, round(_r), round(_g), round(_b));
	
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
	if(x>=0 && x<_surface->w && y>=0 && y<_surface->h){
	Uint32 pixel = SDL_MapRGB(_surface->format, r, g, b);
	Uint32 *pixels = (Uint32*)_surface->pixels;
	pixels[x + y*_surface->w] = pixel;
	}
}

void Background::changeColour(double *increase, double *decrease)
{
	(*increase) += _changeRate;
	(*decrease) -= _changeRate;
}
