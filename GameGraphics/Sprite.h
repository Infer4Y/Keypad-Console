#ifndef Sprite_h
#define Sprite_h

#include "_settings\Sprite_Settings.h"
#include "Arduino.h"
#include "Display.h"

struct PixelLine{
    int data[SPRITEWIDTH];
};

class Sprite {
  public:
    Sprite(Display, PixelLine*);
    void draw(int, int);     // X, Y
    void draw(int, int, int); // X, Y, Scale
  private:
    Display _display;
    PixelLine *_image;
};

#endif