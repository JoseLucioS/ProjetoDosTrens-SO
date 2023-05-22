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
            if(getVelocidade() == 200)
                break;
            if (y == 40 && x < 470)
                x+=10;
            else if (x == 470 && y < 160)
                y+=10;
            else if (x > 200 && y == 160)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (getVelocidade() == 200)
                break;
            if (y == 40 && x <740)
                x+=10;
            else if (x == 740 && y < 160)
                y+=10;
            else if (x > 470 && y == 160)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if (getVelocidade() == 200)
                break;
            if (y == 160 && x <340)
                x+=10;
            else if (x == 340 && y < 280)
                y+=10;
            else if (x > 70 && y == 280)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        case 4: //Trem 4
            if (getVelocidade() == 200)
                break;
            if (y == 160 && x < 610)
                x+=10;
            else if (x == 610 && y < 280)
                y+=10;
            else if (x > 340 && y == 280)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        case 5: //Trem 5
            if (getVelocidade() == 200)
                break;
            if (y == 160 && x < 880)
                x+=10;
            else if (x == 880 && y < 280)
                y+=10;
            else if (x > 610 && y == 280)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
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



