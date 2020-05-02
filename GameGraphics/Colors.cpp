#include "Colors.h"
#include "Arduino.h"

int16_t getColorFromRef(int id) {
  switch (id) {
    case 0 :
      return BLACK;
    case 1 :
      return YELLOW;
    case 2 :
      return RED;
    case 3 :
      return MAGENTA;
    case 4 :
      return BLUE;
    default :
      return BLACK;
  }
};
