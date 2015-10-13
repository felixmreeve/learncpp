#include "Eye.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <math.h>

Eye::Eye(double xPos, double yPos):
	_xPos( xPos ),
	_yPos( yPos ),
	_xCenter( xPos ),
	_yCenter( yPos )
{}

void Eye::update(int xAim, int yAim)
{
	double xDist = xAim - _xCenter;
	double yDist = yAim - _yCenter;
	double totDist = sqrt(xDist*xDist + yDist*yDist);
	xDist = (50.0f*xDist)/totDist;
	yDist = (50.0f*yDist)/totDist;
	_xPos = _xCenter + xDist;
	_yPos = _yCenter + yDist;
}

void Eye::render(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	int x;
	int y;
	for(x=_xPos-1; x<_xPos+2; x++)
		for(y=_yPos-1; y<_yPos+2; y++)
			SDL_RenderDrawPoint(renderer, x, y);
}
