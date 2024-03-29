#include "scenes.h"

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

void Scenes::drawScenes (Map* maps){

    ClearBackground(BLACK);
    maps[currentScene].drawMap();
    turo->drawPlayer();
    maps[currentScene].drawFrontlayer();

    switch (currentScene){

        case 0:{

            switch (colisoes->testColision(turo->getCurrLoc(),currentScene)){
                case 0:{
                    break;
                }
                case 1:{
                        turo->backMov();
                    break;
                }
                case 2:{
                    colisoes->setInGrid(turo->getCurrLoc().x,turo->getCurrLoc().y,0,currentScene);
                    drawDialogue(historyImg[0],"Varias bombas foram instaladas \n\n\nna floresta na noite passada \n\n\nouviu-se que podem destruir a \n\n\nfloresta inteira! Se apresse!");
                    break;
                }
                case 3:{
                    currentScene=1;
                    turo->setCurrLoc(330,400);
                    turo->setCurrMov(2);
                    drawDialogue(historyImg[1],"Esta escuro demais nesse tunel \n\n\ntome cuidado!");
                    break;
                }
                case 4:{
                    colisoes->setInGrid(turo->getCurrLoc().x,turo->getCurrLoc().y,0,currentScene);
                    drawDialogue(historyImg[2],"A passagem por aqui esta\n\n\nbloqueada, arrudei.");
                    break;
                }
                case 5:{
                    colisoes->setInGrid(turo->getCurrLoc().x,turo->getCurrLoc().y,0,currentScene);
                    bomba.setBomb(10);
                    currentState = 4;
                    break;
                }
                case 6:{
                    currentScene=5;
                    turo->setCurrLoc(390,270);
                    turo->setCurrMov(2);
                    break;
                }
                case 7:{
                    currentScene=3;
                    turo->setCurrLoc(290,310);
                    turo->setCurrMov(2);
                    break;
                }
                case 8:{
                    currentScene=4;
                    turo->setCurrLoc(300,280);
                    turo->setCurrMov(2);
                    break;
                }
                case 9:{
                    currentScene=2;
                    turo->setCurrLoc(310,300);
                    turo->setCurrMov(2);
                    break;
                }
		case 10:{
		    currentScene=1;
		    turo->setCurrLoc(650,30);
		}
                
                default:
                    break;
                }
            break;
        }

        case 1:{
            
            switch (colisoes->testColision(turo->getCurrLoc(),currentScene)){
                case 0:{
                    break;
                }
                case 1:{
                    turo->backMov();
                    break;
                }     
                case 2:{
                    currentScene=0;
                    turo->setCurrLoc(200,410);
                    turo->setCurrMov(0);
                    break;
                }
                case 3:{
                    currentScene=4;
                    turo->setCurrLoc(290,220);
                    turo->setCurrMov(0);
                    break;
                }
                case 4:{
                    currentScene=0;
                    turo->setCurrLoc(540,100);
                    turo->setCurrMov(0);
                    break;
                }
                    case 5:{
                    colisoes->setInGrid(350,230,0,currentScene);
                    colisoes->setInGrid(360,230,0,currentScene);
                    drawDialogue(historyImg[3],"Voce ouve um barulho de explosao \n\n\ne gritos vindo da superficie.");
                    break;
                }
                default:
                    break;
                }
            break;
        }

        case 2:{

             switch (colisoes->testColision(turo->getCurrLoc(),currentScene)){
                case 0:{
                    break;
                }
                case 1:{
                    turo->backMov();
                    break;
                }
                
                case 2:{
                    currentScene=0;
                    turo->setCurrLoc(43,390);
                    turo->setCurrMov(2);
                    break;
                }

                default: break;
            }

            break;
        }
        
        case 3:{

            switch (colisoes->testColision(turo->getCurrLoc(),currentScene)){
                case 0:{
                    break;
                }
                case 1:{
                    turo->backMov();
                    break;
                }
                case 2:{
                    currentScene=0;
                    turo->setCurrLoc(620,100);
                    turo->setCurrMov(2);
                    break;
                }
                default: break;
            }

            break;
        }

        case 4:{

            switch (colisoes->testColision(turo->getCurrLoc(),currentScene)){
                case 0:{
                    break;
                }
                case 1:{
                    turo->backMov();
                    break;
                }
                case 2:{
                    currentScene=0;
                    turo->setCurrLoc(70,110);
                    turo->setCurrMov(3);
                    break;
                }
                case 3:{
                    currentScene=1;
                    turo->setCurrLoc(30,160);
                    turo->setCurrMov(0);
                    break;
                }
                default: break;
            }

            break;
        }
      
        case 5:{

            switch (colisoes->testColision(turo->getCurrLoc(),currentScene)){
                case 0:{
                    break;
                }
                case 1:{
                    turo->backMov();
                    break;
                }
                case 2:{
                    colisoes->setInGrid(turo->getCurrLoc().x,turo->getCurrLoc().y,0,currentScene);
                    drawDialogue(historyImg[6],"Todos fugiram mais eu fiquei \n\n\naqui cuidando dos animais\n\n\neles tem muito medos \n\n\ndas explosoes.");
                    break;
                }
                case 3:{
                    currentScene=0;
                    turo->setCurrLoc(600,390);
                    turo->setCurrMov(2);
                }
                default: break;
            }

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
            
            if(framesCounter<n)t[framesCounter+1]=0;
 
            DrawTexture(showNow,330,30,WHITE);

            for(unsigned int i = 0; i < framesCounter && (int)i < n; i++){
               t[i]=text[i];
            }
            
            DrawTextEx(font,t,{20,360},35,5,WHITE);

            if(framesCounter>n){
                
                if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_P)){
                    currentState = 1;
                }
            }

            break;
        }

        case 4:{ //Tela de Bomba
 
            int estadoBomba = bomba.drawBomb(&framesCounter);
            
            switch (estadoBomba){

                case 0:{  //Jogo continua
                    break;
                }
            
                case 1:{ //Ganhou 
                    currentState = 1;
                    drawDialogue(historyImg[5],"Voce consegui destruir a bomba!!!");
                    break;
                }
                case 2:{ //Perdeu!
                    currentState = 0;
		    currentScene = 0;
                    std::cout << "Você perdeu\n";
                    drawDialogue(historyImg[4],"Voce nao conseguiu destruir a \n\n\nbomba, mas lutou baravamente, \n\n\ndescance um pouco guerreiro.");
		    colisoes->loadGrid();
                    turo->setCurrLoc(333,252);
		    turo->setCurrMov(3);

                    break;
                }
               
                default:
                    break;
            }
            
            framesCounter++;
            
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
    historyImg[3]= LoadTexture("assets/images/himg4.png");
    historyImg[4]= LoadTexture("assets/images/himg5.png");
    historyImg[5]= LoadTexture("assets/images/himg6.png");
    historyImg[6]= LoadTexture("assets/images/himg7.png");

}

void Scenes::UnloadImages(){

    for (int i = 0; i < 6; i++)
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
