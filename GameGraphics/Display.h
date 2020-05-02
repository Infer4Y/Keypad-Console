#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include <TFT_ILI9163C.h>

class Display
{
  public:
    Display(void);
    Display(TFT_ILI9163C*);      //tft
    Display(TFT_ILI9163C*, int); // tft , reset
    void begin();
    void draw(); // Left for the user to define
    TFT_ILI9163C* getDisplay();
  private:
    TFT_ILI9163C* _display;
    int _res;
};

#endif