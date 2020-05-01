#include <Adafruit_GFX.h>
#include <gfxfont.h>

#include <Wire.h>
#include <SPI.h>

#include <TFT_ILI9163C.h>

#define __CS1 10
#define __DC 9

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

const int PORT_IIC = 0x3F;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

int playerSprite[8][8] {
  {0, 0, 2, 2, 1, 2, 0, 0},
  {0, 2, 4, 2, 4, 1, 0, 0},
  {0, 2, 3, 1, 2, 2, 0, 0},
  {3, 2, 2, 2, 1, 2, 2, 0},
  {0, 2, 2, 2, 2, 2, 2, 0},
  {0, 0, 2, 2, 0, 2, 2, 0},
  {0, 0, 2, 2, 0, 2, 2, 0}
};

char selected = ' ';

int CHARSIZE = 2;
const int SPRITESIZE = 8;
const int PIXELSIZE = 4;

int playerX = 0, playerY = 0;

TFT_ILI9163C tft = TFT_ILI9163C(__CS1, __DC);

void updateGame() {
  switch (selected) {
    case '1':
      playerX -= 5;
      playerY -= 5;
      break;
    case '2':
      playerY -= 5;
      break;
    case '3':
      playerX += 5;
      playerY -= 5;
      break;
    case '4':
      playerX -= 5;
      break;
    case '6':
      playerX += 5;
      break;
    case '7':
      playerX -= 5;
      playerY += 5;
      break;
    case '8':
      playerY += 5;
      break;
    case '9':
      playerX += 5;
      playerY += 5;
      break;
  }
  selected = ' ';
}

void graphicsUpdate() {
  drawKeypad();
  tft.fillRect(4 * 7 * CHARSIZE + CHARSIZE, 0 , 159 - (4 * 7 * CHARSIZE + CHARSIZE), 127, BLACK);

}

void drawKeypad() {
  tft.setCursor(0, 0);
  for (int i = 0; i < 4; i++) {
    tft.setCursor(0, i * 8 * CHARSIZE);
    for (int j = 0; j < 4; j++) {
      int16_t colorUsed = (hexaKeys[i][j] == selected) ? BLUE : BLACK;
      int offsetX = 0 == j ? 0 : CHARSIZE;
      int offsetY = 0 == i ? 0 : CHARSIZE;
      tft.fillRect(j * 5 * CHARSIZE + offsetX * j, i * 7 * CHARSIZE + offsetY * i, 5 * CHARSIZE, 7 * CHARSIZE, colorUsed);


      tft.print(hexaKeys[i][j]);
    }
    tft.fillRect(5 * 7 * CHARSIZE + CHARSIZE * 5, i * 7 * CHARSIZE + CHARSIZE * i, 5 * CHARSIZE, 7 * CHARSIZE, BLACK);
  }
}

void setup() {
  Wire.begin(PORT_IIC);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output

  tft.begin();
  tft.setRotation(1);
  tft.setTextSize(CHARSIZE);
  graphicsUpdate();
}

void loop() {
  if ((millis() % 1000 / 60) == 0) {
    graphicsUpdate();
    tft.drawPixel(159, 127, RED);
  } else if ((millis() % (1000 / 30)) == 0) {
    updateGame();
  }
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (0 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(' ');
    Serial.print(c);         // print the character
    selected = c;
  }
  Serial.println();
  //graphicsUpdate();
}
