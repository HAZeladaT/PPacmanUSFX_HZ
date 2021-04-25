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
	Texture* textura;

	int numeroFrame;
	int contadorFrames;
	const int framesMovimiento = 1;
	int posicionXEnTextura;
	int posicionYEnTextura;

public:
	//Constructores y destructores
	Pacman(Texture* _textura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//Metodos accesores

	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	
	// Metodos varios

	// Manejador de eventos de pacman
	void handleEvent(SDL_Event& e);
	// Mover pacman
	void move();
	// Renderizar imagen pacman
	void render();
	void update();
};