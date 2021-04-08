#pragma once
#include <SDL.h>
#include "Movimientos.h"

class Fantasma
{
private:
	float velocidad;
	float velocidadPatron;
	float posicionX;
	float posicionY;
	int color;
	char forma;
	int alto;
	int ancho;
	char accesorio;
	char estado;
	int anchoPantalla;
	int altoPantalla;

public:
	// Ventana en la que se realizara el tratamiento grafico de renderizacion
	SDL_Window* window = nullptr;

	// Renderizador de la ventana
	SDL_Renderer* renderer = nullptr;

	// La superficie grafica (surface) que contiene la ventana
	SDL_Surface* screenSurface = nullptr;

	// Supeerficie grafica del fantasma;
	SDL_Surface* fantasmaSurface = nullptr;
public:
	// Constructores y destructores
	Fantasma();
	// ~ Fantasma ();

	// Metodos accesores

	float getPosicionX() { return posicionX; }
	void setPosicionX(float _posicionX) { posicionX = _posicionX; }

	float getPosicionY() { return posicionY; }
	void setPosicionY(float _posicionY) { posicionY = _posicionY; }

	float getVelocidad() { return velocidad; }
	void setVelocidad(float _velocidad) { velocidad = _velocidad; }

	float getVelocidadPatron() { return velocidadPatron; }
	void setVelocidadPatron(float _velocidadPatron) { velocidadPatron = _velocidadPatron; }

	int getAncho() { return ancho; }
	void setAncho(float _ancho) { ancho = _ancho; }

	int getAlto() { return alto; }
	void setAlto(float _alto) { alto = _alto; }

	int getAnchoPantalla() { return anchoPantalla; }
	void setAnchoPantalla(float _anchoPantalla) { anchoPantalla = _anchoPantalla; }

	int getAltoPantalla() { return altoPantalla; }
	void setAltoPantalla(float _altoPantalla) { altoPantalla = _altoPantalla; }

	// Metodos varios

	// Manejador de eventos del fantasma
	// anular handleEvent (SDL_Event & e);

	// Mover fantasma
	void move();
	// Renderizar imagen fantasma
	void  render();
};

