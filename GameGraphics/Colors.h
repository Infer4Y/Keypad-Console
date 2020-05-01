#ifndef Colors_h
#define Colors_h

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

int16_t getColor(int id) {
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
}

#endif