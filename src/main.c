#include <stdio.h>
#include "my_sdl.h"

int main(void)
{
	start();


/*	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*bmp;
	SDL_Texture		*tex;
	SDL_Event		e;
	int				quit;
	SDL_Surface		*img;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Error 0\n");
		return (0);
	}   
	win = SDL_CreateWindow("Hello World!", 100, 100, 600, 600, SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		printf("Error 1\n");
		return (0);
	}
 	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL)
	{
		printf("Error 2\n");
		return (0);
	}
	bmp = SDL_LoadBMP("svbbbdi4_2.bmp");
	if (bmp == NULL)
	{
		printf("Error 3\n");
		return (0);
	}
	tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == NULL)
	{
		printf("Error 4\n");
		return (0);
	}
	//SDL_RenderClear(ren);
	//SDL_RenderCopy(ren, tex, NULL, NULL);
	//SDL_RenderPresent(ren);

	img = SDL_GetWindowSurface(win);
	SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 0xFF, 0xFF, 0xFF));
	if (!img)
		printf("Lol");
	
	quit = 0;
	while (!quit)
	{
		while(SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = 1;
			if (e.type == SDL_KEYUP)
			{
				set_pixel(img, random() % 600, random() % 600, 255);
				printf("OK\n");
				SDL_UpdateWindowSurface(win);
			}
		}
	//	SDL_RenderCopy(ren, img, NULL, NULL);
	//	SDL_RenderPresent(ren);
	}
	SDL_FreeSurface(img);
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit(); */
	return (0);
}
