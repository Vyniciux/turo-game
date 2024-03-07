#pragma once
#include "raylib.h"
#include "collisions.h"

class Player{
private:
    Texture2D playerImgs[4];
    int framesCounter; //Contagem de frames
    int frame; //Sprite em que o personagem se encontra

    Vector2 currLocation; //Posição x e y do porsonagem
    Vector2 oldLocation;
    int currMov; //Posições right, left, up, donw
    float speed; //Velocidade do personagem

    Collisions colisoes; //Objeto para colisões

public:
    Player(int posX, int PosY, int pos, int speed);
    
    void playerMovement(); //Define a movimentaão do personagem

    void drawPlayer();  //Desenha o personagem na tela
    void unloadPlayer();

    //Setters
    void setOldLoc(Vector2 loc);
    void setCurrLoc(int x, int y);
    void setCurrMov(int mov);
    void setFrameCounter(int fcnt);
    void setFrame(int frm);

    //Getters
    int getFrame();
    int getFrameCounter();
    Vector2 getCurrLoc();
    int getcurrMov();
    float getSpeed();
};