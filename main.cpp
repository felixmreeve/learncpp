#include <iostream>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GC.h"
#include "GameManager.h"

int init(void);

int main(int argc, char *argv[]){
	//initialize SDL
	init();
	//create game manager
	GameManager game;
	
	//refresh loop
	while(game.checkState()){
		//int start = SDL_GetTicks();
		game.checkInput();
		game.update();
		game.render();
		
		
		
		
		
		
		
		
		
		//if(timeElapsed < GC::TIME_FOR_FRAME){
			
			//usleep(10000);
			SDL_Delay(10);
		//}
		//int end = SDL_GetTicks();
		//int timeElapsed = end - start;
		//printf("timeElapsed = %d\n", timeElapsed);
		//printf("fps: %f\n\n", 1000.0f/timeElapsed);
	}
	game.close();
	//quit SDL
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	return 0;
}

int init(void)
{
	/** initialises the SDL libraries used.
	 *  
	 *  return int: 0 if no errors, 1, 2 or 3 for errors, depending on which init failed
	 */
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		/* Initialising SDL went wrong */
		perror("Failed to initialise SDL");
		printf("Failed to initialise SDL\n");
		printf("SDL_Init: %s\n", SDL_GetError());
		return -1;
	}
	/* source from libsdl at http://www.libsdl.org/projects/SDL_image/docs/SDL_image_8.html, to use IMG_Init and check for failure  */
	int flags = IMG_INIT_JPG|IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if((initted&flags) != flags) {
		/* Initialising SDL IMG went wrong */
		perror("Failed to initialise IMG");
		printf("failed to initialise IMG\n");
		printf("IMG_Init: %s\n", IMG_GetError());
		return -2;
	}
	/* source from libsdl ends here */
	/* initialise TTF for text stuff */
	if(TTF_Init() != 0){
		perror("Failed to initialise TTF");
		printf("failed to initialise TTF\n");
		printf("TTF_Init: %s\n", TTF_GetError());
		return -3;
	}
	/* return 0 if there are no errors */
	return 0;
}
