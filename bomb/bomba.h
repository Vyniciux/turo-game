#ifndef BOMBA_H
#define BOMBA_H

#include <iostream>
#include <string>
#include <vector>

class Bomba {
protected:
    int tempoParaExplodir;
    int quantidadeSwitches;
    int intervaloPiscarLEDs; 
    int tempoSub;
    std::string nome; 

public:
    // Construtor
    Bomba(int tempo, int switches, int intervalo, int tempoSub, std::string nome);

    // Destrutor 
    virtual ~Bomba();

    // Método para acionar um switch
    virtual bool acionarSwitch(std::vector<char>& teclasPossiveis, char tecla) = 0;

    // Método para iniciar o jogo
    virtual void jogo() = 0;

    // Método para verificar se a bomba foi desarmada
    virtual bool desarmada() const = 0;

    // Método para exibir informações sobre a bomba
    void exibirInformacoes() const;
};

#endif // BOMBA_H
