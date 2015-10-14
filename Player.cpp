#include "Player.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Sprite.h"

#include <math.h>

Player::Player(double maxVel, double acceleration, double xPos, double yPos):
	_maxVel( maxVel ),
	_acceleration( acceleration ),
	_xPos( xPos ),
	_yPos( yPos ),
	_xVel( 0 ),
	_yVel( 0 )
{}

void Player::update(bool aim, int xMouse, int yMouse, const Uint8 *keyState)
{	
	updateHead(aim, xMouse, yMouse, keyState);
}

void Player::render(SDL_Renderer *renderer)
{
	renderHead(renderer);

}

void Player::close()
{
	//_sprite.close();
}

void Player::updateHead(bool aim, int xMouse, int yMouse, const Uint8 *keyState)
{
	// calculate accleration vector
	double xAcc = 0;
	double yAcc = 0;
	
	if(aim == true){
		acceleration(&xAcc, &yAcc, xMouse, yMouse);
	}
	else{
		keyStateAcceleration(&xAcc, &yAcc, keyState);
	}
	
	_xVel += xAcc;
	_yVel += yAcc;
	
	//lock total velocity
	double totVel = sqrt(_xVel*_xVel + _yVel*_yVel);
	if(totVel > _maxVel){
		_xVel = (_maxVel * _xVel) / totVel;
		_yVel = (_maxVel * _yVel) / totVel;
	}
	
	//update position
	_xPos += _xVel;
	_yPos += _yVel;
}

void Player::renderHead(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	int x;
	int y;
	for(x=_xPos-3; x<=_xPos+3; x++)
		for(y=_yPos-3; y<=_yPos+3; y++)
			SDL_RenderDrawPoint(renderer, x, y);
	
	//_sprite.render(renderer, _xPos, _yPos);
}

void Player::acceleration(double *xAcc, double *yAcc, int xAim, int yAim)
{
	float xDist = xAim - _xPos;
	float yDist = yAim - _yPos;
	
	if(abs(xDist) >= 1 || abs(yDist) >= 1)
	{
		double totDist = sqrt(xDist*xDist + yDist*yDist);
		*xAcc += (_acceleration * xDist) / totDist;
		*yAcc += (_acceleration * yDist) / totDist;
	}
}

void Player::keyStateAcceleration(double *xAcc, double *yAcc, const Uint8 *keyState)
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
	
	//FIX SO TOTACCELERATION IS 
	
}

double Player::getTotVel()
{
	return sqrt(_xVel*_xVel + _yVel*_yVel);
}

void Player::getPos(int *x, int *y)
{
	*x = _xPos;
	*y = _yPos;
}

