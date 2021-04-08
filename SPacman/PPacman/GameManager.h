#pragma once
#include <iostream>
#include <string>
#include "Pacman.h"
#include "Fantasma.h"
#include <SDL.h>
//Constantes de dimensión de pantalla 
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class GameManager
{
private:
	bool juego_en_ejecucion;
	// La ventana que mostraremos a 
	SDL_Window* gWindow;
	// El renderizador de ventana
	SDL_Renderer* gRenderer;
	// La superficie contenida por la ventana 
	SDL_Surface* gScreenSurface;
	// Las imágenes que cargaremos y mostraremos en pantalla
	SDL_Surface* gPacManSurface;
	SDL_Surface* gFantasmaSurface;
public:
	GameManager();
	int  onExecute();

	bool  onInit();

	void  onEvent(SDL_Event* Evento);
	void  onLoop();
	void  onRender();
	void  onCleanup();

	/* SDL_Surface * loadMediaToSurface(string _mediaFile); */

	Pacman * pacman;
	Fantasma fantasma;
};

