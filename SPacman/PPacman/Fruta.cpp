#include "Fruta.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
Fruta::Fruta() {
	posicionX = 50;
	posicionY = 50;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
	srand((unsigned int)time(NULL));
	tipoTextura = rand()%4;

	visible = false;

	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
}

Fruta::Fruta(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _frutasTextures[4], int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla)
{
	// Inicializa propiedade de de pacman
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = 25;
	alto = 25;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	srand((unsigned int)time(NULL));
	tipoTextura = rand() % 4;

	visible = false;

	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;

	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	frutasTextures[0] = _frutasTextures[0];
	frutasTextures[1] = _frutasTextures[1];
	frutasTextures[2] = _frutasTextures[2];
	frutasTextures[3] = _frutasTextures[3];
}


void Fruta::mostrar()
{
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			posicionX = 1 + rand() % (anchoPantalla-ancho);
			posicionY = 1 + rand() % (altoPantalla-alto);
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
		}
		else {
			contadorTiempoNoVisible++;
		}
	}
	else {
		contadorTiempoVisible++;
	}
}

void Fruta::render()
{
	if (visible) {

		SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
		//Render to screen
		SDL_RenderCopyEx(renderer, frutasTextures[tipoTextura], nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
	}
}