#include<stdio.h>
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
SDL_Texture* texture = NULL;
SDL_Renderer* gRenderer = NULL;

bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL can't be initialized by%s",SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1"));
		printf("Warning: Linear texture filtering not enabled!");
		gWindow = SDL_CreateWindow("hh", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window can't be created by%s", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer can't be created by%s", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer,0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlag = IMG_INIT_JPG;
				if (!(IMG_Init(imgFlag) & imgFlag))
				{
					printf("SDL_IMG can't be initialized by%s", IMG_GetError());
					success = false;
				}
			}
		}
	}
	return true;
}
SDL_Texture* loadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("the image %s can't be load by%s",path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Texture can't be created by%s",SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}
bool loadMedia()
{
	bool success = true;
	return true;
}
void close()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	SDL_Quit();
	IMG_Quit();
}
int main(int argv,char*args[])
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
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);
					SDL_Rect midRect = {SCREEN_WIDTH/4,SCREEN_HEIGHT/4,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
					SDL_RenderFillRect(gRenderer, &midRect);
					SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
					SDL_Rect BorderRect = { SCREEN_WIDTH / 6,SCREEN_HEIGHT / 6,SCREEN_WIDTH *2/3,SCREEN_HEIGHT *2/ 3 };
					SDL_RenderDrawRect(gRenderer,& BorderRect);
					SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
					SDL_RenderDrawLine(gRenderer,0,SCREEN_HEIGHT/2,SCREEN_WIDTH,SCREEN_HEIGHT/2);
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);

					for (int i = 0; i <= SCREEN_HEIGHT;)
					{
						SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
						i = i + 4;
					}
					SDL_RenderPresent(gRenderer);

				}
			}
		}
	}
	return 0;
}
