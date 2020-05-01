#ifndef Sprite_h
#define Sprite_h

#include "Arduino.h"
#include "Display.h"

class Sprite {
  public:
    Sprite(Display display, int[][] image);
    void draw(int x, int y);
    void draw(int x, int y, int scale);
  private:
    Display _display;
    int[][] _image;
};

#endif