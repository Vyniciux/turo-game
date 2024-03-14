#ifndef BOMBAMEDIUM_H
#define BOMBAMEDIUM_H

#include "bomba.h"

class BombaMedium : public Bomba {
public:
    // Construtor
    BombaMedium();

    bool acionarSwitch(std::vector<char>& teclasPossiveis, char tecla) override;

    // Sobrescrita do método desarmada
    bool desarmada() const override;
    
    void jogo();
};

#endif // BOMBAMEDIUM_H
