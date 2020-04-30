#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

#define __CS 10
#define __DC 9

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

const int PORT_IIC = 0x3F;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

char selected = ' ';

int CHARSIZE = 4;

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);

void setup() {
  Wire.begin(PORT_IIC);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  
  tft.begin();
  tft.setRotation(1);
  tft.clearScreen();
  tft.setTextSize(CHARSIZE);
  tft.setCursor(0,0);
  graphicsUpdate();
}

void loop() {
  if (millis() % 1000 == 0) {
    graphicsUpdate();
  }
}

void graphicsUpdate(){
  tft.clearScreen();
  tft.setCursor(0,0);
  for (int i = 0; i < 4; i++){
    tft.setCursor(0,i*8*CHARSIZE);
    for (int j = 0; j < 4; j++){
      if (hexaKeys[i][j] == selected){
        int offsetX = 0==j ? 0 : CHARSIZE;
        int offsetY = 0==i ? 0 : CHARSIZE;
        tft.fillRect(j*5*CHARSIZE + offsetX*j, i*7*CHARSIZE + offsetY*i, 5*CHARSIZE, 7*CHARSIZE, BLUE);
        
      }
      tft.print(hexaKeys[i][j]);
    } 
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
  graphicsUpdate();
}
