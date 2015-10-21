#include "Food.h"
#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"
#include "Circle.h"

Food::Food(int xMax, int yMax):
	_xPos( 0 ),
	_yPos( 0 ),
	_xPrevPos( 0 ),
	_yPrevPos( 0 ),
	_xMin( 0 ),
	_yMin( 0 ),
	_xMax( xMax ),
	_yMax( yMax ),
	_gone( false ),
	_age( 0 )
{
	place();
}

int Food::update()
{
	int isEaten = 0;
	_age++;
	
	if(_gone){
		isEaten = _age;
		place();
		_gone = false;
	}
	return isEaten;
}

void Food::render(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	int x;
	int y;
	for(x=_xPos-1; x<=_xPos+1; x++)
		for(y=_yPos-1; y<=_yPos+1; y++)
			SDL_RenderDrawPoint(renderer, x, y);
}

void Food::close()
{
	
}

void Food::place()
{
	_xPrevPos = _xPos;
	_yPrevPos = _yPos;
	_xPos = _xMin + rand() % (_xMax - _xMin);
	_yPos = _yMin + rand() % (_yMax - _yMin);
	_age = 0;
}

void Food::eaten()
{
	_gone = true;
}

void Food::getPos(int *x, int *y)
{
	*x = _xPos;
	*y = _yPos;
}

void Food::getPrevPos(int *x, int *y)
{
	*x = _xPrevPos;
	*y = _yPrevPos;
}
int Food::getAge()
{
	return _age;
}
