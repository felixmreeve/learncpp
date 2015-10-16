#include "Food.h"
#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"
#include "Player.h"
#include "Circle.h"

Food::Food(int xMax, int yMax):
	_xPos( 0 ),
	_yPos( 0 ),
	_xMax( xMax ),
	_yMax( yMax ),
	_age( 0 )
{
	place();
}

int Food::update(Player player)
{
	int isEaten = 0;
	int xPlayerPos = 0;
	int yPlayerPos = 0;
	
	_age++;
	
	player.getPos(&xPlayerPos, &yPlayerPos);
	
	int xDist = xPlayerPos - _xPos;
	int yDist = yPlayerPos - _yPos;
	
	double totDist = sqrt(xDist*xDist + yDist*yDist);
	
	if(totDist<20){
		isEaten = _age;
		eaten();
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
	_xPos = rand() % GC::SCREEN_WIDTH;
	_yPos = rand() % GC::SCREEN_HEIGHT;
	_age = 0;
}

void Food::eaten()
{
	place();
}

void Food::getPos(int *x, int *y)
{
	*x = _xPos;
	*y = _yPos;
}

int Food::getAge()
{
	return _age;
}
