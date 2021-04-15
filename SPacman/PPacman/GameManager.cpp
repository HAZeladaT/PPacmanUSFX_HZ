#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	gScreenSurface = nullptr;
	gPacmanTexture = nullptr;
	juego_en_ejecucion = true;

	for (int i = 0; i <= 3; i++) {
		frutas[i] = new Fruta();
	}
}
	
int GameManager::onExecute() {
	srand(time(NULL));
	if (onInit() == false) {
		return -1;
	}
	pacman = new Pacman(gWindow, gRenderer, gScreenSurface, gPacmanTexture, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT, 2);
	for (int i = 0; i <= 3; i++) {
		fantasmas[i] = new Fantasma(gWindow, gRenderer, gScreenSurface, gFantasmaTexture, rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, 1,i);
	}
	for (int i = 0; i <= 3; i++) {
		frutas[i] = new Fruta(gWindow, gRenderer, gScreenSurface, gFrutasTextures, rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	SDL_Event Event;

	while (juego_en_ejecucion) {
		while (SDL_PollEvent(&Event)) {
			onEvent(&Event);
			pacman->handleEvent(Event);
		}
		// Mover Pacman
		pacman->move();

		// Mover Fantasma
		for (int i = 0; i <= 3; i++) {
			fantasmas[i]->move();
		}
		for (int i = 0; i <= 3; i++) {
			frutas[i]->mostrar();
		}
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Update screen

		onLoop();
		onRender();
		SDL_RenderPresent(gRenderer);
	}

	onCleanup();

	return 0;
}

bool GameManager::onInit() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Pacman USFX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{

			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}


			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);

			gPacmanTexture = loadTexture("pacmansito.bmp");
			if (gPacmanTexture == NULL)
			{
				cout << "Fallo en la carga de la textura" << endl;
				success = false;
			}
			//Fantasmas
			if ((gFantasmaTexture[0] = loadTexture("Fantasma1.bmp")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFantasmaTexture[1] = loadTexture("Fantasma2.bmp")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFantasmaTexture[2] = loadTexture("Fantasma3.bmp")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFantasmaTexture[3] = loadTexture("Fantasma4.bmp")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			//Frutitas
			if ((gFrutasTextures[0] = loadTexture("Fruta1.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFrutasTextures[1] = loadTexture("Fruta2.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFrutasTextures[2] = loadTexture("Fruta3.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFrutasTextures[3] = loadTexture("Fruta4.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
		}
	}

	return success;
};

void GameManager::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		juego_en_ejecucion = false;
	}
};
void GameManager::onLoop() {};
void GameManager::onRender() {
	pacman->render();
	for (int i = 0; i <= 3; i++) {
		fantasmas[i]->render();
	}
	for (int i = 0; i <= 3; i++) {
		frutas[i]->render();
	}
};

void GameManager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);

	SDL_Quit();
};


SDL_Texture* GameManager::loadTexture(string path)
{
	// Textura final generada
	SDL_Texture* newTexture = nullptr;

	// Carga una imagen de una ruta especifica
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << "No se pudo cargarla imagen, SDL_image Error: " << IMG_GetError() << endl;
	}
	else
	{
		// Crea una textura a partir de una superficie de pixeles
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			cout << "No se pudo crear la textura, SDL Error: " << SDL_GetError() << endl;
		}

		// Libera la superficie cargada
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}