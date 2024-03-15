#include "bombaeasy.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>
#include <omp.h>
#include <random>

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
    }else{
        tempoParaExplodir -= tempoSub;
        return false;
    }
}

// Método para iniciar o jogo da bomba
void BombaEasy::iniciaJogo() {
    std::cout << nome << std::endl;
    int count = 1;
    char teclaLida;

    std::vector<char> teclasPossiveis;
    for (char letra = 'a'; letra <= 'z'; ++letra) {
        teclasPossiveis.push_back(letra);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(teclasPossiveis.begin(), teclasPossiveis.end(), g);

    teclasPossiveis.resize(quantidadeSwitches);

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                while (tempoParaExplodir > 0 && !teclasPossiveis.empty()) {
                    exibirInformacoes();
                    if (count == 1 || count == intervaloPiscarLEDs){
                        std::cout << "Pressione as teclas: ";
                        for (auto tecla : teclasPossiveis) {
                            std::cout << tecla << " ";
                        }
                        std::cout << std::endl;
                        intervaloPiscarLEDs += intervaloPiscarLEDs;
                    }

                    count++;
                    tempoParaExplodir--;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }

                // Verifica se a bomba foi desarmada ou explodiu
                if (tempoParaExplodir > 0 && teclasPossiveis.empty()) {
                    std::cout << "Bomba desarmada!" << std::endl;
                } else{
                    std::cout << "A bomba explodiu!" << std::endl;
                }
            }
            #pragma omp section
            {
                while(tempoParaExplodir > 0 && !teclasPossiveis.empty()){
                    std::cin >> teclaLida;
                    if(acionarSwitch(teclasPossiveis, teclaLida)){
                        std::cout << "Cortou o fio certo!" << std::endl;
                    }else{
                        std::cout << "Cuidado! Fio errado!" << std::endl;
                    }
                }
            }
        }
    }
}
