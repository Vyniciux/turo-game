#include "telas.h"

void drawCena(gameVars* v, Texture2D* cenas){

    switch (v->cenaAtual){

        case 0:{

            ClearBackground(BLACK);
            DrawTexture(cenas[0], 0, 0, WHITE);
            
            break;
        }

        case 1:{

            ClearBackground(RED);
            DrawText("cena 1, bem vindo", 120, 150, 35, WHITE);
            break;
        }

        case 2:{

            ClearBackground(WHITE);
            DrawText("cena 2, bem vindo", 120, 150, 35, WHITE);
            break;
        }
        
        case 3:{

            ClearBackground(BLUE);
            DrawText("Cena 3, bem vindo", 120, 150, 35, WHITE);
            break;
        }

        default:{
            
            ClearBackground(BLACK);
            DrawText("Cena não encontrada, bugou!", 120, 150, 35, WHITE);
            break;
        }
    }


}

void drawEstado(gameVars* v, Texture2D* icons){

    switch (v->estado){

        case 0:{ //Tela inicial

            ClearBackground(DARKGREEN);
            DrawText("Bem vindo ao Turo's Adventure", 200, 150, 35, LIGHTGRAY);
            DrawText("Pressione enter para jogar", 250, 230, 30, LIGHTGRAY);
            DrawTexture(icons[0], 290, 300, WHITE);
            break;
        }

        case 2:{ //Tela de pause

            
            DrawText("Pausado", 264, 200, 100, BLACK);
            break;
        }

        default:{ //Tela de erro --em caso de erro jogar a estado pra um número alto, ocasionará nessa tela
            
            ClearBackground(BLACK);
            DrawText("Cena não encontrada, bugou!", 140, 200, 35, WHITE);
            break;
        }
    }

}

void loadCenasText(Texture2D* cenas){

    cenas[0] = LoadTexture("assets/mapa/mapa2.png");

}

void unloadCenasText(Texture2D* cenas, int nCenas){

    for (int i = 0; i < nCenas; i++)
    {
        UnloadTexture(cenas[i]);
    }
    
}

void loadPlayerText(Texture2D* player){

    player[0] = LoadTexture("assets/player/right-Sheet.png");
    player[1] = LoadTexture("assets/player/left-Sheet.png");
    player[2] = LoadTexture("assets/player/up-Sheet.png");
    player[3] = LoadTexture("assets/player/down-Sheet.png");

}

void unloadPlayerText(Texture2D* player){

    UnloadTexture(player[0]);
    UnloadTexture(player[1]);
    UnloadTexture(player[2]);
    UnloadTexture(player[3]);
    
}

void loadIconsText(Texture2D* icons){

    icons[0] = LoadTexture("assets/icons/turo2.png");

}

void unloadIconText(Texture2D* icons){

    UnloadTexture(icons[0]);
    
}