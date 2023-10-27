#include<stdio.h>
#include<SDL.h>
#include<SDL_image.h>
#include<string>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 420;

bool init();
bool loadMedia();
SDL_Surface* loadSurface(std::string path);
void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* PNGSurface = NULL;


bool init()
{
	bool success = true;
	if (!SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDl can't be initialize by %s",SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("html",100,100,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("window can't be created by %s",SDL_GetError());
			success = false;
		}
		else
		{
			int imageFlag = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlag)&imageFlag))
			{
				printf("IMG can't be initilized by %s",IMG_GetError());
				success = false;
			}
			else
			{
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}
	return success;
}

SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Image %s can not be load by %s",path.c_str(),IMG_GetError());
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface,gScreenSurface->format,0);
		if (optimizedSurface == NULL)
		{
			printf("can not optimized image by %s",SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}
bool loadMedia()
{
	bool success = true;
	PNGSurface = loadSurface("./images/up.bmp");
	if (PNGSurface == NULL)
	{
		printf("fail to load imagine by %s",SDL_GetError());
		success = false;
	}
	return success ;
}
void close()
{
	SDL_FreeSurface(PNGSurface);
	PNGSurface = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}
int main(int argc, char* args[])
{
	if (!init())
	{
		printf("can not init");
	}
	else
	{
		if (!loadMedia())
		{
			printf("can not load media");
		}
		else
		{
		SDL_Event e;
		bool quit = false;
		while (!quit)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
			SDL_Rect strectchedSurface;
			strectchedSurface.x = 0;
			strectchedSurface.y = 0;
			strectchedSurface.w = SCREEN_WIDTH;
			strectchedSurface.h = SCREEN_HEIGHT;
			SDL_BlitScaled(PNGSurface,NULL,gScreenSurface,NULL);
			SDL_UpdateWindowSurface(gWindow);
		}
		}
	}
	close();
	return 0;
}