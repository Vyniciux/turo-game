#include "scenes.h"
#include "player.h"
#include "collisions.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
const int screenWidth = 960;
const int screenHeight = 540; 

const int scenesNum = 1;

const int getScreenWidth(){
    return screenWidth;
}

const int getScreenHeight(){
    return screenHeight;
}

int main(void)
{
    
    InitWindow(screenWidth, screenHeight, "Game - IHS");
    Player Turo(333, 252, 3, 1.2);
    Scenes cenas(scenesNum, screenWidth, screenHeight, Turo);
    Map *maps = new Map[scenesNum];
    maps[0].setMap("./assets/map/new_Map.png", "./assets/map/front_layer.png");

    SetTargetFPS(60);
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //std::cout<<cenas.getCurrScene() << "\n";
        BeginDrawing();
        ClearBackground(BLACK);

        if(cenas.getCurrState() == 1){
            Turo.playerMovement();
            std:: cout << "Posição x: " << (int)(Turo.getCurrLoc().x/10)+1 << " || " << "Posição y: " << (int)(Turo.getCurrLoc().y/10)+1 << "\n";
        }

        cenas.sceneControl(maps, Turo);

        EndDrawing();
    }

    Turo.unloadPlayer();
    cenas.unloadAllScenes(maps);
    CloseWindow();

    //UnloadTexture(m);

    return 0;
}