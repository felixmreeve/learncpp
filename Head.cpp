#include "Head.h"

Head::Head(float maxVel, float acceleration, float xPos, float yPos):
	Renderable( xPos, yPos ),
	_maxVel( maxVel ),
	_acceleration( acceleration ),
	_xVel( 0 ),
	_yVel( 0 )
{}

void Head::update(bool aim, int xMouse, int yMouse, const Uint8 *keyState)
{
	// calculate accleration vector
	float xAcc = 0;
	float yAcc = 0;
	
	if(aim == true){
		acceleration(&xAcc, &yAcc, xMouse, yMouse);
	}
	else{
		keyStateAcceleration(&xAcc, &yAcc, keyState);
	}
	
	_xVel += xAcc;
	_yVel += yAcc;
	
	//lock total velocity
	float totVel = sqrt(_xVel*_xVel + _yVel*_yVel);
	if(totVel > _maxVel){
		_xVel = (_maxVel * _xVel) / totVel;
		_yVel = (_maxVel * _yVel) / totVel;
	}
	
	//update position
	_xPos += _xVel;
	_yPos += _yVel;
	
	if(!aim){
		int xCheck = _xPos;
		int yCheck = _yPos;
		bool change = checkPos(&xCheck, &yCheck);
		if(change){
			_xPos = xCheck;
			_yPos = yCheck;
		}
	}
}

void Head::render(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	int x;
	int y;
	for(x=_xPos-3; x<=_xPos+3; x++)
		for(y=_yPos-3; y<=_yPos+3; y++)
			renderPoint(renderer, x, y);
	
	//_sprite.render(renderer, _xPos, _yPos);
}

void Head::acceleration(float *xAcc, float *yAcc, int xAim, int yAim)
{
	float xDist = xAim - _xPos;
	float yDist = yAim - _yPos;
	
	if(abs(xDist) >= 1 || abs(yDist) >= 1)
	{
		float totDist = sqrt(xDist*xDist + yDist*yDist);
		*xAcc += (_acceleration * xDist) / totDist;
		*yAcc += (_acceleration * yDist) / totDist;
	}
}

void Head::keyStateAcceleration(float *xAcc, float *yAcc, const Uint8 *keyState)
{
	int xDir = 0;
	int yDir = 0;
	int aimDist = 10;
	
	if(keyState[SDL_SCANCODE_RIGHT]) xDir += aimDist;
	if(keyState[SDL_SCANCODE_LEFT])  xDir -= aimDist;
	if(keyState[SDL_SCANCODE_DOWN])  yDir += aimDist;
	if(keyState[SDL_SCANCODE_UP])    yDir -= aimDist;
		
	int xAim = _xPos + xDir;
	int yAim = _yPos + yDir;
	
	acceleration(xAcc, yAcc, xAim, yAim);	
}

float Head::getTotVel()
{
	return sqrt(_xVel*_xVel + _yVel*_yVel);
}
