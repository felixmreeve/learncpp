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
	_yVel( 0 ),
	_sprite( "Head.png" )
{}

void Player::update(int xMouse, int yMouse, bool aim, const Uint8 *keyState)
{	
	updateHead(xMouse, yMouse, aim, keyState);
}

void Player::render(SDL_Renderer *renderer)
{
	
	
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	int x;
	int y;
	for(x=_xPos-1; x<_xPos+2; x++)
		for(y=_yPos-1; y<_yPos+2; y++)
			SDL_RenderDrawPoint(renderer, x, y);
	
	_sprite.render(renderer, _xPos, _yPos);
}

void Player::close()
{
	_sprite.close();
}

void Player::updateHead(int xMouse, int yMouse, bool aim, const Uint8 *keyState)
{
	// calculate accleration vector
	double xAcc = 0;
	double yAcc = 0;
	
	if(aim == true){
		mouseAcceleration(&xAcc, &yAcc, xMouse, yMouse);
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

void Player::mouseAcceleration(double *xAcc, double *yAcc, int mouseX, int mouseY)
{
	double xDist = mouseX - _xPos;
	double yDist = mouseY - _yPos;
	double totDist = sqrt(xDist*xDist + yDist*yDist);
	*xAcc += (_acceleration * xDist) / totDist;
	*yAcc += (_acceleration * yDist) / totDist;
}

void Player::keyStateAcceleration(double *xAcc, double *yAcc, const Uint8 *keyState)
{
	if(keyState[SDL_SCANCODE_RIGHT]) *xAcc += _acceleration;
	if(keyState[SDL_SCANCODE_LEFT])  *xAcc -= _acceleration;
	if(keyState[SDL_SCANCODE_DOWN])  *yAcc += _acceleration;
	if(keyState[SDL_SCANCODE_UP])    *yAcc -= _acceleration;
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

