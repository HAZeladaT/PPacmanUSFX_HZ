#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma() {
	posicionX = 100;
	posicionY = 100;
	velocidadX = 1;
	velocidadY = 0;
	velocidadPatron = 1;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
	posicionXDestino=600;
	posicionYDestino=0;
	srand(time(NULL));
	tipoTextura = rand() % 4;
}

Fantasma::Fantasma(int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron, int _tipoTextura)
{
	// Inicializa propiedade de de pacman
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 1;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	ancho = 25;
	alto = 25;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	posicionXDestino =ancho+rand()% (anchoPantalla-ancho);
	posicionYDestino = 0;
	tipoTextura = _tipoTextura;
}

Fantasma::Fantasma(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _fantasmaTexture[4], int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron, int _tipoTextura)
{
	// Inicializa propiedade de de pacman
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 1;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	ancho = 25;
	alto = 25;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	posicionXDestino = 600;
	posicionYDestino = 0;
	tipoTextura = _tipoTextura;
	fantasmaTexture[0] = _fantasmaTexture[0];
	fantasmaTexture[1] = _fantasmaTexture[1];
	fantasmaTexture[2] = _fantasmaTexture[2];
	fantasmaTexture[3] = _fantasmaTexture[3];
}

void Fantasma::move()
{
	posicionX += velocidadPatron * velocidadX;
	posicionY += velocidadPatron * velocidadY;
	if (velocidadX == 1) {
		if (posicionX >= posicionXDestino) {
			velocidadX = 0;
			if (posicionY >= posicionYDestino) {
				velocidadY = -1;
			}
			else {
				velocidadY = 1;
			}
		}
	}
	else if(velocidadX== -1){
		if (posicionX <= posicionXDestino) {
			velocidadX = 0;
			if (posicionY >= posicionYDestino) {
				velocidadY = -1;
			}
			else {
				velocidadY = 1;
			}
		}
	}
	
	if (velocidadY == 1) {
		if (posicionY >= posicionYDestino) {
			velocidadY = 0;
			posicionXDestino = 1 + rand() % (anchoPantalla - ancho);
			posicionYDestino = 1 + rand() % (altoPantalla - alto);
			velocidadX = (posicionXDestino-posicionX)/abs(posicionXDestino - posicionX);
		}
	}
	else if (velocidadY == -1) {
		if (posicionY <= posicionYDestino) {
			velocidadY = 0;
			posicionXDestino = 1 + rand() % (anchoPantalla - ancho);
			posicionYDestino = 1 + rand() % (altoPantalla - alto);
			velocidadX = (posicionXDestino - posicionX) / abs(posicionXDestino - posicionX);
		}
	}
	if ((posicionX<0)|| (posicionX+ancho)>anchoPantalla){
		velocidadX *= -1;
	}
	
	if ((posicionY < 0) || (posicionY + alto) > altoPantalla) {
		velocidadY *= -1;
	}
	
}

void Fantasma::render()
{
	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };

	//Render to screen
	SDL_RenderCopyEx(renderer, fantasmaTexture[tipoTextura], nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
}