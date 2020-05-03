#include "Colors.h"
#include "Arduino.h"

Color::Color(int ID, int16_t color){
  _ID = ID;
  _COLOR = color;
};

ColorPallet::ColorPallet(Color* colors){
  _colors = colors;
};

int16_t ColorPallet::getColorFromID(int id){
  int16_t colorFound = 0x0000;

  for (int i = 0; i < sizeof(_colors); i++){
    if(_colors[i].getID() == id) _colors[i].getColor() colorFound;
  }

  return colorFound;
};

ColorPallet defaultColorPallet = ColorPallet (new Color[]{
  Color(0, 0x0000), //BLACK
  Color(1, 0x0029), //DARK BLUE
  Color(2, 0x4800), //DARK RED
  Color(3, 0x0240), //DARK GREEN
  Color(0, 0xF81F), //MAGENTA
  Color(4, 0x2009), //PURPLE
  Color(5, 0xFC40), //ORANGE
  Color(6, 0x4900), //BROWN
  Color(7, 0xFFFF), //WHITE
  Color(8, 0x001F), //BLUE
  Color(9, 0xF800), //RED
  Color(10, 0x07E0), //GREEN
  Color(11, 0xFC5E), //PINK
  Color(12, 0x07FF), //CYAN
  Color(13, 0xFFE0)  //YELLOW
});

int16_t getColorFromRef(int id) {
  return defaultColorPallet.getColorFromID(id);
};

ColorPallet getDefaultPallet(){
  return defaultColorPallet;
}