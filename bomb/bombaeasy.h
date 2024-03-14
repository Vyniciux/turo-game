#ifndef BOMBAEASY_H
#define BOMBAEASY_H

#include "bomba.h"

class BombaEasy : public Bomba {
public:
    // Construtor
    BombaEasy();

    bool acionarSwitch(std::vector<char>& teclasPossiveis, char tecla) override;

    // Sobrescrita do método desarmada
    bool desarmada() const override;
    
    void jogo();
};

#endif // BOMBAEASY_H