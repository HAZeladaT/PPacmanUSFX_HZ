#include <iostream>
#include "GameManager.h"
#include "GameObject.h"
using namespace std;


int main(int argc, char* argv[]) {
    GameManager theApp;
    GameObject objetoJuego(10, 10, 25, 25, 800, 600);

    return theApp.onExecute();
}