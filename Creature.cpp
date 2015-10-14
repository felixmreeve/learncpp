#include "Creature.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <math.h>

Creature::Creature(double maxVel, double xPos, double yPos):
	_maxVel( maxVel ),
	_acceleration( acceleration )
	_xPos( xPos ),
	_yPos( yPos ),
	_xVel( 0 ),
	_yVel( 0 ),
	_totVel( 0 )
{}

void Creature::update(bool aim, int mouseX, int mouseY, const Uint8 *keyState)
{
	if(aim == true){
		double xDist = mouseX - _xPos;
		double yDist = mouseY - _yPos;
		
		_xVel += xDist / 100;
		_yVel += yDist / 100;
	}
	
	
	
	if(keyState[SDL_SCANCODE_RIGHT]) _xVel += 0.3;
	if(keyState[SDL_SCANCODE_LEFT]) _xVel -= 0.3;
	if(keyState[SDL_SCANCODE_DOWN]) _yVel += 0.3;
	if(keyState[SDL_SCANCODE_UP]) _yVel -= 0.3;
	
	_totVel = sqrt(_xVel*_xVel + _yVel*_yVel);
	if(_totVel > 6){
		_xVel = (6.0f*_xVel)/_totVel;
		_yVel = (6.0f*_yVel)/_totVel;
	}
	
	_xPos += _xVel;
	_yPos += _yVel;
}

void Creature::render(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	int x;
	int y;
	for(x=_xPos-1; x<_xPos+2; x++)
		for(y=_yPos-1; y<_yPos+2; y++)
			SDL_RenderDrawPoint(renderer, x, y);
}

void Creature::getPos(int *x, int *y)
{
	*x = _xPos;
	*y = _yPos;
}

