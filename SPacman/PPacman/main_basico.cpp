#include <iostream>
#include <SDL.h>
#include "Pacman.h"
using namespace std;
//Constantes de dimensión de pantalla 
const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 480;
int main() 
{
	Pacman pacmansito;
	
	// La ventana que mostraremos a 
	SDL_Window* window = NULL; 
	// La superficie contenida por la ventana 
	SDL_Surface* screenSurface = NULL;
	//Inicializar 
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "¡SDL no pudo inicializar! SDL_Error:"<< SDL_GetError()<< endl;
	}
	else
	{
		// Crear ventana 
		window = SDL_CreateWindow("Tutorial SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			cout<<"¡No se pudo crear la ventana! SDL_Error:"<< SDL_GetError()<< endl;
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			//Update the surface
			SDL_UpdateWindowSurface(window);
			//Wait two seconds
			SDL_Delay(2000);
		}
	}
	// Destruye la ventana 
	SDL_DestroyWindow (window); 
	// Salir de los subsistemas 
	SDL_Quit (); 
	return 0; 
}