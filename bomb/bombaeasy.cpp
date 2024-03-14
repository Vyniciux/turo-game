#include "bombaeasy.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>

// Construtor da classe BombaEasy
BombaEasy::BombaEasy() : Bomba(75, 6, 8, 10, "Bomba Easy") {}

// Método para acionar um switch (ou tecla)
bool BombaEasy::acionarSwitch(std::vector<char>& teclasPossiveis, char tecla) {
    // Verifica se a tecla pressionada está na lista de teclas possíveis
    auto it = std::find(teclasPossiveis.begin(), teclasPossiveis.end(), tecla);

    // Se a tecla estiver na lista, remove-a e retorna verdadeiro
    if (it != teclasPossiveis.end()) {
        teclasPossiveis.erase(it);
        return true;
    }

    // Se a tecla não estiver na lista, retorna falso
    return false;
}

// Método para verificar se a bomba foi desarmada
bool BombaEasy::desarmada() const {
    return tempoParaExplodir <= 0;
}

// Método para iniciar o jogo da bomba
void BombaEasy::jogo() {
    char teclaPressionada;
    exibirInformacoes();
    int count = 1;

    // Inicializa o jogo...
    std::vector<char> teclasPossiveis;
    for (char tecla = 'a'; tecla < 'a' + quantidadeSwitches; ++tecla) {
        teclasPossiveis.push_back(tecla);
    }
    std::random_shuffle(teclasPossiveis.begin(), teclasPossiveis.end());

    exibirInformacoes();
    while (!desarmada() && tempoParaExplodir > 0 && !teclasPossiveis.empty()) {
        if (count == 1 || count == intervaloPiscarLEDs){
            std::cout << "Pressione as teclas: ";
            for (auto tecla : teclasPossiveis) {
                std::cout << tecla << " ";
            }
            std::cout << std::endl;
            intervaloPiscarLEDs += intervaloPiscarLEDs;
        }

        // Verifica se alguma tecla foi pressionada
        std::cout << "Digite a tecla pressionada: ";
        std::cin >> teclaPressionada;

        // Aciona o switch correspondente
        if (!acionarSwitch(teclasPossiveis, teclaPressionada)) {
            std::cout << "Tecla incorreta! -" << tempoSub << " segundos" << std::endl;
            tempoParaExplodir -= tempoSub;
        }

        count++;
        teclaPressionada = ' ';
        tempoParaExplodir--;
    }

    // Verifica se a bomba foi desarmada ou explodiu
    if (desarmada()) {
        std::cout << "Bomba desarmada!" << std::endl;
    } else {
        std::cout << "A bomba explodiu!" << std::endl;
    }
}
