#ifndef Colors_h
#define Colors_h

#include "Arduino.h"

class Color {
	public:
		Color(int,int16_t); // ID, COLOR
		int getID() {return _ID;};
		int16_t getColor() {return _COLOR;};
	private:
		int _ID;
		int16_t _COLOR;
};

class ColorPallet {
	public:
		ColorPallet(Color*); //Array of colors
		int16_t getColorFromID(int); // gets color needed from id
	private:
		Color *_colors;
};

#define BLACK           0x0000
#define DARK_BLUE       0x0029
#define DARK_RED        0x4800
#define DARK_GREEN      0x0240
#define MAGENTA         0xF81F
#define PURPLE          0x2009
#define ORANGE          0xFC40
#define BROWN           0x4900
#define WHITE           0xFFFF
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define PINK            0xFC5E
#define CYAN            0x07FF
#define YELLOW          0xFFE0

int16_t getColorFromRef(int id);
ColorPallet getDefaultPallet();

#endif
