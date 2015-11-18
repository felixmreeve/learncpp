#ifndef _GC_H_
#define _GC_H_

class GC
{
	public:
		const static int SCREEN_WIDTH = 100;
		const static int SCREEN_HEIGHT = 100;
		const static int TIME_FOR_FRAME = 10;
		
		const static float PLAYER_SPEED = 6;
		const static float PLAYER_ACCELERATION = 0.5;
		
		const static float PLAYER_CIRCLE_MAX_SIZE = 40;
		const static float PLAYER_CIRCLE_START_SIZE = 3;
		const static float PLAYER_CIRCLE_SPEED = 2;
		
		const static float FOOD_CIRCLE_MAX_SIZE = 300;
		const static float FOOD_CIRCLE_START_SIZE = 0;
		const static float FOOD_CIRCLE_SPEED = 1;
		
		const static float BACKGROUND_CHANGE_RATE = 0.7;
		const static float BACKGROUND_JUMP_RATIO = 1;
		GC();
};

#endif
