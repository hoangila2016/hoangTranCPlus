
#include<SDL.h>
#include<stdio.h>
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 670;
int main(int a, char* args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_AUDIO)<0)
	{
		printf("SDL can be intialized because of \n");
	}
	else
	{
		window = SDL_CreateWindow("Co Ty Phu",100,100,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("windown can be intialazed %s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
			SDL_UpdateWindowSurface(window);
			SDL_Event e;
			bool quit = false;
			while (quit==false)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
						quit = true;
				}
			}
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}