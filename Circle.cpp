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
	_increaseRate( 1 )
{printf("%d\n%d\n", _xPos, _yPos);}

void Circle::update()
{
	_radius += 1;
}

void Circle::render(SDL_Renderer *renderer)
{
	int x = _radius;
	int y = 0;
	int error = 1 - _radius;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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

void Circle::close()
{
	
}

int Circle::place(int x, int y)
{
	_radius = 1;
	_xPos = x;
	_yPos = y;
}
/*
void Icircle(SDL_Surface *img,int _xPos,int _yPos,int radius,RGBcolour col)

{

  int x = radius, y=0, error = 1-radius;

  Uint32 pixel = SDL_MapRGB(img->format,col.r,col.g,col.b);

  Uint32 *pixels = (Uint32*)img->pixels;


  while(x>=y)

  { //1 draw call for each octant - ensure coordinates are valid before drawing

    if((x+_xPos)>=0 && (x+_xPos)<img->w && (y+_yPos)>=0 && (y+_yPos)<img->h)

      pixels[(x+_xPos)+(y+_yPos)*img->w]=pixel; //draw point in octant 1 if coordinate is valid


    if((y+_xPos)>=0 && (y+_xPos)<img->w && (x+_yPos)>=0 && (x+_yPos)<img->h)

      pixels[(y+_xPos)+(x+_yPos)*img->w]=pixel; //draw point in octant 2 if coordinate is valid


    if((-x+_xPos)>=0 && (-x+_xPos)<img->w && (y+_yPos)>=0 && (y+_yPos)<img->h)

      pixels[(-x+_xPos)+(y+_yPos)*img->w]=pixel; //draw point in octant 3 if coordinate is valid


    if((-y+_xPos)>=0 && (-y+_xPos)<img->w && (x+_yPos)>=0 && (x+_yPos)<img->h)

      pixels[(-y+_xPos)+(x+_yPos)*img->w]=pixel; //draw point in octant 4 if coordinate is valid 


    if((-x+_xPos)>=0 && (-x+_xPos)<img->w && (-y+_yPos)>=0 && (-y+_yPos)<img->h)

      pixels[(-x+_xPos)+(-y+_yPos)*img->w]=pixel; //draw point in octant 5 if coordinate is valid


    if((-y+_xPos)>=0 && (-y+_xPos)<img->w && (-x+_yPos)>=0 && (-x+_yPos)<img->h)

      pixels[(-y+_xPos)+(-x+_yPos)*img->w]=pixel; //draw point in octant 6 if coordinate is valid


    if((x+_xPos)>=0 && (x+_xPos)<img->w && (-y+_yPos)>=0 && (-y+_yPos)<img->h)

      SDL_RenderDrawPoint(renderer,x+_xPos,-y+_yPos); //draw point in octant 7 if coordinate is valid


    if((y+_xPos)>=0 && (y+_xPos)<img->w && (-x+_yPos)>=0 && (-x+_yPos)<img->h)

      pixels[(y+_xPos)+(-x+_yPos)*img->w]=pixel; //draw point in octant 8 if coordinate is valid


    y++; //increment y coordinate

    if(error<0) { error += 2*y+1; }

    else { x--; error += 2*(y-x)+1; }

  }

}
*/
