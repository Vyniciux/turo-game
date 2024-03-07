#include "map.h"

Map::Map(){
    mapWidth = 680;
    mapHeight = 440;
}

void Map::drawMap(){
    DrawTexture(map, 0, 0, RAYWHITE);
}

void Map::drawFrontlayer(){
    DrawTexture(frontMap, 0, 0, RAYWHITE);
}

void Map::unloadMaps(){
    UnloadTexture(frontMap);
    UnloadTexture(map);
}

//Setters

void Map::setMap(const char* mapImg, const char* frontMapImg){
    map = LoadTexture(mapImg);
    frontMap = LoadTexture(frontMapImg);
}

//Getters
Texture2D Map::getMap(){
    return map;
}

Texture2D Map::getFrontMap(){
    return frontMap;
}