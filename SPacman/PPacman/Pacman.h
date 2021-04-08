#pragma once
class Pacman
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
public:
	void move(float velocidad) {};

	float getPosicionX() { return posicionX; }
	void setPosicionX(float _posicionX) { posicionX = _posicionX; }
	float getPosicionY() { return posicionY; }
	void setPosicionY(float _posicionY) { posicionY = _posicionY; }

	float getVelocidad() { return velocidad; }
	void setVelocidad(float _velocidad) { velocidad = _velocidad; }
};

