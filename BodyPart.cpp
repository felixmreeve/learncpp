#include "BodyPart.h"

BodyPart::BodyPart(float xPos, float yPos):
	Renderable( xPos, yPos )
{}

void BodyPart::update(float xPos, float yPos)
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
			renderPoint(renderer, x, y);
}

