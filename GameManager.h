#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"
#include "Player.h"
#include "Eye.h"

class GameManager
{
	protected:
		bool _go;
		bool _click;
		int _mouseX;
		int _mouseY;
		int _ticks;
		Player _player;
		SDL_Window *_window;
		SDL_Renderer *_renderer;
	public:
		GameManager( GC gc );
		void update();
		void render();
		void close();
		bool checkState();
};
#endif
