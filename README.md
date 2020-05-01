# Keypad-Console
The source code to my projectOn hackaday : https://hackaday.io/project/171302-keypad-console

Future plans are to make a game engine for this device to use. The device has an i2c output to hook up more devices.

Problems currently faced by the device is the 1.8" tft display which has an area of noise. The lower half does not update correct. 

# Game Graphics
Game Graphics is a library for Keypad Console in hopes to make the graphics side of the game easier to use.

## Features
- [ ] Sprites
- [ ] Display
- [X] Color Referance

## How to use
To use I would reccomend the latest release of this library and set up your project like normal using the master of TFT_ILI9163C by sumotoy.

```Cpp
#include <Adafruit_GFX.h>
#include <gfxfont.h> 

#include <SPI.h>

#include <TFT_ILI9163C.h>
#include <Display.h>
#include <Colors.h>
#include <Sprite.h>

#define __DC 9
#define __CS 10

Display display = Display(TFT_ILI9163C(__CS, __DC));

int x = 0, oldX= 0, y = 0, oldY = 0;

bool dirX = true, dirY = true;

void setup(){
    display.begin();
}

void Display::draw(){
    getDisplay().fillRect(oldX, oldY, 10, 10, BLACK);
    getDisplay().fillRect(x, y, 10, 10, RED);
    oldX = x; oldY = y;
}

void gameUpdate(){
    (dirX) ? x+=5 : x-=5;
    (dirY) ? y+=10 : y-=10;

    dirX = (!x-10 >= 118);
    dirY = !(Y-10 >= 118);

    dirX = (x-10 <= 0);
    dirY = (Y-10 <= 0);

}

void loop(){
    if ((millis() % 100) == 0){
        display.draw();
    }
    if ((millis() % 200) == 0){
        gameUpdate();
    }
}
```

## Libraries Used
- For the 1.8" tft display : https://github.com/sumotoy/TFT_ILI9163C
- For the 4x4 Keypad : https://playground.arduino.cc/Code/Keypad/