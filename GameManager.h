#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Background.h"
#include "Player.h"
#include "Food.h"

class GameManager
{
	protected:
		bool _go;
		bool _click;
		int _mouseX;
		int _mouseY;
		const Uint8 *_keyState;
		Player _player;
		Food _food;
		Background _background;
		SDL_Window *_window;
		SDL_Renderer *_renderer;
	public:
		GameManager();
		void checkInput();
		void update();
		void render();
		void close();
		bool checkState();
};
#endif
