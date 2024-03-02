#ifndef PLAYER
#define PLAYER

#include "raylib.h"

#define right 0
#define left 1
#define up 2
#define down 3

const int screenWidth = 960;
const int screenHeight = 540;

typedef struct gameVars //Oganiza as variáveis jogo para ficar mais fácil de trabalhar
{
    int cenaAtual; //Qual mapa do jogo atualmente
    int estado; //Estados >> 0:inicio ; 1:Jogando ; 2:pausado

    int framesCounter; //Contagem de frames
    int frame; //Sprite em que o personagem se encontra

    Vector2 posicao; //Posição x e y do porsonagem
    Vector2 oldPosicao;
    int sPod; //Posições right, left, up, donw
    float speed; //Velocidade do personagem

}gameVars;

void controle(gameVars* v, int*** grid); //Serve pra organizar os controles
void drawPlayer(gameVars* v, Texture2D* playerTex); //Desenha o personagem
void colisao(gameVars* v, int*** grid); //Controlas as colisões == não implementado
int*** loadGrid(int nCenas); //Carregando o grid de colisões

#endif


