#include<stdio.h>
#include<string>
#include<cmath>
#include<string>
#include<SDL.h>
#include<SDL_image.h>

const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 420;

bool init();
bool loadMedia();
SDL_Texture* loadTexture(std::string path);
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* texture = NULL;

bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{	
		printf("SDL can't be  initialized by %s",SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("hh",100,100,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window can't be  created by %s", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer can't be  created by %s", SDL_GetError());
				success = false;
			}
			else
			{

			}
		}
	}
	return success;
}

