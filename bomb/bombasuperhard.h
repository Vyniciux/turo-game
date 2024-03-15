#ifndef BOMBASUPERHARD_H
#define BOMBASUPERHARD_H

#include "bomba.h"

class BombaSuperHard : public Bomba {
public:
    // Construtor
    BombaSuperHard();

    bool acionarSwitch(std::vector<char>& teclasPossiveis, char tecla);
    
    void iniciaJogo();
};

#endif // BOMBASUPERHARD_H
