#pragma once
#include "raylib.h"
#include <iostream>

class Map{
private:
    int mapWidth;
    int mapHeight;
    Texture2D map;
    Texture2D frontMap; //Esse é o mapa que fica por cima do personagem
public:
    Map();  //Constructor para inicializar a informações básicas do mapa

    void drawMap(); //Denham o mapa de fundo
    void drawFrontlayer();  //Desenham a camada do mapa que fica por cima do personagem

    void mainGrid();
    void unloadMaps();

    //Setters
    void setMap( const char* mapImg, const char* frontMapImg);

    //Getters
    Texture2D getFrontMap();
    Texture2D getMap();
};