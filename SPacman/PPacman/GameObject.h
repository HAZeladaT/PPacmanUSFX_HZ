#pragma once
#include <iostream>
#include <string>
#include "Texture.h"
using namespace std;
class GameObject
{
private:
	string nombre;
protected:
	// Posicion en el eje X y Y
	int idObjeto;
	int posicionX;
	int posicionY;

	// Ancho y Alto de la imagen del objeto en pixeles
	int ancho;
	int alto;

	// Ancho y alto de la pantalla del juego
	int anchoPantalla;
	int altoPantalla;

	//Estado del objeto
	bool visible;
	bool eliminar;
	// Textura para representacion grafica del objeto
	Texture* textura;

	int numeroFrame;
	int contadorFrames;
	int framesMovimiento;

public:
	static int numeroObjetosCreados;

public:
	//Constructores y destructores
	GameObject(Texture* _textura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

	//Metodos accesores
	int getIdObjeto() { return idObjeto; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

	int getAncho() { return ancho; }
	void setAncho(int _ancho) { ancho = _ancho; }

	int getAlto() { return alto; }
	void setAlto(int _alto) { alto = _alto; }

	int getAnchoPantalla() { return anchoPantalla; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }

	int getAltoPantalla() { return altoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }

	bool getVisible() { return visible; }
	void setVisible(bool _visible) { visible = _visible; }

	// Metodos varios
	void setParametrosAnimacion(int _framesMovimiento) { framesMovimiento = _framesMovimiento; }

	// Renderizar imagen
	virtual void render();
	virtual void update();
	virtual void move() {};
	virtual void mostrar() {};
	virtual void handleEvent(SDL_Event& e) {};
};

