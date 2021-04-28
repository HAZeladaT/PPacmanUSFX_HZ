#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma(string path, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) : GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	// Inicializa propiedade de de pacman
	velocidadX = 1;
	velocidadY = 0;
	numeroFrame = 0;
	contadorFrames = 0;
	velocidadPatron = _velocidadPatron;
	posicionXDestino =getAncho()+rand()% (getAnchoPantalla()-getAncho());
	posicionYDestino = 0;
	incrementoX = getPosicionX();
	incrementoY = getPosicionY();
	fantasmaTexture = new Texture();
	fantasmaTexture->loadFromImage(path.c_str());
}

Fantasma::Fantasma(Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) : GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	// Inicializa propiedade de de pacman
	velocidadX = 1;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	posicionXDestino = 600;
	posicionYDestino = 0;
	numeroFrame = 0;
	contadorFrames = 0;
	incrementoX = getPosicionX();
	incrementoY = getPosicionY();
	fantasmaTexture = _fantasmaTexture;
}
void Fantasma::move()
{
	incrementoX += velocidadPatron * velocidadX;
	setPosicionX(incrementoX);
	incrementoY += velocidadPatron * velocidadY;
	setPosicionY(incrementoY);
	if (velocidadX == 1) {
		if (incrementoX >= posicionXDestino) {
			velocidadX = 0;
			if (incrementoY >= posicionYDestino) {
				velocidadY = -1;
			}
			else {
				velocidadY = 1;
			}
		}
	}
	else if(velocidadX== -1){
		if (incrementoX <= posicionXDestino) {
			velocidadX = 0;
			if (incrementoY >= posicionYDestino) {
				velocidadY = -1;
			}
			else {
				velocidadY = 1;
			}
		}
	}
	if (velocidadY == 1) {
		if (incrementoY >= posicionYDestino) {
			velocidadY = 0;
			posicionXDestino = 1 + rand() % (getAnchoPantalla() - getAncho());
			posicionYDestino = 1 + rand() % (getAltoPantalla() - getAlto());
			if (posicionXDestino != incrementoX) {
				velocidadX = (posicionXDestino - incrementoX) / abs(posicionXDestino - incrementoX);
			}
			else {
				velocidadX = 1;
			}
		}
	}
	else if (velocidadY == -1) {
		if (incrementoY <= posicionYDestino) {
			velocidadY = 0;
			posicionXDestino = 1 + rand() % (getAnchoPantalla() - getAncho());
			posicionYDestino = 1 + rand() % (getAltoPantalla() - getAlto());
			if (posicionYDestino != incrementoY) {
				velocidadY = (posicionYDestino - incrementoY) / abs(posicionYDestino - incrementoY);
			}
			else {
				velocidadY = 1;
			}
		}
	}
	if ((incrementoX < 0)|| (incrementoX + getAncho())>=getAnchoPantalla()){
		velocidadX *= -1;
	}
	
	if ((incrementoY < 0) || (incrementoY + getAlto()) >= getAltoPantalla()) {
		velocidadY *= -1;
	}
}

void Fantasma::render()
{
	SDL_Rect renderQuad = { 25 * numeroFrame, 25, getAncho(), getAlto() };

	//Render to screen
	fantasmaTexture->render(getPosicionX(), getPosicionY(), &renderQuad);
}

void Fantasma::update() {
	contadorFrames++;
	numeroFrame = contadorFrames / 8;

	if (numeroFrame > framesMovimiento - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}
}
