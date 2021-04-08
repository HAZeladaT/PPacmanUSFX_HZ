#pragma once
#include "Movimientos.h"

class Fantasma
{
private:
	float posicionX;
	float posicionY;
	float velocidad;
	int color;
	char forma;
	int alto;
	int ancho;
	char accesorio;
	char estado;
	Movimiento direccionActual;
	Movimiento direccionSiguiente;

	SDL_Point posicionActual;

public:
	void move(float velocidad) {};

	Movimiento getDireccionActual() { return direccionActual; }
	void setDireccionActual(Movimiento _direccionActual) { direccionActual = _direccionActual; }
	Movimiento getDireccionSiguiente() { return direccionSiguiente; }
	void setDireccionSiguiente(Movimiento _direccionSiguiente) { direccionSiguiente = _direccionSiguiente; }

	float getPosicionX() { return posicionX; }
	void setPosicionX(float _posicionX) { posicionX = _posicionX; }
	float getPosicionY() { return posicionY; }
	void setPosicionY(float _posicionY) { posicionY = _posicionY; }

	float getVelocidad() { return velocidad; }
	void setVelocidad(float _velocidad) { velocidad = _velocidad; }
};

