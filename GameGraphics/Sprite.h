#ifndef Sprite_h
#define Sprite_h

#include "_settings\Sprite_Settings.h"
#include "Arduino.h"
#include "Display.h"

class Sprite {
  public:
    Sprite(const Display, int [][SPRITEWIDTH]);
    void draw(int, int);     // X, Y
    void draw(int, int, int); // X, Y, Scale
  private:
    Display _display;
    int _image[][SPRITEWIDTH];
};

#endif