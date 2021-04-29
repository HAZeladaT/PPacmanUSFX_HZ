#pragma once
#include <SDL.h>
#include "GameObject.h"

enum PODER_MONEDA {
    PODER_MONEDA_NINGUNO,
    PODER_MONEDA_CRECIMIENTO,
    PODER_MONEDA_COMER,
    PODER_MONEDA_VELOCIDAD,
    PODER_MONEDA_SALTO
};


class Moneda :
    public GameObject
{
private:
    int valor;
    PODER_MONEDA tipoPoderMoneda;
    int tiempoPoderMoneda;

public:
    Moneda(Texture* _monedaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

    int getValor() { return valor; }
    void setValor(int _valor) { valor = _valor; }

    PODER_MONEDA getTipoPoderMoneda() { return tipoPoderMoneda; }
    void setTipoPoderMoneda(PODER_MONEDA _poderMoneda) { tipoPoderMoneda = _poderMoneda; }

    int getTiempoPoderMoneda() { return tiempoPoderMoneda; }
    void setTiempoPoderMoneda(int _tiempoPoderMoneda) { tiempoPoderMoneda = _tiempoPoderMoneda; }

};