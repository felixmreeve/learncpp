#include "Player.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

Sprite::Sprite(char *file):
	_img( IMG_Load(file) )
{}

void Sprite::render(SDL_Renderer *renderer, int x, int y){
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, _img);
	SDL_Rect rect = {x, y, 15, 15};
	SDL_RenderCopy(renderer, tex, NULL, &rect);
	SDL_DestroyTexture(tex);
	//MAYBE NOT CREATE AND DESTROY TEXTURE IF IT HASNT UPDATED, USE MEMBER?
}

void Sprite::close()
{
	SDL_FreeSurface(_img);
}
