#ifndef Colors_h
#define Colors_h

#include "Arduino.h"

class Color {
	public:
		Color(int,int16_t); // ID, COLOR
		int getID() = _ID;
		int16_t getColor() = _COLOR;
	private:
		int _ID;
		int16_t _COLOR;
}

class ColorPallet {
	public:
		ColorPallet(Color*); //Array of colors
		int16_t getColorFromID(int); // gets color needed from id
	private:
		Color *_colors;
}

int16_t getColorFromRef(int id);
ColorPallet getDefaultPallet();

#define BLACK      getColorFromRef(0);
#define DARK_BLUE  getColorFromRef(1);
#define DARK_RED   getColorFromRef(2);
#define DARK_GREEN getColorFromRef(3);
#define MAGENTA    getColorFromRef(4);
#define PURPLE     getColorFromRef(5);
#define ORANGE     getColorFromRef(6);
#define BROWN      getColorFromRef(7);
#define WHITE      getColorFromRef(8);
#define BLUE       getColorFromRef(9;
#define RED        getColorFromRef(10);
#define GREEN      getColorFromRef(11);
#define PINK       getColorFromRef(12);
#define CYAN       getColorFromRef(13);
#define YELLOW     getColorFromRef(14);

#define DEFAULT_COLOR_PALLET getDefaultPallet();
#endif
