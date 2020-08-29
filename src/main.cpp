#include <OneButton.h>
#include <Knob.h>


//Libraries Used!
#include <MIDI.h>

#include <protothreads.h>
#include <Encoder.h>


Encoder encoder(2,3);
long lastEncoderValue = -999;


void setup() {  
    

    int j = 0;
    for (int i = 2; i < 66; i=i+4){
      arrayKnobs[j] = Knob(j,i,i+1,i+2,i+3);
      j++;
    }

    configButtons();

    Serial.begin(9600);

}

void readChangeKnob(int i){
    long encoderValue = encoder.read();

    if(encoderValue != lastEncoderValue){
        Serial.println(encoderValue);
        lastEncoderValue = encoderValue;
    }
}

void readKnobs(){
    for(int i = 0;i<16;i++){
        arrayKnobs[i].button.tick();
        readChangeKnob(i);
          
    }
    
    readConfigButtons();
    
}

void loop() {
    readKnobs();
   
}

