#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"
#include "Background.h"
#include "Player.h"
#include "Food.h"
#include "Circle.h"

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
	int x = 0;
	int y = 0;
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
	
	if(jump){
		int x = 0;
		int y = 0;
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
	
	double x = 0;
	double y = 0;
	_player.getHeadPos(&x, &y);
	
	double maxRad = GC::PLAYER_CIRCLE_MAX_SIZE * _player.getHeadVel() / GC::PLAYER_SPEED;
	
	
	/*if(maxRad < GC::PLAYER_CIRCLE_MIN_SIZE){
		maxRad = GC::PLAYER_CIRCLE_MIN_SIZE;
	}
	//*/
	
	
	
	
	addCircle(x, y, GC::PLAYER_CIRCLE_SPEED, GC::PLAYER_CIRCLE_START_SIZE, maxRad);
	
	
	
	
	
	
	//addCircle(x, y, GC::PLAYER_CIRCLE_SPEED, GC::PLAYER_CIRCLE_START_SIZE, GC::PLAYER_CIRCLE_MAX_SIZE);
	
	//iterate through circles vector
	//janky code tho
	for(std::vector<Circle>::iterator it = _circles.begin(); it < _circles.end(); ++it){
		//if(_circles.size() == 0) {printf("empty\n"); break;}
		double radius = 0;
		double maxRadius = 0;
		it->update();
		radius = it->getRadius();
		maxRadius = it->getMaxRadius();
		if(radius > maxRadius){
			_circles.erase(it);
		}
	}
	
	
}

void GameManager::addCircle(int x, int y, double increaseRate, double radius, double maxRadius)
{
	Circle circle(x, y, increaseRate, radius,  maxRadius);
	_circles.push_back(circle);
}
