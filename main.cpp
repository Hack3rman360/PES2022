#include "mbed.h"
#include "iostream"

//init
//IR-Sensorpins:
DigitalIn IRsensorLinks(PA_3);
DigitalIn IRsensorMidden(PA_2);
DigitalIn IRsensorRechts(PA_10);
//Motordriver:
PwmOut MotorlinksSnelheid(PB_4);
PwmOut MotorrechtsSnelheid(PB_10);
DigitalOut MotorlinksVooruit(PB_3);
DigitalOut MotorlinksAchteruit(PB_5);
DigitalOut MotorrechtsVooruit(PA_8);
DigitalOut MotorrechtsAchteruit(PB_1);
//us-SENSORPINS:
DigitalOut USsensorlinksTrig(PA_9);
DigitalIn USsensorlinksEcho(PC_7);
DigitalOut USsensorMiddenBovenTrig(PB_6);
DigitalIn USsensorMiddenBovenEcho(PA_7);
DigitalOut USsensorMiddenOnderTrig(PB_6);
DigitalIn USsensorMiddenOnderEcho(PA_6);
DigitalOut USsensorRechtsTrig(PA_5);
DigitalIn USsensorRechtsEcho(PB_9);

//startknop:

AnalogIn startknop(PC_0);



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


