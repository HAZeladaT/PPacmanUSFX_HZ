#pragma once
#include <SDL.h>
#include "Movimientos.h"

class Fantasma
{
private:
	float velocidad;
	int color;
	char forma;
	int alto;
	int ancho;
	char accesorio;
	char estado;
	Movimiento direccionActual;
	Movimiento direccionSiguiente;

	SDL_Point posicion;

public:
	void move(float velocidad) {};
	SDL_Point getPosicion() { return posicion; }
	void setPosicion(SDL_Point _posicion) { posicion = _posicion; }

	Movimiento getDireccionActual() { return direccionActual; }
	void setDireccionActual(Movimiento _direccionActual) { direccionActual = _direccionActual; }
	Movimiento getDireccionSiguiente() { return direccionSiguiente; }
	void setDireccionSiguiente(Movimiento _direccionSiguiente) { direccionSiguiente = _direccionSiguiente; }

	float getVelocidad() { return velocidad; }
	void setVelocidad(float _velocidad) { velocidad = _velocidad; }
};

