#ifndef BOMBASUPERHARD_H
#define BOMBASUPERHARD_H

#include "bomba.h"

class BombaSuperHard : public Bomba {
public:
    // Construtor
    BombaSuperHard();

    bool acionarSwitch(std::vector<char>& teclasPossiveis, char tecla) override;

    // Sobrescrita do método desarmada
    bool desarmada() const override;
    
    void jogo();
};

#endif // BOMBASUPERHARD_H
