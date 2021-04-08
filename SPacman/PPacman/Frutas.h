#pragma once
#include <SDL.h>
class Frutas
{
private:
	int color;
	SDL_Point posicion;
	char tipo;
public:
	int getColor() { return color; }
	void setColor(int _color) { color = _color; }

	SDL_Point getPosicion() { return posicion; }
	void setPosicion(SDL_Point _posicion) { posicion = _posicion; }

	char getTipo() { return tipo; }
	void setTipo(char _tipo) { tipo = _tipo; }
};

