#pragma once
#include "raylib.h"
#include <stdlib.h>
#include <iostream>
#include <random>
#include "bomb.h"

class Bomb{

    private:
        int tempo;
        int switches;
        int intervalo;
        bool fios[8];
        bool pushed[8];


    public:
        int drawBomb(int* frameCounter);
        void setBomb(int d);
        void randomFios();
        void pressed();
    
};