#include <Adafruit_GFX.h>
#include <Wire.h>
#include <SPI.h>

#include <TFT_ILI9163C.h>
#include <Display.h>
#include <_settings/Sprite_Settings.h>
#include <Sprite.h>
#include <Colors.h>


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

PixelLine playerSpriteData[8] {
  genPixelLine(new int[8]{0, 0, 1, 0, 0, 1, 0, 0}),
  genPixelLine(new int[8]{0, 0, 1, 1, 1, 1, 0, 0}),
  genPixelLine(new int[8]{0, 0, 2, 2, 2, 2, 0, 0}),
  genPixelLine(new int[8]{0, 0, 4, 2, 4, 2, 0, 0}),
  genPixelLine(new int[8]{0, 2, 2, 2, 2, 2, 0, 0}),
  genPixelLine(new int[8]{0, 0, 3, 3, 3, 3, 0, 0}),
  genPixelLine(new int[8]{0, 0, 3, 0, 3, 0, 0, 0}),
  genPixelLine(new int[8]{0, 0, 3, 0, 3, 0, 0, 0})
};

char selected = ' ';

int CHARSIZE = 2;

int playerX = 0, playerY = 0;

TFT_ILI9163C tft = TFT_ILI9163C(__CS1, __DC);
Display display = Display(&tft);

Sprite playerSprite = Sprite (display, playerSpriteData);

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

void Display::draw() {
  drawKeypad();
  getDisplay()->fillRect(4 * 7 * CHARSIZE + CHARSIZE, 0 , 159 - (4 * 7 * CHARSIZE + CHARSIZE), 127, BLACK);

  playerSprite.draw(playerX + (4 * 7 * CHARSIZE + CHARSIZE), playerY, 4);
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
    tft.fillRect(4 * 7 * CHARSIZE + CHARSIZE * 5, i * 7 * CHARSIZE + CHARSIZE * i, 7 * CHARSIZE, 7 * CHARSIZE, BLACK);
  }
  tft.fillRect(0, 4 * 8 * CHARSIZE, 4 * 7 * CHARSIZE + CHARSIZE * 5, 127 - 4 * 8 * CHARSIZE, BLACK);
}

void setup() {
  Wire.begin(PORT_IIC);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output

  display.begin();
  tft.setRotation(1);
  tft.setTextSize(CHARSIZE);
}

void loop() {
  if ((millis() % 1000 / 60) == 0) {
    display.draw();
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
  drawKeypad();
}
