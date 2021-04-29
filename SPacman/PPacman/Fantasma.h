#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include "GameObject.h"
#include "Texture.h"

using namespace std;
class Fantasma : public GameObject {
private:

	//Sentido
	int velocidadX;
	int velocidadY;

	//Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	int posicionXDestino;
	int posicionYDestino;
	int incrementoX;
	int incrementoY;
	
public:
	//Constructores y destructores
	Fantasma(Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	
	//Metodos accesores

	int getVelocidadX() { return velocidadX; }
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }

	int getVelocidadY() { return velocidadY; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }

	int getVelocidadPatron() { return velocidadPatron; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }

	int getIncrementoX() { return incrementoX; }
	void setIncrementoX(int _incrementoX) { incrementoX = _incrementoX; }
	
	int getIncrementoY() { return incrementoY; }
	void setIncrementoY(int _incrementoY) { incrementoY = _incrementoY; }
	// Mover fantasma
	void move();
};