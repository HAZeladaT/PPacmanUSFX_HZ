#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma() {
	posicionX = 100;
	posicionY = 100;
	velocidadX = 1;
	velocidadY = 0;
	velocidadPatron = 5;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
}

Fantasma::Fantasma(int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron)
{
	// Inicializa propiedade de de pacman
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	ancho = 25;
	alto = 25;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
}

Fantasma::Fantasma(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _fantasmaTexture[3], int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron)
{
	// Inicializa propiedade de de pacman
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	ancho = 25;
	alto = 25;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	fantasmaTexture[0] = _fantasmaTexture[0];
	fantasmaTexture[1] = _fantasmaTexture[1];
	fantasmaTexture[2] = _fantasmaTexture[2];
	fantasmaTexture[3] = _fantasmaTexture[3];
}

void Fantasma::move()
{
	/*if (posicionX >= posicionXDestino) {
		if (posicionY >= posicionYDestino) {

			posicionXDestino = 1 + rand() % anchoPantalla;
			posicionYDestino = 1 + rand() % altoPantalla;

			if (posicionX > posicionXDestino) {
				incrementoPosicionX = -1;
			}
			else
			{
				incrementoPosicionX = 1;
			}

			if (posicionY > posicionXDestino) {
				incrementoPosicionY = -1;
			}
			else
			{
				incrementoPosicionX = 1;
			}
		}
		else {
			posicionY = posicionY + incrementoPosicionY;

			// Mover el fantasma arriba o abajo
			posicionY += velocidadY;

			// Verificar si la posicion del fantasma no salio de los bordes superior e inferior
			if ((posicionY < 0) || (posicionY + alto > altoPantalla))
			{
				// Mover fantasma atras
				posicionY -= velocidadY;
			}
		}
	}
	else {
		posicionX = posicionX + incrementoPosicionX;

		// Mover el fantasma a la izquierda o derecha
		posicionX += velocidadX;

		// Verificar si la posicion del fantasma no salio de los bordes izquierdo o derecho
		if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
		{
			// Mover fantasma atras
			posicionX -= velocidadX;
		}
	}*/

	if (posicionX >= posicionXDestino) {
		posicionXDestino = 1 + rand() % anchoPantalla;
		if (posicionY >= posicionYDestino) {
			posicionYDestino = 1 + rand() % altoPantalla;

			if (posicionX > posicionXDestino) {
				incrementoPosicionX = -1;
			}
			else
			{
				incrementoPosicionX = 1;
			}

			if (posicionY > posicionXDestino) {
				incrementoPosicionY = -1;
			}
			else
			{
				incrementoPosicionX = 1;
			}
		}
		else {
			posicionY = posicionY + incrementoPosicionY;

			// Mover el fantasma arriba o abajo
			posicionY += velocidadY;
			// Verificar si la posicion del fantasma no salio de los bordes superior e inferior
			if ((posicionY < 0) || (posicionY + alto > altoPantalla))
			{
				// Mover fantasma atras
				posicionY -= velocidadY;
			}
		}
	}
	else {
		posicionX = posicionX + incrementoPosicionX;

		// Mover el fantasma a la izquierda o derecha
		posicionX += velocidadX;
		if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
		{
			// Mover fantasma atras
			posicionX -= velocidadX;
		}
	}
}

void Fantasma::render()
{
	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };

	//Render to screen
	SDL_RenderCopyEx(renderer, fantasmaTexture[0], nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
	SDL_RenderCopyEx(renderer, fantasmaTexture[1], nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
	SDL_RenderCopyEx(renderer, fantasmaTexture[2], nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
	SDL_RenderCopyEx(renderer, fantasmaTexture[3], nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
}