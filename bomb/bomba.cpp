#include "bomba.h"

// Implementação do construtor
Bomba::Bomba(int tempo, int switches, int intervalo, int tempoSub, std::string nome)
    : tempoParaExplodir(tempo), quantidadeSwitches(switches),
      intervaloPiscarLEDs(intervalo), tempoSub(tempoSub), nome(nome) {}

// Implementação do destrutor
Bomba::~Bomba() {}

// Implementação do método para exibir informações
void Bomba::exibirInformacoes() const {
    std::cout << "Tempo para explodir: " << tempoParaExplodir << " segundos" << std::endl;
}