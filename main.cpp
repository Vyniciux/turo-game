#include "raylib.h"
#include "telas.h"
#include "player.h"
#include <stdio.h>

using namespace std;

const int nCenas = 1;

int main(void)
{
// Inicializando recursos ---------------------------------------------------------------------------------------

    gameVars v;

    v.cenaAtual = 0;
    v.estado = 0;

    v.framesCounter = 0;
    v.frame = 0;

    v.posicao.x = 128;
    v.posicao.y = 380;
    v.sPod = right;
    v.speed = 2;

    int*** grid= loadGrid(nCenas);

//---------------------------------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "Turo's Adventure");

// Inicializando texturas ---------------------------------------------------------------------------------------
   
    Texture2D cenasTex [nCenas];
    loadCenasText(cenasTex);

    Texture2D playerTex [4];
    loadPlayerText(playerTex);

    Texture2D iconsTex [1];
    loadIconsText(iconsTex);

// --------------------------------------------------------------------------------------------------------------

    Camera2D camera = { 0 };
    camera.target = (Vector2){ v.posicao.x + 20.0f, v.posicao.y + 20.0f };
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 3.5f;

    SetTargetFPS(30);    

    while (!WindowShouldClose()){

        BeginDrawing();


            if(v.estado==1){

                camera.target = (Vector2){ v.posicao.x + 20, v.posicao.y + 20 };
                BeginMode2D(camera); 

                drawCena(&v,cenasTex); //Cenas são os mapas, desenha os mapas
                drawPlayer(&v,playerTex); //Desenha o personagem

                EndMode2D();

                printf("Posiçao x:%.0f y:%.0f      ||      x:%.2f y:%.2f\n",v.posicao.x/10+1,v.posicao.y/10+1,v.posicao.x,v.posicao.y);

            }
            else drawEstado(&v,iconsTex); //Estado são telas como inicio, pausado, desenha essas telas
            
            controle(&v,(int***)grid); //Função onde os controles são definidos

        EndDrawing();
        
    }

// Descarregando texturas ----------------------------------------------------------------------------------------

    unloadCenasText(cenasTex, nCenas);
    unloadPlayerText(playerTex);

// ----------------------------------------------------------------------------------------------------------------

    CloseWindow();        

    return 0;
}
