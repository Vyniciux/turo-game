#include "scenes.h"

void Scenes::pauseScreen(Map* maps, Player turo){
    camera.target = (Vector2){ turo.getCurrLoc().x + 20, turo.getCurrLoc().y + 20 };
    BeginMode2D(camera);
    maps[currentScene].drawMap();
    turo.drawPlayer();
    maps[currentScene].drawFrontlayer();
    EndMode2D();
    DrawRectangle(-screenWidth*2,-screenHeight*2,screenWidth*4,screenHeight*4,CLITERAL(Color){250,250,250,100});
    DrawTextEx(font,"Pausado",{220,220},100,8,BLACK);
}

Scenes::Scenes(int scenesNum, const int screenW, const int screenH, Player turo, Collisions *col){  
    screenWidth = screenW;
    screenHeight = screenH;
    currentScene = 0;
    currentState = 0;

    scenesNumber = scenesNum;
    
    colisoes = col;

    menuImg = LoadTexture("./assets/player/turo.png");
    font = LoadFont("assets/fonts/SuperMario256.ttf");
    loadImages();

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
            
            if (colisoes->testColision(turo.getCurrLoc(),currentScene)==2)
            {
                colisoes->setInGrid(turo.getCurrLoc().x,turo.getCurrLoc().y,0,currentScene);
                drawDialogue(historyImg[0],"Varias bombas foram instaladas na \n\n\nfloresta na noite passada ouviu-se \n\n\nque a maior esta no rancho e pode \n\n\ndestruir a floresta inteira!");
                
            }
            

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

        case 3:{

            ClearBackground(BLACK);
            framesCounter++;

            //std::cout << framesCounter << "\n";
            int n = strlen(text);
            char t[n+1];
            t[n]=0;
            if(framesCounter<(unsigned int)n)t[framesCounter+1]=0;
 
            DrawTexture(showNow,330,30,WHITE);

            for(unsigned int i = 0; i < framesCounter && (int)i < n; i++)
            {
               t[i]=text[i];
            }
            
            DrawTextEx(font,t,{20,360},35,5,WHITE);

            if(framesCounter>100){
                
                if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_P)){
                    currentState = 1;
                    framesCounter = 0;
                }
            }

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
    DrawTextEx(font,"Turo's Adventure", {130, 190}, 60, 5, LIGHTGRAY);
    DrawTextEx(font,"Pressione enter para jogar", {170, 270}, 30, 5, LIGHTGRAY);
    DrawTexture(menuImg, 330, 340, WHITE);
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

void Scenes::drawDialogue(Texture2D img, const char* texto){ 
    text = texto;
    framesCounter = 0;  
    currentState = 3;    
    showNow = img;        
}

void Scenes::loadImages(){

    historyImg[0]= LoadTexture("assets/images/himg1.png");
    //historyImg[1]=
    //historyImg[2]=
}

void Scenes::UnloadImages(){

    for (int i = 0; i < 3; i++)
    {
        UnloadTexture(historyImg[i]);
    }
    
}

//Setters

//Getters
int Scenes::getCurrScene(){
    return currentScene;
}

int Scenes::getCurrState(){
    return currentState;
}