#include<stdio.h>
#include<SDL.h>
#include<string>
// initalize variable
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 720;
enum KeyPressSurface
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};
// initalize window
SDL_Window* gWindow = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* currentSurface = NULL;
SDL_Surface* gKeyPressSurface[KEY_PRESS_SURFACE_TOTAL];
//initialize method
bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface(std::string path);

//draw
bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDl can't be init by %s",SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("co ty phu",100,100,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("window can't be created by%s",SDL_GetError());
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
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
	{
		SDL_FreeSurface(gKeyPressSurface[i]);
		gKeyPressSurface[i] = NULL;
	}
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}
SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* loadSurface= SDL_LoadBMP(path.c_str());
	if (loadSurface == NULL)
	{
		printf("can not load surface by %s",SDL_GetError());
	}
	return loadSurface;
}
bool loadMedia()
{
	bool success = true;
	gKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("./images/press.bmp");
	if (gKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("can't load surface default by %s", SDL_GetError());
		success = false;
	}
	gKeyPressSurface[KEY_PRESS_SURFACE_UP] = loadSurface("./images/up.bmp");
	if (gKeyPressSurface[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("can't load surface up by %s", SDL_GetError());
		success = false;
	}
	gKeyPressSurface[KEY_PRESS_SURFACE_DOWN] = loadSurface("./images/down.bmp");
	if (gKeyPressSurface[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		printf("can't load surface DOWN by %s", SDL_GetError());
		success = false;
	}
	gKeyPressSurface[KEY_PRESS_SURFACE_LEFT] = loadSurface("./images/left.bmp");
	if (gKeyPressSurface[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		printf("can't load surface left by %s", SDL_GetError());
		success = false;
	}
	gKeyPressSurface[KEY_PRESS_SURFACE_RIGHT] = loadSurface("./images/right.bmp");
	if (gKeyPressSurface[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		printf("can't load surface right by %s", SDL_GetError());
		success = false;
	}
	return success;
}
int main(int a, char* args[])
{
	if (init())
	{
		if (loadMedia())
		{
			SDL_Event e;
			bool quit = false;
			currentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT];
			while (!quit)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
					{
						quit=true;
					}
					else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							currentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_UP];
							break;
						case SDLK_DOWN:
							currentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_DOWN];
							break;
						case SDLK_LEFT:
							currentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_LEFT];
							break;
						case SDLK_RIGHT:
							currentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_RIGHT];
							break;
						default:
							currentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT];
							break;
						}
					}
				}
				SDL_BlitSurface(currentSurface, NULL, screenSurface, NULL);
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	close();
	return 0;
}




