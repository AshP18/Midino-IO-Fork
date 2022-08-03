#include <OneButton.h>
#include <Knob.h>


//Libraries Used!
#include <MIDI.h>

#include <protothreads.h>



void setup() {  
    

    int j = 0;
    
    for (int i = 2; i < 66; i=i+4){
      arrayKnobs[j] = Knob(j,i,i+1,i+2,i+3);
      j++;
    }
    
    configButtons();

    

    //Serial.begin(115200);

}

void readKnobs(){
    for(int i = 0;i<16;i++){
        arrayKnobs[i].button.tick();
        arrayKnobs[i].readKnob();
    }
    readConfigButtons();    
}

void loop() {
    readKnobs();
   
}

