#pragma once
#include <iostream>
#include <string>

#include <SDL.h>
#include "GameObject.h"
#include "Texture.h"

using namespace std;

class Pacman: public GameObject
{
private:
	// Velocidad en eje X y Y
	int velocidadX;
	int velocidadY;

	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	int posicionXEnTextura;
	int posicionYEnTextura;

public:
	//Constructores y destructores
	Pacman(Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//Metodos accesores

	int getVelocidadX() { return velocidadX; }
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }

	int getVelocidadY() { return velocidadY; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }

	int getVelocidadPatron() { return velocidadPatron; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	
	// Metodos varios

	// Manejador de eventos de pacman
	void handleEvent(SDL_Event& e);
	// Mover pacman
	void move();
};