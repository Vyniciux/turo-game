#ifndef BOMBAHARD_H
#define BOMBAHARD_H

#include "bomba.h"

class BombaHard : public Bomba {
public:
    // Construtor
    BombaHard();

    bool acionarSwitch(std::vector<char>& teclasPossiveis, char tecla);
    
    void iniciaJogo();
};

#endif // BOMBAHARD_H
