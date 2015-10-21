#include "BodyPart.h"
#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

BodyPart::BodyPart(double xPos, double yPos):
	_xPos( xPos ),
	_yPos( yPos )
{}

void BodyPart::update(double xPos, double yPos)
{
	_xPos = xPos;
	_yPos = yPos;
}

void BodyPart::render(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	int x;
	int y;
	for(x=_xPos-2; x<=_xPos+2; x++)
		for(y=_yPos-2; y<=_yPos+2; y++)
			SDL_RenderDrawPoint(renderer, x, y);
}

void BodyPart::getPos(int *x, int *y)
{
	*x = _xPos;
	*y = _yPos;
}
