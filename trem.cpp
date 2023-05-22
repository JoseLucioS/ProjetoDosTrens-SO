#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}
//cada trem se move 270 em X e 120 em Y
//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 40 && x <470)
                x+=10;
            else if (x == 470 && y < 160)
                y+=10;
            else if (x > 200 && y == 160)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 40 && x <740)
                x+=10;
            else if (x == 740 && y < 160)
                y+=10;
            else if (x > 470 && y == 160)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::setVelocidade(int velocidade){
    this->velocidade = velocidade;
}

int Trem::getVelocidade(){

    return this->velocidade;
}



