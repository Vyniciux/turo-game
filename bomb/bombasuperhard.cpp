#include "bombasuperhard.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>

// Construtor da classe BombaSuperHard
BombaSuperHard::BombaSuperHard() : Bomba(55, 12, 17, 25, "Bomba Super Hard") {}

// Método para acionar um switch (ou tecla)
bool BombaSuperHard::acionarSwitch(std::vector<char>& teclasPossiveis, char tecla) {
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
bool BombaSuperHard::desarmada() const {
    return tempoParaExplodir <= 0;
}

// Método para iniciar o jogo da bomba
void BombaSuperHard::jogo() {
    // Chama o método da classe base para exibir informações sobre a bomba
    exibirInformacoes();

    // Inicializa o jogo...
    std::vector<char> teclasPossiveis;
    for (char tecla = 'a'; tecla < 'a' + quantidadeSwitches; ++tecla) {
        teclasPossiveis.push_back(tecla);
    }
    std::random_shuffle(teclasPossiveis.begin(), teclasPossiveis.end());

    while (!desarmada() && tempoParaExplodir > 0 && !teclasPossiveis.empty()) {
        // Piscar todas as teclas
        for (char tecla : teclasPossiveis) {
            std::cout << "Piscando tecla '" << tecla << "'" << std::endl;
        }

        // Aguarda o intervalo de piscar dos LEDs
        std::this_thread::sleep_for(std::chrono::seconds(intervaloPiscarLEDs));

        // Verifica se alguma tecla foi pressionada
        char teclaPressionada;
        std::cout << "Digite a tecla pressionada: ";
        std::cin >> teclaPressionada;

        // Aciona o switch correspondente
        if (!acionarSwitch(teclasPossiveis, teclaPressionada)) {
            std::cout << "Tecla incorreta! -" << tempoSub << " segundos" << std::endl;
            tempoParaExplodir -= tempoSub;
        }
    }

    // Verifica se a bomba foi desarmada ou explodiu
    if (desarmada()) {
        std::cout << "Bomba desarmada!" << std::endl;
    } else {
        std::cout << "A bomba explodiu!" << std::endl;
    }
}
