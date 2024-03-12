#pragma once
#include "raylib.h"
#include <stdlib.h>
#include <iostream>

class Collisions{
private:
    int scenecNum;
    int grid[2881];

public:
    Collisions();  //Constructor 

    int testColision(Vector2 pos, int scene);
    void setInGrid(int x, int y, int set, int cena);

    void loadGrid();
    void unloadGrid();

};