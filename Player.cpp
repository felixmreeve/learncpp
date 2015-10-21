#include "Player.h"
#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Sprite.h"
#include "Head.h"
#include "BodyPart.h"

Player::Player(double maxVel, double acceleration, double xPos, double yPos):
	_head( maxVel, acceleration, xPos, yPos ),
	_bodyParts(  )
{
	for(int i = 0; i < 3; i++){
		BodyPart bodyPart(250,250);
		_bodyParts.push_back(bodyPart);
	}
}

void Player::update(bool aim, int xMouse, int yMouse, const Uint8 *keyState, Food *food)
{
	double xHead = 0;
	double yHead = 0;
	_head.getPos(&xHead, &yHead);
	
	updateBody(xHead, yHead);
	_head.update(aim, xMouse, yMouse, keyState);
	
	int eat = checkFood(food);
	if(eat){
		BodyPart bodyPart(xHead, yHead);
		_bodyParts.push_back(bodyPart);
	}
}

void Player::render(SDL_Renderer *renderer)
{
	_head.render(renderer);
	renderBody(renderer);
}

void Player::close()
{
	//_sprite.close();
}

void Player::updateBody(int xHead, int yHead)
{
	int xNextPos = xHead;
	int yNextPos = yHead;
	int xOldPos = 0;
	int yOldPos = 0;
	
	for(std::vector<BodyPart>::iterator it = _bodyParts.begin(); it < _bodyParts.end(); ++it){
		it->getPos(&xOldPos, &yOldPos);
		it->update(xNextPos, yNextPos);
		
		xNextPos = xOldPos;
		yNextPos = yOldPos;
	}
}

void Player::renderBody(SDL_Renderer *renderer)
{
	for(std::vector<BodyPart>::iterator it = _bodyParts.begin(); it < _bodyParts.end(); ++it){
		it->render(renderer);
	}
}

bool Player::checkFood(Food *food)
{
	bool eat = false;
	double xHeadPos = 0;
	double yHeadPos = 0;
	int xFoodPos = 0;
	int yFoodPos = 0;
	
	getHeadPos(&xHeadPos, &yHeadPos);
	food->getPos(&xFoodPos, &yFoodPos);
	
	double xDist = xHeadPos - xFoodPos;
	double yDist = yHeadPos - yFoodPos;
	
	double totDist = sqrt(xDist*xDist + yDist*yDist);
	
	if(totDist<20){
		food->eaten();
		eat = true;
	}
	return eat;
}

double Player::getHeadVel()
{
	return _head.getTotVel();
}

void Player::getHeadPos(double *x, double *y)
{
	return _head.getPos(x, y);
}

/*
	int isEaten = 0;
	int xPlayerPos = 0;
	int yPlayerPos = 0;
	
	player.getHeadPos(&xPlayerPos, &yPlayerPos);
	
	int xDist = xPlayerPos - _xPos;
	int yDist = yPlayerPos - _yPos;
	
	double totDist = sqrt(xDist*xDist + yDist*yDist);
	
	if(totDist<20){
		isEaten = _age;
		eaten();
	}
	return isEaten;
	* */
