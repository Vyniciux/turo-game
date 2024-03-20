#include "bomb.h"

int Bomb::drawBomb(int* frameCounter){
    
    ClearBackground(BLUE);

   if(*frameCounter>60){
        tempo++;
        *frameCounter=0;
        std:: cout << tempo << " segundos\n";
        
        if(tempo > 60){
            return 2;
        }
    } 

    int c=0;

    for (int i = 0; i < 8; i++){

        if(fios[i]){
            std::cout << "1 ";
        }
        else{
            std::cout << "0 ";
        }
        if(pushed[i]){
            std::cout << "1 \n";
        }
        else{
            std::cout << "0 \n";
        }

        if(fios[i]==pushed[i]){
                        c++;
        }
        if(pushed[i]){ 
            if(!fios[i]){
                return 2;
            }
        }


    }
    if(c==8){
        return 1;
    }   
    std::cout << "\n";
    

    pressed();


    return 0;
}

void Bomb::randomFios(){

    for (int i = 0; i < 8; i++){

        fios[i]= (std::rand())%2;
        if(fios[i]){
            std::cout << "1 ";
        }
        else{
            std::cout << "0 ";
        }
        pushed[i]=0;
    }   
    std::cout << "\n";
}

void Bomb::setBomb(int d){
    randomFios();
    tempo = 0;
    std::cout << "setado \n";
}

void Bomb::pressed(){

    if(IsKeyDown(KEY_Q)){
        pushed[0]=true;
    }
    if(IsKeyDown(KEY_W)){
        pushed[1]=true;
    }
    if(IsKeyDown(KEY_E)){
        pushed[2]=true;
    }
    if(IsKeyDown(KEY_R)){
        pushed[3]=true;
    }
    if(IsKeyDown(KEY_T)){
        pushed[4]=true;
    }
    if(IsKeyDown(KEY_Y)){
        pushed[5]=true;
    }
    if(IsKeyDown(KEY_U)){
        pushed[6]=true;
    }
    if(IsKeyDown(KEY_I)){
        pushed[7]=true;
    }

}
// onstrutor da classe BombaEasy
/*void Bomb::bombaPlay( int a, int b, int c, const char* texto){




    if(tempo>c){
        *Framecounter = 0;
    }

  //ClearBackground(BLUE);
  //std:: cout << tempo << "\n";


    char teclaLida;

    std::vector<char> teclasPossiveis;
    for (char letra = 'a'; letra <= 'z'; ++letra) {
        teclasPossiveis.push_back(letra);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(teclasPossiveis.begin(), teclasPossiveis.end(), g);

    teclasPossiveis.resize(18);


    if (tempo > 0 && !teclasPossiveis.empty()) {
        std::cout << "Tempo para explodir: " << tempo << " segundos" << std::endl;
        
        if (*count == 1 || *count == intervalo){
            std::cout << "Pressione as teclas: ";
            for (auto tecla : teclasPossiveis) {
                std::cout << tecla << " ";
            }
            std::cout << std::endl;
            intervalo += intervalo;
        }

        tempo--;
    }

    // Verifica se a bomba foi desarmada ou explodiu
    if (tempo > 0 && teclasPossiveis.empty()) {
        std::cout << "Bomba desarmada!" << std::endl;
    } else{
        std::cout << "A bomba explodiu!" << std::endl;
        
    }


    while(tempo > 0 && !teclasPossiveis.empty()){
        std::cin >> teclaLida;
        if(acionarSwitch(teclasPossiveis, teclaLida)){
            std::cout << "Cortou o fio certo!" << std::endl;
        }else{
            std::cout << "Cuidado! Fio errado!" << std::endl;
        }
    }
}*/


// onstrutor da classe BombaEasy
/*void Bomb::bombaPlay( int a, int b, int c, const char* texto){




    if(tempo>c){
        *Framecounter = 0;
    }

  //ClearBackground(BLUE);
  //std:: cout << tempo << "\n";


    char teclaLida;

    std::vector<char> teclasPossiveis;
    for (char letra = 'a'; letra <= 'z'; ++letra) {
        teclasPossiveis.push_back(letra);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(teclasPossiveis.begin(), teclasPossiveis.end(), g);

    teclasPossiveis.resize(18);


    if (tempo > 0 && !teclasPossiveis.empty()) {
        std::cout << "Tempo para explodir: " << tempo << " segundos" << std::endl;
        
        if (*count == 1 || *count == intervalo){
            std::cout << "Pressione as teclas: ";
            for (auto tecla : teclasPossiveis) {
                std::cout << tecla << " ";
            }
            std::cout << std::endl;
            intervalo += intervalo;
        }

        tempo--;
    }

    // Verifica se a bomba foi desarmada ou explodiu
    if (tempo > 0 && teclasPossiveis.empty()) {
        std::cout << "Bomba desarmada!" << std::endl;
    } else{
        std::cout << "A bomba explodiu!" << std::endl;
        
    }


    while(tempo > 0 && !teclasPossiveis.empty()){
        std::cin >> teclaLida;
        if(acionarSwitch(teclasPossiveis, teclaLida)){
            std::cout << "Cortou o fio certo!" << std::endl;
        }else{
            std::cout << "Cuidado! Fio errado!" << std::endl;
        }
    }
}*/
