#ifndef Sprite_h
#define Sprite_h

#include "_settings/Sprite_Settings.h"
#include "Arduino.h"
#include "Display.h"
#include "Colors.h"

struct PixelLine{
    int *data;
};

class Sprite {
  public:
    Sprite(Display, PixelLine*);
    Sprite(Display, PixelLine*, int, int); // width and height
    void draw(int, int);     // X, Y
    void draw(int, int, int); // X, Y, Scale
    void draw(int, int, ColorPallet);
    void draw(int, int, int, ColorPallet);
  private:
    Display _display;
    PixelLine *_image;
    int _width = SPRITEWIDTH, _height = SPRITEHEIGHT; 
};

PixelLine genPixelLine(int*);

#endif
