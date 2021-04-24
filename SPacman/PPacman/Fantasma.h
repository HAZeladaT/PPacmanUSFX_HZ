#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include "GameObject.h"
#include "Texture.h"
using namespace std;
class Fantasma : public GameObject {
private:

	//Velocidades
	int velocidadX;
	int velocidadY;

	//Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	int posicionXDestino;
	int posicionYDestino;
	int incrementoX;
	int incrementoY;
	Texture* fantasmaTexture = nullptr;
	int numeroFrame;
	int contadorFrames;
	const int framesMovimiento = 4;
	
public:
	//Constructores y destructores
	Fantasma(string path, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	Fantasma(Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	//~Fantasma();
	//Metodos accesores

	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }

	int getIncrementoX() { return incrementoX; }
	void setIncrementoX(int _incrementoX) { incrementoX = _incrementoX	}
	int getIncrementoY() { return incrementoY; }
	void setIncrementoY(int _incrementoY) { 
		if (_incrementoY < getAltoPantalla() && _incrementoY>0) {
			incrementoY = _incrementoY;
		}
	}
	// Mover fantasma
	void move();
	// Renderizar imagen fantasma
	void render() override;
	// Actualizar datos fantasma
	void update() override;
};