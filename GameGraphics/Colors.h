#ifndef Colors_h
#define Colors_h

#include "Arduino.h"

#define BLACK      0x0000
#define BLUE       0x001F
#define DARK_BLUE  0x0029
#define RED        0xF800
#define DARK_RED   0x4800
#define DARK_GREEN 0x0240
#define GREEN      0x07E0
#define CYAN       0x07FF
#define MAGENTA    0xF81F
#define PURPLE     0x2009
#define PINK       0xFC5E
#define YELLOW     0xFFE0
#define WHITE      0xFFFF
#define BROWN      0x4900

int16_t getColorFromRef(int id);
#endif