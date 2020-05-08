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
  int16_t colorFound = (sizeof(_colors) > id) ? _colors[id].getColor() : 0x0000;
  
  return colorFound;
};

ColorPallet defaultColorPallet = ColorPallet (new Color[15]{
  Color(0, BLACK), //BLACK
  Color(1, DARK_BLUE), //DARK BLUE
  Color(2, DARK_RED), //DARK RED
  Color(3, DARK_GREEN), //DARK GREEN
  Color(4, MAGENTA), //MAGENTA
  Color(5, PURPLE), //PURPLE
  Color(6, ORANGE), //ORANGE
  Color(7, BROWN), //BROWN
  Color(8, WHITE), //WHITE
  Color(9, BLUE), //BLUE
  Color(10, RED), //RED
  Color(11, GREEN), //GREEN
  Color(12, PINK), //PINK
  Color(13, CYAN), //CYAN
  Color(14, YELLOW)  //YELLOW
});

int16_t getColorFromRef(int id) {
  return defaultColorPallet.getColorFromID(id);
};

ColorPallet getDefaultPallet(){
  return defaultColorPallet;
}