#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"

//Screen dimension constants
#define WIDTH 420
#define HEIGHT 360
#define BPP 24

int main(int argc, char* argv[]) {
	SDL_Surface* image, * screen;
	SDL_Rect dest;
	SDL_Event event;
	int done = 0;
	Uint8* keys;

	struct pacman {
		int x, y;
	} pacmansito;

	atexit(SDL_Quit);
	// Iniciar SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("No se pudo iniciar SDL: %s\n", SDL_GetError());
		exit(1);
	}

	// Cargamos gráfico
	image = SDL_LoadBMP("pacmansito.bmp");
	if (image == NULL) {
		printf("No pude cargar gráfico: %s\n", SDL_GetError());
		exit(1);
	}
	SDL_Surface* SDL_SetVideoMode();
	screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_SWSURFACE);
	if (screen == NULL)
	{
		printf("No se ha podido establecer el modo de vídeo: %s\n", SDL_GetError());
		exit(1);
	}
	// Definimos donde dibujaremos el gráfico
	// y lo copiamos a la pantalla.
	pacmansito.x = 50;
	pacmansito.y = 10;

	dest.x = pacmansito.x;
	dest.y = pacmansito.y;
	dest.w = image->w;
	dest.h = image->h;

	while (done == 0) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN)
				done = 1;
		}
	}
	return 0;
}