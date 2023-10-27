#include<stdio.h>
#include<string>
#include<SDL.h>
#include<SDL_image.h>

const int SCREEN_WIDTH = 620;
const int SCREEN_HEIGHT = 420;

enum IMGTexture
{
	TEXTURE_DEFAULT,
	TEXTURE_ATTACK,
	TEXTURE_DEFEND,
	TEXTURE_TOTAL

};

bool init();
bool loadMedia();
SDL_Texture* loadTexture(std::string path);
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* texture = NULL;
SDL_Texture* IMGTexture[TEXTURE_TOTAL];

bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL can't be initialized %s", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("hoang tran", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("window can't be created %s", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("renderer can't be created %s", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL IMG can't be initialized %s", SDL_GetError());
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
	SDL_Surface* loadedSurface = NULL;
	loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("img %s can't be loaded by %s", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("texture can't be created %s", SDL_GetError());
		}
	}
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}
bool loadMedia()
{
	bool success = true;
	IMGTexture[TEXTURE_DEFAULT] = loadTexture("./images/default.bmp");
	if (IMGTexture[TEXTURE_DEFAULT] == NULL)
	{
		printf("img press.bmp can be load by %s", SDL_GetError());
		success = false;
	}
	IMGTexture[TEXTURE_ATTACK] = loadTexture("./images/attack.bmp");
	if (IMGTexture[TEXTURE_ATTACK] == NULL)
	{
		printf("img attack.bmp can be load by %s", SDL_GetError());
		success = false;
	}
	IMGTexture[TEXTURE_DEFEND] = loadTexture("./images/defend.bmp");
	if (IMGTexture[TEXTURE_DEFEND] == NULL)
	{
		printf("img defend.bmp can be load by %s", SDL_GetError());
		success = false;
	}
	return success;
}
void close()
{
	for (int i = 0; i < TEXTURE_TOTAL; i++)
	{
		SDL_DestroyTexture(IMGTexture[i]);
		IMGTexture[i] = NULL;

	}
	SDL_DestroyTexture(texture);
	texture = NULL;
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;
	SDL_Quit();
	IMG_Quit();
}
int main(int argv, char* args[])
{
	if (!init())
	{
		printf("can't init");
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
			texture = IMGTexture[TEXTURE_DEFAULT];
			while (!quit)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					else
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_a:
						{
							texture = IMGTexture[TEXTURE_ATTACK];
							break;
						}
						case SDLK_s:
						{
							texture = IMGTexture[TEXTURE_DEFEND];
							break;
						}
						default:
							texture = IMGTexture[TEXTURE_DEFAULT];
							break;
						}
					}
					SDL_RenderClear(gRenderer);
					SDL_RenderCopy(gRenderer, texture, NULL, NULL);
					SDL_RenderPresent(gRenderer);
				}
			}
		}
	}
	close();
	return 0;
}
