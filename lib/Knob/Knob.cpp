#include "Knob.h"
MIDI_CREATE_DEFAULT_INSTANCE();

float octave = 0;

OneButton configButtonUp;
OneButton configButtonDown;
OneButton configButton3;
OneButton configButton4;

Knob arrayKnobs[16];


Knob::Knob(uint8_t numEncoder,uint8_t a,uint8_t b,uint8_t switchPin,uint8_t ledsPin): encoder(a,b) , button(switchPin,true){
  
    _numOfEncoder = numEncoder;

    _a = a;
    _b = b;

    _switchPin = switchPin;
    _ledsPin  = ledsPin;
    _encoderValue = -999;
   
   button.attachClick( (void (*)(void *)) singleclickKnob,(void*)_numOfEncoder);  
   button.attachLongPressStart((void (*)(void *)) longclickManteinKnob,(void*)_numOfEncoder);
   button.attachLongPressStop((void (*)(void *)) longclickKnob,(void*)_numOfEncoder);
   
};

Knob::Knob():encoder(0,0){

}

void Knob::readKnob(){
    //long encoderValue = min(127,max(0,encoder.read()));
    
    long encoderValue = arrayKnobs[_numOfEncoder].encoder.read();
    if(encoderValue != _encoderValue){
        _encoderValue = encoderValue;
        MIDI.sendControlChange(_numOfEncoder,encoderValue,1);
    }
    


}

void Knob::readButton(){
    
}  

uint8_t Knob::getSwitchPin(){
    return _switchPin;
}

void singleclickKnob(int midiSignal){

    MIDI.sendNoteOn(midiSignal + 16*octave,127,1);
    MIDI.sendNoteOn(midiSignal + 16*octave,0,1);

}

 
void longclickKnob(int midiSignal){
        MIDI.sendNoteOn(midiSignal+16*octave,0,1);
}

void longclickManteinKnob(int midiSignal){
     MIDI.sendNoteOn(midiSignal+16*octave,127,1);
}

void changeUpOctave(){
    if(octave == 7){
        return;
    }else if(octave == 0){
        octave = 0.25;
    }else if(octave == 6.25){
        octave = 7;
    }else{
        octave++;
    }
}

void changeDownOctave(){
    if(octave == 0){
        return;
    }else if(octave == 1){
        octave = 0.25;
    }else if(octave == 0.25){
        octave = 0;
    }else if(octave == 7){
     octave = 6.25;   
    }else{
        octave--;
    }
}

void singleClickButtonUp(){
 changeUpOctave();
};
void singleClickButtonDown(){
 changeDownOctave();
};


void configButtons(){
    configButtonUp = OneButton(65,true);
    configButtonDown = OneButton(66,true);
    configButton3 = OneButton(67,true);
    configButton4 = OneButton(68,true);

    configButtonUp.attachClick(singleClickButtonUp);
    configButtonUp.attachLongPressStart(singleClickButtonUp);
    configButtonDown.attachClick(singleClickButtonDown);
    configButtonDown.attachLongPressStart(singleClickButtonDown);

    /*
    * TODO: Config Buttons.
    configButton3.attachClick();
    configButton3.attachLongPressStart();
    configButton4.attachClick();
    configButton4.attachLongPressStart();
    */
};

void readConfigButtons(){
    configButtonUp.tick();
    configButtonDown.tick();
};


