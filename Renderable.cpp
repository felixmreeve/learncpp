#include "Renderable.h"

Renderable::Renderable(int xPos, int yPos):
	_xPos( xPos ),
	_yPos( yPos )
{}


bool Renderable::checkPos(int *x, int *y)
{
	bool change = false;
	if(*x > GC::SCREEN_WIDTH){
		*x = *x % GC::SCREEN_WIDTH;
		change = true;
	}
	else if(*x < 0){
		*x = *x + ( -(*x / GC::SCREEN_WIDTH) + 1 ) * GC::SCREEN_WIDTH;
		change = true;
	}
	
	if(*y > GC::SCREEN_HEIGHT){
		*y = *y % GC::SCREEN_HEIGHT;
		change = true;
	}
	else if(*y < 0){
		*y = *y + ( -(*y / GC::SCREEN_HEIGHT) + 1 ) * GC::SCREEN_HEIGHT;
		change = true;
	}
	return change;
}

void Renderable::getPos(float *x, float *y)
{
	*x = _xPos;
	*y = _yPos;
}

void Renderable::renderPoint(SDL_Renderer *renderer, int x, int y)
{
	checkPos(&x, &y);
	SDL_RenderDrawPoint(renderer, x, y);
}
/*
{
	int result = 0;
	int a = -163;
	int b = 5;
	int a1 = 0;
	
	if(a < 0){
		int division = -(a / b);
		a1 = a + (division+1) * b;
	}
	else a1 = a;
	
	result = a1 % b;
	std::cout << result << std::endl;
}
*/
