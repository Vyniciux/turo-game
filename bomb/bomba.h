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
    bool acionarSwitch(std::vector<char>& teclasPossiveis, char tecla);

    // Método para iniciar o jogo
    void iniciaJogo();

    // Método para exibir informações sobre a bomba
    void exibirInformacoes() const;

    // Retorna o número de switchs
    int getSwitch();
};

#endif // BOMBA_H
