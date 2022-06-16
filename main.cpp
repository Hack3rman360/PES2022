#include "mbed.h"
#include "hcsr04.h"
#include "motordriver.h"
#include "ctime"
#include <cstdio>




//init
//IR-Sensorpins:
DigitalIn IRsensorLinks(PB_1); // geel
//DigitalIn IRsensorMidden();
DigitalIn IRsensorRechts(PB_15); // geel
//Motordriver:

Motor L(D5, D2, D3, 0); // pwm(paars), fwd(groen), rev(blauw)
Motor R(D6, D4, D7, 0); // pwm(paars), fwd(greon), rev(blauw)

//us-SENSORPINS:
HCSR04 USsensorLinks(D8, D9); //groen, geel
HCSR04 USsensorMiddenBoven(D10, D11);
HCSR04 USsensorMiddenOnder(D12, D13);
HCSR04 USsensorRechts(D14, D15);

//startknop:

DigitalIn startknop(PC_4);

bool setup(){
 
 startknop.read();
 return startknop;
}

bool tiencmveraf() {
    printf("tiencmveraf gecallt\n");
        int distanceLinks;
        int distanceMiddenBoven;
        int distanceMiddenOnder;
        int distanceRechts;

        distanceLinks = USsensorLinks.distance();
        distanceMiddenBoven = USsensorMiddenBoven.distance();
        distanceMiddenOnder = USsensorMiddenOnder.distance();
        distanceRechts = USsensorRechts.distance();
        
        printf("distance is: %d\n\r", distanceLinks);

        return (distanceLinks < 10 || distanceMiddenBoven < 10 || distanceMiddenOnder < 10 || distanceRechts < 10) ;
    
}

bool vijfcmveraf() {
    
    int distanceLinks;
    int distanceMiddenBoven;
    int distanceMiddenOnder;
    int distanceRechts;

    distanceLinks = USsensorLinks.distance();
    distanceMiddenBoven = USsensorMiddenBoven.distance();
    distanceMiddenOnder = USsensorMiddenOnder.distance();
    distanceRechts = USsensorRechts.distance();        
        
    return (distanceLinks < 5 || distanceMiddenBoven < 5 || distanceMiddenOnder < 5 || distanceRechts < 5);

  ThisThread::sleep_for(100ms);
    
}

bool vervalDetectie(){

    IRsensorLinks.read();
    IRsensorRechts.read();
    return (IRsensorLinks || IRsensorRechts);
}


int main(){
        printf("main gestart:%d\n\r", 0);
        startknop.read();
        while (startknop == true) {
            printf("setup is true\n");
        
            int randNum = rand() % 5+1;
            ThisThread::sleep_for(4s);

            printf("sleep for gelukt: %d\n\r", randNum);

            L.speed (1.0);
            R.speed (1.0);
            printf("tot hiero\n");

            if (tiencmveraf() == true) {
        
                L.speed (0.5);
                R.speed (0.5);

                //printf("tot daaro\n");
                           
                if (vijfcmveraf() == true || vervalDetectie() == true){
                //printf("ietsje verder\n");
                    L.speed(0);
                    R.speed(0);
                    ThisThread::sleep_for(500ms);
                    L.speed(-0.7);
                    R.speed(-0.7);
                    ThisThread::sleep_for(5s);
                    L.speed(0);
                    R.speed(0);
                    ThisThread::sleep_for(500ms);
                
                    for (int i = 0; (i <= randNum); i++){
                        L.speed(0.7);
                        R.speed(-0.7);
                        printf(" loop gedaan: %d\n", i);
                        ThisThread::sleep_for(1s);

                    }
                    L.speed(0);
                    R.speed(0);
                }
            }
            if (vervalDetectie() == true){
                L.speed(0);
                R.speed(0);
                ThisThread::sleep_for(500ms);
                L.speed(-0.7);
                R.speed(-0.7);
                ThisThread::sleep_for(5s);

                L.speed(0);
                R.speed(0);
                
                for (int i = 0; (i <= randNum); i++){
                    L.speed(0.7);
                    R.speed(-0.7);
                    printf(" loop gedaan: %d\n", i);
                    ThisThread::sleep_for(1s);
                }

        
            }
        }

        //ThisThread::sleep_for(50ms);

    }    