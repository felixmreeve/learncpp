#include "GameManager.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"
#include "Player.h"
#include "Eye.h"

GameManager::GameManager(GC gc) :
	_go( true ),
	_click( false ),
	_mouseX( GC::SCREEN_WIDTH/2 ),
	_mouseY( GC::SCREEN_HEIGHT/2 ),
	_keyState( SDL_GetKeyboardState(NULL) ),
	_player( GC::PLAYER_SPEED, GC::PLAYER_ACCELERATION, GC::SCREEN_WIDTH/2, GC::SCREEN_HEIGHT/2 ),
	_window( SDL_CreateWindow("THING", 10, 10, GC::SCREEN_WIDTH, GC::SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE) ),
	_renderer( SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) )
{}

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
}

void GameManager::render()
{
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	//clear the entire screen
	SDL_RenderClear(_renderer);
	
	_player.render(_renderer);
	
	//present renderer
	SDL_RenderPresent(_renderer);
}

void GameManager::close()
{
	_player.close();
}

bool GameManager::checkState()
{
	//return whether game is running
	return _go;
}
