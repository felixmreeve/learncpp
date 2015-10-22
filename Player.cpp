#include "Player.h"

Player::Player(float maxVel, float acceleration, float xPos, float yPos):
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
	float xHead = 0;
	float yHead = 0;
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

void Player::updateBody(float xHead, float yHead)
{
	float xNextPos = xHead;
	float yNextPos = yHead;
	float xOldPos = 0;
	float yOldPos = 0;
	
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
	float xHeadPos = 0;
	float yHeadPos = 0;
	float xFoodPos = 0;
	float yFoodPos = 0;
	
	getHeadPos(&xHeadPos, &yHeadPos);
	food->getPos(&xFoodPos, &yFoodPos);
	
	float xDist = xHeadPos - xFoodPos;
	float yDist = yHeadPos - yFoodPos;
	
	float totDist = sqrt(xDist*xDist + yDist*yDist);
	
	if(totDist<20){
		food->eaten();
		eat = true;
	}
	return eat;
}

int Player::getSize(){
	return _bodyParts.size();
}

float Player::getHeadVel()
{
	return _head.getTotVel();
}

void Player::getHeadPos(float *x, float *y)
{
	return _head.getPos(x, y);
}

void Player::getBodyPartPos(int partNum, float *x, float *y){
	_bodyParts.at(partNum).getPos(x, y);
}

/*
	int isEaten = 0;
	int xPlayerPos = 0;
	int yPlayerPos = 0;
	
	player.getHeadPos(&xPlayerPos, &yPlayerPos);
	
	int xDist = xPlayerPos - _xPos;
	int yDist = yPlayerPos - _yPos;
	
	float totDist = sqrt(xDist*xDist + yDist*yDist);
	
	if(totDist<20){
		isEaten = _age;
		eaten();
	}
	return isEaten;
	* */
