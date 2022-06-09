#include "mbed.h"
#include "hcsr04.h"
#include "motordriver.h"



//init
//IR-Sensorpins:
DigitalIn IRsensorLinks(D0);
//DigitalIn IRsensorMidden();
DigitalIn IRsensorRechts(D1);
//Motordriver:
PwmOut MotorlinksSnelheid(D5);
PwmOut MotorrechtsSnelheid(D6);
DigitalOut MotorlinksVooruit(D2);
DigitalOut MotorlinksAchteruit(D3);
DigitalOut MotorrechtsVooruit(D4);
DigitalOut MotorrechtsAchteruit(D7);
//us-SENSORPINS:
HCSR04 USsensorLinks(D8, D9);
HCSR04 USsensorMiddenBoven(D10, D11);
HCSR04 USsensorMiddenOnder(D12, D13);
HCSR04 USsensorRechts(D14, D15);

//startknop:

AnalogIn startknop(A0);

bool setup(){
 if (startknop == true) {
 ThisThread::sleep_for(5s);
 return true;
 }    
 else {
 return false;
 }
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
        
        
        if (distanceLinks < 10 || distanceMiddenBoven < 10 || distanceMiddenOnder < 10 || distanceRechts < 10) {
            return true;
        }
        else{
            return false;
        }

        ThisThread::sleep_for(1ms);
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
        
        
        if (distanceLinks < 5 || distanceMiddenBoven < 5 || distanceMiddenOnder < 5 || distanceRechts < 5) {
            return true;
        }
        else{
            return false;
        }

        ThisThread::sleep_for(100ms);
    }
}


int main(){
    
    if (tiencmveraf() == true) {
        
        
        
    }
}    


