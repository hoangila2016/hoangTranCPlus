#include<iostream>
#include<string>
#include<SDL.h>
#include<SDL_image.h>

const int SCREEN_WIDTH = 670;
const int SCREEN_HEIGHT = 420;

bool init();
bool loadMedia();
SDL_Texture* loadTexture(std::string path);
void close();

SDL_Window* gWindow = NULL;
SDL_Texture* gTexture = NULL;
SDL_Renderer* gRenderer = NULL;
bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL can't be created by %s \n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("warning:asdasdasds\n");
		}
		gWindow = SDL_CreateWindow("asd",100,100,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("window can't be created by %s\n",SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer can't be created by %s \n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer,255,255,255,255);
				int imgFlags = IMG_INIT_PNG;
				if (!((IMG_Init(imgFlags) & imgFlags)))
				{
					printf("SDL_img can't be created by %s \n",IMG_GetError());
					success = false;
				}

			}
		}
		
	}
	return success;
}
void close()
{
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
	IMG_Quit();
}

SDL_Texture* loadTexture(std::string path)
{
	SDL_Texture *newTexture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("%s can't be found by %s", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("texture can't be created by %s" ,SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}
bool loadMedia()
{
	bool success =  true;
	gTexture = loadTexture("./images/texture.png");
	if (gTexture == NULL)
	{
		printf("texture can't be created by %s", SDL_GetError());
		success = false;
	}
	return success;
}
int main(int argc, char* args[])
{
	if (!init())
	{
		printf("can't init");
	}
	else
	{
		if (!loadMedia())
		{
			printf("can't loadMedia");
		}
		else
		{
			bool quit = false;
			SDL_Event e;
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
						quit = true;
				}
				SDL_RenderClear(gRenderer);
				SDL_RenderCopy(gRenderer,gTexture,NULL,NULL);
				SDL_RenderPresent(gRenderer);
			}
		}
	}
	close();
	return 0;
}