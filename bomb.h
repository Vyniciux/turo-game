#pragma once
#include "raylib.h"
#include <stdlib.h>
#include <iostream>
#include <random>
#include "bomb.h"


class Bomb{

    private:
	int time;
        int tempo;
        int switches;
        int intervalo;
        bool fios[18];
        bool pushed[18];

    public:
        int drawBomb(int* frameCounter);
        void setBomb(int d);
        void randomFios();
        void pressed();
        void drawTela();
    
};
