#include "mbed.h"
#include "iostream"

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
DigitalOut USsensorlinksTrig(D8);
DigitalIn USsensorlinksEcho(D9);
DigitalOut USsensorMiddenBovenTrig(D10);
DigitalIn USsensorMiddenBovenEcho(D11);
DigitalOut USsensorMiddenOnderTrig(D12);
DigitalIn USsensorMiddenOnderEcho(D13);
DigitalOut USsensorRechtsTrig(D14);
DigitalIn USsensorRechtsEcho(D15);

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

int main(){
    
    if (setup() == true) {
        while (true) {
        
        }
    }
}    


