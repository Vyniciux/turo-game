#pragma once
#include "raylib.h"
#include "map.h"
#include "player.h"

#include <string.h>
#include <iostream>

//Define toda a mudança de telas

class Scenes{
private:
    int screenWidth;
    int screenHeight;
    int currentScene;
    int currentState;
    int scenesNumber;   //Quantidade de cenas ou mapas

    Collisions *colisoes;

    Texture2D scenes[10];
    Texture2D menuImg;
    Camera2D camera;
    Font font;

    Player *turo;
    Texture2D historyImg[10]; //Imagens de diálogo
    Texture2D showNow; //Imagem de diálogo atual
    const char* text;// Texto do diálogo
    int framesCounter; //Contar tempo

public:
    Scenes(const int scenesNum, const int screenW, const int screenH, Player *turo, Collisions *col);
    void drawScenes(Map* maps); //Desenha os mapas 
    void sceneControl(Map* maps);
    void displayMenu();
    void unloadImg(Texture2D Img);
    void loadMapScene(int index, Texture2D mapScene);
    void pauseScreen(Map* maps, Player turo);               //Desenha a tela de Pause

    void drawDialogue(Texture2D img, const char* text); //Desenhar o diálogo
    void loadImages(); //Load image de diálogos
    void UnloadImages(); //Unload image de diálogos

    void unloadAllScenes(Map* maps);

    //Setters


    //Getters
    int getCurrScene();
    int getCurrState();
};