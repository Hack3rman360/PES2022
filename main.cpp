#include "mbed.h"
#include "hcsr04.h"
#include "motordriver.h"
#include "ctime"
#include <cstdio>


enum State{
    INIT,
    START, 
    TIENCMDIS,
    //VIJFCMDIS,
    VERVAL,

};

//init
//IR-Sensorpins:
DigitalIn IRsensorLinks(PC_8); // geel
//DigitalIn IRsensorMidden();
DigitalIn IRsensorRechts(PB_15); // geel
//Motordriver:

Motor L(D5, D2, D3, 1); // pwm(paars), fwd(groen), rev(blauw)
Motor R(D6, D4, D7, 1); // pwm(paars), fwd(greon), rev(blauw)

//us-SENSORPINS:
HCSR04 USsensorLinks(D8, D9); //groen, geel
HCSR04 USsensorMiddenBoven(D10, D11);
HCSR04 USsensorMiddenOnder(D12, D13);
HCSR04 USsensorRechts(D14, D15);

//startknop:

DigitalIn startknop(PC_4);




//state
State stofzuigen;

bool caseEntry = true;
bool draaipunt = false;




void vooruit(){
    L.speed(0.997);
    R.speed(1);
}

void vooruithalf(){
    L.speed(0.5);
    R.speed(0.5);
}
void achteruit(){
    L.speed(-0.7);
    R.speed(-0.7);
}

void stop(){
    L.speed(0);
    R.speed(0);
}

void stopvoorverval(){
    L.speed(-0.5);
    R.speed(-0.5);
}

void draaien(){
    L.speed(0.7);
    R.speed(-0.7);
}
int main()
{
	
    

   

    while(true){      
            stop();
            while (startknop){
                int distanceLinks = USsensorLinks.distance();
                int distanceMiddenBoven = USsensorMiddenBoven.distance();
                int distanceMiddenOnder = USsensorMiddenOnder.distance();
                int distanceRechts = USsensorRechts.distance();

                //printf("distancelinks is: %d\n\r", distanceLinks);
                //printf("distancerechts is: %d\n\r", distanceRechts);
                //printf("distanceboven is: %d\n\r", distanceMiddenBoven);
                //printf("distanceonder is: %d\n\r", distanceMiddenOnder);
                stofzuigen = State::TIENCMDIS;
                int randNum = rand() % 8+1;
                
                switch (stofzuigen) {
                case State::TIENCMDIS : if(distanceLinks  < 25 ||distanceMiddenBoven < 15 ||distanceMiddenOnder < 15 || distanceRechts < 25){
                    
                    int distanceLinks = USsensorLinks.distance();
                    int distanceMiddenBoven = USsensorMiddenBoven.distance();
                    int distanceMiddenOnder = USsensorMiddenOnder.distance();
                    int distanceRechts = USsensorRechts.distance();
                    

                    if (distanceLinks < 15 || distanceMiddenBoven < 8 ||distanceMiddenOnder < 8 || distanceRechts < 15 ||IRsensorRechts || IRsensorRechts){
                        stopvoorverval();
                        ThisThread::sleep_for(500ms);
                        achteruit();
                        ThisThread::sleep_for(750ms);
                        stop();
                        ThisThread::sleep_for(500ms);
                        draaien();
                        ThisThread::sleep_for(randNum*250ms);
                        stop();
                    }
                    else {
                    vooruithalf();
                    }
                    stofzuigen = State::VERVAL;
                    break;
                }

                case State::VERVAL : if (IRsensorLinks || IRsensorRechts){
                        stopvoorverval();
                        ThisThread::sleep_for(500ms);
                        achteruit();
                        ThisThread::sleep_for(750ms);
                        stop();
                        ThisThread::sleep_for(500ms);
                        draaien();
                        ThisThread::sleep_for(randNum*250ms);
                        stop();
                    break;
                }

                default:
                
                vooruit();  
            ThisThread::sleep_for(5ms);
        }
    }
    }
}