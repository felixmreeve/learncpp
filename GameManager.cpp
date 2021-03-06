#include "GameManager.h"

GameManager::GameManager() :
	_go( true ),
	_click( false ),
	_mouseX( GC::SCREEN_WIDTH/2 ),
	_mouseY( GC::SCREEN_HEIGHT/2 ),
	_keyState( SDL_GetKeyboardState(NULL) ),
	_player( GC::PLAYER_SPEED, GC::PLAYER_ACCELERATION, GC::SCREEN_WIDTH/2, GC::SCREEN_HEIGHT/2 ),
	_food( GC::SCREEN_WIDTH, GC::SCREEN_HEIGHT ),
	_circles(  ),
	_background(  ),
	_window( SDL_CreateWindow("THING", 10, 10, GC::SCREEN_WIDTH, GC::SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE) ),
	_renderer( SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) )
{
	float x = 0;
	float y = 0;
	_food.getPos(&x, &y);
	addCircle(x, y, GC::FOOD_CIRCLE_SPEED, GC::FOOD_CIRCLE_START_SIZE, GC::FOOD_CIRCLE_MAX_SIZE);
}





//
//
//
//





//DO YOU WANT VSYNC?







//
//
//
//


void GameManager::checkInput()
{
	SDL_Event incomingEvent;
	//check incoming events
	while(SDL_PollEvent(&incomingEvent)){
		switch(incomingEvent.type){
			case SDL_QUIT:
				//if user closes program, then brake refresh loop by setting go = false
				_go = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(incomingEvent.button.button == SDL_BUTTON_LEFT){
					_click = true;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if(incomingEvent.button.button == SDL_BUTTON_LEFT){
					_click = false;
				}
				break;
		}
	}
	
	SDL_GetMouseState(&_mouseX, &_mouseY);
}

void GameManager::update()
{
	_player.update(_click, _mouseX, _mouseY, _keyState, &_food);
	int jump = _food.update();
	_background.update(jump);
	
	checkPlayerCollision();
	
	if(jump){
		float x = 0;
		float y = 0;
		_food.getPos(&x, &y);
		addCircle(x, y, GC::FOOD_CIRCLE_SPEED, GC::FOOD_CIRCLE_START_SIZE, GC::FOOD_CIRCLE_MAX_SIZE);
	}
	updateCircles();
	
}

void GameManager::render()
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	//clear the entire screen
	SDL_RenderClear(_renderer);
	
	_background.render(_renderer);
	
	_player.render(_renderer);
	_food.render(_renderer);
	if(!_circles.empty()){
		for(std::vector<Circle>::iterator it = _circles.begin(); it < _circles.end(); ++it){
			//if(_circles.size() == 0) {printf("empty\n"); break;}
			it->render(_renderer);
		}
	}
	//present renderer
	SDL_RenderPresent(_renderer);
}

void GameManager::close()
{
	_player.close();
	_food.close();
	_background.close();
	_circles.clear();
}

bool GameManager::checkState()
{
	//return whether game is running
	return _go;
}

void GameManager::updateCircles()
{
	
	float x = 0;
	float y = 0;
	_player.getHeadPos(&x, &y);
	
	float maxRad = GC::PLAYER_CIRCLE_MAX_SIZE * _player.getHeadVel() / GC::PLAYER_SPEED;
	
	
	/*if(maxRad < GC::PLAYER_CIRCLE_MIN_SIZE){
		maxRad = GC::PLAYER_CIRCLE_MIN_SIZE;
	}
	//*/
	
	
	
	
	addCircle(x, y, GC::PLAYER_CIRCLE_SPEED, GC::PLAYER_CIRCLE_START_SIZE, maxRad);
	
	
	
	
	
	
	//addCircle(x, y, GC::PLAYER_CIRCLE_SPEED, GC::PLAYER_CIRCLE_START_SIZE, GC::PLAYER_CIRCLE_MAX_SIZE);
	
	//iterate through circles vector
	for(std::vector<Circle>::iterator it = _circles.begin(); it < _circles.end(); ++it){
		//if(_circles.size() == 0) {printf("empty\n"); break;}
		float radius = 0;
		float maxRadius = 0;
		it->update();
		radius = it->getRadius();
		maxRadius = it->getMaxRadius();
		if(radius > maxRadius){
			_circles.erase(it);
		}
	}
	
	
}

void GameManager::checkPlayerCollision()
{
	int size = _player.getSize();
	float xHead = 0;
	float yHead = 0;
	
	_player.getHeadPos(&xHead, &yHead);
	
	for(int i = 5; i < size; i++){
		float xBody;
		float yBody;
		
		_player.getBodyPartPos(i, &xBody, &yBody);
		
		float xDist = xBody - xHead;
		float yDist = yBody - yHead;
		
		float totDist = sqrt(xDist*xDist + yDist*yDist);
		
		if(totDist < 5){
			addCircle(xBody, yBody, GC::PLAYER_CIRCLE_SPEED, GC::PLAYER_CIRCLE_START_SIZE, 400);
		}
	}
	/*
	float xHead = 0;
	float yHead = 0;
	
	_player.getHeadPos(&xHead, &yHead);
	
	for(std::vector<Circle>::iterator it = _circles.begin() + 20; it < _circles.end(); ++it){
		
		it->getPos(&xBody, &yBody);
		
		float xDist = xHead - xBody;
		float yDist = yHead - yBody;
		float totDist = sqrt(xDist*xDist + yDist*yDist);
		if(totDist<5){
			addCircle(xBody, yBody, GC::PLAYER_CIRCLE_SPEED, GC::PLAYER_CIRCLE_START_SIZE, 400);
			break;
		}
	}
	*/
	
}

void GameManager::addCircle(int x, int y, float increaseRate, float radius, float maxRadius)
{
	Circle circle(x, y, increaseRate, radius,  maxRadius);
	_circles.push_back(circle);
}
