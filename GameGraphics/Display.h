#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include <TFT_ILI9163C.h>

class Display
{
  public:
    Display(TFT_ILI9163C display);
    Display(TFT_ILI9163C display, int resetPin);
    void begin();
    void draw(); // Left for the user to define
  private:
    TFT_ILI9163C _display;
    int _res
};

#endif