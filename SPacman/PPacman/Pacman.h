#pragma once
#include  < iostream >
#include  <string >
#include  < SDL.h >
using namespace std;
class Pacman
{
private:
	int alto;
	int ancho;
	SDL_Point posicion;
	SDL_Point velocidad;
	char accesorio;
public:
	const  int SCREEN_WIDTH = 640;
	const  int SCREEN_HEIGHT = 480;

	const  int PACMAN_WIDTH = 20;
	const  int PACMAN_HEIGHT = 20;
	const  int PACMAN_VEL = 10;
	Pacman();
	void handleEvent(SDL_Event& e);
	void move();
	void render();
	
	// La ventana a la que estaremos renderizando
	SDL_Window* window = NULL;

	// El renderizador de ventana
	SDL_Renderer* renderer = NULL;

	// La superficie contenida por la ventana
	SDL_Surface* screenSurface = NULL;


	// Texturas de la escena
	// Textura * PacmanTextura;
	SDL_Surface* pacmanSurface = NULL;
};

