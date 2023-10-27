#include<stdio.h>
#include<SDL.h>
const int SCREEN_HEIGHT = 1000;
const int SCREEN_WIDTH = 1000;
int main(int a, char* args[])
{
	SDL_Window* window=NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* background = NULL;
	if (SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf("SDL can be create because of: %s\n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow("Lien Minh Huyen Thoai", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("window can be create because of:%s\n",SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
			background = SDL_LoadBMP("./images/hello_world.bmp");
			if (background == NULL)
			{
				printf("can not load the image");
			}
			else
			{
				SDL_BlitSurface(background, NULL, screenSurface, NULL);
				SDL_FreeSurface(background);
				background = NULL;
			}
			SDL_UpdateWindowSurface(window);
			SDL_Event e;
			bool quit = false;
			while (quit == false)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type ==SDL_QUIT)
						quit = true;
				}
			}
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}