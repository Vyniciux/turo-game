#include "bomb.h"

int Bomb::drawBomb(int* frameCounter){
    
    ClearBackground(WHITE);

   if(*frameCounter>60){
        tempo++;
        *frameCounter=0;
        std:: cout << tempo << " segundos\n";
        
        if(tempo > 3+time){
            return 2;
        }
    } 


    int c=0;

    if(tempo>3){
    	drawTela();
	for (int i = 0; i < 18; i++){

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

   	 if(c==18){
       	 return 1;
   	 }   

   	 std::cout << "\n";
    
   	 pressed();
    }
    else{
	DrawText("Voce encontrou uma bomba,",140,180,50,BLACK);
	DrawText("desarme-a a tempo",220,240,50,BLACK);
    }



    return 0;
}

void Bomb::randomFios(){

    for (int i = 0; i < 18; i++){

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

void Bomb::drawTela(){

    int inc = 50;
    for (int i = 0; i < 18; i++){

        if(!fios[i]||(fios[i]&&pushed[i])) {	
	    DrawCircle(50 + i*inc,480,20, GREEN);
	    DrawText("A",0,i*inc*100,10,GREEN);
	
	}
	else DrawCircle(50 + i*inc,480,20, RED);
	
	}

    	DrawRectangle (480,60,20,50,BROWN);
    	DrawCircle(480,200,100, BLACK);
    	DrawCircle(430,160,20, WHITE);
    	DrawCircle(500,160,20, WHITE);
    	DrawCircle(440,160,10, RED);
    	DrawCircle(510,160,10, RED);
	DrawCircle(490,55+35*((float)tempo/(float)time),10,RED);
	DrawTriangle({490,30+35*((float)tempo/(float)time)},{480,55+35*((float)tempo/(float)time)}, {500,55+35*((float)tempo/(float)time)},RED);   
	DrawCircle(490,55+35*((float)tempo/(float)time),6,ORANGE);
	DrawTriangle({490,39+35*((float)tempo/(float)time)},{485,58+35*((float)tempo/(float)time)}, {495,58+35*((float)tempo/(float)time)},ORANGE);   

	DrawText("q",40,462,30,GREEN);
	DrawText("w",90,462,30,GREEN);
	DrawText("e",140,462,30,GREEN);
	DrawText("r",194,462,30,GREEN);
	DrawText("t",244,462,30,GREEN);
	DrawText("y",294,462,30,GREEN);
	DrawText("u",340,462,30,GREEN);
	DrawText("i",390,462,30,GREEN);
	DrawText("o",443,462,30,GREEN);
	DrawText("p",493,462,30,GREEN);
 	DrawText("a",540,462,30,GREEN);
	DrawText("s",590,462,30,GREEN);
	DrawText("d",645,462,30,GREEN);
	DrawText("f",695,462,30,GREEN);
    	DrawText("g",742,462,30,GREEN);
   	DrawText("h",790,462,30,GREEN);
   	DrawText("j",844,462,30,GREEN);
   	DrawText("k",896,462,30,GREEN);

}

void Bomb::setBomb(int d){
    randomFios();
    tempo = 0;
    time = d;
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
    if(IsKeyDown(KEY_O)){
	pushed[8]=true;
    }
    if(IsKeyDown(KEY_P)){
    	pushed[9]=true;
    }
    if(IsKeyDown(KEY_A)){
        pushed[10]=true;
    }
    if(IsKeyDown(KEY_S)){
        pushed[11]=true;
    }
    if(IsKeyDown(KEY_D)){
        pushed[12]=true;
    }
    if(IsKeyDown(KEY_F)){
        pushed[13]=true;
    }
    if(IsKeyDown(KEY_G)){
        pushed[14]=true;
    }
    if(IsKeyDown(KEY_H)){
        pushed[15]=true;
    }
    if(IsKeyDown(KEY_J)){
	pushed[16]=true;
    }
    if(IsKeyDown(KEY_K)){
        pushed[17]=true;
    }
}
