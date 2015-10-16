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
	Circle circle(GC::SCREEN_WIDTH/2, GC::SCREEN_HEIGHT/2);
	_circles.push_back(circle);
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
	_player.update(_click, _mouseX, _mouseY, _keyState);
	int jump = _food.update(_player);
	_background.update(jump);
	
	if(jump){
		int x = 0;
		int y = 0;
		_food.getPos(&x, &y);
		addCircle(x, y);
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
	
	for(std::vector<Circle>::iterator it = _circles.begin(); it!= _circles.end(); ++it){
		it->render(_renderer);
	}
	
	//present renderer
	SDL_RenderPresent(_renderer);
}

void GameManager::close()
{
	_player.close();
	_food.close();
	_background.close();
}

bool GameManager::checkState()
{
	//return whether game is running
	return _go;
}

void GameManager::updateCircles()
{
	//iterate through circles vector
	for(std::vector<Circle>::iterator it = _circles.begin(); it!= _circles.end(); ++it){
		int radius = 0;
		it->update();
		radius = it->getRadius();
		if(radius > 255){
			_circles.erase(it);
		}
	}
	/*
	int x = 0;
	int y = 0;
	_player.getPos(&x, &y);
	addCircle(x, y);
	*/
}

void GameManager::addCircle(int x, int y)
{
	Circle circle(x, y);
	_circles.push_back(circle);
}
