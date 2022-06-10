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
HCSR04 USsensorLinks(D8, D9);
HCSR04 USsensorMiddenBoven(D10, D11);
HCSR04 USsensorMiddenOnder(D12, D13);
HCSR04 USsensorRechts(D14, D15);

//startknop:

AnalogIn startknop(A0);

bool setup(){
 
 startknop.read();
 return startknop;
}

bool tiencmveraf() {
    while (true)
    {
        float distanceLinks;
        float distanceMiddenBoven;
        float distanceMiddenOnder;
        float distanceRechts;

        distanceLinks = USsensorLinks.distance();
        distanceMiddenBoven = USsensorMiddenBoven.distance();
        distanceMiddenOnder = USsensorMiddenOnder.distance();
        distanceRechts = USsensorRechts.distance();
        
        
        return (distanceLinks < 10 || distanceMiddenBoven < 10 || distanceMiddenOnder < 10 || distanceRechts < 10) ;

        ThisThread::sleep_for(100ms);
    }
}

bool vijfcmveraf() {
    while (true)
    {
        float distanceLinks;
        float distanceMiddenBoven;
        float distanceMiddenOnder;
        float distanceRechts;

        distanceLinks = USsensorLinks.distance();
        distanceMiddenBoven = USsensorMiddenBoven.distance();
        distanceMiddenOnder = USsensorMiddenOnder.distance();
        distanceRechts = USsensorRechts.distance();        
        
        return (distanceLinks < 5 || distanceMiddenBoven < 5 || distanceMiddenOnder < 5 || distanceRechts < 5);

        ThisThread::sleep_for(100ms);
    }
}

bool vervalDetectie(){
    return (IRsensorLinks || IRsensorRechts);
}


int main(){
    
    printf("main gestart:%d\n\r", 0);

    while (setup() == true) {
        
        
        int randNum = rand() % 5+1;
        ThisThread::sleep_for(4s);

        printf("sleep for gelukt: %d\n\r", randNum);

        L.speed (1.0);
        R.speed (1.0);
        printf("tot hiero\n");

        while (tiencmveraf() == true) {
        
            L.speed (0.5);
            R.speed (0.5);

            printf("tot daaro");
                           
            if (vijfcmveraf() == true || vervalDetectie() == true){
                printf("ietsje verder");
                L.speed(0);
                R.speed(0);
                ThisThread::sleep_for(200ms);
                L.speed(-1);
                R.speed(-1);
                ThisThread::sleep_for(5s);
                
                for (int i = 0; (i = randNum); i++){
                    L.speed(0.2);
                    R.speed(-0.2);
                    ThisThread::sleep_for(1s);

                }
            }

            if (vervalDetectie() == true){
                
                ThisThread::sleep_for(200ms);
                L.speed(-1);
                R.speed(-1);
                ThisThread::sleep_for(5s);
                
                for (int i = 0; (i = randNum); i++){
                    L.speed(0.2);
                    R.speed(-0.2);
                    ThisThread::sleep_for(1s);
                }
            }

        
        }
    }
    return 0;
}    


