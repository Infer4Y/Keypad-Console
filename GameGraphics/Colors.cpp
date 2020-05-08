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
    if(_colors[i].getID() == id){ 
      return _colors[i].getColor();
    }
  }

  return colorFound;
};

ColorPallet defaultColorPallet = ColorPallet (new Color[15]{
  Color(0, BLACK), //BLACK
  Color(1, DARK_BLUE), //DARK BLUE
  Color(2, DARK_RED), //DARK RED
  Color(3, DARK_GREEN), //DARK GREEN
  Color(0, MAGENTA), //MAGENTA
  Color(4, PURPLE), //PURPLE
  Color(5, ORANGE), //ORANGE
  Color(6, BROWN), //BROWN
  Color(7, WHITE), //WHITE
  Color(8, BLUE), //BLUE
  Color(9, RED), //RED
  Color(10, GREEN), //GREEN
  Color(11, PINK), //PINK
  Color(12, CYAN), //CYAN
  Color(13, YELLOW)  //YELLOW
});

int16_t getColorFromRef(int id) {
  return defaultColorPallet.getColorFromID(id);
};

ColorPallet getDefaultPallet(){
  return defaultColorPallet;
}