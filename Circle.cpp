#include "Circle.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"

Circle::Circle(int xPos, int yPos, double increaseRate, double radius, double maxRadius):
	_radius( radius ),
	_xPos( xPos ),
	_yPos( yPos ),
	_increaseRate( increaseRate ),
	_maxRadius( maxRadius )
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
	
	int alpha = 255 - (_radius / _maxRadius * 255);
	
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	if(alpha > 0 && alpha <= 255){
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, alpha);
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

int Circle::getRadius()
{
	return _radius;
}

int Circle::getMaxRadius()
{
	return _maxRadius;
}
