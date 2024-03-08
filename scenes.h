#pragma once
#include "raylib.h"
#include "map.h"
#include "player.h"
#include <iostream>

//Define toda a mudança de telas

class Scenes{
private:
    int screenWidth;
    int screenHeight;
    int currentScene;
    int currentState;
    int scenesNumber;   //Quantidade de cenas ou mapas

    Texture2D scenes[3];
    Texture2D menuImg;
    Camera2D camera;
    Font font;
public:
    Scenes(const int scenesNum, const int screenW, const int screenH, Player turo);
    void drawScenes(Map* maps, Player Turo); //Desenha os mapas 
    void sceneControl(Map* maps, Player Turo);
    void displayMenu();
    void unloadImg(Texture2D Img);
    void loadMapScene(int index, Texture2D mapScene);
    void pauseScreen(Map* maps, Player turo);               //Desenha a tela de Pause

    void unloadAllScenes(Map* maps);

    //Setters


    //Getters
    int getCurrScene();
    int getCurrState();
};