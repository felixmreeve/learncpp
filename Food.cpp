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
	_circle( 0, 0 )
{
	place();
}

void Food::update(Player player)
{
	int xPlayerPos = 0;
	int yPlayerPos = 0;
	
	player.getPos(&xPlayerPos, &yPlayerPos);
	
	int xDist = xPlayerPos - _xPos;
	int yDist = yPlayerPos - _yPos;
	
	double totDist = sqrt(xDist*xDist + yDist*yDist);
	
	
	if(totDist<20){
		place();
	}
	_circle.update();
}

void Food::render(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	int x;
	int y;
	for(x=_xPos-1; x<=_xPos+1; x++)
		for(y=_yPos-1; y<=_yPos+1; y++)
			SDL_RenderDrawPoint(renderer, x, y);
	_circle.render(renderer);
}

void Food::close()
{
	_circle.close();
}

void Food::place()
{
	_xPos = rand() % GC::SCREEN_WIDTH;
	_yPos = rand() % GC::SCREEN_HEIGHT;
	_circle.place(_xPos, _yPos);
}
