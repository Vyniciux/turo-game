#include "scenes.h"

void Scenes::pauseScreen(Map* maps, Player turo){
    camera.target = (Vector2){ turo.getCurrLoc().x + 20, turo.getCurrLoc().y + 20 };
    BeginMode2D(camera);
    maps[currentScene].drawMap();
    turo.drawPlayer();
    maps[currentScene].drawFrontlayer();
    EndMode2D();
    DrawRectangle(-screenWidth*2,-screenHeight*2,screenWidth*4,screenHeight*4,CLITERAL(Color){250,250,250,100});
    DrawText("Pausado", 264, 200, 100, BLACK);
}

Scenes::Scenes(int scenesNum, const int screenW, const int screenH, Player turo){  
    screenWidth = screenW;
    screenHeight = screenH;
    currentScene = 0;
    currentState = 0;

    scenesNumber = scenesNum;
    
    menuImg = LoadTexture("./assets/player/turo.png");

    camera = { 0 };
    camera.target = (Vector2){ turo.getCurrLoc().x + 20.0f, turo.getCurrLoc().y + 20.0f };
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 3.5f;
}

void Scenes::drawScenes (Map* maps, Player turo){

    switch (currentScene){

        case 0:{
            ClearBackground(BLACK);
            maps[currentScene].drawMap();
            turo.drawPlayer();
            maps[currentScene].drawFrontlayer();
            break;
        }

        case 1:{

            ClearBackground(RED);
            DrawText("cena 1, bem vindo", 120, 150, 35, WHITE);
            break;
        }

        case 2:{

            ClearBackground(WHITE);
            DrawText("cena 2, bem vindo", 120, 150, 35, WHITE);
            break;
        }
        
        case 3:{

            ClearBackground(BLUE);
            DrawText("Cena 3, bem vindo", 120, 150, 35, WHITE);
            break;
        }

        default:{
            
            ClearBackground(BLACK);
            DrawText("Cena não encontrada, bugou!", 120, 150, 35, WHITE);
            break;
        }
    }


}

void Scenes::sceneControl(Map* maps, Player turo){

    switch (currentState)
    {
        case 0:{

            displayMenu();

            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)){
                //unloadImg(menuImg);
                currentState = 1;
            }
            break;
        }

        case 1:{
            camera.target = (Vector2){ turo.getCurrLoc().x + 20, turo.getCurrLoc().y + 20 };
            BeginMode2D(camera);
            drawScenes(maps, turo);
            //std::cout << "Jogango\n";

            
            if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_P))
                currentState = 2;

            //colisao(v,grid);

            if(turo.getFrameCounter()>10){
                turo.setFrameCounter(0);
                turo.setFrame(turo.getFrame() + 1);
                if(turo.getFrame() > 3){
                    turo.setFrame(0);
                }
            }
            EndMode2D();
            
        }
            break;

        case 2:{
            pauseScreen(maps, turo);
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_P))
                currentState = 1;

            break;
        }

        default:{
            if (IsKeyPressed(KEY_ENTER))
                currentScene = 0;
            break;
        }     
    }
    
}

void Scenes::displayMenu(){
    ClearBackground(DARKGREEN);
    DrawText("Bem vindo ao Turo's Adventure", 200, 150, 35, LIGHTGRAY);
    DrawText("Pressione enter para jogar", 250, 230, 30, LIGHTGRAY);
    DrawTexture(menuImg, 290, 300, WHITE);
}

void Scenes::unloadImg(Texture2D Img){
    UnloadTexture(Img);
}

void Scenes::loadMapScene(int index, Texture2D mapScene){
    scenes[index] = mapScene;
}

void Scenes::unloadAllScenes(Map* maps){
    for(int i=0; i<4; i++)
        maps[i].unloadMaps();
}


//Setters

//Getters
int Scenes::getCurrScene(){
    return currentScene;
}

int Scenes::getCurrState(){
    return currentState;
}