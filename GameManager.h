#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"
#include "Background.h"
#include "Renderable.h"
#include "Player.h"
#include "Food.h"
#include "Circle.h"

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
		std::vector<Circle> _circles;
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
		void updateCircles();
		void checkPlayerCollision();
		void addCircle(int x, int y, float increaseRate, float radius, float maxRadius);
};

#endif
