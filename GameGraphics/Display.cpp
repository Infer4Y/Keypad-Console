#include "Display.h"
#include "Arduino.h"

#include <TFT_ILI9163C.h>

Display::Display(TFT_ILI9163C* display) {
    this->_display = display;
    this->_res = -1; // Set to negitive one incase the user wants to try reseting the display they can check if the pin is set.
};

Display::Display(TFT_ILI9163C* display, int resetPin){
    this->_display = display;
    pinMode(resetPin, OUTPUT);
    this->_res = resetPin;
};

void Display::begin(){
    if (_res != -1) {
        digitalWrite(_res, LOW);
        delay(10);
        digitalWrite(_res, HIGH);
    }

    _display->begin();
};

TFT_ILI9163C* Display::getDisplay(){
    return _display;
};
