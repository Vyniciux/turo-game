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

Scenes::Scenes(int scenesNum, const int screenW, const int screenH,Player *Turo, Collisions *col){  
    screenWidth = screenW;
    screenHeight = screenH;
    currentScene = 0;
    currentState = 0;

    scenesNumber = scenesNum;
    turo = Turo;
    colisoes = col;

    menuImg = LoadTexture("./assets/player/turo.png");
    font = LoadFont("assets/fonts/SuperMario256.ttf");
    loadImages();

    camera = { 0 };
    camera.target = (Vector2){ turo->getCurrLoc().x + 20.0f, turo->getCurrLoc().y + 20.0f };
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 3.5f;
}

void Scenes::drawScenes (Map* maps){

    ClearBackground(BLACK);
    maps[currentScene].drawMap();
    turo->drawPlayer();
    maps[currentScene].drawFrontlayer();

    switch (currentScene){

        case 0:{

            switch (colisoes->testColision(turo->getCurrLoc(),currentScene)){
                case 2:{
                    colisoes->setInGrid(turo->getCurrLoc().x,turo->getCurrLoc().y,0,currentScene);
                    drawDialogue(historyImg[0],"Varias bombas foram instaladas na \n\n\nfloresta na noite passada ouviu-se \n\n\nque a maior esta no rancho e pode \n\n\ndestruir a floresta inteira!");
                    break;
                }
                case 3:{
                    currentScene=1;
                    turo->setCurrLoc(200,200);
                    drawDialogue(historyImg[1],"Esta escuro demais nesse tunel \n\n\ntome cuidado!");
                    break;
                }
                case 4:{
                    colisoes->setInGrid(turo->getCurrLoc().x,turo->getCurrLoc().y,0,currentScene);
                    drawDialogue(historyImg[2],"Voce escuta um forte barulho \n\n\nde explosao e corre para saber \n\n\ndo que se trata.");
                }
                
                default:
                    break;
                }
            break;
        }

        case 1:{

            ClearBackground(RED);
            DrawText("cena 1, bem vindo", 120, 150, 35, BLACK);
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

void Scenes::sceneControl(Map* maps){

    switch (currentState){

        case 0:{ //Menu principal

            displayMenu();

            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)){
                currentState = 1;
            }

            break;
        }

        case 1:{ //Rodando

            turo->playerMovement();

            camera.target = (Vector2){ turo->getCurrLoc().x + 20, turo->getCurrLoc().y + 20 };
            BeginMode2D(camera);

            if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_P)) currentState = 2;

            turo->drawPlayer();

            drawScenes(maps);

            EndMode2D();
            break;
        }        

        case 2:{ //Tela de pausa

            pauseScreen(maps, *turo);
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_P)) currentState = 1;

            break;
        }

        case 3:{ //Tela de diálogos

            ClearBackground(BLACK);
            framesCounter++;

            int n = strlen(text);

            char t[n+1]; t[n]=0;
            
            if(framesCounter<(unsigned int)n)t[framesCounter+1]=0;
 
            DrawTexture(showNow,330,30,WHITE);

            for(unsigned int i = 0; i < framesCounter && (int)i < n; i++){
               t[i]=text[i];
            }
            
            DrawTextEx(font,t,{20,360},35,5,WHITE);

            if(framesCounter>n){
                
                if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_P)){
                    currentState = 1;
                    framesCounter = 0;
                }
            }

            break;
        }
        
        default:{

            if (IsKeyPressed(KEY_ENTER))currentScene = 0;
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
    historyImg[1]= LoadTexture("assets/images/himg2.png");
    historyImg[2]= LoadTexture("assets/images/himg3.png");

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