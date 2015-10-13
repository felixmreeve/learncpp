#ifndef _GC_H_
#define _GC_H_

class GC
{
	public:
		const static int SCREEN_WIDTH = 500;
		const static int SCREEN_HEIGHT = 500;
		const static double PLAYER_SPEED = 6;
		const static double PLAYER_ACCELERATION = 0.5;
		GC();
};


typedef struct vect
{
	double x;
	double y;
} vect;

#endif
