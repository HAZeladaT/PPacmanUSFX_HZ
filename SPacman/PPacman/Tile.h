#pragma once
#include <SDL.h>

class Pacman;
class Fantasma;
class Fruta;
class Moneda;
class Pared;

class Tile
{
private:
	Pacman* pacman;
	Fantasma* fantasma;
	Fruta* fruta;
	Moneda* moneda;
	Pared* pared;
	int posicionX;
	int posicionY;
	//SDL_Point posicion;

public:
	static const int anchoTile = 25;
	static const int altoTile = 25;

public:
	Tile();
	Tile(int _x, int _y);

	Pacman* getPacman() { return pacman; }
	Fantasma* getFantasma() { return fantasma; }
	Fruta* getFruta() { return fruta; }
	Moneda* getMoneda() { return moneda; }
	Pared* getPared() { return pared; }
	//SDL_Point getPosicion() { return posicion; }

	void setPacman(Pacman* _pacman) { pacman = _pacman; }
	void setFantasma(Fantasma* _fantasma) { fantasma = _fantasma; }
	void setFruta(Fruta* _fruta) { fruta = _fruta; }
	void setMoneda(Moneda* _moneda) { moneda = moneda; }
	void setPared(Pared* _pared) { pared = _pared; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

};