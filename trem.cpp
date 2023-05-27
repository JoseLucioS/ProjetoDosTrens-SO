#include "trem.h"
#include <QtCore>
#include "auxiliar.h"

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
            if (y == 40 && x < 470){
                if(x == 450){
                    //regiao critica entrada 0
                    pthread_mutex_lock(&regioesCriticas[0]);
                }
                x+=10;
            }

            else if (x == 470 && y < 160){
                if(y == 140){
                    //regiao critica entrada 2
                    pthread_mutex_lock(&regioesCriticas[2]);
                }
                y+=10;
            }

            else if (x > 200 && y == 160){
                if(x == 450){
                    //regiao critica saida 0
                    pthread_mutex_unlock(&regioesCriticas[0]);
                }
                if(x == 360){
                    //regiao critica entrada 1
                    pthread_mutex_lock(&regioesCriticas[1]);
                }
                if(x == 320){
                    //regiao critica saida 2
                    pthread_mutex_unlock(&regioesCriticas[2]);
                }

                x-=10;
            }

            else{
                if(x == 200 && y == 140){
                    //regiao critica saida 1
                    pthread_mutex_unlock(&regioesCriticas[1]);
                }
                y-=10;
            }

            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (getVelocidade() == 200)
                break;
            if (y == 40 && x <740){
                if(x == 490){
                    //regiao critica saida 0
                    pthread_mutex_unlock(&regioesCriticas[0]);
                }

                x+=10;
            }

            else if (x == 740 && y < 160){
                if(y == 140){
                    //regiao critica entrada 4
                    //regiao critica entrada 6
                    pthread_mutex_lock(&regioesCriticas[4]);
                    pthread_mutex_lock(&regioesCriticas[6]);
                }
                y+=10;
            }

            else if (x > 470 && y == 160){
                if(x == 630){
                    //regiao critica entrada 3
                    pthread_mutex_lock(&regioesCriticas[3]);
                }
                if(x == 590){
                    //regiao critica saida 4
                    //regiao critica saida 6
                    pthread_mutex_unlock(&regioesCriticas[4]);
                    pthread_mutex_unlock(&regioesCriticas[6]);
                }
                if(x == 490){
                    //regiao critica entrada 0
                    pthread_mutex_lock(&regioesCriticas[0]);
                }
                x-=10;
            }

            else{
                if(y == 140){
                    //regiao critica saida 3
                    pthread_mutex_unlock(&regioesCriticas[3]);
                }
                y-=10;
            }

            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if (getVelocidade() == 200)
                break;
            if (y == 160 && x < 340){
                if(x == 180){
                    //regiao critica entrada 1
                    pthread_mutex_lock(&regioesCriticas[1]);
                }
                if(x == 320){
                    //regiao critica entrada 5
                    pthread_mutex_lock(&regioesCriticas[5]);
                }
                x+=10;
            }

            else if (x == 340 && y < 280){
                if(y == 180){
                    //regiao critica saida 1
                    pthread_mutex_unlock(&regioesCriticas[1]);
                }
                /*if(y == 260){

                }*/
                y+=10;
            }

            else if (x > 70 && y == 280){
                if(x == 320){
                    //regiao critica saida 5
                    pthread_mutex_unlock(&regioesCriticas[5]);
                }
                x-=10;
            }

            else
                y-=10;
            emit updateGUI(ID, x, y);    //Emite um sinal
            break;
        case 4: //Trem 4
            if (getVelocidade() == 200)
                break;
            if (y == 160 && x < 610){
                if(x == 360){
                    //regiao critica saida 5
                    pthread_mutex_unlock(&regioesCriticas[5]);
                }
                if(x == 450){
                    //regiao critica entrada 3
                    pthread_mutex_lock(&regioesCriticas[3]);

                }
                if(x == 490){
                    //regiao critica saida 0
                    //regiao critica saida 2
                    pthread_mutex_unlock(&regioesCriticas[0]);
                    pthread_mutex_unlock(&regioesCriticas[2]);
                }
                if(x == 590){
                    //regiao critica entrada 6
                    //pthread_mutex_lock(&regioesCriticas[6]);
                }
                x+=10;
            }

            else if (x == 610 && y < 280){
                if(y == 180){
                    //regiao critica saida 3
                    pthread_mutex_unlock(&regioesCriticas[3]);
                }
                y+=10;
            }

            else if (x > 340 && y == 280){
                if(x == 590){
                    //regiao critica saida 6
                    pthread_mutex_unlock(&regioesCriticas[6]);
                }
                if(x == 360){
                    //regiao critica entrada 5
                    pthread_mutex_lock(&regioesCriticas[5]);
                }
                x-=10;
            }

            else{
                if(y == 180){
                    //regiao critica entrada 2
                    pthread_mutex_lock(&regioesCriticas[2]);
                }
                y-=10;
            }

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



