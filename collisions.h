#pragma once
#include "raylib.h"
#include <stdlib.h>
#include <iostream>

class Collisions{
private:
    int scenecNum;
    short grid[2881];

public:
    Collisions();  //Constructor 

    int testColision(Vector2 pos, int scene);

    void loadGrid();
    void unloadGrid();

};