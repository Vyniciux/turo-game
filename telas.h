#ifndef TELA
#define TELA

#include "player.h"
#include "raylib.h"

void drawCena(gameVars* v, Texture2D* cenas); //Desenha os mapas 
void drawEstado(gameVars* v,  Texture2D* iconsTex); //Desenhas as telas ex: tela inicial, pausado. Define estados do jogo

void loadCenasText(Texture2D* cenas); //Carregas os mapas do jogo
void loadPlayerText(Texture2D* player); //Carrega o sprite do personagem

void unloadCenasText(Texture2D* cenas, int nCenas); //Descarrega os mapas do jogo
void unloadPlayerText(Texture2D* player); //Descarrega o sprite do personagem

void loadIconsText(Texture2D* cenas); //Carregas os mapas do jogo
void loadIconsText(Texture2D* player); //Carrega o sprite do personagem


#endif