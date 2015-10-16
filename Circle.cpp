#include "Circle.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"

Circle::Circle(int xPos, int yPos):
	_radius( 1 ),
	_xPos( xPos ),
	_yPos( yPos ),
	_increaseRate( 2 )
{}

void Circle::update()
{
	_radius += _increaseRate;
}

void Circle::render(SDL_Renderer *renderer)
{
	int x = _radius;
	int y = 0;
	int error = 1 - _radius;
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	if(_radius<255){
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255-_radius);
		while(x>=y)
		{
			if((x+_xPos)>=0 && (x+_xPos)<GC::SCREEN_WIDTH && (y+_yPos)>=0 && (y+_yPos)<GC::SCREEN_HEIGHT)
				SDL_RenderDrawPoint(renderer, x+_xPos, y+_yPos);
				
			if((y+_xPos)>=0 && (y+_xPos)<GC::SCREEN_WIDTH && (x+_yPos)>=0 && (x+_yPos)<GC::SCREEN_HEIGHT)
				SDL_RenderDrawPoint(renderer, y+_xPos, x+_yPos);
			
			if((-x+_xPos)>=0 && (-x+_xPos)<GC::SCREEN_WIDTH && (y+_yPos)>=0 && (y+_yPos)<GC::SCREEN_HEIGHT)
				SDL_RenderDrawPoint(renderer, -x+_xPos, y+_yPos);
				
			if((-y+_xPos)>=0 && (-y+_xPos)<GC::SCREEN_WIDTH && (x+_yPos)>=0 && (x+_yPos)<GC::SCREEN_HEIGHT)
				SDL_RenderDrawPoint(renderer, -y+_xPos, x+_yPos);
				
			if((-x+_xPos)>=0 && (-x+_xPos)<GC::SCREEN_WIDTH && (-y+_yPos)>=0 && (-y+_yPos)<GC::SCREEN_HEIGHT)
				SDL_RenderDrawPoint(renderer, -x+_xPos, -y+_yPos);
				
			if((-y+_xPos)>=0 && (-y+_xPos)<GC::SCREEN_WIDTH && (-x+_yPos)>=0 && (-x+_yPos)<GC::SCREEN_HEIGHT)
				SDL_RenderDrawPoint(renderer, -y+_xPos, -x+_yPos);
				
			if((x+_xPos)>=0 && (x+_xPos)<GC::SCREEN_WIDTH && (-y+_yPos)>=0 && (-y+_yPos)<GC::SCREEN_HEIGHT)
				SDL_RenderDrawPoint(renderer, x+_xPos, -y+_yPos);
				
			if((y+_xPos)>=0 && (y+_xPos)<GC::SCREEN_WIDTH && (-x+_yPos)>=0 && (-x+_yPos)<GC::SCREEN_HEIGHT)
				SDL_RenderDrawPoint(renderer, y+_xPos, -x+_yPos);
				
			y++;
			if(error < 0)
			{
				error += 2*y + 1;
			}
			else{
				x--;
				error += 2*(y-x) + 1;
			}
		}
	}
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
}

void Circle::close()
{
	
}

int Circle::place(int x, int y)
{
	int size = _radius;
	_radius = 1;
	_xPos = x;
	_yPos = y;
	return size;
}

int Circle::getRadius()
{
	return _radius;
}
