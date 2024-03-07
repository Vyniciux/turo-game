#include "player.h"

#define right 0
#define left 1
#define up 2
#define down 3

Player::Player(int posX, int PosY, int pos, int spd){
    framesCounter = 0;
    frame = 0;

    currLocation.x = (float)posX ;
    currLocation.y = (float)PosY;
    currMov = pos;
    speed = spd;

    playerImgs[0] = LoadTexture("./assets/player/right-Sheet.png");
    playerImgs[1] = LoadTexture("./assets/player/left-Sheet.png");
    playerImgs[2] = LoadTexture("./assets/player/up-Sheet.png");
    playerImgs[3] = LoadTexture("./assets/player/down-Sheet.png");

    Collisions colisoes();

}

void Player::playerMovement(){
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        oldLocation = currLocation;
        currLocation.x -= speed;
        framesCounter += speed; 
        currMov = left;

    }
    else if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
        oldLocation = currLocation;
        currLocation.y -= speed;
        framesCounter += speed; 
        currMov = up;
    }
    else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)){
        oldLocation = currLocation;
        currLocation.y += speed;
        framesCounter += speed; 
        currMov = down;
    }
    else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
        oldLocation = currLocation;
        currLocation.x += speed;
        framesCounter += speed; 
        currMov = right;
    }else{

        frame=0; //Voltar a ficar parado quando parar de andar
    }

    if((colisoes.testColision(currLocation,1))!=0){
        currLocation = oldLocation;
    }

    if(framesCounter > 10){
        framesCounter = 0;
        frame += 1;
        if(frame > 3){
            frame=0;
        }
    }    
}

void Player::drawPlayer(){
    DrawTextureRec(playerImgs[currMov],{(float)(frame*playerImgs[currMov].width/4), 0.0f, (float)playerImgs[currMov].width/4, (float)playerImgs[currMov].height }, currLocation ,RAYWHITE);

}

void Player::unloadPlayer(){
    for(int i=0; i<4; i++)
        UnloadTexture(playerImgs[i]);
}

//Getters

    int Player::getFrame(){
        return frame;
    }

    int Player::getFrameCounter(){
        return framesCounter;
    }

    Vector2 Player::getCurrLoc(){
        return currLocation;
    }

    int Player::getcurrMov(){
        return currMov;
    }
    
    float Player::getSpeed(){
        return speed;
    }

//Setters

    void Player::setOldLoc(Vector2 loc){
        oldLocation = loc;
    }

    void Player::setCurrLoc(int x, int y){
        currLocation.x = x;
        currLocation.y = y;
    }

    void Player::setCurrMov(int mov){
        currMov = mov;
    }

    void Player::setFrameCounter(int fcnt){
        framesCounter = fcnt;
    }

    void Player::setFrame(int frm){
        frame = frm;
    }