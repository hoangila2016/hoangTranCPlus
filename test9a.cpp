#include<stdio.h>
#include<SDL.h>
#include<string>
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
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDl can't be initialized",SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("hh", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("window can't be created", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("renderer can't be created", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image can't be initialized", IMG_GetError());
					success = false;
				}
			}

		}
	}
	return success;
}

SDL_Texture* loadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("IMG %s can't be created", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(gRenderer,loadedSurface);
		if (newTexture == NULL)
		{
			printf("newTexture can't be created", SDL_GetError());
		}
	}
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}
bool loadMedia()
{
	bool success = true;
	texture = loadTexture("./images/up.bmp");
	if(texture==NULL)
	{
		printf("texture can't be created", SDL_GetError());
		success = false;
	}
	return success;
}
void close()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	SDL_Quit();
	IMG_Quit();
}
int main(int argv, char* args[])
{
	if (!init())
	{
		printf("can't be initialized");
	}
	else
	{
		if(!loadMedia())
			printf(" loadMedia can't be initialized");
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
					SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
					SDL_RenderClear(gRenderer);
					SDL_Rect topLeftViewport = {0,0,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
					SDL_RenderSetViewport(gRenderer, &topLeftViewport);
					SDL_RenderCopy(gRenderer,texture,NULL, NULL);
					SDL_Rect topRightViewport = { SCREEN_WIDTH/2,0,SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 };
					SDL_RenderSetViewport(gRenderer, &topRightViewport);
					SDL_RenderCopy(gRenderer, texture, NULL, NULL);
					SDL_Rect bottomViewport = {0,SCREEN_HEIGHT/2,SCREEN_WIDTH,SCREEN_HEIGHT/2};
					SDL_RenderSetViewport(gRenderer, &bottomViewport);
					SDL_RenderCopy(gRenderer, texture, NULL, NULL);
					SDL_RenderPresent(gRenderer);
				}
			}
		}
	}
	close();
	return 0;
}