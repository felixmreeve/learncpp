#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Sprite.h"
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
		Player(double maxVel, double acceleration, double xPos, double yPos);
		void update(bool aim, int xMouse, int yMouse, const Uint8 *keyState, Food *food);
		void render(SDL_Renderer *renderer);
		void close();
		
		void updateBody(int xHead, int yHead);
		void renderBody(SDL_Renderer *renderer);
		bool checkFood(Food *food);
		double getHeadVel();
		void getHeadPos(double *x, double *y);
};
#endif
