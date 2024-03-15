#include "bombaeasy.h"
#include "bombamedium.h"
#include "bombahard.h"
#include "bombasuperhard.h"

int main() {
    // Bomba Easy
    BombaEasy bomba_easy;
    std::cout << "Teste Bomba Easy:" << std::endl;
    bomba_easy.iniciaJogo();
    std::cout << std::endl;

    // Bomba Medium
    BombaMedium bomba_medium;
    std::cout << "Teste Bomba Medium:" << std::endl;
    bomba_easy.iniciaJogo();
    std::cout << std::endl;

    // Bomba Hard
    BombaHard bomba_hard;
    std::cout << "Teste Bomba Hard:" << std::endl;
    bomba_hard.iniciaJogo();
    std::cout << std::endl;

    // Bomba Super Hard
    BombaSuperHard bomba_super_hard;
    std::cout << "Jogo da Bomba Super Hard:" << std::endl;
    bomba_super_hard.iniciaJogo();
    std::cout << std::endl;

    return 0;
}
