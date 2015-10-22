#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Sprite.h"
#include "Renderable.h"
#include "Head.h"
#include "BodyPart.h"
#include "Food.h"

class Player
{
	protected:
		Head _head;
		
		std::vector<BodyPart> _bodyParts;
		//Sprite _sprite;
	public:
		Player(float maxVel, float acceleration, float xPos, float yPos);
		void update(bool aim, int xMouse, int yMouse, const Uint8 *keyState, Food *food);
		void render(SDL_Renderer *renderer);
		void close();
		
		void updateBody(float xHead, float yHead);
		void renderBody(SDL_Renderer *renderer);
		bool checkFood(Food *food);
		int getSize();
		float getHeadVel();
		void getHeadPos(float *x, float *y);
		void getBodyPartPos(int partNum, float *x, float *y);
};
#endif
