#include<stdio.h>
#include<SDL.h>
#include<string>
const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* stretchedSurface = NULL;
bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL can't be initialize by %s", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("co ty phu",100,100,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("window can't be create %s",SDL_GetError());
			success = false;
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}
void close()
{
	SDL_FreeSurface(stretchedSurface);
	stretchedSurface = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}
SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("can't load the image %s by %s", path.c_str(), SDL_GetError());
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, 0);
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}
bool loadMedia()
{
	bool success = true;
	stretchedSurface = loadSurface("./images/up.bmp");
	if (stretchedSurface == NULL)
	{
		printf("Can't not load media by %s",SDL_GetError());
		success = false;
	}
	return success;
}
int main(int a, char* args[])
{
	if (!init())
	{
		printf("can't not init");
	}
	else
	{
		if (!loadMedia())
		{
			printf("can't load media");
		}
		else
		{
			SDL_Event e;
			bool quit = false;
			while (!quit)
			{
				while (SDL_PollEvent(&e)!=0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				SDL_Rect strectRect;
				strectRect.x = 0;
				strectRect.y = 0;
				strectRect.w = SCREEN_WIDTH;
				strectRect.h = SCREEN_HEIGHT;
				SDL_BlitScaled(stretchedSurface, NULL, screenSurface, &strectRect );
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	close();
	return 0;
}