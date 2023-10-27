#include<stdio.h>
#include<SDL.h>
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 670;
int main(int a,char*args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* background = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL can't be initialized because of:%s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("Tran hoang",100,100,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window can't be create because of:%s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
			background = SDL_LoadBMP("./images/x.bmp");
			SDL_Event e;
			bool quit = false;
			while (quit == false)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
						background = SDL_LoadBMP("./images/hello_world.bmp");
						SDL_BlitSurface(background, NULL, screenSurface, NULL);
						SDL_UpdateWindowSurface(window);
						SDL_Delay(5000);
					}
				}
				SDL_BlitSurface(background,NULL,screenSurface,NULL);
				SDL_UpdateWindowSurface(window);
			}
		}
	}
	SDL_FreeSurface(background);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}