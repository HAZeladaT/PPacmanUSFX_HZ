#include "TileGraph.h"

TileGraph::TileGraph()
{
	//tiles = nullptr;

	anchoTileGraph = 0;
	altoTileGraph = 0;
}

TileGraph::TileGraph(int _anchoTileGraph, int _altoTileGraph)
{
	// Crear un array dinamico de Tile
	for (auto i = listaTilesGraph.begin(); i != listaTilesGraph.end(); ++i) {
		(*i) = new Tile[_anchoTileGraph * _altoTileGraph];
	}
	//tiles = new Tile[_anchoTileGraph * _altoTileGraph];

	// Set position of all tiles
	// NOTE: This could propably be also made with constructor
	for (int y = 0; y < _altoTileGraph; y++) {
		for (int x = 0; x < _anchoTileGraph; x++) {
			int a = 0;
			for (auto i = listaTilesGraph.begin(); i != listaTilesGraph.end(); ++i) {
				if (a == (x + (y * _anchoTileGraph))) {
					((Tile*)*i)->setPosicionX(x);
					((Tile*)*i)->setPosicionY(y);
				}
				listaTilesGraph.push_back(new Tile(x, y));
			}
			/*tiles[x + (y * _anchoTileGraph)].setPosicionX(x);
			tiles[x + (y * _anchoTileGraph)].setPosicionY(y);
			vectorTilesGraph.push_back(new Tile(x, y));*/
		}
	}

	anchoTileGraph = _anchoTileGraph;
	altoTileGraph = _altoTileGraph;
}

void TileGraph::configurar(int _anchoTileGraph, int _altoTileGraph)
{
	// If the TileGraph is not empty, empty it
	listaTilesGraph.clear();
	for (auto i = listaTilesGraph.begin(); i != listaTilesGraph.end(); ++i) {
		(*i) = new Tile[_anchoTileGraph * _altoTileGraph];
	}
	//tiles = new Tile[_anchoTileGraph * _altoTileGraph];

	if (!listaTilesGraph.empty())
		listaTilesGraph.clear();

	// Set position of all tiles
	// NOTE: This could propably be also made with constructor
	for (int y = 0; y < _altoTileGraph; y++) {
		for (int x = 0; x < _anchoTileGraph; x++) {
			int a = 0;
			for (auto i = listaTilesGraph.begin(); i != listaTilesGraph.end(); ++i) {
				if (a == (x + (y * _anchoTileGraph))) {
					((Tile*)*i)->setPosicionX(x);
					((Tile*)*i)->setPosicionY(y);
				}
				listaTilesGraph.push_back(new Tile(x, y));
			}
			/*(*i).setPosicionX(x);
			(*i).setPosicionY(y);
			listaTilesGraph.push_back(new Tile(x, y));*/
		}
	}

	anchoTileGraph = _anchoTileGraph;
	altoTileGraph = _altoTileGraph;
}

TileGraph::~TileGraph()
{
	listaTilesGraph.clear();
}

Tile* TileGraph::getTileEn(int x, int y)
{
	int indice = getIndice(x, y);
	if (indice < 0)
		return nullptr;

	//return vectorTilesGraph[indice];
	int c = 0;
	for (auto i = listaTilesGraph.begin(); i != listaTilesGraph.end(); ++i) {
		if (c == indice) {
			return (*i);
		};
		c++;
	}
	//return &tiles[indice];
	return NULL;
}

array<Tile*, 4> TileGraph::get4Vecinos(Tile* _tile)
{
	std::array<Tile*, 4> Vecinos;

	int x = _tile->getPosicionX();
	int y = _tile->getPosicionY();

	Vecinos[0] = getTileEn(x, y + 1);		// N
	Vecinos[1] = getTileEn(x + 1, y);		// E
	Vecinos[2] = getTileEn(x, y - 1);		// S
	Vecinos[3] = getTileEn(x - 1, y);		// _anchoTileGraph

	return Vecinos;
}

array<Tile*, 8> TileGraph::get8Vecinos(Tile* _tile)
{
	std::array<Tile*, 8> Vecinos;

	int x = _tile->getPosicionX();
	int y = _tile->getPosicionY();

	Vecinos[0] = getTileEn(x, y + 1);		// N
	Vecinos[1] = getTileEn(x + 1, y);		// E
	Vecinos[2] = getTileEn(x, y - 1);		// S
	Vecinos[3] = getTileEn(x - 1, y);		// _anchoTileGraph
	Vecinos[4] = getTileEn(x + 1, y + 1);	// NE
	Vecinos[5] = getTileEn(x - 1, y + 1);	// SE
	Vecinos[6] = getTileEn(x - 1, y - 1);	// SW
	Vecinos[7] = getTileEn(x + 1, y - 1);	// NW

	return Vecinos;
}

Pacman* TileGraph::getPacman()
{
	/*for (unsigned int i = 0; i < anchoTileGraph * altoTileGraph; i++) {
		Tile tile = tiles[i];

		if (tile.getPacman() != nullptr)
			return tile.getPacman();
	}*/

	for (auto i = listaTilesGraph.begin(); i != listaTilesGraph.end(); ++i) {
		if ((*i)->getPacman())
			return (*i)->getPacman();
	}


	return nullptr;
}

int TileGraph::getIndice(int x, int y)
{
	if (x >= anchoTileGraph || y >= altoTileGraph)
		return -1;

	if (x < 0 || y < 0)
		return -1;

	return x + y * anchoTileGraph;
}