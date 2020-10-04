#include <MIDI.h>
#include <Encoder.h>
#include <OneButton.h>


#ifndef Knob_h
#define Knob_h

extern OneButton configButtonUp;
extern OneButton configButtonDown;
extern OneButton configButton3;
extern OneButton configButton4;
extern float octave; 




class Knob{

  private:
    
    //* Save the num of encoder, use to configurate function of thease.
    int _numOfEncoder;

    //* Pins of encoder, a and b.
    uint8_t _a;
    uint8_t _b;

    //*Encoder Instance, user to manege the encoders.
    

    //* Pins of switch and the ledRingIndicator.
    uint8_t _switchPin;
    uint8_t _ledsPin;

    //* Button instance, use to manage the encoders buttons.
    

    //* TODO: Mode to work.
    uint8_t _mode;
    
    

  public:

  OneButton button;
  
  Knob();
  Knob(uint8_t numEncoder,uint8_t a,uint8_t b,uint8_t switchPin,uint8_t ledsPin);

  void readKnob();
  void readButton();
  uint8_t getSwitchPin();
  void singleclick(int _numOfEncoder);
  void longclick(int _numOfEncoder);
  long _encoderValue;
  long _encoderPrevValue;
  int aState;
  int aLastState;


};
#endif

extern Knob arrayKnobs[16];


void changeOctave();

void singleclickKnob(int midiSignal);
void longclickKnob(int midiSignal);
void longclickManteinKnob(int midiSignal);

void singleClickButtonUp();
void singleClickButtonDown();

void configButtons();
void readConfigButtons();


